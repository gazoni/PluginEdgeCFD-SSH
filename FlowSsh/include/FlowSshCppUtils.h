#pragma once

// Windows
#include <Windows.h>

// STL
#include <exception>

// CRT
#include <assert.h>



namespace FlowSshCpp
{


// NoCopy

class NoCopy
{
public:
	NoCopy() {}

private:
	NoCopy(NoCopy const&);
	void operator= (NoCopy const&);
};



// CriticalSection

class CriticalSection : public NoCopy
{
public:
	CriticalSection();
	~CriticalSection();

	void Lock();
	void Unlock();

private:
	CRITICAL_SECTION m_cs;
};


class CriticalSectionLocker : public NoCopy
{
public:
	CriticalSectionLocker(CriticalSection& cs);
	~CriticalSectionLocker() { Unlock(); }

	bool IsLocked() const { return m_locked; }
	void Lock();		// Locks only if unlocked
	void Unlock();		// Unlocks only if locked

private:
	CriticalSection& m_cs;
	bool m_locked;
};

typedef CriticalSectionLocker CsLocker;	// Alias



// RefPtr

class IRefCountable
{
public:
	virtual ~IRefCountable() {}

	virtual void AddRef() const = 0;
	virtual void Release() const = 0;
};


class RefCountable : public IRefCountable
{
public:
	RefCountable() : m_refCount(1) {}
	virtual ~RefCountable();

	RefCountable(RefCountable const&) : m_refCount(1) {}				// Copy construction should not affect ref count in new object
	RefCountable& operator= (RefCountable const&) { return *this; }		// Assignment should not affect ref count in destination object

	void AddRef() const { InterlockedIncrement(&m_refCount); }
	void Release() const;

private:
	mutable long volatile m_refCount;
};


template <class T>
struct RefData
{
	// No destructor. Safe to use as an element in data vector,
	// where it can be copied around as the vector is resized.
	RefData() : m_ptr(0) {}
	
	T* m_ptr;

	void Detach(T* ptr) 
	{ 
		Detach(m_ptr, 0); // No AddRef() here
		m_ptr = ptr; 
	}
	
	template <class TypeOrDescendant>
	void Detach(RefData<TypeOrDescendant> const& x) 
	{ 
		Detach(m_ptr, x.m_ptr);
		m_ptr = x.m_ptr; 
	}

	static void Detach(IRefCountable* curPtr, IRefCountable* newPtr)
	{
		if (newPtr) newPtr->AddRef();
		if (curPtr) curPtr->Release();
	}
};


template <class T>
class RefPtrConst : public RefData<T>
{
public:
	// Constructors
	RefPtrConst() {}
	RefPtrConst(T const* ptr) { Detach((T*) ptr); }  // No AddRef() here
	
	template <class TypeOrDescendant>
	RefPtrConst(RefPtrConst<TypeOrDescendant> const& sp) { Detach(sp); }

#if _MSC_VER < 1400
	template <>
#endif
	RefPtrConst(RefPtrConst<T> const& sp) { Detach(sp); }

	// Destructor
	~RefPtrConst() { Detach(0); }

	// Copy operator
	RefPtrConst<T>& operator= (T const* ptr) { Detach((T*) ptr); return *this; } // No AddRef() here
	
	template <class TypeOrDescendant>
	RefPtrConst<T>& operator= (RefPtrConst<TypeOrDescendant> const& sp) { Detach(sp); return *this; }

#if _MSC_VER < 1400
	template <>
#endif
	RefPtrConst<T>& operator= (RefPtrConst<T> const& sp) { Detach(sp), return *this; }
	
	// Cast
	template <class U>
	bool IsType() const { return m_ptr ? dynamic_cast<U*>(m_ptr) != 0 : false; }

	template <class U>
	U const* DynamicCast() const { return m_ptr ? dynamic_cast<U const*>(m_ptr) : 0; }

	// Reset: since operator= is overloaded to two pointer types, "*this = 0" is ambiguous
	void Reset() { Detach(0); }

	// Accessors
	T const* Get() const { return m_ptr; }
	T const* operator-> () const { return m_ptr; }
	T const& GetRef() const { assert(m_ptr != 0); return *m_ptr; }
};


template <class T>
class RefPtr : public RefPtrConst<T>
{
public:
	// Constructors
	RefPtr() {}
	RefPtr(T* ptr) : RefPtrConst<T>(ptr) {} // No AddRef() here
	
	template <class TypeOrDescendant>
	RefPtr(RefPtr<TypeOrDescendant> const& sp) : RefPtrConst<T>(sp) {}

#if _MSC_VER < 1400
	template <>
#endif
	RefPtr(RefPtr<T> const& sp) : RefPtrConst<T>(sp) {}

	// Copy operator
	RefPtr<T>& operator= (T* ptr) { Detach(ptr); return *this; } // No AddRef() here
	
	template <class TypeOrDescendant>
	RefPtr<T>& operator= (RefPtr<TypeOrDescendant> const& sp) { Detach(sp); return *this; }

#if _MSC_VER < 1400
	template <>
#endif
	RefPtr<T>& operator= (RefPtr<T> const& sp) { Detach(sp); return *this; }
	
	// Cast
	template <class U>
	bool IsType() const { return dynamic_cast<U*>(m_ptr) != 0; }

	template <class U>
	U* DynamicCast() const { return dynamic_cast<U*>(m_ptr); }

	// Accessors
	T* Get() const { return m_ptr; }
	T* operator-> () const { return m_ptr; }
	T& GetRef() const { assert(m_ptr != 0); return *m_ptr; }

private:
	RefPtrConst<T>& operator= (T const* ptr);
	RefPtrConst<T>& operator= (RefPtrConst<T> const& sp);
};



// Exception

class Exception : public std::exception
{
public:
	Exception(wchar_t const* msg);
	virtual ~Exception() {}
	
	wchar_t const* What() const { return m_wide; }
	char const* what() const { return m_narrow; }

private:
	struct Buffers : public RefCountable
	{
		Buffers() : m_wide(0), m_narrow(0) {}
		~Buffers();

		wchar_t* m_wide;
		char* m_narrow;
	};

	RefPtr<Buffers> m_buffers;
	wchar_t const*	m_wide;
	char const*		m_narrow;
};



// Data

class DataAllocException : public Exception  
{ 
public: 
	DataAllocException() : Exception(L"Error allocating data") {}
};


class Data
{
public:
	Data(BSTR bstr, bool owner = true);
	Data(unsigned char const* ptr, unsigned int size);	
	Data(unsigned int size = 0);		// Creates a writable object if size != 0
	Data(Data const& data);				// Both objects become unwritable
	~Data() { Resize(0); }

	Data& operator=(Data const& data);	// Both objects become unwritable

	void Resize(unsigned int size);		// Object will be writable if size != 0

	// Returns NULL if the object is unwritable. Otherwise, calling Resize()
	// or passing the object as a parameter assignment or copy construction
	// will invalidate the pointer returned here.
	unsigned char* GetWritablePtr() { return m_writablePtr; }

	unsigned char const* GetPtr() const { return m_ptr; }
	unsigned int GetSize() const { return m_size; }

private:
	static unsigned char* BStrToPtrSize(BSTR bstr, unsigned int& size);
	static BSTR PtrSizeToBStr(unsigned char const* ptr, unsigned int size);

	mutable bool m_owner;
	mutable BSTR m_bstr;
	mutable unsigned char* m_writablePtr;
	unsigned char const* m_ptr;
	unsigned int m_size;
	BSTR m_bstrTemp;
};



// HandlerBase

class HandlerBusyException : public Exception
{
public:
	HandlerBusyException() 
		: Exception(L"You cannot pass the same handler object to several requests at once.") {}
};

class ArgumentNullRefPtrException : public Exception
{
public:
	ArgumentNullRefPtrException() : Exception(L"You cannot use a RefPtr(NULL) argument here.") {}
};


template <class H, bool bThrowOnNull>
class HandlerBase
{
protected:
	HandlerBase() : m_locked(0) {}	

	static void OnStartS(RefPtr<H> obj)	
	{
		if (obj.Get()) obj->OnStartBase();
		else if (bThrowOnNull) throw ArgumentNullRefPtrException(); 
	}
	static void OnStartFailedS(RefPtr<H> obj) {	if (obj.Get()) obj->OnStartFailed(); }
	static void AddRefS(RefPtr<H> obj) { if (obj.Get()) obj->AddRef(); }

	void OnStartBase() 
	{
		if (InterlockedIncrement(&m_locked) != 1)
		{ InterlockedDecrement(&m_locked); throw HandlerBusyException(); }
		OnStart(); 
	}
	void OnStartFailed() { InterlockedDecrement(&m_locked);	}	
	void OnDoneBase() { InterlockedDecrement(&m_locked); OnDone(); }

	virtual void OnStart() = 0;
	virtual void OnDone() = 0;
	bool IsDone() const { return InterlockedCompareExchange(&m_locked, 0, 0) == 0; }

private:
	mutable volatile LONG m_locked;
};



// DoneEvent

class CreateEventException : public Exception
{ 
public: 
	CreateEventException() : Exception(L"CreateEvent failed.") {}
};


template <class T>
class DoneEvent : virtual public T
{
protected:
	// This object must be created on the heap.
	virtual ~DoneEvent() { CloseHandle(m_event); }

public:
	DoneEvent() : m_event(CreateEvent(0, true, true, 0))
		{ if (!m_event) throw CreateEventException(); }
	
	HANDLE GetDoneEvent() const { return m_event; }
	bool WaitDone(DWORD timeout = INFINITE) const // Returns true if done.
		{ return WaitForSingleObject(m_event, timeout) == WAIT_OBJECT_0; }
	bool IsDone() const { return WaitDone(0); } 

protected:
	void OnStart() { ResetEvent(m_event); T::OnStart(); }
	void OnDone()  { SetEvent(m_event); T::OnDone(); }

private:
	HANDLE m_event;
};



// DoneMsg

template <class T>
class DoneMsg : virtual public T
{
protected:
	// This object must be created on the heap.
	virtual ~DoneMsg() {}

public:
	DoneMsg(HWND wnd, unsigned int msg, unsigned int requestId=0) : m_wnd(wnd), m_msg(msg), m_requestId(requestId) {}	

protected:
	void OnDone()
	{
		if (IsWindow(m_wnd)) SendMessageW(m_wnd, m_msg, WPARAM(this), LPARAM(m_requestId));
		T::OnDone(); 
	}

	HWND m_wnd;
	unsigned int m_msg;
	unsigned int m_requestId;
};



} // namespace FlowSshCpp

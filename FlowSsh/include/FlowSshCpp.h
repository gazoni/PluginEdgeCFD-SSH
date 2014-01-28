#pragma once

// FlowSshC
#include "FlowSshC.h"

// FlowSshCpp
#include "FlowSshCppUtils.h"

// STL
#include <string>
#include <vector>


//
// Usage Summary for FlowSshCpp 
// ----------------------------
//
// Reference counted objects:
//  - Main objects:    Keypair, PublicKey, Client, ClientSessionChannel, ClientSftpChannel
//  - Handler objects: ErrorHandler, ProgressHandler, ReceiveHandler, RealPathHandler, 
//                     StatHandler, SftpHandler, ListHandler, TransferHandler
//
// 1) Always create them on the heap (dynamic allocation).
// 
// 2) Never delete them.
//    They provide AddRef and Release calls similar to those found in COM objects.
//    FlowSshC will automatically destroy these objects after their reference count drops to 0.
//
//    Important: These objects are destroyed when both the user AND the library have released them. 
//    When the user releases an object before the library does, the object will continue to exist
//	  until it is released by the library. During this time its handlers will still be called.
//
// 3) Use our convenient RefPtr. Example:
//        RefPtr<Client> client(new Client);
//
//    RefPtr manages the necessary AddRef and Release calls of the wrapped object.
//    On occasions where you cannot use RefPtr be sure to call AddRef and Release as appropriate.
//
//
// Handler: FlowSshC has so called handler functions. Essentially they are callback-functions
// which are usually called by internal FlowSshC worker threads. FlowSshCpp wraps 
// these callbacks through a higher level abstraction and provides them to you through 
// classes and convenient virtual methods which you can override when needed.
//


namespace FlowSshCpp
{


// ErrorHandler
//
// OnExceptionInHandler: An uncatched error/exception occurred in one of you
// handlers. Never throw exceptions from within OnExceptionInHandler itself.
// Parameters: fatal == true:
//		error caught by FlowSshC's structured-exception-handling; memory leaks might
//		occur due to undestroyed C++ objects created on the stack of the handler
//		Terminate the application in response to fatal errors. In fact for some errors 
//		the core library (FlowSshC) terminates the process automatically after this event.
//
// By default every FlowSshC call can throw an Exception unless you register your
// own error handler through FlowSshC_Initialize. In any case a custom error handler
// MUST also throw some kind of exceptions for FlowSshC_ErrorFlags::InCall errors.

class ErrorHandler : public RefCountable, public NoCopy
{
protected:
	// This object must be created on the heap.
	virtual ~ErrorHandler() {}

public:
	virtual void OnExceptionInHandler(bool fatal, wchar_t const* desc) = 0;
};



// Initializer
//
// Before using any FlowSshCpp functionality create a SINGLE instance of Initializer (i.e. 
// at the beginning of your main function). Don't create a global instance of this class.

class InitializerExistsException : public Exception
{ 
public:
	InitializerExistsException () : Exception(L"An Initializer already exists.") {}
};


class Initializer : public NoCopy
{
public:
	Initializer(RefPtr<ErrorHandler> errHandler);
	~Initializer();

	static FlowSshC_Version GetVersion();
	void SetActCode(wchar_t const* actCodeHex);
	void Shutdown();

private:
	static void __cdecl FlowSshC(void* thisPtr, unsigned int flags, wchar_t const* desc);
	friend void ExceptionInHandler(std::exception const& e, wchar_t const* handlerName, wchar_t const* defErrDesc);
	friend class DefaultErrorHandler;
	
	static LONG m_count;
	static RefPtr<ErrorHandler> m_errHandler;
	static FlowSshC_ErrorHandler m_extHandler;

public:
	// For internal FlowSshNet usage only!
	static void RegisterExtErrHandler(FlowSshC_ErrorHandler extHandler);
};



// ProgressHandler

class ProgressHandler
	: public RefCountable, public NoCopy, public HandlerBase<ProgressHandler, false>
{
protected:
	// This object must be created on the heap.
	virtual ~ProgressHandler() {}

public:
	ProgressHandler();

	bool Success() const;
	unsigned int GetTaskState() const;
	unsigned int GetTaskSpecificStep() const;
	std::wstring GetAuxInfo() const;

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}
	virtual void OnProgress(unsigned int taskSpecificStep) {}
	virtual void OnSuccess() {}
	virtual void OnError(unsigned int taskSpecificStep, std::wstring const& auxInfo){}

private:
	static void __cdecl FlowSshC(void* thisPtr, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	unsigned int m_taskState; 
	unsigned int m_taskSpecificStep;
	std::wstring m_auxInfo;

	// friends
	friend class Client;
	friend class ClientSessionChannel;
	friend class ClientSftpChannel;
};



// Keypair

class KeypairLoadException : public Exception
{ 
public:
	KeypairLoadException () : Exception(L"Error loading keypair") {}
};


class Keypair : public IRefCountable, public NoCopy
{
protected:
	// This object must be created on the heap.
	virtual ~Keypair() {}

public:
	Keypair(wchar_t const* alg, unsigned int bitCount);
	Keypair(Data const& data, wchar_t const* passphrase);
	Keypair(FlowSshC_Keypair* flowSshC);

	void AddRef()	const;
	void Release()	const;
	
	void SetPassphrase(wchar_t const* passphrase);
	Data GetBitviseData() const;
	Data GetOpenSshData() const;

	FlowSshC_Keypair* GetFlowSshC() const { return m_flowSshC; }

private:
	void SetDestroyHandler();
	static void __cdecl OnDestroy(void* thisPtr);

	// members
	FlowSshC_Keypair* m_flowSshC;
};



// PublicKey

class PublicKeyLoadException : public Exception
{
public: 
	PublicKeyLoadException () : Exception(L"Error loading public key") {}
};


class PublicKey : public IRefCountable, public NoCopy
{
protected:
	// This object must be created on the heap.
	virtual ~PublicKey() {}

public:
	PublicKey(RefPtrConst<Keypair> const& keypair);	
	PublicKey(Data const& data);
	PublicKey(FlowSshC_PublicKey* flowSshC);
		
	void AddRef()	const;
	void Release()	const;

	unsigned int	GetBitCount() const;
	std::wstring	GetAlg() const;
	std::wstring	GetMd5() const;
	std::wstring	GetBubbleBabble() const;
	Data			GetSsh2Data() const;
	Data			GetOpenSshData() const;

	FlowSshC_PublicKey* GetFlowSshC() const { return m_flowSshC; }

private:
	void SetDestroyHandler();
	static void __cdecl OnDestroy(void* thisPtr);

	// members
	FlowSshC_PublicKey* m_flowSshC;
};



// Algorithms

struct KeyExchangeAlgs : public FlowSshC_KeyExchangeAlgs
{
	KeyExchangeAlgs() 
	{	
//		m_dhGexSha256 = 1;
//		m_dhGexSha1 = 1;
		m_dhG14Sha1 = 1;
		m_dhG1Sha1 = 1; 
	}
};

struct HostKeyAlgs : public FlowSshC_HostKeyAlgs
{
	HostKeyAlgs() { m_sshRsa = m_sshDss = 1; }
};

struct EncryptionAlgs : public FlowSshC_EncryptionAlgs
{
	EncryptionAlgs() 
	{ 
		m_aes256Ctr = m_aes192Ctr = m_aes128Ctr = m_tripleDesCtr = 1;
		m_aes256Cbc = m_aes192Cbc = m_aes128Cbc = m_tripleDesCbc = 1;
		m_none = 0; 
	}
};

struct MacAlgs : public FlowSshC_MacAlgs
{
	MacAlgs() 
	{ 
		m_hmacSha2_256 = m_hmacSha1 = m_hmacMd5 = 1;
		m_hmacSha2_256_96 = m_hmacSha1_96 = m_hmacMd5_96 = 1;
		m_none = 0;
	}
};

struct CompressionAlgs : public FlowSshC_CompressionAlgs
{
	CompressionAlgs() { m_zlib = 0; m_none = 1; }
};



// ForwardingRule

struct ForwardingRuleRef
{
	bool m_clientToServer;
	std::wstring m_listInterface;
	unsigned int m_listPort;
};

struct ForwardingRule : public ForwardingRuleRef
{
	std::wstring m_destHost;
	unsigned int m_destPort;
};



// ForwardingErr

struct ForwardingErr
{
	unsigned int m_errCode;
	std::wstring m_auxInfo;

	ForwardingErr() { Reset(); }
	void Reset();
	ForwardingErr& operator= (FlowSshC_ForwardingErr const* x);
};



// ForwardingHandler

class ForwardingHandler
	: public RefCountable, public NoCopy, public HandlerBase<ForwardingHandler, false>
{
protected:
	// This object must be created on the heap.
	virtual ~ForwardingHandler() {}

public:
	ForwardingHandler();

	bool Success() const;
	unsigned int GetListPort() const;
	ForwardingErr GetError() const;

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}
	virtual void OnSuccess(unsigned int listPort) {}
	virtual void OnError(ForwardingErr const& error) {}

private:
	static void __cdecl FlowSshC(void* thisPtr, unsigned int listPort, FlowSshC_ForwardingErr const* error);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	unsigned int m_listPort;
	ForwardingErr m_error;

	// friends
	friend class Client;
};



// Client

class Client : public IRefCountable, public NoCopy
{
protected:
	// This object must be created on the heap.
	virtual ~Client() {}

public:
	Client();
	void AddRef()	const;
	void Release()	const;
	
	void SetAppName(wchar_t const* appNameAndVersion);

	void SetProxyType(unsigned int type);
	void SetProxyHost(wchar_t const* host);
	void SetProxyPort(unsigned int port);
	void SetProxyUserName(wchar_t const* userName);
	void SetProxyPassword(wchar_t const* password);
	void SetProxyOptions(bool resolveLocally);
	
	void SetHost(wchar_t const* host);
	void SetPort(unsigned int port) { FlowSshC_Client_SetPort(m_flowSshC, port); } // **
	void SetUserName(wchar_t const* userName);
	void SetPassword(wchar_t const* password);
	void SetKeypair(RefPtrConst<Keypair> const& keypair);

	void SetKeyExchangeAlgs(KeyExchangeAlgs const& algs);
	void SetHostKeyAlgs(HostKeyAlgs const& algs);
	void SetEncryptionAlgs(EncryptionAlgs const& algs);
	void SetMacAlgs(MacAlgs const& algs);
	void SetCompressionAlgs(CompressionAlgs const& algs);
	void SetOptions(bool startKeyReExchange, int sendBasedKeepAliveTimeoutMs, int recvBasedKeepAliveTimeoutMs, int recvBasedUnresponsivenessTimeoutMs);
	
	void Connect(RefPtr<ProgressHandler> const& progress);
	void Disconnect(RefPtr<ProgressHandler> const& progress);

	void AddForwarding(ForwardingRule const& rule, RefPtr<ForwardingHandler> const& response);
	void CancelForwarding(ForwardingRuleRef const& ruleRef, RefPtr<ForwardingHandler> const& response);
	void InviteForwardings(bool clientToServer, RefPtr<ForwardingHandler> const& response);

	FlowSshC_Client* GetFlowSshC() const { return m_flowSshC; }

	// ** inline implementation prevents linker issues caused by
	//    "#define SetPort  SetPortW" in winspool.h

public:
	class FurtherAuth : public NoCopy
	{
	public:
		FurtherAuth(FlowSshC_FurtherAuth* flowSshC);
		void SetUserName(wchar_t const* userName);
		void SetPassword(wchar_t const* password);
		void SetKeypair(RefPtrConst<Keypair> const& keypair);

		bool HavePartialSuccess() const;
		bool IsPasswordRemaining() const;
		bool IsPublicKeyRemaining() const;
	private:
		FlowSshC_FurtherAuth* m_flowSshC;
	};

	class PasswordChange : public NoCopy
	{
	public:
		PasswordChange(FlowSshC_PasswordChange* flowSshC);
		std::wstring	GetPrompt() const;
		void			SetNewPassword(wchar_t const* password);
	private:
		FlowSshC_PasswordChange* m_flowSshC;
	};

protected:
	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)

	virtual void OnSshVersion(std::wstring const& version) {}

	// Return false to reject host key and disconnect.
	virtual bool OnHostKey(RefPtr<PublicKey> publicKey) { return false; }
		
	// Return false to stop user authentication and disconnect.
	virtual bool OnFurtherAuth(FurtherAuth& furtherAuth) { return false; }
	// Return false to abort password change and continue with user authentication.
	virtual bool OnPasswordChange(PasswordChange& passwordChange) { return false; }

	virtual void OnBanner(std::wstring const& banner) {}
	virtual void OnDisconnect(unsigned int reason, std::wstring const& desc) {}
	
private:
	static void __cdecl OnSshVersion(void* thisPtr, wchar_t const* version);
	static bool __cdecl OnHostKey(void* thisPtr, FlowSshC_PublicKey* publicKey);
	static bool __cdecl OnUserAuth(void* thisPtr, FlowSshC_FurtherAuth* furtherAuth, FlowSshC_PasswordChange* passwordChange);
	static void __cdecl OnBanner(void* thisPtr, wchar_t const* banner);
	static void __cdecl OnDisconnect(void* thisPtr, unsigned int reason, wchar_t const* desc);
	static void __cdecl OnDestroy(void* thisPtr);
	
	// members
	FlowSshC_Client* m_flowSshC;
};



// ReceiveHandler

class ReceiveHandler
	: public RefCountable, public NoCopy, public HandlerBase<ReceiveHandler, true>
{
protected:
	// This object must be created on the heap.
	virtual ~ReceiveHandler() {}

public:
	ReceiveHandler();

	bool Success() const;
	bool StdErr()  const;
	bool Eof()     const;
	// Don't use GetDataPtr or GetDataSize before OnDone is called
	unsigned char const* GetDataPtr()  const;
	unsigned int		 GetDataSize() const;

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}
	virtual void OnReceive(bool stdErr, unsigned char const* dataPtr, unsigned int dataSize, bool eof) {}
	virtual void OnError() {}	// Called if the associated ClientSessionChannel is or gets closed	

private:
	static void __cdecl FlowSshC(void* thisPtr, bool stdErr, unsigned char const* dataPtr, unsigned int dataSize, bool eof);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	bool m_bStdErr;
	bool m_bEof;
	Data m_data;

	// friends
	friend class ClientSessionChannel;
};



// ClientSessionChannel

class ClientSessionChannel : public IRefCountable, public NoCopy
{
protected:
	// This object must be created on the heap.
	virtual ~ClientSessionChannel() {}

public:
	ClientSessionChannel(RefPtrConst<Client> const& client);
	void AddRef()	const;
	void Release()	const;

	void OpenRequest(RefPtr<ProgressHandler> const& progress);
	void PtyRequest(wchar_t const* term, unsigned int widthCols, unsigned int heightRows, RefPtr<ProgressHandler> const& progress);
	void ExecRequest(wchar_t const* command, RefPtr<ProgressHandler> const& progress);
	void ShellRequest(RefPtr<ProgressHandler> const& progress);
	void Receive(unsigned int maxBytes, RefPtr<ReceiveHandler> const& receive);
	void Receive(RefPtr<ReceiveHandler> const& receive, unsigned int maxBytes = 32*1024) { Receive(maxBytes, receive); }
	void Send(Data const& data, bool eof, RefPtr<ProgressHandler> const& progress);
	void Signal(wchar_t const* signalName, RefPtr<ProgressHandler> const& progress);
	void Close(RefPtr<ProgressHandler> const& progress);

	struct ExitSignal
	{
		std::wstring m_name; 
		bool m_coreDumped;
		std::wstring m_errMsg;
	};

protected:
	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnExitStatus(FlowSshC_ExitStatus const& status) {}
	virtual void OnExitSignal(ExitSignal const& signal) {}
	virtual void OnChannelClose() {}

private:
	static void __cdecl OnExit(void* thisPtr, FlowSshC_ExitStatus const* status, FlowSshC_ExitSignal const* signal);
	static void __cdecl OnChannelClose(void* thisPtr);
	static void __cdecl OnDestroy(void* thisPtr);

	// members
	FlowSshC_ClientSessionChannel* m_flowSshC;
};



// FileAttrs

struct FileAttrs
{
	unsigned int m_validAttrFlags;					// FlowSshC_AttrFlags mask of file attributes available
	unsigned char m_type;							// Always present
	unsigned __int64 m_size;						// FlowSshC_Attrs::Size
	unsigned int m_uid; unsigned int m_gid;			// FlowSshC_AttrFlags::UidGid
	unsigned int m_permissions;						// FlowSshC_AttrFlags::Permissions
	unsigned __int64 m_accessTime;					// FlowSshC_AttrFlags::AccessTime
	unsigned int m_accessTimeNs;					// FlowSshC_AttrFlags::AccessTime && FlowSshC_AttrFlags::Subseconds
	unsigned __int64 m_createTime;					// FlowSshC_AttrFlags::CreateTime
	unsigned int m_createTimeNs;					// FlowSshC_AttrFlags::CreateTime && FlowSshC_AttrFlags::Subseconds
	unsigned __int64 m_modifyTime;					// FlowSshC_AttrFlags::ModifyTime
	unsigned int m_modifyTimeNs;					// FlowSshC_AttrFlags::ModifyTime && FlowSshC_AttrFlags::Subseconds
	std::wstring m_owner; std::wstring m_group;		// FlowSshC_AttrFlags::OwnerGroup
	unsigned __int64 m_allocSize;					// FlowSshC_AttrFlags::AllocSize
	unsigned char m_textHint;						// FlowSshC_AttrFlags::TextHint

	FileAttrs() { Reset(); }
	void Reset();
	FileAttrs& operator= (FlowSshC_FileAttrs const* x);
};


// FileInfo

struct FileInfo
{
	std::wstring m_name;
	FileAttrs m_attrs;

	FileInfo() {}
	FileInfo(FlowSshC_FileInfo const* x);
	FileInfo& operator= (FlowSshC_FileInfo const* x);
};


// SftpErr

struct SftpErr
{
	unsigned int m_errCode;
	std::wstring m_errMsg;

	SftpErr() { Reset(); }
	void Reset();
	SftpErr& operator= (FlowSshC_SftpErr const* x);
};


// ListErr

struct ListErr
{
	unsigned int m_listOp;
	unsigned int m_errCode; 
	std::wstring m_errMsg;

	ListErr() { Reset(); }
	void Reset();
	ListErr& operator= (FlowSshC_ListErr const* x);
};


// TransferErr

struct TransferErr
{
	unsigned int m_transferOp;
	unsigned int m_errCode; 
	std::wstring m_errMsg;

	TransferErr() { Reset(); }
	void Reset();
	TransferErr& operator= (FlowSshC_TransferErr const* x);
};



// RealPathHandler

class RealPathHandler
	: public RefCountable, public NoCopy, public HandlerBase<RealPathHandler, true>
{
protected:
	// This object must be created on the heap.
	virtual ~RealPathHandler() {}

public:
	RealPathHandler();

	bool Success() const;
	std::wstring	GetRealPath() const;
	SftpErr			GetError() const;	

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}
	virtual void OnRealPath(std::wstring const& realPath) {}
	virtual void OnError(SftpErr const& error) {}

private:
	static void __cdecl FlowSshC(void* thisPtr, wchar_t const* realPath, FlowSshC_SftpErr const* error);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	std::wstring m_sRealPath;
	SftpErr m_error;

	// friends
	friend class ClientSftpChannel;
};



// StatHandler

class StatHandler
	: public RefCountable, public NoCopy, public HandlerBase<StatHandler, true>
{
protected:
	// This object must be created on the heap.
	virtual ~StatHandler() {}

public:
	StatHandler();

	bool Success() const;
	FileAttrs	GetFileAttrs() const;
	SftpErr		GetError() const;

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}
	virtual void OnStat(FileAttrs const& fileAttrs) {}
	virtual void OnError(SftpErr const& error) {}

private:
	static void __cdecl FlowSshC(void* thisPtr, FlowSshC_FileAttrs const* fileAttrs, FlowSshC_SftpErr const* error);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	FileAttrs m_fileAttrs;
	SftpErr m_error;

	// friends
	friend class ClientSftpChannel;
};



// SftpHandler

class SftpHandler
	: public RefCountable, public NoCopy, public HandlerBase<SftpHandler, false>
{
protected:
	// This object must be created on the heap.
	virtual ~SftpHandler() {}

public:
	SftpHandler();

	bool Success() const;	
	SftpErr GetError() const;

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}
	virtual void OnSuccess() {}
	virtual void OnError(SftpErr const& error) {}

private:
	static void __cdecl FlowSshC(void* thisPtr, FlowSshC_SftpErr const* error);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	SftpErr m_error;

	// friends
	friend class ClientSftpChannel;
};



// ListHandler

class ListHandler
	: public RefCountable, public NoCopy, public HandlerBase<ListHandler, true>
{
protected:
	// This object must be created on the heap.
	virtual ~ListHandler() {}

public:
	ListHandler();

	bool Success() const;
	// Don't use GetFileInfos before OnDone is called
	std::vector<FileInfo> const& GetFileInfos() const;
	ListErr GetError() const;

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}

	// Default implementation stores all file listings to m_fileInfos. 
	// You can retrieve the list with GetFileInfos() once OnDone() is called.
	// If you don't need this functionality override OnList with your own implementation.
	//
	// Returning "false" aborts the listing.
	virtual bool OnList(std::vector<FileInfo> const& fileInfos, bool endOfList);
	virtual void OnError(ListErr const& error) {}

private:
	static bool __cdecl FlowSshC(void* thisPtr, FlowSshC_FileInfo const* fileInfos, unsigned int nrFileInfos, bool endOfList, FlowSshC_ListErr const* error);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	ListErr m_error;
	std::vector<FileInfo> m_fileInfos;

	// friends
	friend class ClientSftpChannel;
};



// TransferHandler

class TransferHandler
	: public RefCountable, public NoCopy, public HandlerBase<TransferHandler, false>
{
protected:
	// This object must be created on the heap.
	virtual ~TransferHandler() {}

public:
	TransferHandler();

	bool Success() const;
	FlowSshC_TransferStat GetTransferStat() const;
	TransferErr GetError() const;

protected:
	virtual void OnStart();

	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnDone() {}
	
	// Returning "false" aborts the transfer.
	virtual bool OnTransfer(bool done, FlowSshC_TransferStat const& transferStat)	{ return true; }
	virtual void OnError(TransferErr const& error) {}

private:
	static bool __cdecl FlowSshC(void* thisPtr, bool done, FlowSshC_TransferStat const* transferStat, FlowSshC_TransferErr const* error);

	// members
	mutable CriticalSection m_cs;
	bool m_bSuccess;
	TransferErr m_error;
	FlowSshC_TransferStat m_transferStat;

	// friends
	friend class ClientSftpChannel;	
};



// ClientSftpChannel

class ClientSftpChannel : public IRefCountable, public NoCopy
{
protected:
	// This object must be created on the heap.
	virtual ~ClientSftpChannel() {}

public:
	ClientSftpChannel(RefPtrConst<Client> const& client);
	void AddRef()	const;
	void Release()	const;

	void Open(RefPtr<ProgressHandler> const& progress);
	void RealPath(wchar_t const* queryPath, RefPtr<RealPathHandler> const& realPath);
	void Stat(wchar_t const* path, unsigned int desiredAttrFlags, RefPtr<StatHandler> const& stat);
	void SetStat(wchar_t const* path, FileAttrs const& fileAttrs, RefPtr<SftpHandler> const& response);
	void MkDir(wchar_t const* path, FileAttrs const& fileAttrs, RefPtr<SftpHandler> const& response);
	void RmDir(wchar_t const* path, RefPtr<SftpHandler> const& response);
	void Remove(wchar_t const* path, RefPtr<SftpHandler> const& response);
	void Rename(wchar_t const* oldPath, wchar_t const* newPath, RefPtr<SftpHandler> const& response);
	void List(wchar_t const* path, RefPtr<ListHandler> const& list);
	void Upload(wchar_t const* localPath, wchar_t const* remotePath, unsigned int transferFlags, RefPtr<TransferHandler> const& transfer);
	void Upload(wchar_t const* localPath, wchar_t const* remotePath, unsigned int transferFlags, unsigned int pipelineSize, RefPtr<TransferHandler> const& transfer);
	void Download(wchar_t const* remotePath, wchar_t const* localPath, unsigned int transferFlags, RefPtr<TransferHandler> const& transfer);
	void Download(wchar_t const* remotePath, wchar_t const* localPath, unsigned int transferFlags, unsigned int pipelineSize, RefPtr<TransferHandler> const& transfer);
	void Close(RefPtr<ProgressHandler> const& progress);

protected:
	// Callback event handlers
	// Note: handlers are usually called from a worker thread (created in FlowSshC.dll)
	virtual void OnSftpVersion(unsigned int version) {}
	virtual void OnChannelClose() {}

private:
	static void __cdecl OnSftpVersion(void* thisPtr, unsigned int version);
	static void __cdecl OnChannelClose(void* thisPtr);	
	static void __cdecl OnDestroy(void* thisPtr);

	// members
	FlowSshC_ClientSftpChannel* m_flowSshC;
};



// DoneEvent's typedefs

typedef DoneEvent<ProgressHandler>			ProgressEvent;
typedef DoneEvent<ForwardingHandler>		ForwardingEvent;
typedef DoneEvent<ReceiveHandler>			ReceiveEvent;
typedef DoneEvent<RealPathHandler>			RealPathEvent;
typedef DoneEvent<StatHandler>				StatEvent;
typedef DoneEvent<SftpHandler>				SftpEvent;
typedef DoneEvent<ListHandler>				ListEvent;
typedef DoneEvent<TransferHandler>			TransferEvent;



// DoneMsg's typedefs

typedef DoneMsg<ProgressHandler>		ProgressMsg;
typedef DoneMsg<ForwardingHandler>		ForwardingMsg;
typedef DoneMsg<ReceiveHandler>			ReceiveMsg;
typedef DoneMsg<RealPathHandler>		RealPathMsg;
typedef DoneMsg<StatHandler>			StatMsg;
typedef DoneMsg<SftpHandler>			SftpMsg;
typedef DoneMsg<ListHandler>			ListMsg;
typedef DoneMsg<TransferHandler>		TransferMsg;



} // namespace FlowSshCpp

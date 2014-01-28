#pragma once

#ifdef COMPILING_FLOWSSHC
#define FLOWSSHC_FUNC extern "C" __declspec(dllexport)
#else
#define FLOWSSHC_FUNC extern "C" __declspec(dllimport)
#ifdef _WIN64
#pragma comment(lib, "FlowSshC64.lib") 
#else
#pragma comment(lib, "FlowSshC32.lib") 
#endif
#endif

// Windows
#define NOMINMAX
#include <windows.h>



struct FlowSshC_Version
{
	unsigned short m_major;
	unsigned short m_minor;
};

FLOWSSHC_FUNC FlowSshC_Version					__cdecl FlowSshC_GetVersion();



struct FlowSshC_ErrorFlags { enum {
	// Notes:
	// - Error (exception) has occurred during FlowSshC function call.
	// - Handler implementation may throw exceptions with this flag.
	// - InCall and InHandler flags are always exclusive.
	InCall		= 0x01,
	// Notes:
	// - Error has occurred in one of the user provided FlowSshC handlers.
	// - Handler implementation must not throw exceptions with this type.
	// - InCall and InHandler flags are always exclusive.
	InHandler   = 0x02 }; };

typedef void (__cdecl* FlowSshC_ErrorHandler)(void* handlerData, unsigned int flags, wchar_t const* desc);



// Notes:
// - FlowSshC needs to be initialized before calling any of the functions below this one.
// - Resources acquired through initialization can be freed with FlowSshC_Shutdown call.
// - The function may be called multiple times for the purpose of changing the error 
//   handler. Calling the function multiple times has no other effects - shutdown will
//   always be performed with the first call to FlowSshC_Shutdown.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Initialize(FlowSshC_ErrorHandler handler, void* handlerData);



// Notes:
// - Call this function with the activation code received from Bitvise once a FlowSsh license has been purchased.
// - Setting a valid activation code will remove the "Welcome to FlowSsh evaluation!" message box shown by the library.
// - The activation code is normally provided as two long lines of hexadecimal characters.
//   Concatenate the two lines of the activation code into a single string before passing it to this function.
FLOWSSHC_FUNC void								__cdecl FlowSshC_SetActCode(wchar_t const* actCodeHex);



struct FlowSshC_TaskState { enum {
	InProgress	= 100,
	Completed	= 200,
	Failed		= 300 }; };

// Notes:
// - Task specific step is provided for InProgress and Failed states only.
// - In-progress steps are registered right before they are to be processed. 
// - Auxilary info may be NULL; it normally is NULL for InProgress and Completed states.
typedef void (__cdecl* FlowSshC_ProgressHandler)(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo);

// Note:
// - Called when object is being destroyed as a result of the last FlowSshC_*_Release call.
typedef void (__cdecl* FlowSshC_DestroyHandler)(void* handlerData);



struct FlowSshC_Keypair {};
FLOWSSHC_FUNC FlowSshC_Keypair*					__cdecl FlowSshC_Keypair_CreateNew(wchar_t const* alg, unsigned int bitCount);
// Notes:
// - Returns NULL if keypair (private key) cannot be decoded (e.g. bad data or passphrase).
// - Supported formats: OpenSSH, Bitvise (regular, WinSSHD, and legacy wcfg).
// - Passphrase parameter can be NULL if passphrase is not required.
FLOWSSHC_FUNC FlowSshC_Keypair*					__cdecl FlowSshC_Keypair_CreateFromData(unsigned char const* data, unsigned int dataBytes, wchar_t const* passphrase);
FLOWSSHC_FUNC FlowSshC_Keypair*					__cdecl FlowSshC_Keypair_CreateCopy(FlowSshC_Keypair* keypair);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Keypair_AddRef(FlowSshC_Keypair* keypair);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Keypair_Release(FlowSshC_Keypair* keypair);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Keypair_SetDestroyHandler(FlowSshC_Keypair* keypair, FlowSshC_DestroyHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Keypair_SetPassphrase(FlowSshC_Keypair* keypair, wchar_t const* passphrase);
// Note for the remaining FlowSshC_Keypair_* functions:
// - Caller needs to release the returned BSTR with SysFreeString().
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_Keypair_GetBitviseData(FlowSshC_Keypair* keypair);
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_Keypair_GetOpenSshData(FlowSshC_Keypair* keypair);


struct FlowSshC_PublicKey {};
FLOWSSHC_FUNC FlowSshC_PublicKey*				__cdecl FlowSshC_PublicKey_CreateFromKeypair(FlowSshC_Keypair* keypair);
// Notes:
// - Returns NULL if public key cannot be decoded.
// - Supported formats: SSH2, OpenSSH, Bitvise, hex-encoded bytes, plain bytes.
FLOWSSHC_FUNC FlowSshC_PublicKey*				__cdecl FlowSshC_PublicKey_CreateFromData(unsigned char const* data, unsigned int dataBytes);
FLOWSSHC_FUNC FlowSshC_PublicKey*				__cdecl FlowSshC_PublicKey_CreateCopy(FlowSshC_PublicKey* publicKey);
FLOWSSHC_FUNC void								__cdecl FlowSshC_PublicKey_AddRef(FlowSshC_PublicKey* publicKey);
FLOWSSHC_FUNC void								__cdecl FlowSshC_PublicKey_Release(FlowSshC_PublicKey* publicKey);
FLOWSSHC_FUNC void								__cdecl FlowSshC_PublicKey_SetDestroyHandler(FlowSshC_PublicKey* publicKey, FlowSshC_DestroyHandler handler, void* handlerData);
FLOWSSHC_FUNC unsigned int						__cdecl FlowSshC_PublicKey_GetBitCount(FlowSshC_PublicKey* publicKey);
// Note for the remaining FlowSshC_PublicKey_* functions:
// - Caller needs to release the returned BSTR with SysFreeString().
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_PublicKey_GetAlg(FlowSshC_PublicKey* publicKey);
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_PublicKey_GetMd5(FlowSshC_PublicKey* publicKey);
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_PublicKey_GetBubbleBabble(FlowSshC_PublicKey* publicKey);
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_PublicKey_GetSsh2Data(FlowSshC_PublicKey* publicKey);
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_PublicKey_GetOpenSshData(FlowSshC_PublicKey* publicKey);



struct FlowSshC_FurtherAuth {};
FLOWSSHC_FUNC void								__cdecl FlowSshC_FurtherAuth_SetUserName(FlowSshC_FurtherAuth* furtherAuth, wchar_t const* userName);
FLOWSSHC_FUNC void								__cdecl FlowSshC_FurtherAuth_SetPassword(FlowSshC_FurtherAuth* furtherAuth, wchar_t const* password);
FLOWSSHC_FUNC void								__cdecl FlowSshC_FurtherAuth_SetKeypair(FlowSshC_FurtherAuth* furtherAuth, FlowSshC_Keypair* keypair);
// Note:
// - Whether any of the previous authentication attempts have succeeded, but at the same
//   time, more authentication is required by the server. Partial success flag is reset
//   each time further authentication continues.
FLOWSSHC_FUNC bool								__cdecl FlowSshC_FurtherAuth_HavePartialSuccess(FlowSshC_FurtherAuth* furtherAuth);
// Notes for the remaining FlowSshC_FurtherAuth_* functions:
// - Whether the server will accept 'password' or 'publickey' authentication methods.
// - Some servers accept password through 'keyboard-interactive' authentication method.
//   Password remaining flag takes that into account as well.
// - Results of these functions are irrelevant if user name is changed.
FLOWSSHC_FUNC bool								__cdecl FlowSshC_FurtherAuth_IsPasswordRemaining(FlowSshC_FurtherAuth* furtherAuth);
FLOWSSHC_FUNC bool								__cdecl FlowSshC_FurtherAuth_IsPublicKeyRemaining(FlowSshC_FurtherAuth* furtherAuth);



struct FlowSshC_PasswordChange {};
FLOWSSHC_FUNC void								__cdecl FlowSshC_PasswordChange_SetNewPassword(FlowSshC_PasswordChange* passwordChange, wchar_t const* password);
// Note:
// - Caller needs to release the returned BSTR with SysFreeString().
FLOWSSHC_FUNC BSTR								__cdecl FlowSshC_PasswordChange_GetPrompt(FlowSshC_PasswordChange* passwordChange);



struct FlowSshC_ConnectStep { enum {
	ConnectToProxy		= 100,	// Skipped when connecting directly.
	ConnectToSshServer	= 200,
	SshVersionString	= 300,
	SshKeyExchange		= 400,
	SshUserAuth			= 500 }; };

struct FlowSshC_DisconnectReason { enum {
	Exception			= 0,
	FlowError			= 1,
	ConnectionError		= 2,
	ConnectionLost		= 3,
	ByServer			= 4,
	ByClient			= 5 }; };

struct FlowSshC_ProxyType { enum {
	None				= 0,
	Socks4				= 1,
	Socks5				= 2,
	HttpConnect			= 3 }; };


// Notes for FlowSshC_*Algs structures:
// - Algorithm is enabled if it holds a non-zero value.
// - Algorithms with lower non-zero values precede algorithms with higher values.
// - Algorithms holding the same non-zero values are ordered by the declaration order. 

struct FlowSshC_KeyExchangeAlgs
{
//	byte m_dhGexSha256;		// diffie-hellman-group-exchange-sha256
//	byte m_dhGexSha1;		// diffie-hellman-group-exchange-sha1
	byte m_dhG14Sha1;		// diffie-hellman-group14-sha1
	byte m_dhG1Sha1;		// diffie-hellman-group1-sha1
};

struct FlowSshC_HostKeyAlgs
{
	byte m_sshRsa;			// ssh-rsa
	byte m_sshDss;			// ssh-dsa
};

struct FlowSshC_EncryptionAlgs
{
	byte m_aes256Ctr;		// aes256-ctr
	byte m_aes192Ctr;		// aes192-ctr
	byte m_aes128Ctr;		// aes128-ctr
	byte m_tripleDesCtr;	// 3des-ctr
	byte m_aes256Cbc;		// aes256-cbc
	byte m_aes192Cbc;		// aes192-cbc
	byte m_aes128Cbc;		// aes128-cbc
	byte m_tripleDesCbc;	// 3des-cbc
	byte m_none;			// none
};

struct FlowSshC_MacAlgs
{
	byte m_hmacSha2_256;	// hmac-sha2-256
	byte m_hmacSha1;		// hmac-sha1
	byte m_hmacMd5;			// hmac-md5
	byte m_hmacSha2_256_96;	// hmac-sha2-256-96
	byte m_hmacSha1_96;		// hmac-sha1-96
	byte m_hmacMd5_96;		// hmac-md5-96
	byte m_none;			// none
};

struct FlowSshC_CompressionAlgs
{
	byte m_zlib;			// zlib
	byte m_none;			// none
};


struct FlowSshC_ForwardingErrCode { enum {
	GeneralError			= 2,
	ClientNotConnected		= 3,
	// Notes:
	// - Listening address is already in use.
	// - Used only when adding client-to-server forwarding.
	AddressInUse			= 4,
	// Notes:
	// - SSH global request has been rejected by the server.
	// - This error can occur while adding server-to-client
	//   forwardings or inviting (server-side) forwardings.
	RejectedByServer		= 5,
	// Note:
	// - Used only when canceling forwardings.
	RuleNotFound			= 6,
	// Note:
	// - Used only when inviting (server-side) forwardings.
	AlreadyInvited			= 7 }; };

struct FlowSshC_ForwardingErr
{
	unsigned int m_errCode;
	// Note:
	// - Auxiliary info is optional and may be left NULL.
	wchar_t const* m_auxInfo;
};

struct FlowSshC_ForwardingRule
{
	bool m_clientToServer;
	wchar_t const* m_listInterface;
	unsigned int m_listPort;
	// Note:
	// - When canceling a forwarding, destination host and
	//   port are not used; they may be left uninitialized.
	wchar_t const* m_destHost;
	unsigned int m_destPort;
};


// Note:
// - SSH version string received from the remote is passed through this handler.
typedef void (__cdecl* FlowSshC_SshVersionHandler)(void* handlerData, wchar_t const* version);
// Note:
// - Return false to reject host key and disconnect.
typedef bool (__cdecl* FlowSshC_HostKeyHandler)(void* handlerData, FlowSshC_PublicKey* publicKey);
// Notes:
// - FurtherAuth and PasswordChange are always exclusive - one will be NULL.
// - When doing FurtherAuth: return false to stop user authentication and disconnect.
// - When doing PasswordChange: return false to abort password change and continue with
//   user authentication (most likely raising FurtherAuth in the process).
typedef bool (__cdecl* FlowSshC_UserAuthHandler)(void* handlerData, FlowSshC_FurtherAuth* furtherAuth, FlowSshC_PasswordChange* passwordChange);
typedef void (__cdecl* FlowSshC_BannerHandler)(void* handlerData, wchar_t const* banner);
// Notes:
// - Error pointer is NULL on success. 
// - Listening port is meaningful only when the forwarding has successfully been added,
//   and when the original forwarding rule had listening port set to 0 (use any port).
typedef void (__cdecl* FlowSshC_ForwardingHandler)(void* handlerData, unsigned int listPort, FlowSshC_ForwardingErr const* error);
// Notes:
// - Disconnect handler can be called only on successfully connected clients.
// - Except for disconnect progress handler (when disconnect is pending), no 
//   client's handlers can be called after this handler.
typedef void (__cdecl* FlowSshC_DisconnectHandler)(void* handlerData, unsigned int reason, wchar_t const* desc);


struct FlowSshC_Client {};
FLOWSSHC_FUNC FlowSshC_Client*					__cdecl FlowSshC_Client_Create();
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_AddRef(FlowSshC_Client* client);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_Release(FlowSshC_Client* client);
// Notes for all FlowSshC_Client_Set*Handler functions:
// - All handlers can be set NULL, in fact, handlers are NULL by default.
// - Host key handler must not be NULL, otherwise host key verification will always fail.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetDestroyHandler(FlowSshC_Client* client, FlowSshC_DestroyHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetVersionHandler(FlowSshC_Client* client, FlowSshC_SshVersionHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetHostKeyHandler(FlowSshC_Client* client, FlowSshC_HostKeyHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetUserAuthHandler(FlowSshC_Client* client, FlowSshC_UserAuthHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetBannerHandler(FlowSshC_Client* client, FlowSshC_BannerHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetDisconnectHandler(FlowSshC_Client* client, FlowSshC_DisconnectHandler handler, void* handlerData);
// Notes:
// - Application name (and version) must be set before attempting to connect the client.
// - Client version string: "SSH-2.0-" + <FlowSshVersion> + " FlowSsh: " + <AppNameAndVersion>.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetAppName(FlowSshC_Client* client, wchar_t const* appNameAndVersion);
// Notes for all FlowSshC_Client_SetProxy_* functions:
// - Use of proxy server is disabled by default (ProxyType = FlowSshC_ProxyType::None).
// - Default proxy host is empty string while proxy port is set to 1080 by default. 
// - Resolve (DNS name) locally is enabled by default (ProxyOptions: resolveLocally = true).
// - SOCKSv4 supports DNS names starting with SOCKSv4a extension. Therefore, if your SOCKSv4 
//   proxy does not support SOCKSv4a extension, resolve (DNS name) locally must be enabled.
// - SOCKSv4 (including SOCKSv4a) does not support authentication.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetProxyType(FlowSshC_Client* client, unsigned int type);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetProxyHost(FlowSshC_Client* client, wchar_t const* host);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetProxyPort(FlowSshC_Client* client, unsigned int port);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetProxyUserName(FlowSshC_Client* client, wchar_t const* userName);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetProxyPassword(FlowSshC_Client* client, wchar_t const* password);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetProxyOptions(FlowSshC_Client* client, bool resolveLocally);
// Notes for the remaning FlowSshC_Client_Set* functions.
// - Host and user name are empty strings by default, while default port value is 22.
// - Password and keypair are NULL by default - are not set by default.
// - Authentication procedure:
//    - If neither password and keypair are set, 'none' authentication method will be attempted.
//    - If both password and keypair are set, 'publickey' authentication will be performed first.
//    - If password is set and 'password' authentication method either fails or is not available,
//      then password through 'keyboard-interactive' will be attempted. Conditions for a successful
//      password through 'keyboard-interactive' authentication are the following:
//       - Kbdi info request must contain exactly one prompt.
//       - One of the kbdi info request strings must contain a case-insensitive "password" substring.
//    - If further authentication is required, user auth handler will be called. If such handler is not 
//      set or if the handler returns false, client will disconnect with user authentication failure.
//    - If password change is requested during 'password' authentication, user auth handler will be
//      called. If such handler is not set, if it returns false, or if the server rejects new password,
//      the original 'password' authentication attempt will fail.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetHost(FlowSshC_Client* client, wchar_t const* host);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetPort(FlowSshC_Client* client, unsigned int port);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetUserName(FlowSshC_Client* client, wchar_t const* userName);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetPassword(FlowSshC_Client* client, wchar_t const* password);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetKeypair(FlowSshC_Client* client, FlowSshC_Keypair* keypair);
// Notes for all FlowSshC_Client_Set*Algs functions:
// - By default:
//    - all key exchange algorithms are enabled and ordered by their declaration order,
//    - both host key algorithms are enabled and ordered by their declaration order,
//    - all encryption algorithms except none are enabled and ordered by their declaration order,
//    - all MAC algorithms except none are enabled and ordered by their declaration order,
//    - zlib compression is disabled while none is enabled.
// - Compression will be used only if both the client and server have it enabled.
// - Compression may deteriorate transfer rate on connections with high throughput. 
// - Changing algorithms have no effect on active clients past the initial key exchange.
// - Passing a null algorithm pointer will load default values.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetKeyExchangeAlgs(FlowSshC_Client* client, FlowSshC_KeyExchangeAlgs const* algs);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetHostKeyAlgs(FlowSshC_Client* client, FlowSshC_HostKeyAlgs const* algs);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetEncryptionAlgs(FlowSshC_Client* client, FlowSshC_EncryptionAlgs const* algs);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetMacAlgs(FlowSshC_Client* client, FlowSshC_MacAlgs const* algs);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetCompressionAlgs(FlowSshC_Client* client, FlowSshC_CompressionAlgs const* algs);
// Notes:
// - Both start key re-exchange and keep-alive are set/enabled by default.
// - If start key re-echange is set, the client will initiate key re-exchange after every
//   1 hour of connection time, or after every 1 GB of exchanged data. If disabled, the client 
//   will still correctly respond to key re-exchange requests started by the server.
// - If keep-alive is enabled, the client will periodically generate network traffic when idle.
// - Set any of the keep-alive values to:
//     0 to disable it;
//     -1 to use the default value built into FlowSsh;
//     or provide your own value in milliseconds.
// - Changing options has no efect on active clients past the initial key exchange.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_SetOptions(FlowSshC_Client* client, bool startKeyReExchange, int sendBasedKeepAliveTimeoutMs, int recvBasedKeepAliveTimeoutMs, int recvBasedUnresponsivenessTimeoutMs);
// Notes:
// - Connect will fail (through the progress handler) when called on an active client.
// - Connect will fail (through the progress handler) if application name (and version) is not set.
// - If client gets disconnected while connecting, the disconnect handler will not be
//   called. Instead, failure will be relayed through the connect's progress handler.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_Connect(FlowSshC_Client* client, FlowSshC_ProgressHandler handler, void* handlerData);
// Notes:
// - Disconnect will fail (through progress handler) if client is already disconnecting.
// - Disconnecting an already disconnected client will yield success.
// - If client is connecting, then issuing disconnect will abort the connection.
// - No client's handlers can be called past the successfully completed disconnect.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_Disconnect(FlowSshC_Client* client, FlowSshC_ProgressHandler handler, void* handlerData);
// Notes for all FlowSshC_Client_*Forwarding* functions:
// - Forwarding instructions will fail immediately if the client is not connected or connecting,
//   and if the client is connecting they will be delayed until connect operation is completed.
// - The invite forwardings instruction will enable server-configured forwardings which are available
//   only on Bitvise SSH Server (WinSSHD).
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_AddForwarding(FlowSshC_Client* client, FlowSshC_ForwardingRule const* rule, FlowSshC_ForwardingHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_CancelForwarding(FlowSshC_Client* client, FlowSshC_ForwardingRule const* rule, FlowSshC_ForwardingHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_Client_InviteForwardings(FlowSshC_Client* client, bool clientToServer, FlowSshC_ForwardingHandler handler, void* handlerData);



struct FlowSshC_ExitStatus
{
	unsigned int m_code;
};

struct FlowSshC_ExitSignal
{
	wchar_t const* m_name; 
	bool m_coreDumped;
	wchar_t const* m_errMsg;
};


// Notes:
// - Close handler can be called only on successfully opened channels.
// - No channel's handlers can be called after this handler.
typedef void (__cdecl* FlowSshC_ChannelCloseHandler)(void* handlerData);
// Note:
// - ExitStatus and ExitSignal are always exclusive - one will be NULL.
typedef void (__cdecl* FlowSshC_ExitHandler)(void* handlerData, FlowSshC_ExitStatus const* status, FlowSshC_ExitSignal const* signal);
// Note:
// - Receive handler with all parameter set to zero (stdErr=false, data=NULL, dataBytes=0, eof=false)
//   is called when the associated channel is or gets closed.
typedef void (__cdecl* FlowSshC_ReceiveHandler)(void* handlerData, bool stdErr, unsigned char const* data, unsigned int dataBytes, bool eof);
	
 
struct FlowSshC_ClientSessionChannel {};
// Notes:
// - Returns NULL on fatal error only (after fatal error handler is called).
// - Channel can be created even if the associated client is not yet connected.
// - Channel keeps the associated client alive throughout channel's lifetime.
// - Channel is closed immediately if FlowSshC_ClientSessionChannel_Close is called.
//   Otherwise, if channel is closed by the server or due to client disconnection,
//   then channel will linger (channel close handler will be delayed) until all data 
//   (and/or EOF) received is retrieved through FlowSshC_ClientSessionChannel_Receive.
//   Sending data, EOF, or requests at this point will fail with the following message:
//   "Session channel is closing."
FLOWSSHC_FUNC FlowSshC_ClientSessionChannel*	__cdecl FlowSshC_ClientSessionChannel_Create(FlowSshC_Client* client);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_AddRef(FlowSshC_ClientSessionChannel* channel);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_Release(FlowSshC_ClientSessionChannel* channel);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_SetDestroyHandler(FlowSshC_ClientSessionChannel* client, FlowSshC_DestroyHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_SetExitHandler(FlowSshC_ClientSessionChannel* channel, FlowSshC_ExitHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_SetCloseHandler(FlowSshC_ClientSessionChannel* channel, FlowSshC_ChannelCloseHandler handler, void* handlerData);
// Notes:
// - Client must be connected before sending open request, otherwise the request will
//   fail immediately through the supplied progress handler.
// - A closed channel can be re-opened at any time.
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_OpenRequest(FlowSshC_ClientSessionChannel* channel, FlowSshC_ProgressHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_PtyRequest(FlowSshC_ClientSessionChannel* channel, wchar_t const* term, unsigned int widthCols, unsigned int heightRows, FlowSshC_ProgressHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_ExecRequest(FlowSshC_ClientSessionChannel* channel, wchar_t const* command, FlowSshC_ProgressHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_ShellRequest(FlowSshC_ClientSessionChannel* channel, FlowSshC_ProgressHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_Receive(FlowSshC_ClientSessionChannel* channel, unsigned int maxBytes, FlowSshC_ReceiveHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_Send(FlowSshC_ClientSessionChannel* channel, unsigned char const* data, unsigned int dataBytes, bool eof, FlowSshC_ProgressHandler handler, void* handlerData);
// Notes:
// - SSH defines the following signals names: ABRT, ALRM, FPE, HUP, ILL, INT, KILL,
//   PIPE, QUIT, SEGV, TERM, USR1, USR2. These are POSIX signals without the SIG prefix.
// - There are two ways to send the Ctrl+C signal: either by sending 0x03 data byte or
//   by issuing the INT signal.
// - Bitvise SSH Server (WinSSHD) will accept INT and a custom BREAK@bitvise.com
//   (Ctrl+Break) signal.
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_Signal(FlowSshC_ClientSessionChannel* channel, wchar_t const* signalName, FlowSshC_ProgressHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSessionChannel_Close(FlowSshC_ClientSessionChannel* channel, FlowSshC_ProgressHandler handler, void* handlerData);



struct FlowSshC_FileType { enum {
	Regular		= 1,
    Directory	= 2,
    Symlink		= 3,
    Special		= 4,
    Unknown		= 5,
	// SFTPv6+
    Socket		= 6,
    CharDevice	= 7,
    BlockDevice = 8,
    Fifo		= 9 }; }; 

struct FlowSshC_AttrFlags { enum {
	Size		= 0x00000001,
	UidGid		= 0x00000002, // SFTPv3-
	Permissions	= 0x00000004,
	// SFTPv4+
	AccessTime	= 0x00000008, // Available in SFTPv3- together with ModifyTime
	CreateTime	= 0x00000010, 
	ModifyTime	= 0x00000020, // Available in SFTPv3- together with AccessTime
	OwnerGroup	= 0x00000080,	
	Subseconds	= 0x00000100,
	// SFTPv6+
	AllocSize	= 0x00000400, 
	TextHint	= 0x00000800  }; };   

struct FlowSshC_TextHint { enum {
	KnownText		= 0,
	GuessedText		= 1,
    KnownBinary		= 2,
    GuessedBinary	= 3 }; };    

struct FlowSshC_FileAttrs
{
	unsigned int m_validAttrFlags;					// FlowSshC_AttrFlags mask of file attributes available
	unsigned char m_type;							// Always present
	unsigned __int64 m_size;						// FlowSshC_AttrFlags::Size
	unsigned int m_uid; unsigned int m_gid;			// FlowSshC_AttrFlags::UidGid
	unsigned int m_permissions;						// FlowSshC_AttrFlags::Permissions
	unsigned __int64 m_accessTime;					// FlowSshC_AttrFlags::AccessTime
	unsigned int m_accessTimeNs;					// FlowSshC_AttrFlags::AccessTime && FlowSshC_AttrFlags::Subseconds
	unsigned __int64 m_createTime;					// FlowSshC_AttrFlags::CreateTime
	unsigned int m_createTimeNs;					// FlowSshC_AttrFlags::CreateTime && FlowSshC_AttrFlags::Subseconds
	unsigned __int64 m_modifyTime;					// FlowSshC_AttrFlags::ModifyTime
	unsigned int m_modifyTimeNs;					// FlowSshC_AttrFlags::ModifyTime && FlowSshC_AttrFlags::Subseconds
	wchar_t const* m_owner; wchar_t const* m_group;	// FlowSshC_AttrFlags::OwnerGroup
	unsigned __int64 m_allocSize;					// FlowSshC_AttrFlags::AllocSize
	unsigned char m_textHint;						// FlowSshC_AttrFlags::TextHint
};

struct FlowSshC_FileInfo
{
	wchar_t const* m_name;
	FlowSshC_FileAttrs m_attrs;
};

struct FlowSshC_SftpErrCode { enum {
	Eof						= 1,
	NoSuchFile				= 2,
	PermissionDenied		= 3,
	Failure					= 4,
	BadMessage				= 5,
	NoConnection			= 6,
	ConnectionLost			= 7,
	OpUnsupported			= 8,
	// SFTP4+
	InvalidHandle			= 9,
	NoSuchPath				= 10,
	FileAlreadyExists		= 11,
	WriteProtect			= 12,
	NoMedia					= 13,
	// SFTP5+
	NoSpaceOnFilesystem		= 14,
	QuotaExceeded			= 15,
	UnknownPrinciple		= 16,
	LockConflict			= 17,
	// SFTP6+
	DirNotEmpty				= 18,
	NotADirectory			= 19,
	InvalidFilename			= 20,
	LinkLoop				= 21,
	CannotDelete			= 22,
	InvalidParameter		= 23,
	FileIsADirectory		= 24,
	ByteRangeLockConflict	= 25,
	ByteRangeLockRefused	= 26,
	DeletePending			= 27,
	FileCorrupt				= 28,
	OwnerInvalid			= 29,
	GroupInvalid			= 30,
	NoMatchingByteRangeLock	= 31 }; };

struct FlowSshC_SftpErr
{
	unsigned int m_errCode;
	wchar_t const* m_errMsg;
};

struct FlowSshC_ListOp { enum {
	// Codeless errors
	Exception		= 0,
	// SFTP errors - FlowSshC_SftpErrCode
	ListDir			= 100,
	ChannelNotOpen	= 150, }; };	// If channel is closed, closing, or opening.

struct FlowSshC_ListErr
{
	unsigned int m_listOp;
	unsigned int m_errCode; 
	wchar_t const* m_errMsg;
};

struct FlowSshC_TransferOp { enum {
	// Codeless errors
	Exception				= 0,
	// SFTP errors - FlowSshC_SftpErrCode
	MakeRemoteDir			= 100,
	OpenRemoteFile			= 101,
	ReadRemoteFile			= 102,
	WriteRemoteFile			= 103,
	ChannelNotOpen			= 150,		// If channel is closed, closing, or opening.
	// WinAPI errors - see MSDN
	MakeLocalDir			= 200,
	OpenLocalFile			= 201,
	ReadLocalFile			= 202,
	WriteLocalFile			= 203,
	// Resume errors - FlowSshC_ResumeErrCode
	ResumeLocalFile			= 300,
	ResumeRemoteFile		= 301 }; }; 

struct FlowSshC_ResumeErrCode { enum {
	TextMode	  = 1,		// Files opened in text mode cannot be resumed.
	FileSize	  = 2,		// Target file is already larger than source file.
	Conversion	  = 3,		// Text files for which conversion is required cannot be resumed.
	Content		  = 4,		// Target and source files differ.
	FileSizeError = 5 }; };	// Unable to retrieve file size.

struct FlowSshC_TransferErr
{
	unsigned int m_transferOp;
	unsigned int m_errCode; 
	wchar_t const* m_errMsg;
};
	
struct FlowSshC_TransferStat
{
	unsigned __int64 m_bytesTransferred;
	unsigned __int64 m_timeElapsedMs;
	unsigned __int64 m_currentFileSize;
	unsigned __int64 m_finalFileSize; // May change during transfer due to text conversion.
	// Note:
	// - Final file size will be invalid if source file size cannot be retrieved.
	//   Furthermore, final size will go invalid if transfer reaches final size 
	//   without also reaching EOF. When final size is invalid, it will hold the
	//   same value as current file size. A successfully completed file transfer
	//   will always hold a valid final size that will be equal to current file
	//   size; however, that is not necessarily true the other way around.
	bool m_finalFileSizeValid;
};


// Note for all FlowSshC_Client* handlers:
// - Error pointer is NULL on success. On error, handler's variables other than
//   error pointer must not be accessed (they may be NULL or uninitialized).
typedef void (__cdecl* FlowSshC_SftpVersionHandler)(void* handlerData, unsigned int version);
typedef void (__cdecl* FlowSshC_RealPathHandler)(void* handlerData, wchar_t const* realPath, FlowSshC_SftpErr const* error);
typedef void (__cdecl* FlowSshC_StatHandler)(void* handlerData, FlowSshC_FileAttrs const* fileAttrs, FlowSshC_SftpErr const* error);
typedef void (__cdecl* FlowSshC_SftpHandler)(void* handlerData, FlowSshC_SftpErr const* error);
// Notes:
// - Return false to cancel the listing.
// - List handler can be called multiple times. The last call will have 
//   endOfList=true, error!=NULL, or it will return false (cancels listing).
typedef bool (__cdecl* FlowSshC_ListHandler)(void* handlerData, FlowSshC_FileInfo const* fileInfos, unsigned int nrFileInfos, bool endOfList, FlowSshC_ListErr const* error);
// Notes:
// - Return false to cancel the transfer.
// - Transfer handler can be called multiple times. The last call will have  
//   done=true, error!=NULL, or it will return false (cancels transfer).
typedef bool (__cdecl* FlowSshC_TransferHandler)(void* handlerData, bool done, FlowSshC_TransferStat const* transferStat, FlowSshC_TransferErr const* error);


struct FlowSshC_TransferFlags { enum {
	// Note:
	// - Transfer files without any modifications in SFTP binary mode.
	Binary		= 0x00000000,
	// Notes:
	// - When downloading, convert UNIX text files to the Windows format (LF->CRLF).
	// - When uploading, convert Windows text files to the UNIX format (CRLF->LF).
	// - AutoLf operates in SFTP binary mode (SFTP text mode is available in SFTPv4+).
	AutoLf		= 0x00000001,
	// Notes:
	// - When downloading, use text hint to determine whether to use Binary or Text
	//   mode. If text hint is unavailable or is holding guessed values, then file
	//   is opened in SFTP binary mode and tested for text (same procedure as AutoLf).
	//   If text is detected, file is re-opened in SFTP text mode (same as Text mode). 
	// - When uploading Windows text files same as Text mode; same as Binary otherwise.
	// - Requires SFTP version 4 or higher.
	AutoStd		= 0x00000002, // SFTPv4+
	// Note:
	// - Transfer files in SFTP text mode.
	// - Requires SFTP version 4 or higher.
	Text		= 0x00000003, // SFTPv4+
	// Note for Resume and Overwrite: 
	// - When both are set resume has priority.
	Resume		= 0x00000010,
	Overwrite	= 0x00000020,
	// Note:
	// - If enabled, source file will be erased upon successfully completed transfer.
	Move		= 0x00000040,
	// Note:
	// - Automatically create the missing directory structure for the target file.
	AutoMkDir	= 0x00000080 }; };


struct FlowSshC_ClientSftpChannelOpenStep { enum {
	OpenRequest		= 100,
	SftpRequest		= 200,
	InitPacket		= 300 }; };


struct FlowSshC_ClientSftpChannel {};
// Notes:
// - Returns NULL on fatal error only (after fatal error handler is called).
// - Channel can be created even if the associated client is not yet connected.
// - Channel keeps the associated client alive throughout channel's lifetime.
FLOWSSHC_FUNC FlowSshC_ClientSftpChannel*		__cdecl FlowSshC_ClientSftpChannel_Create(FlowSshC_Client* client);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_AddRef(FlowSshC_ClientSftpChannel* channel);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Release(FlowSshC_ClientSftpChannel* channel);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_SetDestroyHandler(FlowSshC_ClientSftpChannel* channel, FlowSshC_DestroyHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_SetVersionHandler(FlowSshC_ClientSftpChannel* channel, FlowSshC_SftpVersionHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_SetCloseHandler(FlowSshC_ClientSftpChannel* channel, FlowSshC_ChannelCloseHandler handler, void* handlerData);
// Notes:
// - Client must be connected before sending open request, otherwise the request will
//   fail immediately through the supplied progress handler.
// - A closed channel can be re-opened at any time.
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Open(FlowSshC_ClientSftpChannel* channel, FlowSshC_ProgressHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_RealPath(FlowSshC_ClientSftpChannel* channel, wchar_t const* queryPath, FlowSshC_RealPathHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Stat(FlowSshC_ClientSftpChannel* channel, wchar_t const* path, unsigned int desiredAttrFlags, FlowSshC_StatHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_SetStat(FlowSshC_ClientSftpChannel* channel, wchar_t const* path, FlowSshC_FileAttrs const* attrs, FlowSshC_SftpHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_MkDir(FlowSshC_ClientSftpChannel* channel, wchar_t const* path, FlowSshC_FileAttrs const* attrs, FlowSshC_SftpHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_RmDir(FlowSshC_ClientSftpChannel* channel, wchar_t const* path, FlowSshC_SftpHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Remove(FlowSshC_ClientSftpChannel* channel, wchar_t const* path, FlowSshC_SftpHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Rename(FlowSshC_ClientSftpChannel* channel, wchar_t const* oldPath, wchar_t const* newPath, FlowSshC_SftpHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_List(FlowSshC_ClientSftpChannel* channel, wchar_t const* path, FlowSshC_ListHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Upload(FlowSshC_ClientSftpChannel* channel, wchar_t const* localPath, wchar_t const* remotePath, unsigned int transferFlags, FlowSshC_TransferHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Upload2(FlowSshC_ClientSftpChannel* channel, wchar_t const* localPath, wchar_t const* remotePath, unsigned int transferFlags, unsigned int pipelineSize, FlowSshC_TransferHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Download(FlowSshC_ClientSftpChannel* channel, wchar_t const* remotePath, wchar_t const* localPath, unsigned int transferFlags, FlowSshC_TransferHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Download2(FlowSshC_ClientSftpChannel* channel, wchar_t const* remotePath, wchar_t const* localPath, unsigned int transferFlags, unsigned int pipelineSize, FlowSshC_TransferHandler handler, void* handlerData);
FLOWSSHC_FUNC void								__cdecl FlowSshC_ClientSftpChannel_Close(FlowSshC_ClientSftpChannel* channel, FlowSshC_ProgressHandler handler, void* handlerData);



// Notes:
// - Shutdown should be called before exiting the process or unloading FlowSshC.dll.
//    - C/C++: Shutdown should be called before returning from the main function or,
//      if FlowSshC.dll is loaded dynamically, before calling FreeLibrary() on it.
// - Handlers may be called during shutdown, however, no handler can be called once
//   shutdown is complete. FlowSshC_ErrorHandler will never be called during shutdown
//   though; or in other words, shudown will never raise a FlowSshC error.
// - What shutdown does is disconnect/abort any connected/connecting FlowSshC_Client,
//   closes all opened channels, and then and then waits for all FlowSshC threads to
//   finish gracefully. Furthermore, it frees resources acquired via initialization.
//   What shutdown does NOT do is destroy FlowSshC objects that haven't properly been
//   disposed of. The following functions create a new FlowSshC thread:
//    - FlowSshC_Client_Connect,
//    - FlowSshC_ClientSessionChannel_OpenRequest,
//    - FlowSshC_ClientSftpChannel_Open,
//    - FlowSshC_ClientSftpChannel_List,
//    - FlowSshC_ClientSftpChannel_Upload,
//    - FlowSshC_ClientSftpChannel_Download.
// - After shutdown is completed, FlowSshC may continue be using normally if it is
//   initialized again with FlowSshC_Initialize call.
FLOWSSHC_FUNC void								__cdecl FlowSshC_Shutdown();

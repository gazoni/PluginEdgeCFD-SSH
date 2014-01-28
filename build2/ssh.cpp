#include "ssh.h"

// ####################### MAIN SSH ###################

//CONSTRUTOR DA CLASSE
CallSSH::CallSSH(Ui::runEdgeCFDClass *uissh)
{

}

//DESTRUTOR DA CLASSE
CallSSH::~CallSSH(){}



// #################### METODOS ###############
void CallSSH::WrapCallSSH(QString host, QString user, int port, QString passwd, QString cmd, Ui::runEdgeCFDClass *uissh )
{
	//######### CRIANDO UM ARQUIVO DE BAT PARA EXECUTAR O SSH ###################
	
	// CHAMADA PARA O EXECUTAVEL COM PARAMETROS DE CONEXAO
	QString SSHFile = "sshCFD.exe -host=" + host  
		+ "-user=" + user +
		"-pw=" + passwd +
		"-port=" + QString::number(port) +
		"-cmd=\"" + cmd +"\"";
	
	
	QString BatFileName = "sshCFD.bat";
	QFile sshBatFile(BatFileName);	

	if(!sshBatFile.open(QFile::WriteOnly | QFile::Text))
	{
		qDebug() << "Erro arquivo";
		return;
	}

	QTextStream out(&sshBatFile);
	out << "@echo off" << endl;
	out << SSHFile << " -user=" << user << " -pw=" << passwd << " -host=" << host << " -port=" << port << " -cmd=\"" << cmd << "\""; 
		 	
	// FECHANDO O ARQUIVO	
	sshBatFile.flush();
	sshBatFile.close();

	//FIM DA CRIACAO DE UM ARQUIVO DE BAT PARA A EXECUCAO DA MACRO ANSYS


	//################ EXECUTANDO O SSH PARA DISPARAR UM JOB  OU EXECUTAR ALGUM COMANDO #######################################

	//DEFININDO UM ARQUIVO DE LOG
	QString logFile("terminal.txt");

	// CRIANDO O PROCESSO PARA A EXECUCAO
	process = new QProcess(this);
	process->setWorkingDirectory("./");
	process->setReadChannel(QProcess::StandardOutput);
    process->setReadChannelMode(QProcess::MergedChannels);
	process->setStandardOutputFile(logFile);
	
	process->start(SSHFile);
	process->waitForFinished();
	// ###################################################################################################


	
	//######### APAGANDO O ARQUIVO BAT DO SSH ############
	sshBatFile.remove();
	//####################################################
	//inserir quebra de linha
	qDebug() << "quebra" << QString(QChar(0x2028));
	uissh->textEdit_ssh->append("");


	LerArquivoLog(logFile);

	QFile file(logFile);
    if(!file.exists()){
        qDebug() << "arquivo nao existe"<<logFile;
    }else{
        qDebug() << logFile<<" encontrado...";
    }
	
    QString line;
	//uissh->textEdit_ssh->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
			uissh->textEdit_ssh->setText(uissh->textEdit_ssh->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }
	file.close();
}




void CallSSH::AtualizaJanela()
{
	//atualizando a janela da interface com a execucao de algum comando
	QString filename="terminal.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "Nao existe arquivo "<< filename;
    }else{
        qDebug() << filename << " encontrado...";
    }

    QString line;
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            //ui->textEdit->setText(ui->textEdit->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }
    file.close();

}


void CallSSH::LerArquivoLog(QString filename){
	
	

}


void CallSSH::CopiarArquivosSolver()
{

}

//###################################################################################

//
//enum ExitCodes
//{
//	Success,		// no exit code received from remote
//	UsageError,
//	SessionError,	// including connection error 
//	FatalError,
//	ExitCodeBase = 1000,	// ExitCode = ExitCodeBase + exit code received from remote
//};
//
//
//// CmdLineParams
//
//struct CmdLineParams
//{
//	bool		m_bOk;
//	wstring		m_sUserName;
//	wstring		m_sPassword;
//	int			m_nPort;
//	wstring		m_sHost;
//
//	wstring		m_sPty;
//	wstring		m_sCmd;
//
//	//CmdLineParams(int argc, wchar_t const* argv[]);
//};
//
////########################################################################################
//
//
//class MyErrorHandler : public ErrorHandler
//{
//public:
//	// This object must be created on the heap.
//	MyErrorHandler();
//	~MyErrorHandler() {};
//
//protected:
//	virtual void OnExceptionInHandler(bool fatal, wchar_t const* desc)
//	{
//		wcout << (fatal ? L"Error [fatal]: " : L"Error: ");
//		wcout << (desc ? desc : L"<no error description>") << endl;
//		// For the sake of simplicity, no cleanup is performed here.
//		// The lack of cleanup may cause debugger to report memory leaks.
//		exit(FatalError);
//	}
//};
//
////####################
//
//// ConsoleDisableEchoInput
//
//class ConsoleDisableEchoInput
//{
//public:
//	ConsoleDisableEchoInput()
//	{
//		m_stdIn = GetStdHandle(STD_INPUT_HANDLE);		
//
//		m_restoreMode = FALSE;
//		if (GetFileType(m_stdIn) == FILE_TYPE_CHAR)
//			if (m_restoreMode = GetConsoleMode(m_stdIn, &m_originalMode))
//				m_restoreMode = SetConsoleMode(m_stdIn, m_originalMode & ~((DWORD) ENABLE_ECHO_INPUT));
//	}
//	~ConsoleDisableEchoInput() { if (m_restoreMode)	SetConsoleMode(m_stdIn, m_originalMode); }
//
//private:
//	HANDLE m_stdIn;
//	DWORD  m_originalMode;
//	BOOL   m_restoreMode;
//};
//
////####################
//
//// MyClient
//
//class MyClient : public Client
//{
//private: 
//	// This object must be created on the heap.
//	~MyClient()	{}
//
//public:
//	MyClient(volatile int& exitCode) : m_exitCode(exitCode)	{}	
//
//	void SetClientSettings(CmdLineParams& params)
//	{
//		if (params.m_sUserName.size()) SetUserName(params.m_sUserName.c_str());
//		if (params.m_sPassword.size()) SetPassword(params.m_sPassword.c_str());
//		if (params.m_nPort)			   SetPort(params.m_nPort);
//		if (params.m_sHost.size())     SetHost(params.m_sHost.c_str());
//	}
//
//protected:
//	void OnSshVersion(std::wstring const& version)
//	{
//		wcout << L"Server version: " << version << endl;
//	}
//
//	bool OnHostKey(RefPtr<PublicKey> publicKey)
//	{
//		wcout << L"Received the following host key:" << endl;
//		wcout << L"  MD5 Fingerprint: " << publicKey->GetMd5() << endl;
//		wcout << L"  Bubble-Babble: "   << publicKey->GetBubbleBabble() << endl;
//		wcout << L"Accept the key (yes/no)? ";
//
//		std::wstring input;
//		wcin >> input;
//
//		if (input == L"yes")
//			return true;
//
//		// host key rejected
//		return false;
//	}
//
//	bool OnFurtherAuth(FurtherAuth& furtherAuth)
//	{
//		ConsoleDisableEchoInput disableEchoInput;
//		bool success = false;
//
//		if (furtherAuth.IsPasswordRemaining())
//		{	// user must provide a password
//			wcout << L"Password: ";
//
//			std::wstring password;	
//			wcin >> password;
//
//			if (password.length() > 0)
//			{
//				furtherAuth.SetPassword(password.c_str());
//				success = true;
//			}
//			wcout << endl;
//		}
//
//		return success;
//	}
//
//
//	bool OnPasswordChange(PasswordChange& passwordChange)
//	{
//		ConsoleDisableEchoInput disableEchoInput;
//		bool success = false;
//
//		// Production code should remove volatile characters from prompt first.
//		wcout << passwordChange.GetPrompt() << endl;
//		wcout << L"New password: ";
//
//		std::wstring newPassword;
//		wcin >> newPassword;
//
//		if (newPassword.length() > 0)
//		{
//			wcout << endl << L"Repeat password: ";
//
//			std::wstring repeatPassword;
//			wcin >> repeatPassword;
//
//			if (newPassword == repeatPassword)
//			{
//				passwordChange.SetNewPassword(newPassword.c_str());
//				success = true;
//			}
//			else
//				wcout << endl << L"Passwords do not match!";
//		}
//
//		wcout << endl;
//		return success;
//	}
//
//	void OnBanner(std::wstring const& banner)
//	{	// Production code should remove volatile characters from banner first.
//		wcout << endl << endl << L"User authentication banner:" << endl << banner << endl;
//	}
//	void OnDisconnect(unsigned int reason, std::wstring const& desc)
//	{			
//		if (reason != FlowSshC_DisconnectReason::ByClient)
//		{
//			wcout << endl << endl << L"Client disconnecting: " << endl << desc << endl;
//			if (m_exitCode == Success)
//				m_exitCode = SessionError;
//		}
//	}
//
//private:
//	volatile int& m_exitCode;
//};
//
//
////####################
//
//
//// MyClientSessionChannel
//
//class MyClientSessionChannel : public ClientSessionChannel
//{
//private: 
//	// This object must be created on the heap.	
//	~MyClientSessionChannel() {}
//
//public:
//	MyClientSessionChannel(RefPtrConst<Client> const& client, volatile int& exitCode) 
//		: ClientSessionChannel(client), m_exitCode(exitCode) {}
//
//protected:
//	virtual void OnExitStatus(FlowSshC_ExitStatus const& status)
//	{	// i.e. user enters Eof (Ctrl-Z + Enter)
//		if (m_exitCode == Success) 
//			m_exitCode = ExitCodeBase + status.m_code;
//	}
//
//private:
//	volatile int& m_exitCode;
//};
//
//
////####################
//
//
//// Channel input thread
//
//class StdInput
//{
//public:
//	StdInput() : m_readThread(0), m_dataSize(0), m_exitCode(Success)
//	{
//		m_file				= GetStdHandle(STD_INPUT_HANDLE); 
//		m_newDataEvent		= CreateEvent(0, false, false, 0);
//		m_continueReadEvent = CreateEvent(0, false, false, 0);		
//
//		if (!m_newDataEvent || !m_continueReadEvent)
//		{
//			wcout << L"CreateEvent() failed with Windows error " << GetLastError() << L"." << endl;
//			m_exitCode = FatalError;
//			return;
//		}
//		else if (!(m_readThread = CreateThread(0, 0, &StdInput::ReadThread, this, 0, 0)))
//		{
//			wcout << L"CreateThread() failed with Windows error " << GetLastError() << L"." << endl;
//			m_exitCode = FatalError;
//		}
//	}
//
//	~StdInput()
//	{		
//		if (m_readThread)
//		{
//			TerminateThread(m_readThread, 0);
//			WaitForSingleObject(m_readThread, INFINITE);
//		}
//		if (m_readThread)		 CloseHandle(m_readThread);
//		if (m_newDataEvent)		 CloseHandle(m_newDataEvent);
//		if (m_continueReadEvent) CloseHandle(m_continueReadEvent);
//	}
//
//	HANDLE GetNewDataEvent() const { return m_newDataEvent; }
//	void   ContinueRead() { SetEvent(m_continueReadEvent); }
//	HANDLE GetReadThreadHandle() const { return m_readThread; }
//	unsigned char const* GetDataPtr() const { return m_dataPtr; }
//	unsigned int		 GetDataSize() const { return m_dataSize; }
//	int	   GetExitCode() const { return m_exitCode; }
//
//private:
//
//	static DWORD WINAPI ReadThread(LPVOID thisPtr)
//	{
//		StdInput* p = static_cast<StdInput*>(thisPtr);
//		if (!p) return 0;
//
//		while (true)
//		{	
//			DWORD read = 0;
//			if (!ReadFile(p->m_file, p->m_dataPtr, sizeof(p->m_dataPtr), &read, 0))
//				return GetLastError();
//
//			p->m_dataSize = read;
//
//			SetEvent(p->m_newDataEvent);
//			WaitForSingleObject(p->m_continueReadEvent, INFINITE);
//		}
//		return 0;
//	};
//
//	HANDLE m_file;	
//	HANDLE m_newDataEvent;
//	HANDLE m_continueReadEvent;
//	HANDLE m_readThread;
//	unsigned int m_dataSize;
//	unsigned char m_dataPtr[4*1024];
//	int m_exitCode;
//};
//
////#######################################
//class InputParams
//{
//public:
//	
//	volatile int& m_exitCode;
//	ClientSessionChannel* m_channel;
//	HANDLE m_thisThread;
//	HANDLE m_outputThread;		// same as OutputParams::m_thisThread
//
//	~InputParams() { if (m_thisThread) CloseHandle(m_thisThread); }
//
//public:
//	static DWORD WINAPI ChannelInputThread(LPVOID param)
//	{
//		InputParams* inParam =  static_cast<InputParams*>(param);
//		if (!inParam) return 0;
//		RefPtr<ClientSessionChannel> pChannel(inParam->m_channel); pChannel->AddRef();
//
//		try
//		{
//			RefPtr<ProgressEvent> progress(new ProgressEvent);
//			StdInput stdInput;
//
//			if (stdInput.GetExitCode() != Success)
//			{
//				if (inParam->m_exitCode == Success)
//					inParam->m_exitCode = stdInput.GetExitCode();
//			}
//			else
//			{
//				while (true)
//				{
//					HANDLE waitObjects[3] = { inParam->m_outputThread, stdInput.GetReadThreadHandle(), stdInput.GetNewDataEvent() };
//					DWORD dw = WaitForMultipleObjects(3, waitObjects, false, INFINITE);
//					if (dw == WAIT_OBJECT_0)
//						break;
//					else if (dw == WAIT_OBJECT_0 + 1)
//					{	// stdInput::ReadThread terminated
//						DWORD winExitCode = 0;
//						GetExitCodeThread(stdInput.GetReadThreadHandle(), &winExitCode); 
//						wcout << L"ReadFile() failed with Windows error " << winExitCode << L"." << endl;
//						if (inParam->m_exitCode == Success)
//							inParam->m_exitCode = FatalError;
//						break;
//					}
//
//					if (!stdInput.GetDataSize()) // user enters Eof (Ctrl-Z + Enter)?
//						break;
//
//					pChannel->Send(Data(stdInput.GetDataPtr(), stdInput.GetDataSize()), false, progress);
//					stdInput.ContinueRead();
//					progress->WaitDone();
//				}
//			}
//		}
//		catch (Exception const& e)
//		{
//			wcout << e.What() << endl;
//			if (inParam->m_exitCode == Success)
//				inParam->m_exitCode = FatalError;
//		}
//
//		try	{ pChannel->Send(Data(), true, NULL); }	// send Eof (implicitly terminates ChannelOutputThread)
//		catch (Exception const&) {}
//		return 0;
//	};
//};
//
////#########################################################
//
//// Channel output thread
//
//class OutputParams
//{
//public:
//	
//
//	volatile int& m_exitCode;
//	ClientSessionChannel* m_channel;
//	HANDLE m_thisThread;
//
//	~OutputParams() { if (m_thisThread) CloseHandle(m_thisThread); }
//
//public:
//
//  static DWORD WINAPI ChannelOutputThread(LPVOID param)
//	{
//		OutputParams* outParam =  static_cast<OutputParams*>(param);
//		if (!outParam) return 0;	
//
//		try
//		{		
//			HANDLE stdErr = GetStdHandle(STD_ERROR_HANDLE);
//			HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);	
//
//			bool writeFileError = false;
//			RefPtr<ClientSessionChannel> pChannel(outParam->m_channel); pChannel->AddRef();
//			RefPtr<ReceiveEvent> receiver(new ReceiveEvent);
//
//			do
//			{
//				pChannel->Receive(receiver);
//				receiver->WaitDone();
//
//				if (receiver->Success())	// true until ClientSessionChannel is or gets closed
//				{
//					unsigned char const* dataPtr = receiver->GetDataPtr();
//					DWORD dataSyze				 = receiver->GetDataSize();
//
//					while (dataSyze && !writeFileError)
//					{
//						DWORD written;
//						if (WriteFile(receiver->StdErr() ? stdErr : stdOut, dataPtr, dataSyze, &written, 0))
//						{
//							dataPtr  += written;
//							dataSyze -= written;
//						}
//						else
//						{
//							wcout << L"WriteFile() failed with Windows error " << GetLastError() << "." << endl;
//							if (outParam->m_exitCode == Success)
//								outParam->m_exitCode = FatalError;
//							writeFileError = true;
//						}
//					}
//				}
//			} while (!writeFileError && receiver->Success() && !receiver->Eof());
//		}	
//		catch (Exception const& e) 
//		{ 
//			wcout << e.What() << endl;
//			if (outParam->m_exitCode == Success)
//				outParam->m_exitCode = FatalError;
//		}
//
//		return 0;
//	}
//};






//
//
//// ############# CONTRUTOR ####################
//ssh::ssh(void)
//{
//}
//
//// ############# DESTRUTOR ####################
//ssh::~ssh(void)
//{
//}
//
////###################### METODOS FLOW SSH ################################
//
//void ssh::ErrorHandler(void* handlerData, unsigned int flags, wchar_t const* desc)
//{
//	wprintf(L"Fatal error: %s\n", desc ? desc : L"<no error description>");
//	// For the sake of simplicity, no cleanup is performed here.
//	// The lack of cleanup may cause debugger to report memory leaks.
//	exit(FatalError);
//}
//
//void ssh::SshVersionHandler(void* handlerData, wchar_t const* version)
//{
//	wprintf(L"Server version: %s\n", version);
//}
//
//
//bool ssh::HostKeyHandler(void* handlerData, FlowSshC_PublicKey* publicKey)
//{
//	bool success = false;
//
//	BSTR md5 = FlowSshC_PublicKey_GetMd5(publicKey);
//	BSTR bb = FlowSshC_PublicKey_GetBubbleBabble(publicKey);
//
//	wprintf(L"Received the following host key:\n"
//			L"MD5: %s\n"
//			L"BB: %s\n",
//			md5, bb);
//
//	SysFreeString(md5);
//	SysFreeString(bb);
//
//	wprintf(L"Accept the key (yes/no)? ");
//
//	wchar_t input[10] = L"yes"; 
//
//	if (_getws_s(input, 9))
//		if (!_wcsicmp(input, L"yes"))
//			success = true;
//
//	return success;
//}
//
//
//bool ssh::UserAuthHandler(void* handlerData, FlowSshC_FurtherAuth* furtherAuth, FlowSshC_PasswordChange* passwordChange)
//{
//	bool success = false;
//	
//	// Disable echo on input
//	HANDLE stdIn = GetStdHandle(STD_INPUT_HANDLE);
//	DWORD originalMode;
//	BOOL restoreMode = FALSE;
//	if (GetFileType(stdIn) == FILE_TYPE_CHAR)
//		if (restoreMode = GetConsoleMode(stdIn, &originalMode))
//			restoreMode = SetConsoleMode(stdIn, originalMode & ~((DWORD) ENABLE_ECHO_INPUT));
//
//	if (furtherAuth)
//	{
//		if (FlowSshC_FurtherAuth_IsPasswordRemaining(furtherAuth))
//		{
//			wprintf(L"Password: ");	
//
//			wchar_t password[100];	
//			if (_getws_s(password, 99))
//			{
//				FlowSshC_FurtherAuth_SetPassword(furtherAuth, password);
//				success = true;
//			}
//
//			memset(password, 0, sizeof(password));
//
//			wprintf(L"\n");
//		}
//	}
//	else if (passwordChange)
//	{
//		BSTR prompt = FlowSshC_PasswordChange_GetPrompt(passwordChange);
//		// Production code should remove volatile characters from prompt first.
//		wprintf(L"%s\n", prompt);
//		SysFreeString(prompt);
//
//		wprintf(L"New password: ");
//
//		wchar_t newPassword[100];
//		if (_getws_s(newPassword, 99))
//		{
//			wprintf(L"\nRepeat password: ");
//			
//			wchar_t repeatPassword[100];	
//			if (_getws_s(repeatPassword, 99))
//			{
//				if (wcscmp(newPassword, repeatPassword))
//					wprintf(L"\nPasswords do not match!");
//				else
//				{
//					FlowSshC_PasswordChange_SetNewPassword(passwordChange, newPassword);
//					success = true;
//				}
//			}
//
//			memset(repeatPassword, 0, sizeof(repeatPassword));
//		}
//
//		memset(newPassword, 0, sizeof(newPassword));
//
//		wprintf(L"\n");
//	}
//
//	// Restore echo on input
//	if (restoreMode)
//		SetConsoleMode(stdIn, originalMode);
//
//	return success;
//}
//
//
//void ssh::BannerHandler(void* handlerData, wchar_t const* banner)
//{
//	// Production code should remove volatile characters from banner first.
//	wprintf(L"User authentication banner:\n%s\n", banner);
//}
//
//
//void ssh::DisconnectHandler(void* handlerData, unsigned int reason, wchar_t const* desc)
//{
//	wprintf(L"%s", desc);
//
//	if (handlerData)
//	{
//		if (g_exitCode == Success)
//			g_exitCode = SessionError;
//
//		SetEvent(((Events*) handlerData)->m_exitEvent);
//	}
//}
//
//
//
//void ssh::ConnectProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	if (taskState == FlowSshC_TaskState::Completed)
//	{
//		SetEvent(((Events*) handlerData)->m_readyEvent);
//	}
//	else if (taskState == FlowSshC_TaskState::Failed)
//	{
//		if (taskSpecificStep == FlowSshC_ConnectStep::ConnectToProxy)
//			wprintf(L"Connecting to proxy server failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		else if (taskSpecificStep == FlowSshC_ConnectStep::ConnectToSshServer)
//			wprintf(L"Connecting to SSH server failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		else if (taskSpecificStep == FlowSshC_ConnectStep::SshVersionString)
//			wprintf(L"SSH version string failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		else if (taskSpecificStep == FlowSshC_ConnectStep::SshKeyExchange)
//			wprintf(L"SSH key exchange failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		else if (taskSpecificStep == FlowSshC_ConnectStep::SshUserAuth)
//			wprintf(L"SSH authentication failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		else
//			wprintf(L"Connecting failed at unknown step: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		
//		if (g_exitCode == Success)
//			g_exitCode = SessionError;
//
//		SetEvent(((Events*) handlerData)->m_exitEvent);
//	}
//}
//
//
//void ssh::CloseHandler(void* handlerData)
//{
//	SetEvent(((Events*) handlerData)->m_exitEvent);
//}
//
//
//void ssh::ExitHandler(void* handlerData, FlowSshC_ExitStatus const* status, FlowSshC_ExitSignal const* signal)
//{
//	if (status)
//		if (g_exitCode == Success)
//			g_exitCode = ExitCodeBase + status->m_code;
//}
//
//
//void ssh::OpenChannelProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	if (taskState == FlowSshC_TaskState::Completed)
//	{
//		SetEvent(((Events*) handlerData)->m_readyEvent);
//	}
//	else if (taskState == FlowSshC_TaskState::Failed)
//	{
//		wprintf(L"Opening session channel failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		
//		if (g_exitCode == Success)
//			g_exitCode = SessionError;
//
//		SetEvent(((Events*) handlerData)->m_exitEvent);
//	}
//}
//
//
//void ssh::SendPtyReqProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	if (taskState == FlowSshC_TaskState::Completed)
//	{
//		SetEvent(((Events*) handlerData)->m_readyEvent);
//	}
//	else if (taskState == FlowSshC_TaskState::Failed)
//	{
//		wprintf(L"Pty request failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//
//		if (g_exitCode == Success)
//			g_exitCode = SessionError;
//		
//		SetEvent(((Events*) handlerData)->m_exitEvent);
//	}
//}
//
//
//void ssh::SendExecRequestProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	if (taskState == FlowSshC_TaskState::Completed)
//	{
//		SetEvent(((Events*) handlerData)->m_readyEvent);
//	}
//	else if (taskState == FlowSshC_TaskState::Failed)
//	{
//		wprintf(L"Exec request failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		
//		if (g_exitCode == Success)
//			g_exitCode = SessionError;
//		
//		SetEvent(((Events*) handlerData)->m_exitEvent);
//	}
//}
//
//
//void ssh::SendShellRequestProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	if (taskState == FlowSshC_TaskState::Completed)
//	{
//		SetEvent(((Events*) handlerData)->m_readyEvent);
//	}
//	else if (taskState == FlowSshC_TaskState::Failed)
//	{
//		wprintf(L"Shell request failed: %s\n",  auxInfo ? auxInfo : L"<no auxiliary info>");
//		
//		if (g_exitCode == Success)
//			g_exitCode = SessionError;
//		
//		SetEvent(((Events*) handlerData)->m_exitEvent);
//	}
//}
//
//
//void ssh::DisconnectProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	if (taskState == FlowSshC_TaskState::Completed || taskState == FlowSshC_TaskState::Failed)
//		SetEvent((HANDLE) handlerData);
//}
//
//
//void ssh::CloseProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	int i = 0;
//}
//
//DWORD WINAPI ssh::ReadFileThread(LPVOID param)
//{
//	ReadParams* p = (ReadParams*) param;
//
//	while (true)
//	{	
//		DWORD read;
//		if (!ReadFile(p->m_file, p->m_data, sizeof(p->m_data), &read, 0))
//			return GetLastError();
//
//		p->m_dataBytes = read;
//
//		SetEvent(p->m_readyEvent);
//		WaitForSingleObject(p->m_continueEvent, INFINITE);
//	}
//	
//	return 0;
//};
//
//
//void ssh::SendProgressHandler(void* handlerData, unsigned int taskState, unsigned int taskSpecificStep, wchar_t const* auxInfo)
//{
//	if (taskState != FlowSshC_TaskState::InProgress)
//	{
//		InputParams* p = (InputParams*) handlerData;
//		p->m_sentResult = taskState == FlowSshC_TaskState::Completed;
//		SetEvent(p->m_sentEvent);
//	}
//}
//
///*
//DWORD WINAPI ssh::ChannelInputThread(LPVOID param)
//{
//	InputParams* p = (InputParams*) param;
//
//	ReadParams r = { 0, 0, 0, 0 };
//	r.m_file = GetStdHandle(STD_INPUT_HANDLE);
//	r.m_readyEvent = CreateEvent(0, false, false, 0);
//	r.m_continueEvent = CreateEvent(0, false, false, 0);
//
//	if (!r.m_readyEvent && !r.m_continueEvent)
//	{
//		wprintf(L"CreateEvent() failed with Windows error %u.\n", GetLastError());
//		
//		if (g_exitCode == Success)
//			g_exitCode = FatalError;
//	}
//	
//	else if (!(r.m_thread = CreateThread(0, 0, ReadFileThread, &r, 0, 0)))
//	{
//		wprintf(L"CreateThread() failed with Windows error %u.\n", GetLastError());
//		
//		if (g_exitCode == Success)
//			g_exitCode = FatalError;
//	}
//	else
//	{
//		while (true)
//		{
//			HANDLE waitObjects[3] = { p->m_outputThread, r.m_thread, r.m_readyEvent };
//			DWORD dw = WaitForMultipleObjects(3, waitObjects, false, INFINITE);
//			if (dw == WAIT_OBJECT_0)
//				break;
//			else if (dw == WAIT_OBJECT_0 + 1)
//			{
//				DWORD exitCode = 0;
//				GetExitCodeThread(r.m_thread, &exitCode);
//				wprintf(L"ReadFile() failed with Windows error %u.\n", exitCode);
//				
//				if (g_exitCode == Success)
//					g_exitCode = FatalError;
//				break;
//			}
//			
//			if (!r.m_dataBytes)
//				break;
//
//			FlowSshC_ClientSessionChannel_Send(p->m_channel, r.m_data, r.m_dataBytes, false, SendProgressHandler, p);
//			SetEvent(r.m_continueEvent);
//			WaitForSingleObject(p->m_sentEvent, INFINITE);
//		}
//	}
//
//	FlowSshC_ClientSessionChannel_Send(p->m_channel, 0, 0, true, 0, 0);
//
//	if (r.m_thread)
//	{
//		TerminateThread(r.m_thread, 0);
//		WaitForSingleObject(r.m_thread, INFINITE);
//	}
//
//	CloseHandle(r.m_readyEvent);
//	CloseHandle(r.m_continueEvent);
//	CloseHandle(r.m_thread);
//
//	return 0;
//}
//*/
//
//
//
//
//void ssh::ReceiveHandler(void* handlerData, bool stdErr, unsigned char const* data, unsigned int dataBytes, bool eof)
//{
//	OutputParams* p = (OutputParams*) handlerData;
//	
//	p->m_recvStdErr = stdErr;
//	p->m_recvDataBytes = dataBytes;
//	p->m_recvEof = eof;
//	if (dataBytes) 
//		memcpy(p->m_recvData, data, dataBytes);
//	
//	SetEvent(p->m_recvEvent);
//}
//
//
//
//
//DWORD WINAPI ssh::ChannelOutputThread(LPVOID param)
//{
//	OutputParams* p = (OutputParams*) param;
//	
//	unsigned char buffer[4*1024];
//	p->m_recvData = buffer;
//	MemoryBarrier();
//
//	HANDLE stdErr = GetStdHandle(STD_ERROR_HANDLE);
//	HANDLE stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
//
//	bool writeFileError = false;
//
//	do
//	{
//		FlowSshC_ClientSessionChannel_Receive(p->m_channel, sizeof(buffer), ssh.ReceiveHandler, p);
//		WaitForSingleObject(p->m_recvEvent, INFINITE);
//
//		unsigned char* data = p->m_recvData;
//		DWORD dataBytes = p->m_recvDataBytes;
//
//		while (dataBytes && !writeFileError)
//		{
//			DWORD written;
//			if (WriteFile(p->m_recvStdErr ? stdErr : stdOut, data, dataBytes, &written, 0))
//			{
//				data += written;
//				dataBytes -= written;
//			}
//			else
//			{
//				wprintf(L"WriteFile() failed with Windows error %u.\n", GetLastError());
//				
//				if (g_exitCode == Success)
//					g_exitCode = FatalError;
//				writeFileError = true;
//			}
//		}
//	}
//	while (!writeFileError && p->m_recvDataBytes && !p->m_recvEof);
//
//	return 0;
//}
//
//
//
//
//



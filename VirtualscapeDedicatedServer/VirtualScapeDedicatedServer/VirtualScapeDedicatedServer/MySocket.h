#ifndef _MYSOCKET_H_
#define _MYSOCKET_H_

class CMySocket : public CSocket
{
//*************
// The defines
//*************

//*************
// The members
//*************
public:
	// The game name
	CString		m_GameName;
	// The player name
	CString		m_PlayerName;
	// The game language
	CString		m_GameLanguage;
	// The server type
	int			m_ServerType;
	// The server port
	int			m_ServerPort;
	// The server IP
	CString		m_ServerIP;
	// The server port
	UINT		m_NewServerPort;

protected:
	// Buffer for create message to send
	char*		m_BufferSend;
	// The buffer size
	int			m_BufferSendSize;
	// Buffer for reception
	char*		m_BufferReceive;
	// The receive buffer size
	int			m_BufferReceiveSize;

//*************
// The methods
//*************
public:
	// The constructor
	CMySocket();
	// The destructor
	virtual ~CMySocket();
	// Send a message to the other application
	void	SendMessage( short ID );
	// Read a short
	void	ReadType( short& s );
	// Read a char
	void	ReadType( char& c );
	// Read a double
	void	ReadType( double& d );
	// Read a double array
	void	ReadType( double* d, int Size );
	// Read a int64
	void	ReadType( __int64& i );
	// Read a int
	void	ReadType( int& i );
	// Read a UINT
	void	ReadType( UINT& i );
	// Read a LONG
	void	ReadType( LONG& i );
	// Read a BYTE
	void	ReadType( BYTE& i );
	// Read a string
	void	ReadType( CString& Str );
	// Read datas
	void	ReadDatas( char* pBuf, int Size );
	// Create a Buffer for send data
	void	CreateBuffer();
	// Write a short
	void	WriteType( short s );
	// Write a int64
	void	WriteType( __int64 i );
	// Write a double
	void	WriteType( double d );
	// Write a int
	void	WriteType( int i );
	// Write a UINT
	void	WriteType( UINT i );
	// Write a LONG
	void	WriteType( LONG i );
	// Write a BYTE
	void	WriteType( BYTE i );
	// Write a char
	void	WriteType( char c );
	// Write a CString
	void	WriteType( CString Str );
	// An error occur (display the error)
	void	SocketError();
	// Create a char* from a unicode CString
	char*	GetAsciiString( CString Str );

protected:
	// Read a message
	void	ReadAMessage();
	// A Do event
	void	DoEvents(void);


//******************
// Generate by VC++
//******************
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySocket)
	public:
	virtual void OnClose(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CMySocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

#endif // #ifndef _MYSOCKET_H_

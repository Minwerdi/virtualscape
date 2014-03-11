// VirtualScapeDedicatedServerDlg.cpp : fichier d'impl�mentation
//

#include "stdafx.h"

#include "GlobalIHM.h"
#include "SocketMessageId.h"
#include "VirtualScapeDedicatedServer.h"
#include "VirtualScapeDedicatedServerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// bo�te de dialogue CAboutDlg utilis�e pour la bo�te de dialogue '� propos de' pour votre application

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Donn�es de bo�te de dialogue
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Impl�mentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// bo�te de dialogue CVirtualScapeDedicatedServerDlg




CVirtualScapeDedicatedServerDlg::CVirtualScapeDedicatedServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVirtualScapeDedicatedServerDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVirtualScapeDedicatedServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SERVER_LIST, m_ServerListCtrl);
}

BEGIN_MESSAGE_MAP(CVirtualScapeDedicatedServerDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDOK, &CVirtualScapeDedicatedServerDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// gestionnaires de messages pour CVirtualScapeDedicatedServerDlg

BOOL CVirtualScapeDedicatedServerDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Ajouter l'�l�ment de menu "� propos de..." au menu Syst�me.

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes syst�me.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// D�finir l'ic�ne de cette bo�te de dialogue. L'infrastructure effectue cela automatiquement
	//  lorsque la fen�tre principale de l'application n'est pas une bo�te de dialogue
	SetIcon(m_hIcon, TRUE);			// D�finir une grande ic�ne
	SetIcon(m_hIcon, FALSE);		// D�finir une petite ic�ne

	// Positionne toute les colonnes
	CGlobalIHM::CreateColumnListCtrl( &m_ServerListCtrl, _T("Nom du serveur;Createur;IP;Port;Type serveur;Heure;Etat;Language") );

	m_pConnexionSocket = new CConnexionSocket;
	m_pConnexionSocket->Create(2811);
	m_pConnexionSocket->AsyncSelect( FD_ACCEPT | FD_CONNECT | FD_CLOSE );
	m_pConnexionSocket->Listen();

	return TRUE;  // retourne TRUE, sauf si vous avez d�fini le focus sur un contr�le
}

void CVirtualScapeDedicatedServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton R�duire � votre bo�te de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'ic�ne. Pour les applications MFC utilisant le mod�le Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CVirtualScapeDedicatedServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de p�riph�rique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'ic�ne dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'ic�ne
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// Le syst�me appelle cette fonction pour obtenir le curseur � afficher lorsque l'utilisateur fait glisser
//  la fen�tre r�duite.
HCURSOR CVirtualScapeDedicatedServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CVirtualScapeDedicatedServerDlg::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnClose();
	
	delete m_pConnexionSocket;

	DestroyWindow();;

	delete this;
}

void CVirtualScapeDedicatedServerDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();

	delete m_pConnexionSocket;

	DestroyWindow();

	delete this;
}

// Add a new server to the list
//
void CVirtualScapeDedicatedServerDlg::AddNewServer( CString GameName, CString GameLanguage, CString PlayerName, CString NewServerIP, int NewServerPort, int ServerType, CMySocket* pSocket )
{
	for( int i=0; i<m_ServerListCtrl.GetItemCount(); i++ )
	{
		CMySocket* pSocketData = (CMySocket*) m_ServerListCtrl.GetItemData(i);
		if( pSocketData->m_ServerIP==NewServerIP )
		{
			m_ServerListCtrl.DeleteItem(i);

			return;
		}
	}
	// Nom du serveur;Createur;IP;Port;Type serveur;Heure;Etat
	CString Str;
	CString myServerType;
	CString myDate;

	if( ServerType==0 )
		myServerType=_T("Basic");
	else
		myServerType=_T("Expert");

	myDate = CTime::GetCurrentTime().Format( _T("%d/%m/%y %H:%M:%S") );

	Str.Format( _T("%s;%s;%s;%i;%s;%s;Attente;%s"), GameName, PlayerName, NewServerIP, NewServerPort, myServerType, myDate, GameLanguage );

	CGlobalIHM::AddListItem( &m_ServerListCtrl, Str, -1, -1 );
	m_ServerListCtrl.SetItemData( m_ServerListCtrl.GetItemCount()-1, (DWORD_PTR) pSocket );

	// Insert this information into file
	CString FileName,Str2;
	FileName.Format( _T("C:\\VirtualscapeServer\\%s.txt"), CTime::GetCurrentTime().Format( _T("%d.%m.%Y") ) );
	CStdioFile f( FileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeText );
	f.SeekToEnd();
	Str2.Format( _T("%s;Game Created;%s\n"), myDate, Str );
	f.WriteString( Str2 );
	f.Close();
}

// Remove a server from the list
//
void CVirtualScapeDedicatedServerDlg::RemoveServer( CMySocket* pSocket )
{
	// Insert this information into file
	CString myDate = CTime::GetCurrentTime().Format( _T("%d/%m/%y %H:%M:%S") );

	CString FileName,Str2;
	FileName.Format( _T("C:\\VirtualscapeServer\\%s.txt"), CTime::GetCurrentTime().Format( _T("%d.%m.%Y") ) );
	CStdioFile f( FileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeText );
	f.SeekToEnd();
	Str2.Format( _T("%s;Remove Server;%s\n"), myDate, pSocket->m_ServerIP );
	f.WriteString( Str2 );
	f.Close();

	for( int i=0; i<m_ServerListCtrl.GetItemCount(); i++ )
	{
		CMySocket* pSocketData = (CMySocket*) m_ServerListCtrl.GetItemData(i);
		if( pSocketData==pSocket )
		{
			m_ServerListCtrl.DeleteItem(i);

			return;
		}
		if( pSocketData->m_ServerIP==pSocket->m_ServerIP )
		{
			m_ServerListCtrl.DeleteItem(i);

			return;
		}
	}
}

// Get the server list
//
void CVirtualScapeDedicatedServerDlg::GetServerList( CMySocket* pSocket )
{
	int NbServer = m_ServerListCtrl.GetItemCount();
	if( NbServer>0 )
	{
		pSocket->CreateBuffer();
		pSocket->WriteType( NbServer );
		for( int i=0; i<NbServer; i++ )
		{
			CMySocket* pSocketData = (CMySocket*) m_ServerListCtrl.GetItemData(i);
			pSocket->WriteType( pSocketData->m_GameName );
			pSocket->WriteType( pSocketData->m_GameLanguage );
			pSocket->WriteType( pSocketData->m_PlayerName );
			pSocket->WriteType( pSocketData->m_ServerIP );
			pSocket->WriteType( pSocketData->m_ServerPort );
			pSocket->WriteType( pSocketData->m_ServerType );
		}
		pSocket->SendMessageW( SMI_FROMDEDICATEDSERVER_SET_SERVER_LIST );
	}

	// Insert this information into file
	CString myDate = CTime::GetCurrentTime().Format( _T("%d/%m/%y %H:%M:%S") );

	CString FileName,Str2;
	FileName.Format( _T("C:\\VirtualscapeServer\\%s.txt"), CTime::GetCurrentTime().Format( _T("%d.%m.%Y") ) );
	CStdioFile f( FileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeText );
	f.SeekToEnd();
	Str2.Format( _T("%s;Ask servers;%s\n"), myDate, pSocket->m_ServerIP );
	f.WriteString( Str2 );
	f.Close();
}

// A game begin
//
void CVirtualScapeDedicatedServerDlg::GameBegin( CMySocket* pSocket )
{
	int NbPlayer;
	pSocket->ReadType( NbPlayer );
	for( int i=0; i<m_ServerListCtrl.GetItemCount(); i++ )
	{
		CMySocket* pSocketData = (CMySocket*) m_ServerListCtrl.GetItemData(i);
		if( pSocketData==pSocket )
		{
			// Insert this information into file
			CString myDate = CTime::GetCurrentTime().Format( _T("%d/%m/%y %H:%M:%S") );

			CString FileName,Str2;
			FileName.Format( _T("C:\\VirtualscapeServer\\%s.txt"), CTime::GetCurrentTime().Format( _T("%d.%m.%Y") ) );
			CStdioFile f( FileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeText );
			f.SeekToEnd();
			Str2.Format( _T("%s;Game Begin;%s;%i\n"), myDate, pSocketData->m_ServerIP, NbPlayer );
			f.WriteString( Str2 );
			f.Close();

			m_ServerListCtrl.DeleteItem(i);

			return;
		}
	}
}

// A game end
//
void CVirtualScapeDedicatedServerDlg::GameEnd( CMySocket* pSocket )
{
	// Insert this information into file
	CString myDate = CTime::GetCurrentTime().Format( _T("%d/%m/%y %H:%M:%S") );

	CString FileName,Str2;
	FileName.Format( _T("C:\\VirtualscapeServer\\%s.txt"), CTime::GetCurrentTime().Format( _T("%d.%m.%Y") ) );
	CStdioFile f( FileName, CFile::modeCreate | CFile::modeNoTruncate | CFile::modeWrite | CFile::shareDenyWrite | CFile::typeText );
	f.SeekToEnd();
	Str2.Format( _T("%s;Game End;%s\n"), myDate, pSocket->m_ServerIP );
	f.WriteString( Str2 );
	f.Close();
}


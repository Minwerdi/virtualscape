// VirtualScapeDedicatedServer.h�: fichier d'en-t�te principal pour l'application PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'stdafx.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CVirtualScapeDedicatedServerApp:
// Consultez VirtualScapeDedicatedServer.cpp pour l'impl�mentation de cette classe
//

class CVirtualScapeDedicatedServerApp : public CWinApp
{
protected:
	// The socket list
	//CPtrArray m_SocketList;

public:
	// The constructor
	CVirtualScapeDedicatedServerApp();

// Substitutions
	public:
	virtual BOOL InitInstance();
	// Add a Socket to the list
	//void AddSocket( void* pSocket );

// Impl�mentation

	DECLARE_MESSAGE_MAP()
};

extern CVirtualScapeDedicatedServerApp theApp;
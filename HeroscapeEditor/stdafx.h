// stdafx.h�: fichier Include pour les fichiers Include syst�me standard,
// ou les fichiers Include sp�cifiques aux projets qui sont utilis�s fr�quemment,
// et sont rarement modifi�s

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN		// Exclure les en-t�tes Windows rarement utilis�s
#endif

// Modifiez les d�finitions suivantes si vous devez cibler une plate-forme avant celles sp�cifi�es ci-dessous.
// Reportez-vous � MSDN pour obtenir les derni�res informations sur les valeurs correspondantes pour les diff�rentes plates-formes.
#ifndef WINVER				// Autorise l'utilisation des fonctionnalit�s sp�cifiques � Windows�XP ou version ult�rieure.
#define WINVER 0x0501		// Attribuez la valeur appropri�e � cet �l�ment pour cibler d'autres versions de Windows.
#endif

#ifndef _WIN32_WINNT		// Autorise l'utilisation des fonctionnalit�s sp�cifiques � Windows�XP ou version ult�rieure.                   
#define _WIN32_WINNT 0x0501	// Attribuez la valeur appropri�e � cet �l�ment pour cibler d'autres versions de Windows.
#endif						

#ifndef _WIN32_WINDOWS		// Autorise l'utilisation des fonctionnalit�s sp�cifiques � Windows�98 ou version ult�rieure.
#define _WIN32_WINDOWS 0x0410 // Attribuez la valeur appropri�e � cet �l�ment pour cibler Windows�Me ou version ult�rieure.
#endif

#ifndef _WIN32_IE			// Autorise l'utilisation des fonctionnalit�s sp�cifiques � Internet Explorer�6.0 ou version ult�rieure.
#define _WIN32_IE 0x0600	// Attribuez la valeur appropri�e � cet �l�ment pour cibler d'autres versions d'Internet Explorer.
#endif

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// certains constructeurs CString seront explicites

// d�sactive le masquage MFC de certains messages d'avertissement courants et par ailleurs souvent ignor�s
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // composants MFC principaux et standard
#include <afxext.h>         // extensions MFC


#include <afxdisp.h>        // Classes MFC Automation



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>		// Prise en charge MFC pour les contr�les communs Internet Explorer�4
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// Prise en charge des MFC pour les contr�les communs Windows
#endif // _AFX_NO_AFXCMN_SUPPORT


#include <afxsock.h>		// extensions du socket MFC







#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif



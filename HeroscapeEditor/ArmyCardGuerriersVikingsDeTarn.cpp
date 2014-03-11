#include "StdAfx.h"

#include "ArmyCardGuerriersVikingsDeTarn.h"
#include "FigureObject.h"
#include "Resource.h"

// The constructor
//
CArmyCardGuerriersVikingsDeTarn::CArmyCardGuerriersVikingsDeTarn()
:
// Call the base constructor
CArmyCard()
{
	// The name of the card
	m_Name.LoadString(IDS_GUERRIERSVIKINGSDETARNNAME);
	// The basic rule text
	//m_BasicText.LoadStringW(IDS_);
	// The basic rule movement
	m_BasicMovementSpace = 4;
	// The basic range
	m_BasicRangeSpace = 1;
	// The basic rule attack
	m_BasicAttackDice = 3;
	// The basic rule defense
	m_BasicDefenseDice = 4;
	// The expert rule text
	//m_ExpertText.LoadStringW(IDS_);
	// The expert rule movement
	m_ExpertMovementSpace = 4;
	// The expert rule range
	m_ExpertRangeSpace = 1;
	// The expert rule attack
	m_ExpertAttackDice = 3;
	// The expert rule defense
	m_ExpertDefenseDice = 4;
	// The expert rule cost point
	m_ExpertCostPoint = 50;
	// The expert rule total life point
	m_ExpertTotalLifePoint = 4;
	// The current life point
	m_CurrentLifePoint = m_ExpertTotalLifePoint;
	// The ability to fly
	m_CanFly = false;
	// The bitmap file name
	m_BitmapFileName = _T("Guerriers_vikings_de_Tarn");
	// The figures list
	CString Str;
	Str.LoadStringW( IDS_GUERRIERSVIKINGTARN1_4 );
	CFigureObject* pFigureObject = new CFigureObject( false, Str, _T("GUERRIERS VIKING TARN 1-4"), this );
	m_Figures.Add( pFigureObject );
	Str.LoadStringW( IDS_GUERRIERSVIKINGTARN2_4 );
	pFigureObject = new CFigureObject( false, Str, _T("GUERRIERS VIKING TARN 2-4"), this );
	m_Figures.Add( pFigureObject );
	Str.LoadStringW( IDS_GUERRIERSVIKINGTARN3_4 );
	pFigureObject = new CFigureObject( false, Str, _T("GUERRIERS VIKING TARN 3-4"), this );
	m_Figures.Add( pFigureObject );
	Str.LoadStringW( IDS_GUERRIERSVIKINGTARN4_4 );
	pFigureObject = new CFigureObject( false, Str, _T("GUERRIERS VIKING TARN 4-4"), this );
	m_Figures.Add( pFigureObject );
}

// The destructor
//
CArmyCardGuerriersVikingsDeTarn::~CArmyCardGuerriersVikingsDeTarn(void)
{
}


// TileSand3.cpp : implementation file
//

#include "StdAfx.h"

#include "TileSand3.h"

// The constructor
//
CTileSand3::CTileSand3()
{
	m_NbTile = 3;
	m_Type = TYPE_SAND*1000+m_NbTile;
	m_TileColor = RGB(206,172,40);

	Init();
}

// The destructor
//
CTileSand3::~CTileSand3()
{
}

// Get a copy of this tile
//
CTile* CTileSand3::GetCopy()
{
	return new CTileSand3;
}

// When the rotation change
//
void CTileSand3::OnRotationChange()
{
	int CurrentPos = 0;
	switch( m_CurrentRotation )
	{
	case 0:
	case 2:
	case 4:
		m_TilePosition[CurrentPos].x = 0;
		m_TilePosition[CurrentPos++].y = 0;
		m_TilePosition[CurrentPos].x = 1;
		m_TilePosition[CurrentPos++].y = 0;
		m_TilePosition[CurrentPos].x = 0;
		m_TilePosition[CurrentPos++].y = 1;
		break;
	case 1:
	case 3:
	case 5:
		m_TilePosition[CurrentPos].x = 0;
		m_TilePosition[CurrentPos++].y = 0;
		m_TilePosition[CurrentPos].x = -1;
		m_TilePosition[CurrentPos++].y = 1;
		m_TilePosition[CurrentPos].x = 0;
		m_TilePosition[CurrentPos++].y = 1;
		break;
	}
}

#ifndef _TILECASTLEWALLEND_H_
#define _TILECASTLEWALLEND_H_

#include "Tile.h"

class CTileCastleWallEnd : public CTile
{
//************
// The members
//************
protected:
	// The second color
	COLORREF	m_TileColor2;

//************
// The methods
//************
public:
	// The constructor
	CTileCastleWallEnd();
	// The destructor
	~CTileCastleWallEnd();
	// Get a copy of this tile
	virtual CTile*	GetCopy();
	// Draw the tiles
	void			Draw( CDC* pDC, int x, int y, int x2, int x3, int y2, int y3, int y4, int DrawingLevel);
	// Draw the tiles
	void			DrawSurround( CDC* pDC, int x, int y, int x2, int x3, int y2, int y3, int y4, int DrawingLevel);
	// Draw more on a tile
	void			DrawExtend( CDC* pDC, int x, int y, int x2, int x3, int y2, int y3, int y4, int DrawingLevel);
	// Render a tile 1 hexagon
	virtual void	Render1( void* pView, bool ForShadow, bool BindTexture );
	// Verify that something is under the tile
	virtual void	VerifySomethingUnderTile( void* pTheDoc );
	// Fill the members with members of an other tile
	virtual void	FillCopy( CTile* pTile );
};

#endif // #ifndef _TILECASTLEWALLEND_H_

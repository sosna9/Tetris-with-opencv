#pragma once
#include "Pieces.h"
#include "funcs.h"
#include <time.h>
class Game
{
public:
	//Pieces piece;
	int boardwidth = 10;
	int boardheight = 20;
	int score = 0;
	int board[10][20];
	int xposition, yposition;	// Position of the piece that is falling down
	int piece, rotation;		// Kind and rotation of the piece that is falling down
	void storepiece(int pX, int pY, int pPiece, int pRotation);
	void initboard();			// initialise board that contains the pieces
	void initgame();
	void createnewshape();		
	bool isgameover();
	bool isblockfree(int pX, int pY);
	bool checkcollision(int pX, int pY, int pPiece, int pRotation);
	void deletepossiblelines();
	//void deleteline(int pY);
};


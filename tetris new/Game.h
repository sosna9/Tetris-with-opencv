#pragma once
#include "Pieces.h"
#include "funcs.h"
#include <time.h>
class Game
{
public:
	//Game(Basicfunctions basicfunctions);
	//Pieces piece;
	Basicfunctions basicfunctions;
	int boardwidth = 10;
	int boardheight = 20;
	int score = 0;				// score counter
	int board[10][20];			// board to store pieces
	int xposition, yposition;	// Position of the piece that is falling down
	int piece, rotation;		// Kind and rotation of the piece that is falling down
	int nextpiece, nextrotation;
	void storepiece(int pX, int pY, int pPiece, int pRotation); //saves pieces into board
	void initboard();			// initialise board to store pieces
	void initgame();
	void createnewshape();		//creates new piece that is falling
	bool isgameover();			//checks if game is over
	bool isblockfree(int pX, int pY); //checks if this place on board is free
	bool checkcollision(int pX, int pY, int pPiece, int pRotation);
	void deletepossiblelines(); // deletes full lanes
	//void deleteline(int pY);
};


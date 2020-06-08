#pragma once
#include "Pieces.h"
//#include "Drawing.h"
#include <time.h>
class Game
{
public:

	int boardwidth = 10;
	int boardheight = 20;
	int score = 0;				// score counter
	int board[10][20];			// board to store pieces
	int xposition, yposition;	// Position of the piece that is falling down
	int piece, rotation;		// Kind and rotation of the piece that is falling down
	int nextpiece, nextrotation;
	int getrand(int a, int b);
	void storepiece(int xposition, int yposition, int piece, int rotation); //saves pieces into board
	void initgame();
	void createnewshape();		//creates new piece that is falling
	bool isgameover();			//checks if game is over
	bool isblockfree(int xposition, int yposition); //checks if this place on board is free
	bool checkcollision(int xposition, int yposition, int piece, int rotation); // checks collision if piece would move into given place
	void deletepossiblelines(); // deletes full lanes
	void keyboardinput(int k);
};


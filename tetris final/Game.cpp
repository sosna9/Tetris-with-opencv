#include "Game.h"
#include <windows.h>
#include<cstringt.h>

void Game::initgame()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
			board[i][j] = 0;
	}																				//initialize board
	srand ((unsigned int) time (NULL));
	Pieces functions;
	piece = getrand(0,6);															//picking first and next piece randomly
	rotation = getrand(0, 3);
	nextpiece = getrand(0, 6);
	nextrotation = getrand(0, 3);
	xposition = (boardwidth / 2) + functions.GetXInitialPosition(piece, rotation); //placing first piece
	yposition = functions.GetYInitialPosition(piece, rotation);
}

void Game::createnewshape()
{ 
	piece = nextpiece;
	rotation = nextrotation;
	nextpiece = getrand(0, 6);
	nextrotation = getrand(0, 3);
	Pieces functions;
	xposition = (boardwidth / 2) + functions.GetXInitialPosition(piece, rotation);
	yposition = functions.GetYInitialPosition(piece, rotation);
	score += 10;
}

void Game::storepiece(int xposition, int yposition, int piece, int rotation) // Store each block of the falling piece into the board
{
	Pieces functions;
	for (int i1 = xposition, i2 = 0; i1 < xposition + 5; i1++, i2++)
	{
		for (int j1 = yposition, j2 = 0; j1 < yposition + 5; j1++, j2++)
		{
			if (functions.GetBlockType(piece, rotation, j2, i2) != 0) // Store only the blocks of the piece that are not empty
				board[i1][j1] = 1;
		}
	}
}

bool Game::isgameover()
{
	//first line has any block -> game is over
	for (int i = 0; i < boardwidth; i++)
	{
		if (board[i][0] == 1) return true;
	}
	return false;
}
bool Game::isblockfree(int pX, int pY)
{
	if (board[pX][pY] == 0) return true; else return false;
}

bool Game::checkcollision(int xposition, int yposition, int piece, int rotation) //checks if there is collision if block would be in this specific position
{
	Pieces functions;
	// check all 5x5 blocks of a piece in the board
	for (int i1 = xposition, i2 = 0; i1 < xposition + 5; i1++, i2++)
	{
		for (int j1 = yposition, j2 = 0; j1 < yposition + 5; j1++, j2++)
		{
			// check collisions with borders
			if (i1 < 0 || i1 > boardwidth - 1 || j1 > boardheight - 1)
			{
				if (functions.GetBlockType(piece, rotation, j2, i2) != 0)
					return 0; //collision
			}

			// check collisions with pieces stored in the map
			if (j1 >= 0)
			{
				if ((functions.GetBlockType(piece, rotation, j2, i2) != 0) &&
					(!isblockfree(i1, j1)))
					return 0; //collision
			}
		}
	}
	// No collision
	return 1;
}

void Game::deletepossiblelines()
{

	for (int j = 0; j < boardheight; j++)
	{
		int i = 0;
		while (i < boardwidth)
		{
			if (board[i][j] != 1) break;
			i++;
		}

		if (i == boardwidth) //deleteline(j);
		{
			for (int a = j; a > 0; a--)
			{
				for (int b = 0; b < boardwidth; b++)
				{
					board[b][a] = board[b][a - 1];
				}
			}
			score += 100 ;
		}
	}
}
void Game::keyboardinput(int key)
{
	switch (key)
	{
	case ('d'):
	{
		if (checkcollision(xposition + 1, yposition, piece, rotation)) // if movement to right is possible
			xposition++;  // shift moving piece to right
		break;
	}

	case ('a'):
	{
		if (checkcollision(xposition - 1, yposition, piece, rotation))
			xposition--; //just like above but lft :~~D
		break;
	}

	case ('s'):
	{
		if (checkcollision(xposition, yposition + 1, piece,rotation))
			yposition++; 
		break;
	}


	case ('w'):
	{
		if (checkcollision(xposition, yposition, piece, (rotation + 1) % 4))
			rotation = (rotation + 1) % 4; //change rotation to next

		break;
	}
	case (27):exit(0); //if esc pressed, then exit
	}

	if (checkcollision(xposition, yposition + 1, piece, rotation))
	{
		yposition++; //when no move key is pressed, or movement coresponding to key is not possible piece is falling down if its possible
	}
	else
	{	//if further falling is not posslible
		storepiece(xposition, yposition, piece, rotation); //piece is stored on the board
		deletepossiblelines(); // and all full lanes ale deleted

		if (isgameover()) //if there is no place for new pieces
		{
			exit(0);			//game is over
		}

		createnewshape(); //if not, create new piece
	}
}
int Game::getrand(int pA, int pB) // RNG
{
	return rand() % (pB - pA + 1) + pA;
}

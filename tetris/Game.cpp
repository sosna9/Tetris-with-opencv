#include "Game.h"
#include <windows.h>


void Game::initboard()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
			mBoard[i][j] = 0;
}
void Game::initgame()
{
	srand ((unsigned int) time (NULL));
	Basicfunctions basicfunctions;
	Pieces functions;
	// First piece
	piece = basicfunctions.GetRand(0,6);
	rotation = basicfunctions.GetRand(0, 3);
	mPosX = (boardwidth / 2) + functions.GetXInitialPosition(piece, rotation);
	yposition = functions.GetYInitialPosition(piece, rotation);
}
void Game::CreateNewPiece()
{ 
	Basicfunctions basicfunctions;
	Pieces functions;
	piece = basicfunctions.GetRand(0, 6);
	rotation = basicfunctions.GetRand(0, 3);
	mPosX = (boardwidth / 2) + functions.GetXInitialPosition(piece, rotation);
	yposition = functions.GetYInitialPosition(piece, rotation);
}

void Game::storepiece(int pX, int pY, int pPiece, int pRotation)
{
	Pieces functions;
	// Store each block of the piece into the board
	for (int i1 = pX, i2 = 0; i1 < pX + 5; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + 5; j1++, j2++)
		{
			// Store only the blocks of the piece that are not holes
			if (functions.GetBlockType(pPiece, pRotation, j2, i2) != 0)
				mBoard[i1][j1] = 1;
		}
	}
}

bool Game::isgameover()
{
	//first line has any block -> game is over
	for (int i = 0; i < boardwidth; i++)
	{
		if (mBoard[i][0] == 1) return true;
	}
	return false;
}
bool Game::isblockfree(int pX, int pY)
{
	if (mBoard[pX][pY] == 0) return true; else return false;
}

bool Game::checkcollision(int pX, int pY, int pPiece, int pRotation)
{
	Pieces functions;
	// check all 5x5 blocks of a piece in the board
	for (int i1 = pX, i2 = 0; i1 < pX + 5; i1++, i2++)
	{
		for (int j1 = pY, j2 = 0; j1 < pY + 5; j1++, j2++)
		{
			// check collisions with borders
			if (i1 < 0 || i1 > boardwidth - 1 || j1 > boardheight - 1)
			{
				if (functions.GetBlockType(pPiece, pRotation, j2, i2) != 0)
					return 0;
			}

			// check collisions with pieces stored in the map
			if (j1 >= 0)
			{
				if ((functions.GetBlockType(pPiece, pRotation, j2, i2) != 0) &&
					(!isblockfree(i1, j1)))
					return 0;
			}
		}
	}
	// No collision
	return 1;
}
/*void Game::deleteline(int pY)
{
	// Moves all the upper lines one row down
	for (int j = pY; j > 0; j--)
	{
		for (int i = 0; i < boardwidth; i++)
		{
			mBoard[i][j] = mBoard[i][j - 1];
		}
	}
}*/
void Game::deletepossiblelines()
{

	for (int j = 0; j < boardheight; j++)
	{
		int i = 0;
		while (i < boardwidth)
		{
			if (mBoard[i][j] != 1) break;
			i++;
		}

		if (i == boardwidth) //deleteline(j);
		{
			for (int a = j; a > 0; a--)
			{
				for (int b = 0; b < boardwidth; b++)
				{
					mBoard[b][a] = mBoard[b][a - 1];
				}
			}
		}
	}
}


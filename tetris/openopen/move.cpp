#include "Move.h"
#include <stdio.h>
#include <Game.h>
void Move::keyboardinput(int k,int mposX, int mposY, int piece, int mRotation, int board[10][20])
{//mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation
	Game game;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 20; j++)
		game.mBoard[i][j] = board[i][j];
	if (k == 'a')
	{
			if (game.checkcollision(mposX + 1, mposY, piece,mRotation))
				mposX++;
		printf("\na ok\n");
	}

	if (k == 'd')
	{
		printf("\nd ok\n");
	}

	if (k == 'w')
	{
		printf("\nw ok\n");
	}

}

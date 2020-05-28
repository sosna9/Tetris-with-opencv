#include "Move.h"
#include <stdio.h>
#include <Game.h>
void Move::keyboardinput(int key, Game* game)
{
	switch (key)
	{
	case ('d'):
	{
		if (game->checkcollision(game->xposition + 1, game->yposition, game->piece, game->rotation)) // if movement to right is possible
			game->xposition++;  // shift moving piece to right
		break;
	}

	case ('a'):
	{
		if (game->checkcollision(game->xposition - 1, game->yposition, game->piece, game->rotation))
			game->xposition--; //just like above but lft :~~D
		break;
	}

	case ('s'):
	{
		if (game->checkcollision(game->xposition, game->yposition + 1, game->piece, game->rotation))
			game->yposition++; //u wouldnt guess
		break;
	}


	case ('w'):
	{
		if (game->checkcollision(game->xposition, game->yposition, game->piece, (game->rotation + 1) % 4))
			game->rotation = (game->rotation + 1) % 4; //yeah sherlock, rotating piece

		break;
	}
	case (27):exit(0); //if esc pressed, then exit
	}

	if (game->checkcollision(game->xposition, game->yposition + 1, game->piece, game->rotation))
	{
		game->yposition++; //when no move key is pressed, or movement coresponding to key is not possible piece is falling down if its possible
	}
	else
	{	//if further falling is not posslible
		game->storepiece(game->xposition, game->yposition, game->piece, game->rotation); //piece is stored on the board
		game->deletepossiblelines(); // and all full lanes ale deleted

		if (game->isgameover()) //if there is no place for new pieces
		{
			exit(0);			//game is over
		}

		game->createnewshape(); //if not, create new piece
	}
}

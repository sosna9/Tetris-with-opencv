#include <opencv2\opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <funcs.h>
#include <move.h>
#include <time.h>
#include <Pieces.h>
#include <Game.h>
using namespace cv;

int main() 
{

	int field[10][20] = { 0 }; 
	Basicfunctions start;
	Game game;
	start.startscreen();
	game.initboard();
	printf("test\n");
	int key;
	//start.draw();
	game.initgame();
	while (true) //p�tla gry
	{
		//start.showtestscreen();
		start.draw(game.xposition, game.yposition, game.piece, game.rotation, game.board);
		key = waitKey(550);
		//move.keyboardinput(key, game.xposition, game.mPosY, game.piece, game.mRotation, game.board);
		//move.keyboardinput(key, game.xposition, gamemPosY, game.piece, int& mRotation)
		switch (key)
		{
		case ('d'):
		{
			if (game.checkcollision(game.xposition + 1, game.yposition, game.piece, game.rotation))
				game.xposition++;
			break;
		}

		case ('a'):
		{
			if (game.checkcollision(game.xposition - 1, game.yposition, game.piece, game.rotation))
				game.xposition--;
			break;
		}

		case ('s'):
		{
			if (game.checkcollision(game.xposition, game.yposition + 1, game.piece, game.rotation))
				game.yposition++;
			break;
		}


		case ('w'):
		{
			if (game.checkcollision(game.xposition, game.yposition, game.piece, (game.rotation + 1) % 4))
				game.rotation = (game.rotation + 1) % 4;

			break;
		}
		case (27):exit(0);
		}
		if (game.checkcollision(game.xposition, game.yposition + 1, game.piece, game.rotation))
		{
			game.yposition++;
		}
		else
		{
			game.storepiece(game.xposition, game.yposition, game.piece, game.rotation);

			game.deletepossiblelines();

			if (game.isgameover())
			{
				exit(0);
			}

			game.createnewshape();
		}
		
	}
	return 0;
}

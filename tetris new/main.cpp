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
	Basicfunctions start;
	Game game;
	Move move;
	start.startscreen(); //wyœwietlenie ekranu startowego 
	game.initboard();
	int key;
	game.initgame();
	while (true) //main loop
	{
		start.draw(game.xposition, game.yposition, game.piece, game.rotation, game.board, game.score, game.nextpiece, game.nextrotation); // drawing every element of game
		key = waitKey(550);				//input
		move.keyboardinput(key, &game); //input handling
	}
	return 0;
}

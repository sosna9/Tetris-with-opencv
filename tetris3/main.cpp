#include <opencv2\opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Drawing.h>
#include <time.h>s
#include <Pieces.h>
#include <Game.h>
using namespace cv;

int main() 
{
	Drawing drawing;
	Game game;
	drawing.startscreen(); //wyœwietlenie ekranu startowego 
	int key;
	game.initgame();
	while (true) //main loop
	{
		drawing.draw(&game);	//drawing whole game
		key = waitKey(550);		//input
		game.keyboardinput(key);//input handling
	}
	return 0;
}

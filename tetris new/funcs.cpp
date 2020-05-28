#include <funcs.h>
#include <opencv2/core.hpp>
#include <opencv2\opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Pieces.h>
#include <iostream>
#include <sstream>
using namespace cv;

/*
double Basicfunctions::test(double a, double b)
{
    return a + b;
}
*/
/*
Basicfunctions::~Basicfunctions()
{
	delete 
}
*/

void Basicfunctions::startscreen(void)
{
	Mat image = Mat::zeros(600, 450, CV_8UC3);
	// Game welcoming screen
	while (true)
	{
		if (image.empty())
			break;
		putText(image, "Tetriz", Point(120, image.rows * 0.3), FONT_HERSHEY_DUPLEX, 2, Scalar(255, 20, 147), 2);
		putText(image, "PRESS ANY KEY TO PLAY", Point(60, image.rows * 0.5 + 10), FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255), 1);
		imshow("Tetris", image); // Image is shown in the window
		if (waitKey(10) >= 0) // To close the window
			break;
	}
}
void Basicfunctions::showtestscreen(void)
{
	Mat image = Mat::zeros(600, 450, CV_8UC3);
	putText(image, "a, w, d Test, esc to quit", Point(60, image.rows * 0.5 + 10), FONT_HERSHEY_DUPLEX, 0.8, Scalar(255, 255, 255), 1);
	imshow("Tetris", image);
}

int Basicfunctions::GetRand(int pA, int pB) // RNG
{
	return rand() % (pB - pA + 1) + pA;
} 
int mBoard[10][20];

/*
void Basicfunctions::draw(int board[10][20])
{
	Mat image = Mat::zeros(600, 450, CV_8UC3);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (board[i][j])
			{
				rectangle(image, Point(20 + 25*i, 80 + 25*j), Point(20 + 25*i + 19, 80 + 25*j + 19), Scalar(255, 20, 147), 1, 1);
			}
		}
	}
	rectangle(image, Point(17,75), Point(268,577), Scalar(255, 250, 147), 1, 1); 
	imshow("Tetris", image);
}*/

void Basicfunctions::draw(int pX, int pY, int pPiece, int pRotation, int board[10][20], int score , int nextpiece, int nextrotation)
{
	Mat image = Mat::zeros(600, 450, CV_8UC3);
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (board[i][j])
			{
				rectangle(image, Point(20 + 25*i, 80 + 25*j), Point(20 + 25*i + 19, 80 + 25*j + 19), Scalar(255, 20, 147), -1, 1); //draws filled squares for blocks on board
			}
		}
	}
	rectangle(image, Point(17,75), Point(268,577), Scalar(255, 250, 147), 1, 1);  // borders of board
	Pieces piecefunctions;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (piecefunctions.GetBlockType(pPiece, pRotation, j, i) != 0)
			{
				if(pY+j>=0) rectangle(image, Point(20 + 25 * (pX+i), 80 + 25 * (pY+j) ), Point(20 + 25 * (pX+i) + 19, 80 + 25 * (pY+j) + 19), Scalar(255, 20, 147), 1, 1); //draws empty squares for moving piece
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (piecefunctions.GetBlockType(nextpiece, nextrotation, j, i) != 0)
			{
				rectangle(image, Point(300 + 25 * i, 80 + 25 * j), Point(300 + 25 * i + 19, 80 + 25 *  j + 19), Scalar(255, 20, 147), 1, 1); //draws empty squares for moving piece
			}
		}
	}
	std::stringstream ss;
	ss << score;
	std::string s;
	ss >> s;
	putText(image, "SCORE:", Point(280, 280), FONT_HERSHEY_DUPLEX, 1, Scalar(0, 255, 0), 1);
	putText(image, "NEXT BLOCK:", Point(300, 60), FONT_HERSHEY_DUPLEX, 0.5, Scalar(0, 255, 0), 1);
	putText(image, s, Point(280, 320), FONT_HERSHEY_DUPLEX, 1, Scalar(255, 191, 0), 1);
	imshow("Tetris", image);
}



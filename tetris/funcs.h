#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
class Basicfunctions
{
public:
	double test(double a, double b);
	void startscreen(void);
	void showtestscreen(void);
	int GetRand(int pA, int pB);
	void draw(int[10][20]);
	void drawpiece(int pX, int pY, int pPiece, int pRotation, int board[10][20]);
};

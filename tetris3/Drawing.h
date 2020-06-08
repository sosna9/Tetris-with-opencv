#pragma once
#include <opencv2\opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Game.h>
class Drawing
{
public:
	void startscreen(void);
	void showtestscreen(void);
	void draw(Game* game);
};

#pragma once
#define func(a) ((a>0)?1:((a<0)?-1:0)) //isare teyin edir
void myInit();
void drawPixel(int x, int y);
void drawBLine(int x1,int x2, int y1, int y2);
void drawDLine(int x1, int x2, int y1, int y2);
void drawBCircle(int xc, int yc, int r);
void drawMCircle(int xc, int yc, int r);
void drawEllipse(int xc, int yc, int rx, int ry);

class drawingMethods
{
public:
	drawingMethods();
	~drawingMethods();
};


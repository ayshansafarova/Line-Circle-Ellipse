#include <gl/glut.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "drawingMethods.h"

using namespace std;

drawingMethods::drawingMethods()
{
}

drawingMethods::~drawingMethods()
{
}

void drawPixel(int x, int y) {
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	cout << x << "  " << y << endl;
	glEnd();
}

void eCircle(int xc, int yc, int x, int y) {
	glColor3f(0.5, 1, 0.7);
	drawPixel(xc + x, yc + y);
	glColor3f(1, 0, 0.3);
	drawPixel(xc + x, yc - y);
	glColor3f(1, 1, 0.5);
	drawPixel(xc - x, yc + y);
	glColor3f(0.9, 0.2, 0);
	drawPixel(xc - x, yc - y);
}

void circle(int xc, int yc, int x, int y) {
	glColor3f(0, 1, 0);
	drawPixel(xc + x, yc + y);
	glColor3f(1, 1, 0.4);
	drawPixel(xc + x, yc - y);
	glColor3f(0, 1, 1);
	drawPixel(xc - x, yc + y);
	glColor3f(1, 1, 1);
	drawPixel(xc - x, yc - y);
	glColor3f(0.6, 1, 1);
	drawPixel(xc + y, yc + x);
	glColor3f(0.1, 0.3, 0.8);
	drawPixel(xc - y, yc + x);
	glColor3f(0, 1, 0.9);
	drawPixel(xc + y, yc - x);
	glColor3f(1, 1, 1);
	drawPixel(xc - y, yc - x);
}

//-------------------------------------------------------------------------
// Brensenham line alqoritmi, 4 parametr
//-------------------------------------------------------------------------
void drawBLine(int x1, int x2, int y1, int y2) {
	glColor3f(1, 0, 0);
	int dx, dy, x, y, d, s1, s2, swap = 0, temp;
	x = x1;
	y = y1;
	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	s1 = func(x2 - x1);
	s2 = func(y2 - y1); 
	if (dy > dx) { temp = dx; dx = dy; dy = temp; swap = 1; }
	else { swap = 0; }
	/* Set the initial decision parameter and the initial point */
	d = 2 * dy - dx;
	int i;
	for (i = 1; i <= dx; i++)
	{
		drawPixel(x, y);

		while (d >= 0)
		{
			if (swap) {
				x = x + s1;
			}
			else
				y = y + s2;
			d = d - 2 * dx;
		}
		if (swap) {
			y = y + s2;
		}
		else x = x + s1;
		d = d + 2 * dy;
	}
}

//-------------------------------------------------------------------------
// DDA line alqoritmi, 4 parametr
//-------------------------------------------------------------------------
void drawDLine(int x1, int x2, int y1, int y2) {
	glColor3f(0, 1, 0);
	int steps, i;
	int dy = y2-y1;
	int dx = x2-x1;
	
	float xinc, yinc, x = x1, y = y1;
	if (abs(dx)>abs(dy))
	{
		steps = abs(dx);
	}
	else
	{
		steps = abs(dy);
	}
	xinc = (float)dx / (float)steps;
	yinc = (float)dy / (float)steps;
	drawPixel(round(x), round(y));
	for (i = 0; i<steps; i++)
	{
		x += xinc;
		y += yinc;
		drawPixel(round(x), round(y));
	}
}

//-------------------------------------------------------------------------
// MidPoint Circle alqoritmi, merkezi koordinatlar ve radius
//-------------------------------------------------------------------------
void drawMCircle(int xc, int yc, int r) {
	glColor3f(0, 0, 1);
	int x = 0;
	int y = r;
	float decision = 3 - 2 * r;
	while (x <= y)
	{
		x++;
		if (decision < 0)
		{
			decision += 2 * x + 1;
		}
		else
		{
			y--;
			decision += 2 * (x - y) + 1;
		}
		circle(xc, yc, x, y);
	}
}

//-------------------------------------------------------------------------
// Bresenham Circle alqoritmi, merkezi koordinatlar ve radius
//-------------------------------------------------------------------------
void drawBCircle(int xc, int yc, int r) {
	glColor3f(1, 1, 0);
	int x = 0, y = r;
	int d = 3 - 2 * r;
	while (x < y)
	{
		drawPixel(xc + x, yc + y);
		drawPixel(xc - x, yc + y);
		drawPixel(xc + x, yc - y);
		drawPixel(xc - x, yc - y);
		drawPixel(xc + y, yc + x);
		drawPixel(xc - y, yc + x);
		drawPixel(xc + y, yc - x);
		drawPixel(xc - y, yc - x);
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawPixel(xc + x, yc + y);
		drawPixel(xc - x, yc + y);
		drawPixel(xc + x, yc - y);
		drawPixel(xc - x, yc - y);
		drawPixel(xc + y, yc + x);
		drawPixel(xc - y, yc + x);
		drawPixel(xc + y, yc - x);
		drawPixel(xc - y, yc - x);
	}
}

//-------------------------------------------------------------------------
// Ellipse cekme alqoritmi, merkezi koordinatlar ve radius
//-------------------------------------------------------------------------
void drawEllipse(int xc, int yc, int rx, int ry)
{
	glColor3f(1, 0, 0);
	int rx2 = rx * rx, ry2 = ry * ry;
	int trx2 = rx2, try2 = ry2;
	int p, x = 0, y = ry;
	int px = 0, py = trx2 * y;
	eCircle(xc, yc, x, y);
	p = round(ry2 - (rx2*ry) + (0.25*rx2));
	while (px<py) {
		x++;
		px += try2;
		if (p<0)
			p += ry2 + px;
		else
		{
			y--;
			py -= trx2;
			p += ry2 + px - py;
		}
		eCircle(xc, yc, x, y);
	}
	p = round(ry2*(x + 0.5)*(x + 0.5) + rx2 * (y - 1)*(y - 1) - rx2 * ry2);
	while (y > 0) {
		y--;
		py -= trx2;
		if (p>0)
			p += rx2 - py;
		else
		{
			x++;
			px += try2;
			p += rx2 + px - py;
		}
		eCircle(xc, yc, x, y);
	}
	
}

#include <gl/glut.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include "drawingMethods.h"

using namespace std;

char objectName;
char algorithmName;
int x1, x2, y1_, y2;

void init()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 600, 0, 600);
}

void drawObject()
{
	cout << endl << "enter name of object which you will draw: ";
	cin >> objectName;

	cout << endl << "enter name of algorithm: ";
	cin >> algorithmName;

	switch (objectName)
	{
	case 'l':
		if (algorithmName == 'b') {
			cout << endl << "enter 4 parametrs: ";
			cin >> x1;
			cin >> x2;
			cin >> y1_;
			cin >> y2;
			drawBLine(x1, x2, y1_, y2);
			//break;
		}
		else if (algorithmName == 'd') {
			cout << endl << "enter 4 parameters: ";
			cin >> x1;
			cin >> x2;
			cin >> y1_;
			cin >> y2;
			drawDLine(x1, x2, y1_, y2);
			//break;
		}
		break;

	case 'c':
		if (algorithmName == 'b')
		{
			cout << endl << "enter 3 parameters(xc, yc, r): ";
			cin >> x1;
			cin >> y2;
			cin >> y2;
			drawBCircle(x1, x2, y2);
			//break;
		}
		else if (algorithmName == 'm') {
			cout << endl << "enter 3 parameters(xc, yc, r): ";
			cin >> x1;
			cin >> x2;
			cin >> y2;
			drawMCircle(x1, x2, y2);
			//break;
		}
		break;

	case 'e':
		if (algorithmName == 'm')
		{
			cout << endl << "enter 4 parameters(xc, yc, rx, ry): ";
			cin >> x1;
			cin >> x2;
			cin >> y1_;
			cin >> y2;
			drawEllipse(x1, x2, y1_, y2);
			//break;
		}
		else
		{
			//...
			break;
		}
		break;
	}
	glutPostRedisplay();
}

void display(void)
{
	glutSwapBuffers();
	glClear(GL_COLOR_BUFFER_BIT);
	drawObject();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutCreateWindow("Drawing algorithms");
	init();
	glutDisplayFunc(display);
	//glutMouseFunc(mouse);
	//glutMotionFunc(motion);
	//glutPassiveMotionFunc(pmotion);
	//glutKeyboardFunc(keyboard);

	glutMainLoop();
}
#include <math.h>
#include <queue>
#include <string>
#include <iostream>
#include "glut.h"

using namespace std;

unsigned char prevKey;

class Point {
public:
	double x, y;

	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
	}
};

class GrilaCarteziana
{
private:
	const double padding = 0.1;
	const Point origin = Point(-1 + padding, -1 + padding);
	int no_lines, no_columns;
	double  dist_lines, dist_columns, radium_pixel;

	void DrawGrila()
	{
		glColor3d(0.0, 0.0, 0.0);
		glLineWidth(2);

		for (int i = 0; i < no_lines; i++)
		{
			glBegin(GL_LINES);
			glVertex2d(padding - 1, 1 - padding - i * dist_lines);
			glVertex2d(1 - padding, 1 - padding - i * dist_lines);
			glEnd();
		}

		for (int i = 0; i < no_columns; i++)
		{
			glBegin(GL_LINES);
			glVertex2d(1 - padding - i * dist_columns, 1 - padding);
			glVertex2d(1 - padding - i * dist_columns, padding - 1);
			glEnd();
		}
	}

public:
	GrilaCarteziana(int no_columns, int no_lines)
	{
		this->no_lines = no_lines;
		this->no_columns = no_columns;
		this->dist_lines = (2 - 2 * padding) / (no_lines - 1);
		this->dist_columns = (2 - 2 * padding) / (no_columns - 1);

		if (dist_lines < dist_columns)
		{
			this->radium_pixel = dist_lines / 4;
		}
		else
		{
			this->radium_pixel = dist_columns / 4;
		}

		DrawGrila();
	}

	void pixel(int x, int y)
	{
		if (x >= no_columns || y >= no_lines)
		{
			return;
		}

		double _2pi = 8 * atan(1.0);
		double ratio = 0.1;

		double centre_x = origin.x + dist_columns * x;
		double centre_y = origin.y + dist_lines * y;

		glColor3f(0, 0, 0);

		glPolygonMode(GL_FRONT, GL_FILL);
		glBegin(GL_POLYGON);

		for (double i = 0; i < _2pi/2; i += ratio) //construim punctul in jurul pixelului din centru (cel plasat pe linie)  - sens invers acelor de ceasornic
		{
			double x = radium_pixel * cos(i);
			double y = radium_pixel * sin(i);
			glVertex2d(centre_x + x, centre_y + y);
		}

		glEnd();
	}

	void linie(int x0, int y0, int xn, int yn) //AfisareSegmentDreapta3 Alg
	{
		double x0_abs = origin.x + dist_columns * x0;
		double xn_abs = origin.x + dist_columns * xn;

		double y0_abs = origin.y + dist_lines * y0;
		double yn_abs = origin.y + dist_lines * yn;

		int panta = 1;

		if (yn < y0)
		{
			panta = -panta;
		}

		//dx, dy sunt constante scoase din ecuatia dreptei
		int dist_x = xn - x0;
		int dist_y = panta * (yn - y0);

		//alg afisareSegmentDreapta3
		int d = 2 * dist_y - dist_x;
		int dE = 2 * dist_y;
		int dNE = 2 * (dist_y - dist_x);

		int x = x0;
		int y = y0;

		deque<Point> listPoints;

		listPoints.push_back(Point(x, y));

		while (x < xn)
		{
			if (d <= 0)
			{
				d += dE;
				x++;
			}
			else
			{
				d += dNE; 
				x++;
				y += panta;
			}
			listPoints.push_back(Point(x, y));
		}
		//end alg

		//trasare linii
		glLineWidth(3);
		glColor3f(1, 0, 0); //red
		glBegin(GL_LINES);
		glVertex2d(x0_abs, y0_abs);
		glVertex2d(xn_abs, yn_abs);
		glEnd();

		//desenare puncte
		while (!listPoints.empty())
		{
			Point p = listPoints.front();
			listPoints.pop_front();
			pixel(p.x, p.y);  //punctele de pe line (si cea de sus si cea de jos)

			if (panta < 0)
			{
				pixel(p.x, p.y + 1); //punctele de deasupra liniei de sus -> F(x,y) > 0 => puncte situate deasupra dreptei 
				pixel(p.x, p.y - 1); //punctele de sub linia de sus -> F(x,y) < 0 => puncte situate sub dreapta
			}
		}
	}
};

void Init(void)
{

	glClearColor(1.0, 1.0, 1.0, 1.0);

	glLineWidth(1);

	glPolygonMode(GL_FRONT, GL_LINE);
}

void Display(void)
{
	if (prevKey == 'g')
	{
		glClear(GL_COLOR_BUFFER_BIT);
		GrilaCarteziana grila(10, 15);
		grila.pixel(0, 0);
		grila.pixel(1, 1);
		grila.pixel(3, 5);
		glFlush();
	}
	else
	{
		glClear(GL_COLOR_BUFFER_BIT);
		GrilaCarteziana grila(16, 16);
		grila.linie(0, 15, 15, 10);
		grila.linie(0, 0, 15, 7);
		glFlush();
	}
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y)
{
	prevKey = key;

	if (key == 27) // escape
		exit(0);

	glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y)
{
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow(argv[0]);
	Init();
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(KeyboardFunc);
	glutMouseFunc(MouseFunc);
	glutDisplayFunc(Display);
	glutMainLoop();
	return 0;
}
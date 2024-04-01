#include "Canvas.h"

Canvas::Canvas(int width, int height) 
{
	this->width = width;
	this->height = height;
	mat = new char* [height];

	for (int i = 0; i < height; i++)
	{
		mat[i] = new char [width];
	}

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++)
		{
			mat[i][j] = ' ';
		}
	}
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++)
		{
			if (std::pow(i - y, 2) + std::pow(j - x, 2) <= std::pow(ray, 2))
			{
				mat[i][j] = ch;
			}
		}
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	for (int i = y - ray; i <= y + ray; i++)
	{
		for (int j = x - ray; j <= x + ray; j++)
		{
			if (std::pow(i - y, 2) + std::pow(j - x, 2) <= std::pow(ray, 2))
			{
				mat[i][j] = ch;
			}
		}
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	DrawLine(left, top, right, top, ch);
	DrawLine(right, top, right, bottom, ch);
	DrawLine(left, bottom, right, bottom, ch);
	DrawLine(left, top, left, bottom, ch);
}

void Canvas::SetPoint(int x, int y, char ch)
{
	mat[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = std::abs(x2 - x1);
	int dy = std::abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) {
			err -= dy;
			x1 += sx;
		}
		if (e2 < dx) {
			err += dx;
			y1 += sy;
		}
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top; i <= bottom; i++)
		for (int j = left; j <= right; j++)
			mat[i][j] = ch;
}

void Canvas::Print() // shows what was printed
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			std::cout << mat[i][j];
		std::cout << '\n';
	}
}
void Canvas::Clear() // clears the canvas
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			mat[i][j] = ' ';
}
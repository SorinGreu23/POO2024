#include <iostream>
#include "Canvas.h"
using namespace std;

int main() {
	Canvas c(30, 30);
	//c.FillRect(1, 1, 20, 10, '%');
	c.FillCircle(10, 10, 9, '!');
	c.DrawRect(1, 1, 5, 9, '$');
	c.FillRect(10, 10, 20, 25, '*');
	c.DrawLine(7, 7, 10, 10, '\\');
	//c.DrawCircle(10, 10, 9, '~');
	// c.Print();
	//c.Clear();
	c.Print();
	return 0;
}
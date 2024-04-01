#include <iostream>
#include "Math.h"
using namespace std;

int main()
{
	Math math;

	cout << math.Add(1, 2) << endl;
	cout << math.Add(1, 2, 3) << endl;
	cout << math.Add(1.1, 2.2) << endl;
	cout << math.Add(1.1, 2.2, 3.3) << endl;
	cout << math.Add(6, 4, 6, 4, 5, 3, 15) << endl;
	cout << math.Mul(1, 2) << endl;
	cout << math.Mul(1.1, 2.2) << endl;
	cout << math.Mul(1, 2, 3) << endl;
	cout << math.Mul(1.1, 2.2, 3.3) << endl;
	cout << math.Add("6", "21");
}

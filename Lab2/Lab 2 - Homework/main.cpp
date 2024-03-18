#include "NumberList.h"

int main() {
	NumberList nr;
	nr.Init();
	nr.Add(15);
	nr.Add(23);
	nr.Add(19);
	nr.Add(99);
	nr.Add(27);
	nr.Add(11);
	nr.Sort();
	nr.Print();
	return 0;
}
#include <stdio.h>
#include "NumberList.h"


void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10) { // if count is bigger or equal to 10, the function will return false
		return false;
	}
	numbers[count++] = x; // add x to the numbers list and increase the count.
	return true;
}

void NumberList::Sort()
{
	for (int i = 0; i < count - 1; i++) {
		for (int j = i + 1; j < count; j++) {
			if (numbers[i] > numbers[j])
			{
				int aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
		}
	}
}
void NumberList::Print() {
	for (int i = 0; i < count; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");
}
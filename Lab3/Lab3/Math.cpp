#include "Math.h"

int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}

int Math::Add(double x, double y)
{
	return (int)(x + y);
}

int Math::Add(double x, double y, double z)
{
	return (int)(x + y + z);
}

int Math::Mul(int x, int y)
{
	return x * y;
}

int Math::Mul(int x, int y, int z)
{
	return x * y * z;
}

int Math::Mul(double x, double y)
{
	return (int)(x * y);
}

int Math::Mul(double x, double y, double z)
{
	return (int)(x * y * z);
}

int Math::Add(int count, ...) // sums up a list of integers
{
	va_list list;
	int sum = 0;
	va_start(list, count);
	for (int i = 0; i < count; i++) {
		sum += va_arg(list, int);
	}
	va_end(list);
	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr) 
		return nullptr;

	int s1_length = strlen(s1);
	int s2_length = strlen(s2);
	int resultLength = s1_length > s2_length ? s1_length + 1 : s2_length + 1;
	
	char* result = new char[resultLength + 1];
	result[resultLength] = '\0';

	int carry = 0;
	for (int i = 0; i < resultLength; ++i)
	{
		int digit1 = i < s1_length ? s1[s1_length - i - 1] - '0' : 0;
		int digit2 = i < s2_length ? s2[s2_length - i - 1] - '0' : 0;

		int sum = digit1 + digit2 + carry;
		carry = sum / 10;
		result[resultLength - i - 1] = (sum % 10) + '0';
	}

	if (result[0] == '0')
	{
		for (int i = 0; i < resultLength; i++) {
			result[i] = result[i + 1];
		}
	}

	return result;
}
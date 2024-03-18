#include <stdio.h>

int handle_string_to_int(const char* str) {
	int value = 0;
	int sign = 1;
	if (*str == '-') {
		sign = -1;
		str++;
	}

	while (*str >= '0' && *str <= '9') {
		value = value * 10 + (*str - '0');
		++str;
	}

	return value * sign;
}

int main() 
{
	FILE* file = fopen("in.txt", "r"); // file used for reading the input data
	char buffer[256]; // buffer used for parsing the numbers from the text file
	int sum = 0;

	// if we have no file, an error will appear on the screen
	if (file == NULL) {
		printf("An error occured while trying to open the file");
		return 1;
	}

	// processing the data
	while (fgets(buffer, sizeof(buffer), file)) {
		sum += handle_string_to_int(buffer);
	}

	fclose(file);
	printf("Sum = %d\n", sum);

	return 0;
}
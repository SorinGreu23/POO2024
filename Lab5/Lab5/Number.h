#pragma once
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Number
{
private:
	int base;
	char* value;
	int digitsCount;

public:
	// Constructors
	Number(const char* value, int base);
	Number(int);
	Number(const Number&); // Copy constructor
	Number(Number&&) noexcept; // Move constructor
	
	// Destructor
	~Number();

	// Assignment Operators
	Number& operator=(const Number&);
	Number& operator=(int);
	Number& operator=(const char*);

	// Friend functions for addition and substraction
	friend Number operator+ (const Number&, const Number&);
	friend Number operator- (const Number&, const Number&);

	// Compound assignment operator (+=)
	Number& operator+=(const Number&);

	// Relational operators
	bool operator>(const Number&) const;
	bool operator<(const Number&) const;
	bool operator<=(const Number&) const;
	bool operator>=(const Number&) const;
	bool operator==(const Number&) const;
	bool operator!=(const Number&) const;

	// Increment/Decrement operators
	Number& operator--();		// Prefix decrement
	Number operator--(int);		// Postfix decrement
	
	char& operator[](int);

	void SwitchBase(int newBase);
	void Print() const;
	int GetDigitsCount();	// returns the number of digits for the current number
	int GetBase();			// returns the current base

	// Other methods
	int stringToInt(const char* value, int base) const;
	string intToBaseString(int value, int base) const;
};

#include "Number.h"

Number::Number(const char* value, int base): base(base), digitsCount(strlen(value)) {
    this->value = new char[strlen(value) + 1];
    strcpy_s(this->value, digitsCount + 1, value);
}

Number::Number(int val) : base(10) {
    string temp = to_string(val);
    int string_length = temp.length();
    
    this->value = new char[string_length + 1];
    copy(temp.begin(), temp.end(), this->value);
    this->value[string_length] = '\0';
    
    this->digitsCount = string_length;
}

// Copy constructor
Number::Number(const Number& other) : base(other.base), digitsCount(other.digitsCount)
{
    value = new char[digitsCount + 1];
    strcpy_s(value, digitsCount + 1, other.value);
}

// Move constructor
Number::Number(Number&& other) noexcept : base(other.base), value(other.value), digitsCount(other.digitsCount) {
    other.value = nullptr;
    other.digitsCount = 0;
}

Number::~Number() {
    delete[] this->value;
}

void Number::Print() const {
    cout << "Number in base " << base << ": " << value << endl;
}

int Number::GetDigitsCount() {
    return digitsCount;
}

int Number::GetBase() {
    return base;
}

Number& Number::operator=(const Number& other)
{
    this->base = other.base;

    char* newValue = new char[digitsCount + 1];
    strcpy_s(newValue, digitsCount + 1, other.value);

    delete[] value;
    value = newValue;

    return *this;
}

Number& Number::operator=(int val) {
    char temp[100];
    sprintf_s(temp, "%d", val); // integer to string conversion
    
    *this = Number(temp, 10);
    
    return *this;
}

Number& Number::operator=(const char* val)
{
    int newDigitsCount = strlen(val);
    char* newValue = new char[newDigitsCount + 1];
    strcpy_s(newValue, newDigitsCount + 1, val);

    delete[] value;
    value = newValue;
    digitsCount = newDigitsCount;

    return *this;
}

Number operator+(const Number& lhs, const Number& rhs)
{
    int lhsValue = lhs.stringToInt(lhs.value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);
    
    int sum = lhsValue + rhsValue;

    string resultString = lhs.intToBaseString(sum, lhs.base);

    return Number(resultString.c_str(), lhs.base);
}

Number operator-(const Number& lhs, const Number& rhs)
{
    int lhsValue = lhs.stringToInt(lhs.value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);

    int dif = lhsValue - rhsValue;

    string resultString = lhs.intToBaseString(dif, lhs.base);

    return Number(resultString.c_str(), lhs.base);
}

bool Number::operator>(const Number& rhs) const {
    int thisValue = this->stringToInt(this->value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);
    return thisValue > rhsValue;
}

bool Number::operator<(const Number& rhs) const {
    int thisValue = this->stringToInt(this->value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);
    return thisValue < rhsValue;
}

bool Number::operator<=(const Number& rhs) const {
    int thisValue = this->stringToInt(this->value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);
    return thisValue <= rhsValue;
}

bool Number::operator>=(const Number& rhs) const {
    int thisValue = this->stringToInt(this->value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);
    return thisValue >= rhsValue;
}

bool Number::operator==(const Number& rhs) const {
    int thisValue = this->stringToInt(this->value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);
    return thisValue == rhsValue;
}

bool Number::operator!=(const Number& rhs) const {
    int thisValue = this->stringToInt(this->value, 10);
    int rhsValue = rhs.stringToInt(rhs.value, 10);
    return thisValue != rhsValue;
}

Number& Number::operator--() {
    int currentValue = this->stringToInt(this->value, this->base);
    currentValue -= 1;

    string newValue = this->intToBaseString(currentValue, this->base);

    delete[] this->value;
    size_t valueLength = newValue.length() + 1;
    this->value = new char[valueLength];
    strcpy_s(this->value, valueLength, newValue.c_str());

    this->digitsCount = newValue.length();

    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);

    --(*this);

    return temp;
}

Number& Number::operator+=(const Number& rhs) {
    int thisValue = this->stringToInt(this->value, this->base);
    int rhsValue = rhs.stringToInt(rhs.value, rhs.base);

    thisValue += rhsValue;

    string newValue = this->intToBaseString(thisValue, this->base);

    delete[] value;
    size_t valueLength = newValue.length() + 1;
    this->value = new char[valueLength];
    strcpy_s(this->value, valueLength, newValue.c_str());
    this->digitsCount = newValue.length();

    return *this;
}

char& Number::operator[](int index) {
    return value[index];
}

void Number::SwitchBase(int newBase) {
    if (newBase < 2 || newBase > 16 || newBase == this->base) return;

    int intValue = stringToInt(this->value, this->base);
    std::string newBaseValue = intToBaseString(intValue, newBase);

    delete[] this->value;
    this->value = new char[newBaseValue.length() + 1];
    strcpy_s(this->value, newBaseValue.length() + 1, newBaseValue.c_str());
    this->base = newBase;
    this->digitsCount = newBaseValue.length();
}

int Number::stringToInt(const char* value, int base) const {
    int result = 0;
    for (int i = 0; value[i] != '\0'; ++i) {
        char c = value[i];
        if (c >= '0' && c <= '9') result = result * base + (c - '0');
        else if (c >= 'A' && c <= 'F') result = result * base + (c - 'A' + 10);
        else if (c >= 'a' && c <= 'f') result = result * base + (c - 'a' + 10);
    }
    return result;
}

string Number::intToBaseString(int value, int base) const {
    string result;
    string digits = "0123456789ABCDEF";

    if (value == 0) return "0";

    while (value > 0) {
        result = digits[value % base] + result;
        value /= base;
    }

    return result;
}
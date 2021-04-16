#include "FloatRange.h"

FloatRange::FloatRange()
{
	first = 0;
	second = 0;
}
FloatRange::FloatRange(double first = 0, double second = 0) throw(MyException, invalid_argument)
{
	if (first > second)
		throw MyException("MyException - Error!(first < second)");
	if (first == second)
		throw invalid_argument("Built in exception - Error!(first = second)");
	this->first = first;
	this->second = second;
}
FloatRange::FloatRange(const FloatRange& c)
{
	first = c.first;
	second = c.second;
}

void FloatRange::SetFirst(double first)
{
	this->first = first;
}
void FloatRange::SetSecond(double second)
{
	this->second = second;
}

double FloatRange::GetFirst() const { return first; }
double FloatRange::GetSecond() const { return second; }

FloatRange& FloatRange::operator = (const FloatRange& c)
{
	first = c.first;
	second = c.second;

	return *this;
}
istream& operator >> (istream& in, FloatRange& c) throw(const char*, bad_exception&)
{
	cout << "Enter a First number in range: "; in >> c.first;
	cout << "Enter a Second number in range: "; in >> c.second;
	cout << endl;

	if (c.first > c.second)
		throw "Error!(first > second)";
	if (c.first == c.second)
		throw bad_exception();
	return in;
}
ostream& operator << (ostream& out, const FloatRange& c)
{
	out << string(c);
	return out;
}
FloatRange::operator string() const
{
	stringstream ss;
	ss << "First number in range is equal to " << first << endl;
	ss << "Second number in range is equal to " << second << endl;

	return ss.str();

}

FloatRange& FloatRange::operator ++()
{
	first++;
	return *this;
}
FloatRange& FloatRange::operator --()
{
	first--;
	return *this;
}
FloatRange FloatRange::operator ++ (int)
{
	FloatRange t(*this);
	second++;
	return t;
}
FloatRange FloatRange::operator -- (int)
{
	FloatRange t(*this);
	second--;
	return t;
}

bool operator > (const FloatRange a, const double number)
{
	if (a.GetSecond() > number)
		return 1;
	else
		return 0;
}
bool operator < (const FloatRange a, const double number)
{
	if (a.GetFirst() < number)
		return 1;
	else
		return 0;
}

bool FloatRange::rangeCheck(const FloatRange a, const double number)
{
	return a < number&& a > number;
}
void FloatRange::rangeCheckResult(const bool result)
{
	if (result == 1)
		cout << "Yes, the number is within the specified range" << endl;
	else
		cout << "No, the number is not within the specified range" << endl;
}

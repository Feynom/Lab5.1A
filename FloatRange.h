#pragma once
#include <iostream>
#include <string>
#include <sstream>

#include "MyException.h"

using namespace std;

class FloatRange
{
	double first, second;
public:
	FloatRange();
	FloatRange(double, double);
	FloatRange(const FloatRange&);

	void SetFirst(double);
	void SetSecond(double);

	double GetFirst() const;
	double GetSecond() const;

	FloatRange& operator = (const FloatRange&);
	friend istream& operator >> (istream&, FloatRange&) throw(const char*, bad_exception&);
	friend ostream& operator << (ostream&, const FloatRange&);
	operator string() const;

	FloatRange& operator ++ ();
	FloatRange& operator -- ();
	FloatRange operator ++ (int);
	FloatRange operator -- (int);

	friend bool operator > (const FloatRange a, const double number);
	friend bool operator < (const FloatRange a, const double number);

	bool rangeCheck(const FloatRange a, const double number);
	void rangeCheckResult(const bool result);
};


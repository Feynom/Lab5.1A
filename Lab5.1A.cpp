#include <iostream>
#include "FloatRange.h"

#include <exception>;
#include <stdexcept>;

int main()
{
	double number;
	FloatRange a;

	bool initResult;

	do
	{
	    try
	    {
	        initResult = true;
	        cin >> a;
	    }
	    catch (const char* str)
	    {
			initResult = false;
	        cerr << str << endl;	        
	    }
	    catch (bad_exception& e)
	    {
			initResult = false;
	        cerr << e.what() << endl;	        
	    }
		catch (invalid_argument e)
		{
			initResult = false;
			cerr << e.what() << endl;			
		}
	} while (!initResult);

	try
	{
		//FloatRange testMyException(5, 3);
		//FloatRange testMyExceptionSecond(5, 5);
	}
	catch (MyException e)
	{
		cerr << e.what() << endl;
		initResult = false;
	}
	catch (invalid_argument e)
	{
		cerr << e.what() << endl;
	}

	cout << "Enter a number to check for entry in the specified range: "; cin >> number;
	a.rangeCheckResult(a.rangeCheck(a, number));

	++a; cout << a;
	--a; cout << a;

	a++; cout << a;
	a--; cout << a;


	return 0;
}
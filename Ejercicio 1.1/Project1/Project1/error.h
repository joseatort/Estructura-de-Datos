#ifndef ERROR_H
#define ERROR_H

#include <iostream>
#include <iomanip>
using namespace std;

class error
{
private:
	string er;

public:
	error(string e)
	{
		er = e;
	}
	string getInfo()
	{
		return this->er;
	}
};


#endif // !ERROR_H

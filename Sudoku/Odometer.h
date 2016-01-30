#ifndef ODOMETER_H
#define ODOMETER_H

#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

class Odometer
{
private:
	static const string ODOMETER[36]; 

	static int binarySearchOdometerIndex(int low, int hi, string value);

public:
	static int odometerToInt(string value);
	static string intToOdometer(int num);
};

#endif

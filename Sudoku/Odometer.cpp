#include "Odometer.h"

string ODOMETER[36] =
{
	"0","1","2","3","4","5","6","7","8","9",
	"A","B","C","D","E","F","G","H","I","J",
	"K","L","M","N","O","P","Q","R","S","T",
	"U","V","W","X","Y","Z"
};

int Odometer::binarySearchOdometerIndex(int low, int hi, string value)
{
	while (low <= hi)
	{
		int mid = low + (hi - low) / 2;
		if (ODOMETER[mid] == value)
			return mid;
		else if (ODOMETER[mid] < value)
			low = mid + 1;
		else
			hi = mid - 1;
	}

	return -1;
}

int Odometer::odometerToInt(string value)
{
	int retVal = binarySearchOdometerIndex(0, 35, value);
	if (retVal < 0)
	{
		cerr << "binarySearchOdometerIndex failed with invalid value: " + value + '\n';
		cerr << "Replaced with 0\n";
		retVal = 0;
	}

	return retVal;
}

string Odometer::intToOdometer(int num)
{
	string retVal;
	try
	{
		retVal = ODOMETER[num];
	}
	catch (out_of_range& oor)
	{
		cerr << "intToOdometer failed with invalid number: " << num << '\n';
		cerr << "Replaced with 0\n";
	}

	return retVal;
}
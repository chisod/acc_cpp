#include <iostream>
#include "median.h"

using std::cout;
using std::endl;

int main()
{
	double numbers[] = {
		10, 20, 30, 30, 40, 50, 80, 90, 100, 1000
	};
	cout << median(numbers) << endl;
	return 0;
}

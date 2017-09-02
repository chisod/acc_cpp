#include <iostream>
#include "median.h"

using std::cout;
using std::endl;

int main()
{
	double numbers[] = {
		10, 30, 20, 80, 90, 20, 50, 60, 100, 1000
	};
	const size_t nnumbers = sizeof(numbers)/sizeof(*numbers);
	cout << median(numbers, nnumbers) << endl;
	return 0;
}

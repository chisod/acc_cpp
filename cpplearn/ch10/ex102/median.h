#ifndef GUARD_median_h
#define GUARD_median_h

#include <algorithm>

using std::sort;

double median(double* values, int nvalues)
{
	sort(values, values+nvalues);
	size_t mid = nvalues/2;
	double median = nvalues % 2 == 0 ? values[mid] : (values[mid] + values[mid-1])/2.0;

	return median;
}

#endif

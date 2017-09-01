#ifndef GUARD_median_h
#define GUARD_median_h

double median(double[] values)
{
	static const size_t nvalues = sizeof(values)/sizeof(*values);

	size_t mid = nvalues/2;
	double median = nvalues % 2 == 0 ? values[mid] : (values[mid] + values[mid-1])/2.0;

	return median;
}

#endif

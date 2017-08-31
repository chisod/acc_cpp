#include <vector>
#include "grade.h"
#include "median.h"

using std::vector;

double grade(double m, double f, const vector<double>& hw)
{
	return (0.4*m+0.4*f+0.2*median(hw));
}

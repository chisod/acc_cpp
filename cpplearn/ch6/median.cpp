#include <algorithm>
#include <stdexcept>
#include <vector>
#include <numeric>

using std::domain_error;
using std::sort;
using std::vector;
using std::accumulate;

double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size==0)
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	
	vec_sz mid = size/2;
	vec_sz median = size % 2 == 0 ? (vec[mid]+vec[mid-1])/2 : vec[mid];
	return median;
}

double average(const vector<double>& v)
{
	return accumulate(v.begin(), v.end(), 0.0) / v.size();
}

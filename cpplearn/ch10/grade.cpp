#include <vector>
#include <string>
#include "grade.h"
#include "median.h"

using std::vector;
using std::string;

double grade(double m, double f, const vector<double>& hw)
{
	return (0.4*m+0.4*f+0.2*median(hw));
}

string letter_grade(double grade)
{
	static const double numbers[] = {
		97, 94, 90, 87, 84, 80, 77, 74, 70, 60, 0
	};

	static const char* const letters[] = {
		"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "C-", "D", "F"
	};

	static const size_t ngrades = sizeof(numbers)/sizeof(*numbers);

	for (size_t i = 0; i < ngrades; ++i) {
		if (grade >= numbers[i])
			return letters[i];
	}

	return "?/?/?";
}


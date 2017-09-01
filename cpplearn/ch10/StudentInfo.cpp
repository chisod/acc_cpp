#include <istream>
#include <string>
#include <vector>

#include "grade.h"
#include "StudentInfo.h"

using std::istream;
using std::string;
using std::vector;


istream& read_hw(istream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}
	return in;
}

bool compare(const StudentInfo& x, const StudentInfo& y)
{
	return x.name() < y.name();
}

istream& StudentInfo::read(istream& in)
{
	in >> n >> midterm_grade >> final_grade;
	read_hw(in, homework);
	return in;
}

double StudentInfo::grade() const
{
	return ::grade(midterm_grade, final_grade, homework);
}

StudentInfo::StudentInfo(): midterm_grade(0), final_grade(0) { }

StudentInfo::StudentInfo(istream& is) { read(is); }

#include "Student_info.h"

using std::istream;
using std::ifstream;
using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

ifstream& read(ifstream& is, Student_info& s)
{
	is >> s.name >> s.midterm_grade >> s.final_grade;

	read_hw(is, s.homework);
	return is;

}

ifstream& read_hw(ifstream& in, vector<double>& hw)
{
	if (in) {
		hw.clear();

		double x;
		while (in >> x)
			hw.push_back(x);

		in.clear();
	}
}


#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "StudentInfo.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::ifstream;
using std::max;
using std::sort;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
	ifstream in;
	vector<StudentInfo> students;
	StudentInfo record;
	string::size_type maxlen = 0;

	in.open("scores.txt");

	while (record.read(in)) {
		maxlen = max(maxlen, record.name().size());
		students.push_back(record);
	}

	sort(students.begin(), students.end(), compare);

	for (vector<StudentInfo>::const_iterator iter = students.begin(); iter != students.end(); iter++) {
		cout << iter->name() << string(maxlen + 1 - iter->name().size(), ' ');
		try {
			double total_grade = iter->grade();
			streamsize prec = cout.precision();
			cout << setprecision(3) << total_grade << setprecision(prec) << endl;
		} catch (domain_error e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}


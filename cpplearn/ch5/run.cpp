#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::list;

int main()
{
	list<Student_info> students, failures;
	Student_info record;
	string::size_type maxlen = 0;
	typedef list<Student_info>::const_iterator student_iterator;

	while (read(cin, record)) {
		maxlen = max(maxlen, record.name.size());
		students.push_back(record);
	}

	failures = extract_fails(students);
	for (student_iterator iter = failures.begin(); iter != failures.end(); ++iter) {
		cout << iter->name << " failed!" << endl;
	}
	
	students.sort(compare);

	for (student_iterator iter = students.begin(); iter != students.end(); ++iter) {
		
		cout << iter->name << string(maxlen + 1 - iter->name.size(), ' ');

		try {
			double total_grade = grade(*iter);
			streamsize prec = cout.precision();
			cout << setprecision(3) << total_grade << setprecision(prec);
		} catch (domain_error e) {
			cout << e.what();
		}
		cout << endl;
	}
	return 0;
}

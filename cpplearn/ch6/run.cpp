#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <fstream>
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
using std::ifstream;

int main()
{
	ifstream in;
	list<Student_info> students, failures;
	Student_info record;
	string::size_type maxlen = 0;
	typedef list<Student_info>::const_iterator student_iterator;

	in.open("scores.txt");
	
	while (read(in, record)) {
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

	//ch 6 work
	vector<Student_info> did, didnt;
	Student_info student;

	while (read(in, record)) {
		if (did_all_hw(student))
			did.push_back(student);
		else
			didnt.push_back(student);
	}

	if (did.empty()) {
		cout << "No student did all the homework!" << endl;
		return 1;
	}

	if (didnt.empty()) {
		cout << "Every student did all the homework!" << endl;
		return 1;
	}

	return 0;

}

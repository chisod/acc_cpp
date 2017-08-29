#include <stdexcept>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

#include "grade.h"
#include "median.h"
#include "Student_info.h"

using std::back_inserter;
using std::domain_error;
using std::endl;
using std::list;
using std::ostream;
using std::remove_copy;
using std::string;
using std::transform;
using std::vector;

double grade(double midterm_grade, double final_grade, double homework)
{
	return 0.2*midterm_grade + 0.4*final_grade + 0.4*homework;
}

double grade(double midterm_grade, double final_grade, const vector<double>& hw)
{
	if (hw.size() == 0)
		throw domain_error("student has done no homework");
	return grade(midterm_grade, final_grade, median(hw));
}

double grade(const Student_info& s)
{
	return grade(s.midterm_grade, s.final_grade, s.homework);
}

bool did_all_hw(const Student_info& s)
{
	return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

bool failing_grade(const Student_info& s)
{
	return grade(s) < 60;
}

bool passing_grade(const Student_info& s)
{
	return !failing_grade(s);
}


/* double-pass solution
vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info> fail;
	remove_copy_if(students.begin(), students.end(), back_inserter(fail), passing_grade);
	students.erase(remove_if(students.begin(), students.end(), failing_grade), students.end());

	return fail;
}
*/

vector<Student_info> extract_fails(vector<Student_info>& students)
{
	vector<Student_info>::iterator iter = stable_partition(students.begin(), students.end(), passing_grade);
	vector<Student_info> fail(iter, students.end());
	students.erase(iter, students.end());

	return fail;
}

//ch6 extras
double grade_aux(const Student_info& s)
{
	try {
		return grade(s);
	} catch (domain_error) {
		return grade(s.midterm_grade, s.final_grade, 0);
	}
}

double median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), grade_aux);

	return median(grades);
}

double average_grade(const Student_info& s)
{
	return grade(s.midterm_grade, s.final_grade, average(s.homework));
}

double average_analysis(const vector<Student_info>& students)
{
	vector<double> grades;

	transform(students.begin(), students.end(), back_inserter(grades), average_grade);

	return median(grades);
}

double optimistic_median(const Student_info& s)
{
	vector<double> nonzero;
	remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

	if (nonzero.empty())
		return grade(s.midterm_grade, s.final_grade, 0);
	else
		return grade(s.midterm_grade, s.final_grade, median(nonzero));
}

double optimistic_median_analysis(const vector<Student_info>& students)
{
	vector<double> grades;
	transform(students.begin(), students.end(), back_inserter(grades), optimistic_median);
	return median(grades);
}

void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt)
{
	out << name << ": median(did) = " << analysis(did) <<
				   ", median(didnt) = " << analysis(didnt) << endl;
}

					

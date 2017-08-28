#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <list>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool failed_grade(const Student_info&);
bool did_all_hw(const Student_info&);
std::list<Student_info> extract_fails(std::list<Student_info>&);

double grade_aux(const Student_info&);
double median_analysis(const vector<Student_info>&);
double average_grade(const Student_info&);
double average_analysis(const vector<Student_info>&);
double optimistic_median(const Student_info&);
double optimistic_median_analysis(const vector<Student_info>&);
void write_analysis(ostream& out, const string& name,
					double analysis(const vector<Student_info>&),
					const vector<Student_info>& did,
					const vector<Student_info>& didnt);

#endif

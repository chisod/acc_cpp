#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include <iostream>
#include <list>
#include <string>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool failed_grade(const Student_info&);
bool passed_grade(const Student_info&);
bool did_all_hw(const Student_info&);
std::vector<Student_info> extract_fails(std::vector<Student_info>&);

double grade_aux(const Student_info&);
double median_analysis(const std::vector<Student_info>&);
double average_grade(const Student_info&);
double average_analysis(const std::vector<Student_info>&);
double optimistic_median(const Student_info&);
double optimistic_median_analysis(const std::vector<Student_info>&);
void write_analysis(std::ostream& out, const std::string& name,
					double analysis(const std::vector<Student_info>&),
					const std::vector<Student_info>& did,
					const std::vector<Student_info>& didnt);

#endif

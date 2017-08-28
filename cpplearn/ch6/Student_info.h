#ifndef GUARD_Student_info
#define GUARD_Student_info

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Student_info {
	std::string name;
	double midterm_grade, final_grade;
	std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::ifstream& read(std::ifstream&, Student_info&);
std::ifstream& read_hw(std::ifstream&, std::vector<double>&);

#endif

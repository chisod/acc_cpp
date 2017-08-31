#ifndef GUARD_StudentInfo
#define GUARD_StudentInfo

#include <istream>
#include <string>
#include <vector>

class StudentInfo {
	private:
		std::string n;
		double midterm_grade, final_grade;
		std::vector<double> homework;
	public:
		StudentInfo();
		StudentInfo(std::istream&);
		
		std::string name() const { return n; }
		bool valid() const { return !homework.empty(); }
		std::istream& read(std::istream&);
		double grade() const;
};

bool compare(const StudentInfo&, const StudentInfo&);

#endif

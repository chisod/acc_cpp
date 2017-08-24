#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;

int main()
{
    cout << "Enter name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;
    
    cout << "Please enter your midterm and final grades: ";
    double midtermg, finalg;
    cin >> midtermg >> finalg;

    cout << "Enter all your homework grades: "
	"followed by end-of-file: ";

	vector<double> homework;
    double x;

	while (cin >> x)
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (size == 0) {
		cout << endl << "enter grades!" << endl;
		return 1;
	}
	
	sort(homework.begin(), homework.end());

	vec_sz mid = size/2;
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1])/2 : homework[mid];

	streamsize prec = cout.precision();
	cout << "your final grade is " << setprecision(3)
		 << 0.2 * midtermg + 0.4 * finalg + 0.4 * median
		 << setprecision(prec) << endl;

	return 0;
}

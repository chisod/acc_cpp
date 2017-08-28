#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::back_inserter;

int main()
{
	vector<int> u(10, 100);
	vector<int> v;
	copy(u.begin(), u.end(), back_inserter(v));

	cout << "u" << endl;
	for (vector<int>::const_iterator iter = u.begin(); iter != u.end(); iter++)
		cout << (*iter) << endl;

	cout << "v" << endl;
	for (vector<int>::const_iterator iter = v.begin(); iter != v.end(); iter++)
		cout << (*iter) << endl;

	return 0;
}

#include <algorithm>
#include <string>
#include <vector>
#include <ios>
#include <iostream>
#include "permuted_string.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main()
{
	string s;
	vector<PermutedString> perms;

	getline(cin, s);
	
	perms = get_permuted_strings(s);
	sort(perms.begin(), perms.end(), compare);

	for (vector<PermutedString>::const_iterator iter = perms.begin(); iter != perms.end(); iter++) {
		string::size_type sep = iter->separator;
		cout << iter->object.substr(sep,iter->object.size()-sep) << "--" << iter->object.substr(0,sep) << endl;
	}
	
	return 0;
}


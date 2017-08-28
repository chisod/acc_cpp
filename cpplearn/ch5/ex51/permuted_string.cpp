#include "permuted_string.h"
#include <cctype>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::find_if;

bool compare(const PermutedString& x, const PermutedString& y)
{
	return x.object[0] < y.object[0];
}

vector<PermutedString> get_permuted_strings(const string& line)
{
	vector<PermutedString> ret;
	vector<string> words;
	vector<string>::size_type k=0;

	words = split(line);

	for (vector<string>::size_type i = 0; i != words.size(); i++) {
		PermutedString ps;
		bool cycled = false;
		string::size_type unrotated = 0;
		for (vector<string>::size_type j = 0; j != words.size(); j++) {
			
			k = i + j;
			if (k >= words.size()) {
				k -= words.size();
				cycled = true;
			}
			
				
			if (j == 0)
				ps.object = words[k];
			else
				ps.object.append(words[k]);

			if (j != words.size()-1)
				ps.object.append(" ");

			if (!cycled)
				unrotated += words[k].size() + 1;
		
		}
		ps.separator = unrotated-1;
		ret.push_back(ps);

	}

	return ret;
}

//split method from ch6
bool space(char c)
{
	return isspace(c);
}

bool not_space(char c)
{
	return !isspace(c);
}

vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;

	iter i = str.begin();
	while (i != str.end()) {
		i = find_if(i, str.end(), not_space);

		iter j = find_if(i, str.end(), space);

		if (i != str.end())
			ret.push_back(string(i, j));
		i = j;
	}
	return ret;
}

/*
vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i = 0;

	while (i != s.size()) {
		while (i != s.size() && isspace(s[i]))
			++i;

		string_size j = i;
		while (j != s.size() && !isspace(s[j]))
			++j;

		if (i != j) {
			ret.push_back(s.substr(i, j-i));
			i = j;
		}
	}

	return ret;
}
*/

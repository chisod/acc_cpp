#ifndef GUARD_permuted_string
#define GUARD_permuted_string

#include <string>
#include <vector>

struct PermutedString {
	std::string object;
	std::string::size_type separator;
};

bool compare(const PermutedString&, const PermutedString&);
std::vector<PermutedString> get_permuted_strings(const std::string&);
std::vector<std::string> split(const std::string&);

#endif

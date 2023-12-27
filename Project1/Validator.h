#pragma once
#include <string>
#include <sstream>
#include <vector>
#include <regex>

class Validator {
 public:
	bool match(const std::string& string) const;
	std::vector<std::string> split(const std::string& string, 
																 const char delim) const;
};
#include "Validator.h"


bool Validator::match(const std::string& string) const {
    std::string exp = "^(\\d{1,} |([1-9]{1,}|0{1})\\.\\d{1,} )"
                      "{2}(red|green|blue)$";
    std::regex regular(exp);
    std::cmatch res;
    return std::regex_match(string.c_str(), res, regular);
}

std::vector<std::string> Validator::split(const std::string& string, 
                                          const char delim) const {
    std::vector<std::string> vector;
    std::stringstream stringstream(string);
    std::string buff;
    while (std::getline(stringstream, buff, delim))
        vector.push_back(buff);
    return vector;
}
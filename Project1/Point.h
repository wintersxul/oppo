#pragma once
#include "ColorsnCords.h"
#include "Validator.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

class Point {
 public:
	void Load(std::istream& file);
	void PrintPoints(std::ostream& out) const;
	void PrintPoint(const size_t pos, std::ostream& out) const;
	void SetPoint(const std::string& data);
	void DeletePoint(const size_t pos);
	void DeletePoints();
 private:
	std::vector<CordsnColors> data_;
  Validator validator_;
	CordsnColors MakeCC(const std::vector<std::string>& vector) const;
};


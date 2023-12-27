#pragma once
#include "Fields.h"
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
	std::vector<Fields> data_;
  Validator validator_;
	const std::string compare(const Color color) const;
	const Color compare(const std::string color) const;
	Fields make_fields(const std::vector<std::string>& vector) const;
};


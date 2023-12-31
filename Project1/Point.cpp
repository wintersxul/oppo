#include "Point.h"

void Point::SetPoint(const std::string& string) {
	if (validator_.match(string)) {
		CordsnColors field = MakeCC(validator_.split(string, ' '));
		if (std::find(data_.begin(), data_.end(), field) == data_.end())
			data_.emplace_back(field);
	}
}

void Point::DeletePoint(const size_t pos) {
	try {
		auto to_find = data_.at(pos);
		data_.erase(data_.begin() + pos);
	} catch (std::out_of_range& exc) {
		std::cerr << "failed to find an element\n\n";
	}
}

void Point::DeletePoints() {
	data_.clear();
}

void Point::Load(std::istream& file) {
	std::string buff;
	while (std::getline(file, buff)) {
		SetPoint(buff);
	}
}

void Point::PrintPoints(std::ostream& out) const {
	const size_t size = data_.size();
	if (size) {
		for (size_t i = 0; i < size; i++) {
			PrintPoint(i, out);
		}
	}
}

void Point::PrintPoint(const size_t pos, 
											 std::ostream& out) const {
	try {
		auto to_find = data_.at(pos);
		out << to_find.x << " " << to_find.y << " ";
		out << CordsnColors::compare(to_find.color) << "\n";
	} catch (std::out_of_range& exc) {
		out << "failed to find an element\n\n";
	}
}

CordsnColors Point::MakeCC(
		const std::vector<std::string>& vector) const {
	CordsnColors fields;
	fields.x = stof(vector[0]);
	fields.y = stof(vector[1]);
	fields.color = CordsnColors::compare(vector[2]);
	return fields;
}

#include <iostream>
#include <fstream>
#include <vector>

enum Color { red, green, blue, white };

struct Fields {
	float x, y;
	Color color;
};

class Data {
 public:
	void load(std::istream& file);
	void print() const;
 private:
	const char* compare(const Color color) const;
	const Color compare(const char color[]) const;
	std::vector<Fields> data_;
};

void Data::load(std::istream& file) {
	char color[20];
	while (!file.fail()) {
		Fields buff;
		file >> buff.x;
		file >> buff.y;
		file >> color;
		buff.color = compare(color);
		data_.push_back(buff);
		if (file.eof())
			return;
	}
}

void Data::print() const {
	if (data_.size())
		for (auto i : data_) {
			std::cout << i.x << " " << i.y << " " <<
				compare(i.color) << "\n";
		}
}

const char* Data::compare(const Color color) const {
	if (color == red) { return "red"; }
	if (color == blue) { return "blue"; }
	if (color == green) { return "green"; }
	return nullptr;
}

const Color Data::compare(const char color[]) const {
	if (std::strcmp(color, "red") == 0) { return red; }
	if (std::strcmp(color, "blue") == 0) { return blue; }
	if (std::strcmp(color, "green") == 0) { return green; }
	return white;
}

int main() {
	Data data;
	std::ifstream file("InputPoints.txt");
	data.load(file);
	data.print();
	return 0;
}
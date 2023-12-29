#pragma once
#include <string>
enum Color { red, green, blue, white };

struct CordsnColors {
	float x = 0, y = 0;
	Color color = red;
	CordsnColors() = default;
	CordsnColors(const float x, const float y, const Color color)
		: x(x), y(y), color(color) {};

	bool operator == (const CordsnColors& field) const {
		return this->x == field.x && 
					 this->x == field.y && 
					 this->x == field.color;
	}

	static std::string compare(const Color color) {
		if (color == red) { return "red"; }
		if (color == blue) { return "blue"; }
		if (color == green) { return "green"; }
		return std::string();
	}

	static Color compare(const std::string color) {
		if (color == "red") { return red; }
		if (color == "blue") { return blue; }
		if (color == "green") { return green; }
		return white;
	}
};

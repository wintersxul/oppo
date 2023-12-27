#pragma once
enum Color { red, green, blue, white };

struct Fields {
	float x = 0, y = 0;
	Color color = red;
	Fields() = default;
	Fields(const float x, const float y, const Color color)
		: x(x), y(y), color(color) {};

	bool operator == (const Fields& field) const {
		return this->x == field.x && 
					 this->x == field.y && 
					 this->x == field.color;
	}
};
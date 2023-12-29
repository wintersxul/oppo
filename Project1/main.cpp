#include "Point.h"
#include <iostream>

int main() {
	Point point;
	std::ifstream file("InputPoints.txt");
	if (!file.is_open())
		return -1;
	point.Load(file);
	point.PrintPoints(std::cout);
	point.DeletePoints();
	file.close();
	return 0;
}

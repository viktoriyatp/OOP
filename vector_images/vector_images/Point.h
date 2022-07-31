#pragma once
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

/// <summary>
///Point i a class that holds 2 double numbers : X and Y that represents the coordinates of a point
/// </summary>

class Point
{
private:
	double x, y;

public:
	Point();
	Point(double x, double y);
	//returns X coordinate of a point
	double get_x() const;
	//returns Y coordinate of a point
	double get_y() const;
	//sets X coordinate of a point
	void set_x(double x);
	//sets Y coordinate of a point
	void set_y(double y);
	//translates point to another
	void translate(Point& p);
};

ostream& operator << (ostream& os, const Point& p);
istream& operator >> (istream& is, Point& p);
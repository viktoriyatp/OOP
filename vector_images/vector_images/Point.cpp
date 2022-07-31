#include "Point.h"

Point::Point() : x(0), y(0)
{
}

Point::Point(double x, double y) : x(x), y(y)
{
}

double Point::get_x() const
{
	return this->x;
}

double Point::get_y() const
{
	return this->y;
}

void Point::set_x(double x)
{
	this->x = x;
}

void Point::set_y(double y)
{
	this->y = y;
}

void Point::translate(Point& p)
{
	this->x = this->x + p.x;
	this->y = this->y + p.y;
}

ostream& operator<<(ostream& os, const Point& p)
{
	os << "(" << p.get_x() << ", " << p.get_y() << ")";
	return os;
}

istream& operator>>(istream& is, Point& p)
{
	char character;
	double coordinate;
	is >> character >> coordinate;
	p.set_x(coordinate);
	is >> character >> coordinate;
	p.set_y(coordinate);
	is >> character;
	return is;
}

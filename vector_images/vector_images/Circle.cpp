#include "Circle.h"

Circle::Circle() : center(0,0), radius(0)
{
}

Circle::Circle(Point& center, double radius, string contour_color, string filling_color) 
{
	this->center = center;
	this->radius = radius;
	
	Point TL = { center.get_x() - radius, center.get_y() + radius };
	set_top_left(TL);
	Point BR = { center.get_x() + radius, center.get_y() - radius };
	set_bottom_right(BR);
	set_contour_color(contour_color);
	set_filling_color(filling_color);
}

Point Circle::get_center() const
{
	return this->center;
}

double Circle::get_radius() const
{
	return this->radius;
}

void Circle::set_center(Point& c)
{
	this->center = c;
	Point TL = { c.get_x() - this->radius, c.get_y() + this->radius };
	Figure::set_top_left(TL);
	Point BR = { c.get_x() + this->radius, c.get_y() - this->radius };
	Figure::set_bottom_right(BR);
}

void Circle::set_radius(double r)
{
	this->radius = r;
	Point TL = { this->center.get_x() - r, this->center.get_y() + r };
	Figure::set_top_left(TL);
	Point BR = { this->center.get_x() + r, this->center.get_y() - r };
	Figure::set_bottom_right(BR);
}

void Circle::translate(double horizontal, double vertical)
{
	Point new_c = { this->center.get_x() + horizontal, this->center.get_y() + vertical };
	set_center(new_c);
}

void Circle::rotate(int angle)
{
	cout << "Circles remain the same when you rotate them!" << endl;
}

void Circle::scale(int width_x, int width_y)
{
	//cout << "Circles can't be scaled!" << endl;
	set_radius(width_x);
}

void Circle::print() const
{
	cout << "circle (" << this->center.get_x() << "," << this->center.get_y() << ") " << radius << " " << get_contour_color() << 
		" " << get_filling_color() << endl;
}

string Circle::to_SVG()
{
	string rec = "<circle cx=";

	string double_num;
	double_num = std::to_string(get_center().get_x());
	rec += double_num;
	rec += " cy=";
	double_num = std::to_string(get_center().get_y());
	rec += double_num;
	rec += " r=";
	double_num = std::to_string(get_radius());
	rec += double_num;
	rec += " stroke=(";
	rec += get_contour_color();
	rec += ") fill=(";
	rec += get_filling_color();
	rec += ") />";
	return rec;
}

Figure* Circle::clone() const
{
	return new Circle(*this);
}

Figure* CircleCreator::create_figure(istream& is) const
{
	Point center;
	is >> center;
	double radius;
	is >> radius;
	if (radius > center.get_x() || radius > center.get_y())
	{
		cout << "Radius is getting out of the picture" << endl;
		return nullptr;
	}
	string contour, filling;
	is >> contour;
	is >> filling;
	return new Circle(center, radius, contour, filling);
}

static CircleCreator __; // създава се обекта, но не се използва
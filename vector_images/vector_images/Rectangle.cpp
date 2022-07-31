#include "Rectangle.h"

Rectangle::Rectangle() : top_left(0,0), width(0), length(0)
{
}

Rectangle::Rectangle(Point& top_left, double width, double length, string contour_color, string filling_color)
{
	this->top_left = top_left;
	this->width = width;
	this->length = length;
	Point BR = { top_left.get_x() + width , top_left.get_y() + length };
	set_top_left(top_left);
	set_bottom_right(BR);
	set_contour_color(contour_color);
	set_filling_color(filling_color);
}

void Rectangle::set_top_left(Point& top_left)
{
	this->top_left = top_left;
	Point BR = { top_left.get_x() + this->width , top_left.get_y() + this->length };
	Figure::set_top_left(this->top_left);
	Figure::set_bottom_right(BR);
}

void Rectangle::set_width(double width)
{
	this->width = width;
	Point BR = { this->top_left.get_x() + width , this->top_left.get_y() + this->length };
	Figure::set_top_left(this->top_left);
	Figure::set_bottom_right(BR);
}

void Rectangle::set_length(double length)
{
	this->length = length;
	Point BR = { this->top_left.get_x() + this->width , this->top_left.get_y() + length };
	Figure::set_top_left(this->top_left);
	Figure::set_bottom_right(BR);
}

Point Rectangle::get_top_left() const
{
	return this->top_left;
}

double Rectangle::get_width() const
{
	return this->width;
}

double Rectangle::get_length() const
{
	return this->length;
}

void Rectangle::translate(double horizontal, double vertical)
{
	Point new_top_left = { this->top_left.get_x() + horizontal, this->top_left.get_y() + vertical};
	set_top_left(new_top_left);
}

void Rectangle::rotate(int angle)
{
	// Shifting the pivot point to the origin
	// and the given points accordingly
	double x_shifted = this->top_left.get_x() - get_center().get_x();
	double y_shifted = this->top_left.get_y() - get_center().get_y();
	// Calculating the rotated point co-ordinates
	// and shifting it back
	Point new_coordinates; 
	new_coordinates.set_x(get_center().get_x() + (x_shifted * COS(angle) - y_shifted * SIN(angle)));
	new_coordinates.set_y(get_center().get_y() + (x_shifted * SIN(angle) + y_shifted * COS(angle)));
	set_top_left(new_coordinates);

	x_shifted = get_bottom_right().get_x() - get_center().get_x();
	y_shifted = get_bottom_right().get_y() - get_center().get_y();

	new_coordinates.set_x(get_center().get_x() + (x_shifted * COS(angle) - y_shifted * SIN(angle)));
	new_coordinates.set_y(get_center().get_y() + (x_shifted * SIN(angle) + y_shifted * COS(angle)));
	set_bottom_right(new_coordinates);

}

void Rectangle::scale(int width_x, int width_y)
{
	set_length(this->length * width_y);
	set_width(this->width * width_x);
}

void Rectangle::print() const
{
	cout << "Rectangle (" << this->top_left.get_x() << "," << this->top_left.get_y() << ") " 
		<< this->width << " " << this->length << " " << get_contour_color() << " " << get_filling_color() << endl;
}

Figure* Rectangle::clone() const
{
	return new Rectangle(*this);
}

string Rectangle::to_SVG()
{
	string rec = "<rect width=";

	string double_num;
	double_num = std::to_string(get_width());
	rec += double_num;
	rec += " height=";
	double_num = std::to_string(get_length());
	rec += double_num;
	rec += " style=fill:rgb(";
	rec += get_filling_color();
	rec += ");stroke:rgb(";
	rec += get_contour_color();
	rec += ") />";
	return rec;
}

Figure* RectangleCreator::create_figure(istream& is) const
{
	Point top_left;
	is >> top_left;
	double length, width;
	is >> length;
	is >> width;
	string contour, filling;
	is >> contour;
	is >> filling;
	return new Rectangle(top_left, width, length, contour, filling);
}

static RectangleCreator __;





#include "Line.h"

Line::Line() : beginning(0,0), end(0,0)
{
}

Line::Line(Point& beginning, Point& end, string contour_color, string filling_color) : Figure(beginning, end, contour_color,filling_color)
{
	this->beginning = beginning;
	this->end = end;
}

void Line::set_beginning(Point& beginning)
{
	this->beginning = beginning;
	Figure::set_bottom_right(beginning);
}

void Line::set_end(Point& end)
{
	this->end = end;
	Figure::set_top_left(end);
}

Point Line::get_beginning() const
{
	return this->beginning;
}

Point Line::get_end() const
{
	return this->end;
}

void Line::translate(double horizontal, double vertical)
{
	this->beginning.set_x(this->beginning.get_x() + horizontal);
	this->beginning.set_y(this->beginning.get_y() + vertical);
	this->end.set_x(this->end.get_x() + horizontal);
	this->end.set_y(this->end.get_y() + vertical);
}

//Rotation matrix
void Line::rotate(int angle)
{
	// Shifting the pivot point to the origin
	// and the given points accordingly
	double x_shifted = this->beginning.get_x() - get_center().get_x();
	double y_shifted = this->beginning.get_y() - get_center().get_y();
	// Calculating the rotated point co-ordinates
	// and shifting it back
	Point new_coordinates;
	new_coordinates.set_x(get_center().get_x() + (x_shifted * COS(angle) - y_shifted * SIN(angle)));
	new_coordinates.set_y(get_center().get_y() + (x_shifted * SIN(angle) + y_shifted * COS(angle)));
	set_beginning(new_coordinates);

	x_shifted = this->end.get_x() - get_center().get_x();
	y_shifted = this->end.get_y() - get_center().get_y();

	new_coordinates.set_x(get_center().get_x() + (x_shifted * COS(angle) - y_shifted * SIN(angle)));
	new_coordinates.set_y(get_center().get_y() + (x_shifted * SIN(angle) + y_shifted * COS(angle)));
	set_end(new_coordinates);
}

void Line::scale(int width_x, int width_y)
{
	Point new_end = { this->end.get_x() * width_x, this->end.get_y() * width_y };
	Point new_beginning = { this->beginning.get_x() * width_x,this->beginning.get_y() * width_y };
	set_beginning(new_beginning);
	set_end(new_end);
}

void Line::print() const
{
	cout << "line segment (" << this->beginning.get_x() << "," << this->beginning.get_y() << ")" <<
		" (" << this->end.get_x() << "," << this->end.get_y() << ") " << get_contour_color() << " " << get_filling_color() << endl;
}

string Line::to_SVG()
{
	string rec = "<line x1=";

	string double_num;
	double_num = std::to_string(get_beginning().get_x());
	rec += double_num;
	rec += " y1=";
	double_num = std::to_string(get_beginning().get_y());
	rec += double_num;	
	rec += " x2=";
	double_num = std::to_string(get_end().get_x());
	rec += double_num;
	rec += " y2=";
	double_num = std::to_string(get_end().get_y());
	rec += double_num;
	rec += " style=stroke:rgb(";
	rec += get_contour_color();
	rec += ") />";

	return rec;
}

Figure* Line::clone() const
{
	return new Line(*this);
}

Figure* LineCreator::create_figure(istream& is) const
{
	Point beginning, end;
	is >> beginning;
	is >> end;
	string contour, filling;
	is >> contour;
	is >> filling;
	return new Line(beginning, end, contour, filling);
}

static LineCreator __;
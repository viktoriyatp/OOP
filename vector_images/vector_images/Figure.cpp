#include "Figure.h"
#include "FigureManager.h"

void Figure::set_top_left(Point& p)
{
	this->top_left = p;
	this->calculate_center();

}

void Figure::set_bottom_right(Point& p)
{
	this->bottom_right = p;
	this->calculate_center();;
}

void Figure::set_contour_color(string& contour_color)
{
	this->contour_color = contour_color;
}

void Figure::set_filling_color(string& filling_color)
{
	this->filling_color = filling_color;
}

Point Figure::get_top_left() const
{
	return this->top_left;
}

Point Figure::get_bottom_right() const
{
	return this->bottom_right;
}

Point Figure::get_center() const
{
	return this->center;
}

string Figure::get_contour_color() const
{
	return this->contour_color;
}

string Figure::get_filling_color() const
{
	return this->filling_color;
}

void Figure::calculate_center()
{
	this->center.set_x((this->top_left.get_x() + this->bottom_right.get_x()) / 2.0);
	this->center.set_y((this->top_left.get_y() + this->bottom_right.get_y()) / 2.0);
}

Figure::Figure(Point& t_l, Point& b_r, string c_c, string f_c)
{
	this->top_left = t_l;
	this->bottom_right = b_r;
	this->calculate_center();
	this->contour_color = c_c;
	this->filling_color = f_c;
}

FigureCreator::FigureCreator(const char* command) : command(command)
{
	FigureManager::start_figure_manager().register_figure(this);
}

const char* FigureCreator::get_command() const
{
	return this->command;
}

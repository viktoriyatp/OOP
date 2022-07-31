#include "Polygon.h"

Polygon::Polygon() 
{
}

Polygon::Polygon(vector<Point>& points, string contour_color, string filling_color)
{
	this->set_polygon(points);
	set_contour_color(contour_color);
	set_filling_color(filling_color);
}

void Polygon::set_polygon(vector<Point>& points)
{
	this->points_of_polygon = points;
	double min_x = this->points_of_polygon.front().get_x();
	double min_y = this->points_of_polygon.front().get_y();
	double max_x = this->points_of_polygon.front().get_x();
	double max_y = this->points_of_polygon.front().get_y();

	for (int i = 1; i < this->points_of_polygon.size(); i++)
	{
		if (min_x > this->points_of_polygon.at(i).get_x())
		{
			min_x = this->points_of_polygon.at(i).get_x();
		}
		if (max_x < this->points_of_polygon.at(i).get_x())
		{
			max_x = this->points_of_polygon.at(i).get_x();
		}
		if (min_y > this->points_of_polygon.at(i).get_y())
		{
			min_y = this->points_of_polygon.at(i).get_y();
		}
		if (max_y < this->points_of_polygon.at(i).get_y())
		{
			max_y = this->points_of_polygon.at(i).get_y();
		}
	}
	Point BR = { max_x,max_y };
	Point TL = { min_x,min_y };
	set_bottom_right(BR);
	set_top_left(TL);
}

vector<Point> Polygon::get_polygon() const
{
	return this->points_of_polygon;
}

void Polygon::translate(double horizontal, double vertical)
{
	try {
		vector<Point> new_points(this->points_of_polygon.size());
		for (int i = 0; i < this->points_of_polygon.size(); i++)
		{
			new_points.at(i).set_x(this->points_of_polygon.at(i).get_x() + horizontal);
			new_points.at(i).set_y(this->points_of_polygon.at(i).get_y() + vertical);
		}
		set_polygon(new_points);
	}
	catch (exception ex)
	{
		cout << ex.what();
		throw ex;
	}
}

//https://www.geeksforgeeks.org/2d-transformation-rotation-objects/?fbclid=IwAR1hGtO82pjCcpqt_EAyqHr_WxbgmBhZvRxPI5s4OIfz8_u-QJPntnsto5w

void Polygon::rotate(int angle)
{
	try {
		vector<Point> new_points(this->points_of_polygon.size());
		for (int i = 0; i < this->points_of_polygon.size(); i++)
		{
			// Shifting the pivot point to the origin
			// and the given points accordingly
			int x_shifted = this->points_of_polygon.at(i).get_x() - get_center().get_x();
			int y_shifted = this->points_of_polygon.at(i).get_y() - get_center().get_y();

			// Calculating the rotated point co-ordinates
			// and shifting it back
			new_points.at(i).set_x(get_center().get_x() + (x_shifted * COS(angle) - y_shifted * SIN(angle)));
			new_points.at(i).set_y(get_center().get_y() + (x_shifted * SIN(angle) + y_shifted * COS(angle)));
		}
		set_polygon(new_points);
	}
	catch (exception ex)
	{
		cout << ex.what();
		throw ex;
	}
}

void Polygon::scale(int width_x, int width_y)
{
	try {
		vector<Point> new_points(this->points_of_polygon.size());
		for (int i = 0; i < this->points_of_polygon.size(); i++)
		{
			new_points.at(i).set_x(this->points_of_polygon.at(i).get_x() * width_x);
			new_points.at(i).set_y(this->points_of_polygon.at(i).get_y() * width_y);


		}
		set_polygon(new_points);
	}
	catch (exception ex)
	{
		cout << ex.what();
		throw ex;
	}
}

void Polygon::print() const
{
	cout << "Polygon ";
	for (int i = 0; i < this->points_of_polygon.size(); i++)
	{
		cout << "(" << this->points_of_polygon.at(i).get_x() << "," << this->points_of_polygon.at(i).get_y() << ") ";
	}
	cout << get_contour_color() << " " << get_filling_color() << endl;
}

string Polygon::to_SVG()
{
	string rec = "<polygon points=";

	string double_num;
	for (int i = 0; i < get_polygon().size(); i++)
	{
		double_num = std::to_string(get_polygon().at(i).get_x());
		rec += double_num;
		rec += ",";
		double_num = std::to_string(get_polygon().at(i).get_y());
		rec += double_num;
		rec += " ";
	}
	rec += " style=fill:(";
	rec += get_filling_color();
	rec += ");stroke:(";
	rec += get_contour_color();
	rec += ") />";
	return rec;
}

Figure* Polygon::clone() const
{
	return new Polygon(*this);
}

Figure* PolygonCreator::create_figure(istream& is) const
{
	vector<Point> polygon;
	string contour, filling;
	try {
		size_t num_of_points;
		is >> num_of_points;
		polygon.resize(num_of_points);
		for (int i = 0; i < num_of_points; i++)
		{
			is >> polygon.at(i);
		}
		is >> contour;
		is >> filling;
	}
	catch (exception ex)
	{
		cout << ex.what();
		throw ex;
	}
	return new Polygon(polygon, contour, filling);
}

static PolygonCreator __;
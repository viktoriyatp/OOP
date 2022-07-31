#pragma once
#include "Figure.h"

/// <summary>
/// This class represents an SVG circle and inherits the Figure class
/// </summary>

class Rectangle : public Figure
{
private:
	Point top_left;
	double width;
	double length;

public:
	Rectangle();
	Rectangle(Point& top_left, double width, double length, string contour_color, string filling_color);

	//set top left point of the rectangle
	void set_top_left(Point& top_left);
	//set width of rectangle
	void set_width(double width);
	//set length of the rectangle
	void set_length(double length);
	//get top left point of rectangle
	Point get_top_left() const;
	//get width of rectangle
	double get_width() const;
	//get length of rectagle
	double get_length() const;

	//translates rectangle by horizontal and vertical
	virtual void translate(double horizontal, double vertical) override;
	//rotates rectangle by angle
	virtual void rotate(int angle) override;
	//scales rectangle by x and y
	virtual void scale(int width_x, int width_y) override;
	//prints rectangle
	virtual void print() const override;
	//translates rectangle to SVG format
	virtual string to_SVG() override;
	//clone the object
	virtual Figure* clone() const override;
};

/// <summary>
/// This class represents rectangle creation and inherits the FigureCreator class
/// </summary>

class RectangleCreator : public FigureCreator
{
public:
	RectangleCreator() : FigureCreator("rectangle") {};
	virtual Figure* create_figure(istream& is) const override;
};

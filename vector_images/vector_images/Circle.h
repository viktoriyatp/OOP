#pragma once
#include "Figure.h"

/// <summary>
/// This class represents an SVG circle and inherits the Figure class
/// </summary>

class Circle : public Figure
{
private:
	Point center;
	double radius;

public:
	Circle();
	Circle(Point& center, double radius, string contour_color, string filling_color);

	//get the center point
	Point get_center() const;
	//get the radius
	double get_radius() const;
	//set the center
	void set_center(Point& c);
	//set the radius
	void set_radius(double r);

	//translates the circle by horizontal and verical
	virtual void translate(double horizontal, double vertical) override;
	//rotates the circle by angle
	virtual void rotate(int angle) override;
	//scale the circle
	virtual void scale(int width_x, int width_y = 0) override;
	//print the circle
	virtual void print() const override;
	//translates the circle to SVG format
	virtual string to_SVG() override;
	//clone the object
	virtual Figure* clone() const override;

};

/// <summary>
/// This class represents circle creation and inherits the FigureCreator class
/// </summary>

class CircleCreator : public FigureCreator
{
public:
	CircleCreator() : FigureCreator("circle") {};
	virtual Figure* create_figure(istream& is) const override;
};
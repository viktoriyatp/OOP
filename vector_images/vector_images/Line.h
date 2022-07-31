#pragma once
#include "Figure.h"

/// <summary>
/// This class represents an SVG circle and inherits the Figure class
/// </summary>

class Line : public Figure
{
private:
	Point beginning;
	Point end;

public:
	Line();
	Line(Point& beginning, Point& end, string contour_color, string filling_color);
	//sets the beginning point
	void set_beginning(Point& beginning);
	//sets the end point
	void set_end(Point& end);
	//returns beginning point
	Point get_beginning() const;
	//returns end point
	Point get_end() const;


	//translates line by horizontal and vertical
	virtual void translate(double horizontal, double vertical) override;
	//rotate line by angle
	virtual void rotate(int angle) override;
	//scale line by x and y
	virtual void scale(int width_x, int width_y) override;
	//print line
	virtual void print() const override;
	//translates the line to SVG format
	virtual string to_SVG() override;
	//clone the object
	virtual Figure* clone() const override;

};

/// <summary>
/// This class represents line creation and inherits the FigureCreator class
/// </summary>

class LineCreator : public FigureCreator
{
public:
	LineCreator() : FigureCreator("line") {};
	virtual Figure* create_figure(istream& is) const override;
};

#pragma once
#include "Figure.h"

/// <summary>
/// This class represents an SVG polygon and inherits the Figure class
/// </summary>

class Polygon : public Figure
{
private:
	vector<Point> points_of_polygon;

public:
	Polygon();
	Polygon(vector<Point>& points, string contour_color, string filling_color);

	//set points of polygon
	void set_polygon(vector<Point>& points);
	//get points of polygon
	vector<Point> get_polygon() const;

	//translate polygon by horizontal and vertical
	virtual void translate(double horizontal, double vertical) override;
	//rotate polygon by angle
	virtual void rotate(int angle) override;
	//scale polygon by x and y
	virtual void scale(int width_x, int width_y) override;
	//print polygon
	virtual void print() const override;
	//translates polygon to SVG format
	virtual string to_SVG() override;
	//clone object
	virtual Figure* clone() const override;
};

/// <summary>
/// This class represents polygon creation and inherits the FigureCreator class
/// </summary>

class PolygonCreator : public FigureCreator
{
public:
	PolygonCreator() : FigureCreator("polygon") {};
	virtual Figure* create_figure(istream& is) const override;

};



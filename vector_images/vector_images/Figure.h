#pragma once
#include "Point.h"
#include <cmath>
#include <exception>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::exception;

#define SIN(x) sin(x * 3.141592653589 / 180)
#define COS(x) cos(x * 3.141592653589 / 180)

/// <summary>
/// This is the base class for all SVG objects.
/// </summary>

class Figure
{
private:
	Point top_left = { 0,0 };
	Point bottom_right = { 0,0 };
	Point center = { 0,0 };
	string contour_color;
	string filling_color;
	
protected:
	//sets the top left point
	void set_top_left(Point& p);
	//sets the bootom left point
	void set_bottom_right(Point& p);
	//sets the contour colour
	void set_contour_color(string& contour_color);
	//sets filling color
	void set_filling_color(string& filling_color);
	//gets top left point
	Point get_top_left() const;
	//gets bottom right point
	Point get_bottom_right() const;
	//gets the center
	Point get_center() const;
	//gets contour color
	string get_contour_color() const;
	//gets filling color
	string get_filling_color() const;


private:
	void calculate_center();

public:
	Figure() {};
	Figure(Point& t_l, Point& b_r, string c_c, string f_c);
	virtual ~Figure() {};

	virtual void translate(double horizontal, double vertical) = 0;
	virtual void rotate(int angle) = 0;
	virtual void scale(int width_x, int width_y) = 0;
	virtual void print() const = 0;

	virtual Figure* clone() const = 0;

	virtual string to_SVG() = 0;

};

/// <summary>
/// This is the base class for creating figures
/// </summary>

class FigureCreator
{
protected:
	const char* const command;

public:
	FigureCreator(const char* command);
	virtual ~FigureCreator() {};
	//защото не искаме да създаваме два такива обекта
	FigureCreator(const FigureCreator&) = delete;
	FigureCreator& operator=(const FigureCreator&) = delete;
	const char* get_command() const;

	virtual Figure* create_figure(istream& is) const = 0;
};



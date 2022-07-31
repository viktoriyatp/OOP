#pragma once
#include "FigureManager.h"
#include <fstream>

/// <summary>
/// A command handler
/// </summary>

class InputManager
{
private:
	vector<Figure*> picture;

public:
	InputManager() {};

	//open file
	void open(string& file_name);
	//save to file in SVG format
	void save(string& file_name);
	//create new figure
	void create();
	//print all figures
	void print();
	//translate figure by index
	void translate(int id, double horizontal, double vertical);
	//translate all figures
	void translate(double horizontal, double vertical);
	//scale figure by index
	void scale(int id, int width_x, int width_y);
	//scale all figures
	void scale(int width_x, int width_y);
	//rotate figure by index
	void rotate(int id, double angle);
	//rotate all figures
	void rotate(double angle);
	//bring fugure forward by index
	void bring_forward(int id, int n);
	//bring figure backward by index
	void bring_backward(int id, int n);
	//help center
	void help();
};


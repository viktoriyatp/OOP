#include "InputManager.h"
#include <algorithm>
using std::ifstream;
using std::ofstream;
using std::fstream;

void InputManager::open(string& file_name)
{
	ifstream file(file_name);
	if (!file)
	{
		cout << "File can't be opened!" << endl;
		return;
	}

    int amount_of_figures;
	if (file.peek() != ifstream::traits_type::eof())
		file >> amount_of_figures;
	else
		amount_of_figures = 0;

	picture.resize(amount_of_figures);
	for (int i = 0; i < amount_of_figures; ++i)
	{
		picture[i] = FigureManager::start_figure_manager().crete_figure(file);
	}
	cout << "Successfully opened " << file_name << endl;
}

void InputManager::save(string& file_name)
{
	ofstream write_to_file;
	write_to_file.open(file_name, std::ios::app);
	if (!write_to_file) return;

	write_to_file.write("<svg ",6);
	for (int i = 0; i < picture.size(); i++)
	{
		write_to_file.write(picture[i]->to_SVG().c_str(), picture[i]->to_SVG().size()) << endl;
	}
	write_to_file.write("</svg>", 7);
	write_to_file.close();
}

void InputManager::create()
{
	cout << "Enter new figure" << endl;
	picture.push_back(FigureManager::start_figure_manager().crete_figure(cin));
}

void InputManager::print()
{
	try {
		for (int i = 0; i < this->picture.size(); i++)
		{
			cout << i + 1 << ". ";
			picture[i]->print();
			cout << endl;
		}
	}
	catch (...)
	{
		throw;
	}
}

void InputManager::translate(int id, double horizontal, double vertical)
{
	if (id < picture.size())
	{
		picture[id-1]->translate(horizontal, vertical);
	}
	else
	{
		cout << "Invalid id!" << endl;
		return;
	}
}

void InputManager::translate(double horizontal, double vertical)
{
	for (int i = 0; i < this->picture.size(); i++)
	{
		picture[i]->translate(horizontal, vertical);
	}
}

void InputManager::scale(int id, int width_x, int width_y)
{
	if (id < picture.size())
	{
		picture[id - 1]->scale(width_x, width_y);
	}
	else
	{
		cout << "Invalid id!" << endl;
		return;
	}
}

void InputManager::scale(int width_x, int width_y)
{
	for (int i = 0; i < this->picture.size(); i++)
	{
		picture[i]->scale(width_x, width_y);
	}
}

void InputManager::rotate(int id, double angle)
{
	if (id < picture.size())
	{
		picture[id - 1]->rotate(angle);
	}
	else
	{
		cout << "Invalid id!" << endl;
		return;
	}
}

void InputManager::rotate(double angle)
{
	for (int i = 0; i < this->picture.size(); i++)
	{
		picture[i]->rotate(angle);
	}
}

void InputManager::bring_forward(int id, int n)
{
	if (id < picture.size() && id - 1 + n <= picture.size())
	{
		for (int i = id - 1; i < id - 1 + n; i++)
		{
			std::swap(picture[i], picture[i + 1]);
		}
	}
	else
	{
		cout << "Incorrect ID or position!" << endl;
	}
}

void InputManager::bring_backward(int id, int n)
{
	if (id < picture.size() && id - 1 - n >= 0)
	{
		for (int i = id - 1; i > id - 1 - n; i--)
		{
			std::swap(picture[i], picture[i - 1]);
		}
	}
	else
	{
		cout << "Incorrect ID or position!" << endl;
	}
}

void InputManager::help()
{
	cout << "Help center :)" << endl << endl;
	cout << "How to use functions :" << endl;
	cout << "1. To operate with files use: open, save" << endl;
	cout << "2. Functions related to svg : " << endl;
	cout << "2.1 Use print, to get all svg objects" << endl;
	cout << "2.2 Use create, to create new svg object" << endl;
	cout << "2.3 Use translate, to translate an object selected by id number and by horizontal and vertical given by you.";
	cout << "Don't enter id number if you want to translate all the objects." << endl;
	cout << "2.4 Use scale, to scale an object selected by id number. Enter scalars on X an Y. ";
	cout << "Don't enter id number if you want to scale all the objects." << endl;	
	cout << "2.5 Use rotate, to rotate an object selected by id number. Enter the angle that you want to. ";
	cout << "Don't enter id number if you want to rotate all the objects." << endl;
	cout << "3. Use save to save the changes on the picture." << endl;
}


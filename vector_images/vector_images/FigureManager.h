#pragma once
#include "Figure.h"

/// <summary>
/// Main class that contains an array of svg objects.
/// </summary>

class FigureManager
{
private:
	vector<const FigureCreator*> set_of_figures;

	FigureManager() {};
	~FigureManager() {};
	FigureManager(const FigureManager&) = delete;
	FigureManager& operator=(const FigureManager&) = delete;

	//trying to find a figure by command
	const FigureCreator* get_figure(const string& str) const
	{
		for (int i = 0; i < set_of_figures.size(); i++)
		{
			if (set_of_figures.at(i)->get_command() == str)
				return set_of_figures.at(i);
		}
		cout << "Command not found!";
		return nullptr;
	}

public:
	//creates a ficure
	Figure* crete_figure(istream& stream)
	{
		string command;
		stream >> command;

		const FigureCreator* figure = get_figure(command);
		if (figure)
		{
			return figure->create_figure(stream);
		}
		else
		{
			int max_input = 4096;
			stream.ignore(max_input, '\n');
			return nullptr;
		}
	}
	//registers a figure
	void register_figure(const FigureCreator* figure)
	{
		set_of_figures.push_back(figure);
	}
	//singleton 
	static FigureManager& start_figure_manager()
	{
		static FigureManager THE_figure_manager;
		return THE_figure_manager;
	}
};


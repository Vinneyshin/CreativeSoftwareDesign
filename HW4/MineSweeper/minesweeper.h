#ifndef minesweeper_h
#define minesweeper_h

#include <stdio.h>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class Minesweeper
{
public:
	////////// 4-3-1 (7 score) //////////
	Minesweeper();
	~Minesweeper();

	// return false when input is incorrect
	bool setMap(size_t _width, size_t _height, vector<string>& _map);
	bool toggleMine(int _x, int _y);

	// return map width, height, and char
	size_t width() const;
	size_t height() const;
	char get(int _x, int _y) const; // return ' ' if input is illegal

									////////// 4-3-2 (3 score) //////////
	bool setPlay(); // return false when map is not set
	bool touchMap(int _x, int _y); // return true when dead

	int touchCount() const;

private:
	vector<string> m_playmap;
	vector<string> m_map;
	int m_width;
	int m_height;
	int m_touchcount;
	
	// add private member variables and functions if it is needed.
};

#endif /* minesweeper_h */
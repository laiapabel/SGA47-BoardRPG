#pragma once

#include "../GameDev/GameDev.h"
#include <list>
#include <cstdlib>
#include <ctime>
#include <string>

class MAP
{
public :
	MAP();
	~MAP();

	void Input(INT);
	void Update(DWORD);
	void Draw(HDC);

	void SetImage();
	void DelImage();

	Point& GetStart();

private :
	std::list<int> tile_type1;
	int shop_cnt;
	Point start;
};
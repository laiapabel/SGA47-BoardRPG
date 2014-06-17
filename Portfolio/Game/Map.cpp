#include "Map.h"

MAP::MAP()
	: shop_cnt(0), start(0,0)
{
	srand((unsigned)time(NULL));
}
MAP::~MAP()
{
}

void MAP::SetImage()
{

	int ids1 [] = {3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3,
				  1, 9, 9, 9, 9, 1, 9, 9, 9, 9, 1,
				  1, 9, 9, 9, 9, 1, 9, 9, 9, 9, 1,
				  2, 1, 1, 1, 1, 5, 1, 1, 1, 1, 2,
				  1, 9, 9, 9, 9, 1, 9, 9, 9, 9, 1,
				  1, 9, 9, 9, 9, 1, 9, 9, 9, 9, 1,
				  3, 1, 1, 1, 1, 2, 1, 1, 1, 1, 3};

	for (int i = 0; i < sizeof(ids1)/sizeof(int); i++)
	{
		tile_type1.push_back(ids1[i]);
	}

}

void MAP::Input(INT type)
{
}
void MAP::Update(DWORD)
{
}
void MAP::Draw(HDC hdc)
{

	ImgDepot["BackGround"]->Draw(hdc);

	int cx = GameGlobal.rcClient.right - GameGlobal.rcClient.left;
	int cy = GameGlobal.rcClient.bottom - GameGlobal.rcClient.top;
	int mapx = (cx - 880)/2;
	int mapy = (cy - 560)/2;

	Rect rcBox(mapx, mapy, 80, 80);

	std::list<int>::iterator it;

	int i = 0;
	for (it = tile_type1.begin(); it != tile_type1.end(); it++, i++)
	{
		int shop = rand()%10;

		if (*it == 1 && shop < 2 && shop_cnt < 5)
		{
			*it = 4;
			shop_cnt++;
		}

		std::ostringstream oss;
		oss << "tile" << *it;

		Rect rcDraw = rcBox >> Size(80*(i%11), 80*(i/11));

		if (*it == 5)
		{
			start.x = rcDraw.left+9;
			start.y = rcDraw.top+8;
		}

		//if (*it == 9)
		//	continue;

		ImgDepot[oss.str()]->SetRect(rcDraw);
		ImgDepot[oss.str()]->Draw(hdc);

	}
}

Point& MAP::GetStart()
{
	return start;
}

void MAP::DelImage()
{
}
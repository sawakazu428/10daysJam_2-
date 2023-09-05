#pragma once
class MapClass
{
public:
	void Initialize();

	void Update();

	void Draw();
private:
	int map[20][27];
	int mapFormat[20][27];
	int map2[22][27];
	int mapFormat2[22][27];
	int map3[20][27];
	int mapFormat3[20][27];

	int mapCountX;
	int mapCountY;
				  
	int mapCountX2;
	int mapCountY2;
				  
	int mapCountX3;
	int mapCountY3;
};				  


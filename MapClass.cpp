#include "MapClass.h"

void MapClass::Initialize()
{
	map[20][27];
	mapFormat[20][27];
	map2[22][27];
	mapFormat2[22][27];
	map3[20][27];
	mapFormat3[20][27];

	mapCountX;
	mapCountY;
	mapCountX2;
	mapCountY2;
	mapCountX3;
	mapCountY3;
}
void MapClass::Update()
{
	mapCountX = sizeof(map[0]) / sizeof(map[0][0]);
	mapCountY = sizeof(map) / sizeof(map[0]);

	mapCountX2 = sizeof(map2[0]) / sizeof(map2[0][0]);
	mapCountY2 = sizeof(map2) / sizeof(map2[0]);

	mapCountX3 = sizeof(map3[0]) / sizeof(map3[0][0]);
	mapCountY3 = sizeof(map3) / sizeof(map3[0]);
}

void MapClass::Draw()
{
	
}

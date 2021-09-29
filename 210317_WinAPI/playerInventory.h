#pragma once
#include "GameNode.h"

class Image;
class playerInventory:public GameNode
{
	//Image* 


public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};


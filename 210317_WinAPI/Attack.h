#pragma once
#include "GameNode.h"

class player;
class Attack : public GameNode
{
private:



public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);
};


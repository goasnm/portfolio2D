#pragma once
#include "GameNode.h"

class player;
class Mapmove: public GameNode
{
	player* play;

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
};


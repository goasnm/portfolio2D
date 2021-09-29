#pragma once
#include "GameNode.h"
class Image;
class Talk : public GameNode
{
private:
	Image* T_imag;

public:
	HRESULT Init(FPOINT pos);
	void Release();
	void Update();
	void Render(HDC hdc);
};


#pragma once
#include "GameNode.h"

class Boss;
class player;
class Image;
class EndScene: public GameNode
{
private:

	Image* D_imag;
	Image* W_Imag;
	Image* D1_imag;
	Image* W1_imag;

	FPOINT End_pos;

	player* play;
	Boss* boss;

	int type;

	int currFrame;
	int endTimer;


public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	EndScene(int type) { this->type = type; }
	virtual ~EndScene() {};
};


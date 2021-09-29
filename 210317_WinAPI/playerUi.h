#pragma once
#include "GameNode.h"

class player;
class Image;
class playerUi : public GameNode
{
	FPOINT I_pos;
	int size;
	int maxHp;
	RECT shape;

	player* play;

	Image* p_imag[20];
	Image* iVen;
	bool check = false;


public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void Inven();

	inline void Setplayer(player* play) { this->play = play; }

};


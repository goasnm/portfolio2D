#pragma once
#include "GameNode.h"

enum class Invenstate
{
	None,
	Sword,
	Shield,
	MagicFeather,
	End
};

class player;
class playerUi;
class Image;
class Inven : public GameNode
{
private:
	FPOINT showPos;
	RECT rc;
	Invenstate invenstate;

	Image* Iv_img;

	player* play;
	playerUi* p_ui;

	int changeWeapon;

	char name;



public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void InvenZ();
	void InvenC();

};


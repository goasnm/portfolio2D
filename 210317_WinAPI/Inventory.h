#pragma once
#include "GameNode.h"

enum class Weapon
{
	SWORD,
	SHIELD,
	MAGICFEATER,
	End
};

class playerUi;
class player;
class Image;
class Inventory : public GameNode
{
private:

	FPOINT Ven_pos;
	FPOINT I_pos;
	RECT Ven_rc;

	map<Weapon, Image*> W_img;
	Image* Ven_img[8];
	Image* S_ven_img;

	Weapon W_a;
	Weapon W_d;
	Weapon W_s;

	player* play;
	playerUi* p_inven;

	float Frame;

	BOOL Ven_check;
	bool checkA;
	bool checkD;

public:
	HRESULT Init(player* play);
	void Release();
	void Update();
	void Render(HDC hdc);

	void InvenA();
	void InvenD();

	Weapon SleleWeapon_A() { return this->W_a; }
	Weapon SleleWeapon_D() { return this->W_d; }

};

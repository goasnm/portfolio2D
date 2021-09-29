#include "Inventory.h"
#include "Image.h"
#include "player.h"
#include "playerUi.h"

HRESULT Inventory::Init(player* play)
{
	ImageManager::GetSingleton()->AddImage("P_playerShield", "Image/Inventory/Inventory_playerShield.bmp", 8 * 3, 20 * 3, 1, 1, true, RGB(0, 57, 115));
	Ven_img[0] = ImageManager::GetSingleton()->FindImage("P_playerShield");

	ImageManager::GetSingleton()->AddImage("P_playerSword", "Image/Inventory/Inventory_playerSword.bmp", 8 * 3, 16 * 3, 1, 1, true, RGB(0, 57, 115));
	Ven_img[1] = ImageManager::GetSingleton()->FindImage("P_playerSword");

	ImageManager::GetSingleton()->AddImage("P_playerMagicFeather", "Image/Inventory/Inventory_playerMagicFeather.bmp", 8 * 3, 16 * 3, 1, 1, true, RGB(0, 57, 115));
	Ven_img[2] = ImageManager::GetSingleton()->FindImage("P_playerMagicFeather");


	ImageManager::GetSingleton()->AddImage("P_playerInven", "Image/Inventory/Inventory_playerInven.bmp", 50 * 5, 20 * 3, 1, 1, true, RGB(0, 57, 115));
	Ven_img[3] = ImageManager::GetSingleton()->FindImage("P_playerInven");

	this->play = play;


	for (int i = 0; i < 3; i++)
	{
		Ven_rc.left = Ven_pos.x - Ven_img[i]->GetFrameWidth() / 2;
		Ven_rc.top = Ven_pos.y - Ven_img[i]->GetFrameHeight() / 2;
		Ven_rc.right = Ven_rc.left + Ven_img[i]->GetFrameWidth();
		Ven_rc.bottom = Ven_rc.top + Ven_img[i]->GetFrameHeight();
	}

	I_pos.x = WINSIZE_X / 2;
	I_pos.y = WINSIZE_Y / 2;

	W_a = Weapon::SWORD;
	W_d = Weapon::SHIELD;

	W_img.insert(make_pair(Weapon::SWORD, ImageManager::GetSingleton()->FindImage("P_playerSword")));
	W_img.insert(make_pair(Weapon::SHIELD, ImageManager::GetSingleton()->FindImage("P_playerShield")));
	W_img.insert(make_pair(Weapon::MAGICFEATER, ImageManager::GetSingleton()->FindImage("P_playerMagicFeather")));

	checkA = false;
	checkD = false;

	Ven_check = false;

	p_inven = new playerUi();
	p_inven->Init();
	p_inven->Setplayer(play);

    return S_OK;
}

void Inventory::Release()
{
	SAFE_RELEASE(p_inven);
}

void Inventory::Update()
{
	InvenA();

	InvenD();

	this->Ven_pos.x = play->GetPos().x;
	this->Ven_pos.y = play->GetPos().y;
	
	p_inven->Update();

}

void Inventory::Render(HDC hdc)
{
	
	Ven_img[3]->Render(hdc, I_pos.x - 240, I_pos.y + 165);

	if (Ven_check)
	{
		Ven_img[0]->FrameRender(hdc, play->GetScreenPos().x - 35, play->GetScreenPos().y + Ven_rc.top, 0, 0,true, 0.5f);
		Ven_img[1]->FrameRender(hdc, play->GetScreenPos().x, play->GetScreenPos().y + Ven_rc.top, 0, 0,true, 1);
		Ven_img[2]->FrameRender(hdc, play->GetScreenPos().x + 40, play->GetScreenPos().y + Ven_rc.top, 0, 0,true, 0.5f);
	}
	if (checkA == false)
	{
		W_img[W_a]->Render(hdc, I_pos.x-195, I_pos.y+190,true);
	}	
	if (checkD == false)
	{
		W_img[W_d]->Render(hdc, I_pos.x-70, I_pos.y+190,true);
	}

	p_inven->Render(hdc);
}

void Inventory::InvenA()
{
	Frame += 5 * TimerManager::GetSingleton()->GetElapsedTime();

	if (KeyManager::GetSingleton()->IsOnceKeyDown('A'))
	{
		for (int i = 0; i < (int)Weapon::End; ++i)
		{
			Ven_img[i] = W_img[(Weapon)((((int)W_a) + i + (int)Weapon::End - 1) % (int)Weapon::End)];
		}
		if (Ven_check == 0)
		{
			W_s = W_a;
			Ven_check = 1;
		}
		else
		{
			if (W_d == W_s) swap(W_a, W_d);
			else W_a = W_s;
			Ven_check = 0;
		}
	}
	
	if (Ven_check == 1)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('S'))
		{
			S_ven_img = Ven_img[0];
			Ven_img[0] = Ven_img[1];
			Ven_img[1] = Ven_img[2];
			Ven_img[2] = S_ven_img;
			W_s = (Weapon)(((int)W_s + 1) % (int)Weapon::End);
		}
	}
}

void Inventory::InvenD()
{
	Frame += 5 * TimerManager::GetSingleton()->GetElapsedTime();

	if (KeyManager::GetSingleton()->IsOnceKeyDown('D'))
	{
		for (int i = 0; i < (int)Weapon::End; ++i)
		{
			Ven_img[i] = W_img[(Weapon)((((int)W_d) + i + (int)Weapon::End - 1) % (int)Weapon::End)];
		}
		if (Ven_check == 0)
		{
			W_s = W_d;
			Ven_check = 2;
		}
		else
		{
			if (W_a == W_s) swap(W_d, W_a);
			else W_d = W_s;
			Ven_check = 0;
		}
	}

	if (Ven_check == 2)
	{
		if (KeyManager::GetSingleton()->IsOnceKeyDown('S'))
		{
			S_ven_img = Ven_img[0];
			Ven_img[0] = Ven_img[1];
			Ven_img[1] = Ven_img[2];
			Ven_img[2] = S_ven_img;
			W_s = (Weapon)(((int)W_s + 1) % (int)Weapon::End);
		}
	}
}

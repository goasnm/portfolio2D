#include "Inven.h"
#include "player.h"
#include "Image.h"
#include "playerUi.h"

HRESULT Inven::Init()
{
	//이넘 초기화
	invenstate = Invenstate::None;

	// 플레이어유아이
	p_ui = new playerUi();
	p_ui->Init();

	// 플레이어
	play = new player();
	play->Init();

	// 이미지 좌표 초기화
	showPos.x = WINSIZE_X/2;
	showPos.y = WINSIZE_Y/2;

	// 이미지 렉트
	rc.left = showPos.x - Iv_img->GetFrameWidth() / 2;
	rc.top = showPos.y - Iv_img->GetFrameHeight() / 2;
	rc.right = rc.left + Iv_img->GetFrameWidth();
	rc.bottom = rc.top + Iv_img->GetFrameHeight();

    return S_OK;
}

void Inven::Release()
{
}

void Inven::Update()
{

}

void Inven::Render(HDC hdc)
{
	p_ui->Render(hdc);
}

void Inven::InvenZ()
{
	if (KeyManager::GetSingleton()->IsOnceKeyUp('A'))
	{
		invenstate = Invenstate::End;
	}

	if (KeyManager::GetSingleton()->IsStayKeyDown('A'))
	{
		switch (invenstate)
		{
		case Invenstate::None:
			break;
		case Invenstate::Sword:
			ImageManager::GetSingleton()->FindImage("P_playerSword");
			showPos.x = -200;
			showPos.y = +100;

			break;
		case Invenstate::Shield:
			ImageManager::GetSingleton()->FindImage("P_playerShield");
			showPos.x = -100;
			showPos.y = +100;

			break;
		case Invenstate::MagicFeather:
			ImageManager::GetSingleton()->FindImage("P_playerMagicFeather");
			showPos.x = +100;
			showPos.y = +100;

			break;
		case Invenstate::End:
			break;
		default:
			break;
		}
	}
}

void Inven::InvenC()
{
}

#include "Talk.h"
#include "GameNode.h"
#include "MainGame.h"

HRESULT Talk::Init(FPOINT pos)
{
	ImageManager::GetSingleton()->AddImage("T_back", "Image/T_back.bmp", 490 * 3, 120 * 3, 0, 0, true, RGB(0, 57, 115));
	T_imag = ImageManager::GetSingleton()->FindImage("T_back");

    return S_OK;
}

void Talk::Release()
{
}

void Talk::Update()
{
}

void Talk::Render(HDC hdc)
{	
	//HDC hBackDC = T_imag->GetMemDC();

	//SceneManager::GetSingleton()->Render(hBackDC);

	TextOut(hdc, 20, 20, "MainGame ·»´õ Áß", strlen("MainGame ·»´õ Áß"));
	// ¸¶¿ì½º ÁÂÇ¥
	//wsprintf(szText, "X : %d, Y : %d", g_ptMouse.x, g_ptMouse.y);
	//TextOut(hBackDC, 800, 20, szText, strlen(szText));
	// FPS
	//TimerManager::GetSingleton()->Render(hBackDC);
}

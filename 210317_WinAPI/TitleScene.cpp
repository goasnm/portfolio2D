#include "TitleScene.h"
#include "Image.h"
#include "CommonFunction.h"



HRESULT TitleScene::Init()
{
	ImageManager::GetSingleton()->AddImage("Å¸ÀÌÆ²¾À", "Image/Title.bmp", WINSIZE_X, WINSIZE_Y);
	//ImageManager::GetSingleton()->AddImage("¼±ÅÃÅÊÅ©", "Image/BattleCity/Player/tank.bmp", 128, 56, 2, 1, true, RGB(255, 0, 255));
	//selectTank = ImageManager::GetSingleton()->FindImage("¼±ÅÃÅÊÅ©");
	titleImage = ImageManager::GetSingleton()->FindImage("Å¸ÀÌÆ²¾À");
	//0: 1P	//1: 2P	//2: ¸ÊÅø
	selectMode = 0;
	currFrame = 0;
	titleTimer = 0;


	return S_OK;
}

void TitleScene::Release()
{	
}

void TitleScene::Update()
{

	if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_RETURN))
	{
		SceneManager::GetSingleton()->ChangeScene("¿ùµå ¸Ê");
	}	
	if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_SPACE))
	{
		SceneManager::GetSingleton()->ChangeScene("Å¸ÀÏ¸ÊÅø");
	}


	titleTimer++;
	if (titleTimer % 100 == 0)
	{
		currFrame++;
		if (currFrame > 1)
		{
			currFrame = 0;
		}
	}
}

void TitleScene::Render(HDC hdc)
{
	titleImage->Render(hdc);
	//selectTank->FrameRender(hdc, WINSIZE_X / 3 - 40, tankPosY, currFrame, 0, true);
}


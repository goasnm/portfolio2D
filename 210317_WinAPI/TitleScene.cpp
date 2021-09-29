#include "TitleScene.h"
#include "Image.h"
#include "CommonFunction.h"



HRESULT TitleScene::Init()
{
	ImageManager::GetSingleton()->AddImage("Ÿ��Ʋ��", "Image/Title.bmp", WINSIZE_X, WINSIZE_Y);
	//ImageManager::GetSingleton()->AddImage("������ũ", "Image/BattleCity/Player/tank.bmp", 128, 56, 2, 1, true, RGB(255, 0, 255));
	//selectTank = ImageManager::GetSingleton()->FindImage("������ũ");
	titleImage = ImageManager::GetSingleton()->FindImage("Ÿ��Ʋ��");
	//0: 1P	//1: 2P	//2: ����
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
		SceneManager::GetSingleton()->ChangeScene("���� ��");
	}	
	if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_SPACE))
	{
		SceneManager::GetSingleton()->ChangeScene("Ÿ�ϸ���");
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


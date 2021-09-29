#include "EndScene.h"
#include "Image.h"
#include "player.h"
#include "Boss.h"
#include "CommonFunction.h"

HRESULT EndScene::Init()
{
    ImageManager::GetSingleton()->AddImage("WinEnd","Image/GameClear_1.bmp",WINSIZE_X,WINSIZE_Y);
    W_Imag = ImageManager::GetSingleton()->FindImage("WinEnd");

    ImageManager::GetSingleton()->AddImage("DeadEnd", "Image/GameOver.bmp", WINSIZE_X, WINSIZE_Y);
    D_imag = ImageManager::GetSingleton()->FindImage("DeadEnd");

    ImageManager::GetSingleton()->AddImage("DeadEnd1", "Image/GameOver_111.bmp", 5120, 720,4,1, true, RGB(200, 200, 200));
    D1_imag = ImageManager::GetSingleton()->FindImage("DeadEnd1");


    currFrame = 0;
    endTimer = 0;

    return S_OK;
}

void EndScene::Release()
{
}

void EndScene::Update()
{
    //if (play->GetHp() <= 0)
    if (KeyManager::GetSingleton()->IsOnceKeyDown(VK_RETURN))
    {
        SceneManager::GetSingleton()->ChangeScene("Å¸ÀÌÆ²¾À");
    }

    endTimer += 1.5f * TimerManager::GetSingleton()->GetElapsedTime();
    if (endTimer % 10 == 0)
    {
        currFrame++;
        if (currFrame > 1)
        {
            currFrame = 0;
        }
    }
}

void EndScene::Render(HDC hdc)
{
    if (type == 0)
    {
        D_imag->Render(hdc);
        D1_imag->FrameRender(hdc, WINSIZE_X/2, WINSIZE_Y/2, currFrame, 0, true);
    }
    else
    {
        W_Imag->Render(hdc);
    }
}

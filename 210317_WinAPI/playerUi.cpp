#include "playerUi.h"
#include "CommonFunction.h"
#include "Image.h"
#include "player.h"
#include "TitleScene.h"

HRESULT playerUi::Init()
{
    // 기본 UI 와 player 인벤토리 도 겸함

   ImageManager::GetSingleton()->AddImage("P_HP","Image/Inventory/Inventory_playerHp.bmp" ,48 * 3, 8 * 3, 6, 1, true, RGB(0, 57, 115));
   p_imag[0] = ImageManager::GetSingleton()->FindImage("P_HP");

   ImageManager::GetSingleton()->AddImage("P_Inventory_basic", "Image/Inventory/Inventory_basic.bmp", 160 * 3, 144 * 3, 1, 1, true, RGB(0, 57, 115));
   p_imag[1] = ImageManager::GetSingleton()->FindImage("P_Inventory_basic");
   
   ImageManager::GetSingleton()->AddImage("P_Inventory_num", "Image/Inventory/Inventory_num.bmp", 96 * 2, 8 * 2, 12, 1, true, RGB(248, 248, 168));
   p_imag[2] = ImageManager::GetSingleton()->FindImage("P_Inventory_num");

   ImageManager::GetSingleton()->AddImage("P_playerInven", "Image/Inventory/Inventory_playerInven.bmp", 70 * 3, 20 * 3, 1, 1, true, RGB(248, 248, 168));
   p_imag[3] = ImageManager::GetSingleton()->FindImage("P_playerInven");

   ImageManager::GetSingleton()->AddImage("P_playerShield", "Image/Inventory/Inventory_playerShield.bmp", 8 * 3, 20 * 3, 1, 1, true, RGB(0, 57, 115));
   p_imag[4] = ImageManager::GetSingleton()->FindImage("P_playerShield");

   ImageManager::GetSingleton()->AddImage("P_playerSword", "Image/Inventory/Inventory_playerSword.bmp", 8 * 3, 16 * 3, 1, 1, true, RGB(0, 57, 115));
   p_imag[5] = ImageManager::GetSingleton()->FindImage("P_playerSword");

   ImageManager::GetSingleton()->AddImage("P_playerMagicFeather", "Image/Inventory/Inventory_playerMagicFeather.bmp", 8 * 3, 16 * 3, 1, 1, true, RGB(0, 57, 115));
   p_imag[6] = ImageManager::GetSingleton()->FindImage("P_playerMagicFeather");


   // 이미지 렉트
   //shape.left = I_pos.x - p_imag[]->GetFrameWidth() / 2;
   //shape.top = I_pos.y - p_imag[]->GetFrameHeight() / 2;
   //shape.right = shape.left + p_imag[]->GetFrameWidth();
   //shape.bottom = shape.top + p_imag[]->GetFrameHeight();


    I_pos.x = WINSIZE_X / 2 ;
    I_pos.y = WINSIZE_Y / 2 ;


    return S_OK;
}

void playerUi::Release()
{
}

void playerUi::Update()
{
}

void playerUi::Render(HDC hdc)
{
    if (p_imag)
    {
        play->GetIsAlive();
        for (int i = 0; i < (play->GetMaxHp() / 4); i++)
        {
            p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 4, 0, true);
        }

        for (int i = 0; i <= (play->GetHp() / 4); i++)
        {
            if (i != ((int)(play->GetHp() / 4)))
            {
                p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 0, 0, true);
            }
            else
            {
                switch (play->GetHp() % 4)
                {
                case 0:
                    p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 0, 0, true);
                    break;
                case 1:
                    p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 3, 0, true);
                    break;
                case 2:
                    p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 2, 0, true);
                    break;
                case 3:
                    p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 1, 0, true);
                    break;
                case 4:
                    p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 4, 0, true);
                    break;
                }
            }
            if (((float)play->GetHp() / 4) == i)
            {
                p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 4, 0, true);
            }

            //if(play->GetHp() / 4 == 0)
            //    p_imag[0]->FrameRender(hdc, I_pos.x + 100 + (i * 24), I_pos.y + 170, 4, 0, true);


        }      

        //p_imag[3]->Render(hdc, I_pos.x - 240 , I_pos.y+165);    // 게임화면 밑에 아이템 표시 UI
        p_imag[2]->FrameRender(hdc, I_pos.x - 160, I_pos.y +205, 1, 0, true);
        p_imag[2]->FrameRender(hdc, I_pos.x - 35, I_pos.y +205, 1, 0, true);
        p_imag[2]->FrameRender(hdc, I_pos.x -140 , I_pos.y +205, 3, 0, true);
        p_imag[2]->FrameRender(hdc, I_pos.x -15 , I_pos.y +205, 3, 0, true);
        //p_imag[4]->Render(hdc, I_pos.x - 110 , I_pos.y+155);    // 플레이어 실드
        //p_imag[5]->Render(hdc, I_pos.x - 218 , I_pos.y+160);    // 플레이어 소드
    }

    if (check == true)
    {
        p_imag[1]->Render(hdc, I_pos.x, I_pos.y);
    }

}

void playerUi::Inven()
{
    bool check = false;
    if (KeyManager::GetSingleton()->IsOnceKeyDown('F'))
    {
        check = true;
        p_imag[1] = ImageManager::GetSingleton()->FindImage("P_Inventory_basic");
    }
}

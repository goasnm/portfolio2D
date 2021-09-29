#include "MainCamera.h"

HRESULT MainCamera::Init()
{
    Mc_pos.x = WINSIZE_X / 2;
    Mc_pos.y = WINSIZE_Y / 2;

    return S_OK;
}

void MainCamera::Release()
{
    Singleton::ReleaseSingleton();
}

void MainCamera::Update()
{
   // if (KeyManager::GetSingleton()->IsStayKeyDown(VK_NUMPAD8))
   // {
   //     Mc_pos.y -= 1;
   // }
   // if (KeyManager::GetSingleton()->IsStayKeyDown(VK_NUMPAD5))
   // {
   //     Mc_pos.y += 1;
   // }
   // if (KeyManager::GetSingleton()->IsStayKeyDown(VK_NUMPAD4))
   // {
   //     Mc_pos.x -= 1;
   // }
   // if (KeyManager::GetSingleton()->IsStayKeyDown(VK_NUMPAD6))
   // {
   //     Mc_pos.x += 1;
   // }
}

void MainCamera::Render(HDC hdc)
{

}

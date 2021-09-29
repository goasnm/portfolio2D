#include "ObjectCamera.h"
#include "player.h"
#include "MainCamera.h"

HRESULT ObjectCamera::Init()
{
    //C_pos.x = WINSIZE_X;
    //C_pos.y = WINSIZE_Y;
    //
    //C_pos.x = play->GetPos().x - C_rc.left;
    //C_pos.y = play->GetPos().y - C_rc.top;

    return S_OK;
}

void ObjectCamera::Release()
{
}

void ObjectCamera::Update()
{
   C_pos.x = MainCamera::GetSingleton()->GetMc_pos().x;
   C_pos.y = MainCamera::GetSingleton()->GetMc_pos().y;

}

void ObjectCamera::Render(HDC hdc)
{
}

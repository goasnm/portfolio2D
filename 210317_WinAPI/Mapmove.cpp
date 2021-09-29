#include "Mapmove.h"
#include "player.h"

HRESULT Mapmove::Init()
{
    play->Init();

    return S_OK;
}

void Mapmove::Release()
{
}

void Mapmove::Update()
{
    if(play)
    {}

}

void Mapmove::Render(HDC hdc)
{
}

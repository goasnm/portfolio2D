#include "BossManager.h"
#include "Boss.h"
#include "Boss1.h"

HRESULT BossManager::Init()
{
    vBoss.resize(15);
    for (int i = 0; i < 15; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vBoss[i] = new Boss();
    }

    vBoss[0]->Init({ WINSIZE_X/2,WINSIZE_Y/2 });


    vBoss_Bar.resize(15);

    for (int i = 0; i < 15; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vBoss_Bar[i] = new Boss1();
    }

    vBoss_Bar[0]->Init({ WINSIZE_X / 2,WINSIZE_Y / 2 -5 });
    vBoss_Bar[1]->Init({ WINSIZE_X / 2  ,WINSIZE_Y / 2 + 43 });
    vBoss_Bar[2]->Init({ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 91 });
    //vBoss_Bar[3]->Init({ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 144 });
    vBoss_Bar[4]->Init({ WINSIZE_X / 2  ,WINSIZE_Y / 2 - 53 });
    vBoss_Bar[5]->Init({ WINSIZE_X / 2  ,WINSIZE_Y / 2 - 101 });
    vBoss_Bar[6]->Init({ WINSIZE_X / 2  ,WINSIZE_Y / 2 - 149 });

    return S_OK;
}

void BossManager::Release()
{
    vector<Boss*>::iterator it;
    for (it = vBoss.begin(); it != vBoss.end();)
    {
        (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it);
        it = vBoss.erase(it);
    }


    vector<Boss1*>::iterator it1;
    for (it1 = vBoss_Bar.begin(); it1 != vBoss_Bar.end();)
    {
        (*it1)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it1);
        it1 = vBoss_Bar.erase(it1);
    }
}

void BossManager::Update()
{
    vector<Boss*>::iterator it;
    for (it = vBoss.begin(); it != vBoss.end();)
    {
        (*it)->Update();
        if (!(*it)->GetIsAliveB())
        {
            (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it);
            it = vBoss.erase(it);
        }
        else
            it++;
    }


    vector<Boss1*>::iterator it1;
    for (it1 = vBoss_Bar.begin(); it1 != vBoss_Bar.end();)
    {
        (*it1)->Update();
        if (!(*it1)->GetIsAliveB1())
        {
            (*it1)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it1);
            it1 = vBoss_Bar.erase(it1);
        }
        else
            it1++;
    }
}

void BossManager::Render(HDC hdc)
{
    for (int i = 0; i < vBoss.size(); i++)
    {
        vBoss[i]->Render(hdc);
    }


    for (int i = 0; i < vBoss_Bar.size(); i++)
    {
        vBoss_Bar[i]->Render(hdc);
    }
}

void BossManager::AddEnemy(int size)
{
}

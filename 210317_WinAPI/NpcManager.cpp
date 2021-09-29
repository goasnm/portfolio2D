#include "NpcManager.h"
#include "Npc.h"
#include "Npc1.h"
#include "Npc8.h"
#include "Npc9.h"
#include "Npc10.h"

HRESULT NpcManager::Init()
{
    vNpcs.resize(5);
    for (int i = 0; i < 5; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vNpcs[i] = new Npc();
    }
    vNpcs[0]->Init({ 800,2500 });
    vNpcs[1]->Init({ 1000,2700 });
    vNpcs[2]->Init({ 1200,2100 });
    vNpcs[3]->Init({ 1500,2500 });
    vNpcs[4]->Init({ 1400,2300 });


    vNpcs1.resize(5);
    for (int i = 0; i < 5; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vNpcs1[i] = new Npc1();
    }
    vNpcs1[0]->Init({ 1000,2600 });
    vNpcs1[1]->Init({ 1250,2000 });
    vNpcs1[2]->Init({ 1300,2600 });
    vNpcs1[3]->Init({ 1600,2900 });

    vNpcs8.resize(2);
    for (int i = 0; i < 2; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vNpcs8[i] = new Npc8();
    }
    vNpcs8[0]->Init({ 840,2900 });

    vNpcs9.resize(2);
    for (int i = 0; i < 2; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vNpcs9[i] = new Npc9();
    }
    vNpcs9[0]->Init({ 170,3000 });

    vNpcs10.resize(2);
    for (int i = 0; i < 2; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vNpcs10[i] = new Npc10();
    }
    vNpcs10[0]->Init({ 265,2040 });


	return S_OK;
}

void NpcManager::Release()
{
    vector<Npc*>::iterator it;
    for (it = vNpcs.begin(); it != vNpcs.end();)
    {
        (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it);
        it = vNpcs.erase(it);
    }


    vector<Npc1*>::iterator it1;
    for (it1 = vNpcs1.begin(); it1 != vNpcs1.end();)
    {
        (*it1)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it1);
        it1 = vNpcs1.erase(it1);
    }

    vector<Npc8*>::iterator it8;
    for (it8 = vNpcs8.begin(); it8 != vNpcs8.end();)
    {
        (*it8)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it8);
        it8 = vNpcs8.erase(it8);
    }
    vector<Npc9*>::iterator it9;
    for (it9 = vNpcs9.begin(); it9 != vNpcs9.end();)
    {
        (*it9)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it9);
        it9 = vNpcs9.erase(it9);
    }
    vector<Npc10*>::iterator it10;
    for (it10 = vNpcs10.begin(); it10 != vNpcs10.end();)
    {
        (*it10)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it10);
        it10 = vNpcs10.erase(it10);
    }
}

void NpcManager::Update()
{
    vector<Npc*>::iterator it;
    for (it = vNpcs.begin(); it != vNpcs.end();)
    {
        (*it)->Update();
        if (!(*it)->GetIsAliveN())
        {
            (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it);
            it = vNpcs.erase(it);
        }
        else
            it++;
    }


    vector<Npc1*>::iterator it1;
    for (it1 = vNpcs1.begin(); it1 != vNpcs1.end();)
    {
        (*it1)->Update();
        if (!(*it1)->GetIsAliveN1())
        {
            (*it1)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it1);
            it1 = vNpcs1.erase(it1);
        }
        else
            it1++;
    }

    vector<Npc8*>::iterator it8;
    for (it8 = vNpcs8.begin(); it8 != vNpcs8.end();)
    {
        (*it8)->Update();
        if (!(*it8)->GetIsAliveN8())
        {
            (*it8)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it8);
            it8 = vNpcs8.erase(it8);
        }
        else
            it8++;
    }

    vector<Npc9*>::iterator it9;
    for (it9 = vNpcs9.begin(); it9 != vNpcs9.end();)
    {
        (*it9)->Update();
        if (!(*it9)->GetIsAliveN9())
        {
            (*it9)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it9);
            it9 = vNpcs9.erase(it9);
        }
        else
            it9++;
    }

    vector<Npc10*>::iterator it10;
    for (it10 = vNpcs10.begin(); it10 != vNpcs10.end();)
    {
        (*it10)->Update();
        if (!(*it10)->GetIsAliveN9())
        {
            (*it10)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it10);
            it10 = vNpcs10.erase(it10);
        }
        else
            it10++;
    }
}

void NpcManager::Render(HDC hdc)
{
    for (int i = 0; i < vNpcs.size(); i++)
    {
        vNpcs[i]->Render(hdc);
    }


    for (int i = 0; i < vNpcs1.size(); i++)
    {
        vNpcs1[i]->Render(hdc);
    }

    for (int i = 0; i < vNpcs8.size(); i++)
    {
        vNpcs8[i]->Render(hdc);
    }
    for (int i = 0; i < vNpcs9.size(); i++)
    {
        vNpcs9[i]->Render(hdc);
    }
    for (int i = 0; i < vNpcs10.size(); i++)
    {
        vNpcs10[i]->Render(hdc);
    }
}

void NpcManager::AddEnemy(int size)
{
}

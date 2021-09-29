#include "EnemyManager.h"
#include "Enemy.h"
#include "Enemy1.h"

HRESULT EnemyManager::Init()
{
    // 1) 배열
    //Enemy* enemys = new Enemy[10];
    //for (int i = 0; i < 10; i++)
    //{
    //    enemys[i].Init();
    //}

    // TODO : emplace_back() 성능 차이
    // 2) vector push_back()
    //for (int i = 0; i < 10; i++)
    //{
    //    vEnemys.push_back(new Enemy());
    //    vEnemys[i]->Init();
    //}

    // 3) vector resize()
    //vEnemys.resize(10);
    vEnemys.resize(15);
    for (int i = 0; i < 15; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vEnemys[i] = new Enemy();
    }
        vEnemys[0]->Init({400,300});
        vEnemys[1]->Init({180,400});
        vEnemys[2]->Init({780,400});
        vEnemys[3]->Init({300,1000});
        vEnemys[4]->Init({500,1200});
        vEnemys[5]->Init({400,1100});
        vEnemys[6]->Init({1300,1000});
        vEnemys[7]->Init({1200,1300});
        vEnemys[8]->Init({1100,1300});
        vEnemys[9]->Init({1300,1300});
        vEnemys[10]->Init({1200,600});
        vEnemys[11]->Init({1700,1000});
        vEnemys[12]->Init({1600,800});
        vEnemys[13]->Init({1700,150});
        vEnemys[14]->Init({1500,150});

    vEnemys_1.resize(10);
    for (int i = 0; i < 10; i++)
    {
        vEnemys_1[i] = new Enemy1();
    }
        vEnemys_1[0]->Init({ 315,120 });
        vEnemys_1[1]->Init({ 1500,690 });
        vEnemys_1[2]->Init({ 790,4050 });
        vEnemys_1[3]->Init({ 850,4050 });
        vEnemys_1[4]->Init({ 120,3750 });
        vEnemys_1[5]->Init({ 70,3750 });
        vEnemys_1[6]->Init({ 1320,4000 });
        vEnemys_1[7]->Init({ 1440,3335 });
        vEnemys_1[8]->Init({ 1420,3765 });
        vEnemys_1[9]->Init({ 315,1700 });



    //// 4) vector reserve()
    //vEnemys.reserve(10);
    //for (int i = 0; i < 10; i++)
    //{
    //    vEnemys.push_back(new Enemy());
    //    vEnemys[i]->Init();
    //}


    return S_OK;
}

void EnemyManager::Release()
{
    // 반복자(iterator) : STL 자료구조를 구성하는 원소의 메모리를 저장하는 객체
    vector<Enemy*>::iterator it;
    for (it = vEnemys.begin(); it != vEnemys.end();)
    {
        (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it);
        it = vEnemys.erase(it);
    }

    vector<Enemy1*>::iterator it1;
    for (it1 = vEnemys_1.begin(); it1 != vEnemys_1.end();)
    {
        (*it1)->Release();
        delete (*it1);
        it1 = vEnemys_1.erase(it1);
    }
}

void EnemyManager::Update()
{
   //vector<Enemy*>::iterator it;
   //for (it = vEnemys.begin(); it != vEnemys.end(); it++)
   //{
   //    (*it)->Update();
   //}

    vector<Enemy*>::iterator it;
    for (it = vEnemys.begin(); it != vEnemys.end();)
    {
        (*it)->Update();
        if (!(*it)->GetIsAlive())
        {
            (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it);
            it = vEnemys.erase(it);
        }
        else
            it++;
    }

    vector<Enemy1*>::iterator it1;
    for (it1 = vEnemys_1.begin(); it1 != vEnemys_1.end();)
    {
        (*it1)->Update();
        if (!(*it1)->GetIsAlive1())
        {
            (*it1)->Release();
            delete (*it1);
            it1 = vEnemys_1.erase(it1);
        }
        else
            it1++;
    }
}

void EnemyManager::Render(HDC hdc)
{
   /* vector<Enemy*>::iterator it;
    for (it = vEnemys.begin(); it != vEnemys.end(); it++)
    {
        (*it)->Render(hdc);
    }*/
    for (int i = 0; i < vEnemys.size(); i++)
    {
        vEnemys[i]->Render(hdc);
    }

    for (int i = 0; i < vEnemys_1.size(); i++)
    {
        vEnemys_1[i]->Render(hdc);
    }
}

void EnemyManager::AddEnemy(int size )
{
    //for (int i = 0; i < size; i++)
    //{
    //    vEnemys.push_back(new Enemy());
    //    vEnemys[vEnemys.size() - 1]->Init();
    //}

    //for (int i = 0; i < size; i++)
    //{
    //    vEnemys.push_back(new Enemy());
    //    vEnemys.back()->Init();
    //}
}

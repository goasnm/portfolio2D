#include "EnemyD1_Manager.h"
#include "EnemyD1.h"

HRESULT EnemyD1_Manager::Init()
{
    vEnemysD1.resize(15);
    for (int i = 0; i < 15; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vEnemysD1[i] = new EnemyD1();
    }

    vEnemysD1[0]->Init({ 430,300 });
    vEnemysD1[1]->Init({ 300,200 });
    vEnemysD1[2]->Init({ 430,150 });
    vEnemysD1[3]->Init({ 400,200 });
    vEnemysD1[4]->Init({ 300,100 });
    vEnemysD1[5]->Init({ 220,100 });


	return S_OK;
}

void EnemyD1_Manager::Release()
{
    vector<EnemyD1*>::iterator it;
    for (it = vEnemysD1.begin(); it != vEnemysD1.end();)
    {
        (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it);
        it = vEnemysD1.erase(it);
    }
}

void EnemyD1_Manager::Update()
{
    vector<EnemyD1*>::iterator it;
    for (it = vEnemysD1.begin(); it != vEnemysD1.end();)
    {
        (*it)->Update();
        if (!(*it)->GetIsAliveD1())
        {
            (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it);
            it = vEnemysD1.erase(it);
        }
        else
            it++;
    }
}

void EnemyD1_Manager::Render(HDC hdc)
{
    for (int i = 0; i < vEnemysD1.size(); i++)
    {
        vEnemysD1[i]->Render(hdc);
    }
}

void EnemyD1_Manager::AddEnemy(int size)
{
}

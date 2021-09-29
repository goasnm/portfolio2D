#include "EnemyD_Manager.h"
#include "EnemyD.h"

HRESULT EnemyD_Manager::Init()
{
    vEnemysD.resize(15);
    for (int i = 0; i < 15; i++)
    {
        //vEnemys.push_back(new Enemy());         
        vEnemysD[i] = new EnemyD();
    }

    vEnemysD[0]->Init({ 230,300 });
    vEnemysD[1]->Init({ 250,350 });
    vEnemysD[2]->Init({ 260,400 });
    vEnemysD[3]->Init({ 300,500 });
    vEnemysD[4]->Init({ 650,500 });
    vEnemysD[5]->Init({ 800,600 });
    vEnemysD[6]->Init({ 900,300 });
    vEnemysD[7]->Init({ 1000,200 });
    vEnemysD[8]->Init({ 1230,300 });
    vEnemysD[9]->Init({ 1350,300 });
    vEnemysD[10]->Init({ 1400,200 });
    vEnemysD[11]->Init({ 1400,600 });
    vEnemysD[12]->Init({ 1300,400 });
    vEnemysD[13]->Init({ 1200,700 });

    return S_OK;
}

void EnemyD_Manager::Release()
{
    vector<EnemyD*>::iterator it;
    for (it = vEnemysD.begin(); it != vEnemysD.end();)
    {
        (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
        delete (*it);
        it = vEnemysD.erase(it);
    }
}

void EnemyD_Manager::Update()
{
    vector<EnemyD*>::iterator it;
    for (it = vEnemysD.begin(); it != vEnemysD.end();)
    {
        (*it)->Update();
        if (!(*it)->GetIsAliveD())
        {
            (*it)->Release();   // (*it) -> Enemy* 데이터타입확인
            delete (*it);
            it = vEnemysD.erase(it);
        }
        else
            it++;
    }
}

void EnemyD_Manager::Render(HDC hdc)
{
    for (int i = 0; i < vEnemysD.size(); i++)
    {
        vEnemysD[i]->Render(hdc);
    }
}

void EnemyD_Manager::AddEnemy(int size)
{
}

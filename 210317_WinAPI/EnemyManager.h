#pragma once
#include "GameNode.h"
#include <vector>



class Enemy1;
class Enemy;
class EnemyManager : public GameNode
{
private:
	vector<Enemy*> vEnemys;
	vector<Enemy1*> vEnemys_1;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
	vector<Enemy*> GetEnemy() { return this->vEnemys; }
	vector<Enemy1*> GetEnemy1() { return this->vEnemys_1; }
};


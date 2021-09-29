#pragma once
#include "GameNode.h"
#include <vector>


class EnemyD1;
class EnemyD1_Manager
{
private:
	vector<EnemyD1*> vEnemysD1;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
	vector<EnemyD1*> GetEnemy() { return this->vEnemysD1; }
};


#pragma once
#include "GameNode.h"
#include <vector>


class EnemyD;
class EnemyD_Manager
{

private:
	vector<EnemyD*> vEnemysD;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
	vector<EnemyD*> GetEnemy() { return this->vEnemysD; }
};


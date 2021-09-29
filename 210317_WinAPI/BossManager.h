#pragma once
#include "GameNode.h"
#include <vector>

class Boss1;
class Boss;
class BossManager : public GameNode
{
private:
	vector<Boss*> vBoss;
	vector<Boss1*> vBoss_Bar;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
	vector<Boss*> GetEnemy() { return this->vBoss; }
	vector<Boss1*> GetEnemy1() { return this->vBoss_Bar; }
};


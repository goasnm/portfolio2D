#pragma once
#include "GameNode.h"
#include <vector>

class Npc;
class Npc1;
class Npc8;
class Npc9;
class Npc10;
class NpcManager : public GameNode
{
private:

	vector<Npc*> vNpcs;
	vector<Npc1*> vNpcs1;
	vector<Npc8*> vNpcs8;
	vector<Npc9*> vNpcs9;
	vector<Npc10*> vNpcs10;




public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	void AddEnemy(int size);
	vector<Npc*> GetNpc() { return this->vNpcs; }
	vector<Npc1*> GetNpc1() { return this->vNpcs1; }
	vector<Npc8*> GetNpc8() { return this->vNpcs8; }
	vector<Npc9*> GetNpc9() { return this->vNpcs9; }
	vector<Npc10*> GetNpc10() { return this->vNpcs10; }
};
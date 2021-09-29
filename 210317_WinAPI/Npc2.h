#pragma once
#include "GameNode.h"

enum class NpcState2
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class NpcSee2
{
	DOWN,
	UP,
	LEFT,
	RIGHT,
	END
};

class StartScene;
class player;
class Image;
class Npc2
{
private:

	Image* N2_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT N2_pos;
	int N2_size;
	string name;
	RECT N2_rc;
	float moveSpeed;


	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;
	bool N2_isAlive;

	NpcState2 N2_state;
	NpcSee2 N2_see;
	FPOINT N2_ScreenPos;

	StartScene* S_scece;


public:
	HRESULT Init(FPOINT pos);
	void Release();
	void Update();
	void Render(HDC hdc);

	void Move();
	void See();
	void Dead();
	void HorizonMove();

	// get, set
	inline void SetPosN2(FPOINT pos) { this->N2_pos = pos; }
	inline void SetTargetN2(player* play) { this->play = play; }
	inline int GetSizeN2() { return this->N2_size; }
	inline void SetIsAliveN2(bool isAlive) { this->N2_isAlive = isAlive; }
	inline bool GetIsAliveN2() { return this->N2_isAlive; }
	//void SetN_Hp(int E_currhp) { this->B_currhp = E_currhp; }
	//int GetN_Hp() { return this->B_currhp; }

	FPOINT GetN2_Pos() { return this->N2_pos; }
	RECT GetN2_RC() { return this->N2_rc; }
	NpcSee2 GetNpcSee2() { return this->N2_see; }
};


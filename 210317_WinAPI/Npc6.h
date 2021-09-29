#pragma once
#include "GameNode.h"

enum class NpcState6
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class NpcSee6
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
class Npc6
{
private:

	Image* N_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT N_pos;
	int N_size;
	string name;
	RECT N_rc;
	float moveSpeed;


	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;
	bool N_isAlive;

	NpcState6 N_state;
	NpcSee6 N_see;
	FPOINT N_ScreenPos;

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
	inline void SetPosN6(FPOINT pos) { this->N_pos = pos; }
	inline void SetTargetN6(player* play) { this->play = play; }
	inline int GetSizeN6() { return this->N_size; }
	inline void SetIsAliveN6(bool isAlive) { this->N_isAlive = isAlive; }
	inline bool GetIsAliveN6() { return this->N_isAlive; }
	//void SetN_Hp(int E_currhp) { this->B_currhp = E_currhp; }
	//int GetN_Hp() { return this->B_currhp; }

	FPOINT GetN6_Pos() { return this->N_pos; }
	RECT GetN6_RC() { return this->N_rc; }
	NpcSee6 GetNpcSee6() { return this->N_see; }
};


#pragma once
#include "GameNode.h"

enum class NpcState5
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class NpcSee5
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
class Npc5
{

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

	NpcState5 N_state;
	NpcSee5 N_see;
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
	inline void SetPosN4(FPOINT pos) { this->N_pos = pos; }
	inline void SetTargetN4(player* play) { this->play = play; }
	inline int GetSizeN4() { return this->N_size; }
	inline void SetIsAliveN4(bool isAlive) { this->N_isAlive = isAlive; }
	inline bool GetIsAliveN4() { return this->N_isAlive; }
	//void SetN_Hp(int E_currhp) { this->B_currhp = E_currhp; }
	//int GetN_Hp() { return this->B_currhp; }

	FPOINT GetN4_Pos() { return this->N_pos; }
	RECT GetN4_RC() { return this->N_rc; }
	NpcSee5 GetNpcSee4() { return this->N_see; }
};


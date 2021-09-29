#pragma once
#include "GameNode.h"

enum class NpcState4
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class NpcSee4
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
class Npc4
{
private:

	Image* N4_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT N4_pos;
	int N4_size;
	string name;
	RECT N4_rc;
	float moveSpeed;


	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;
	bool N4_isAlive;

	NpcState4 N4_state;
	NpcSee4 N4_see;
	FPOINT N4_ScreenPos;

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
	inline void SetPosN4(FPOINT pos) { this->N4_pos = pos; }
	inline void SetTargetN4(player* play) { this->play = play; }
	inline int GetSizeN4() { return this->N4_size; }
	inline void SetIsAliveN4(bool isAlive) { this->N4_isAlive = isAlive; }
	inline bool GetIsAliveN4() { return this->N4_isAlive; }
	//void SetN_Hp(int E_currhp) { this->B_currhp = E_currhp; }
	//int GetN_Hp() { return this->B_currhp; }

	FPOINT GetN4_Pos() { return this->N4_pos; }
	RECT GetN4_RC() { return this->N4_rc; }
	NpcSee4 GetNpcSee4() { return this->N4_see; }
};


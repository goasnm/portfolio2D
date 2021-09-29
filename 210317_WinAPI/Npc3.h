#pragma once
#include "GameNode.h"

enum class NpcState3
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class NpcSee3
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
class Npc3
{
private:

	Image* N3_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT N3_pos;
	int N3_size;
	string name;
	RECT N3_rc;
	float moveSpeed;


	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;
	bool N3_isAlive;

	NpcState3 N3_state;
	NpcSee3 N3_see;
	FPOINT N3_ScreenPos;

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
	inline void SetPosN3(FPOINT pos) { this->N3_pos = pos; }
	inline void SetTargetN3(player* play) { this->play = play; }
	inline int GetSizeN3() { return this->N3_size; }
	inline void SetIsAliveN3(bool isAlive) { this->N3_isAlive = isAlive; }
	inline bool GetIsAliveN3() { return this->N3_isAlive; }
	//void SetN_Hp(int E_currhp) { this->B_currhp = E_currhp; }
	//int GetN_Hp() { return this->B_currhp; }

	FPOINT GetN3_Pos() { return this->N3_pos; }
	RECT GetN3_RC() { return this->N3_rc; }
	NpcSee3 GetNpcSee3() { return this->N3_see; }
};


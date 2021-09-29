#pragma once
#include "GameNode.h"


enum class NpcState1
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class NpcSee1
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
class Npc1
{
private:

	Image* N1_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT N1_pos;
	int N1_size;
	string name;
	RECT N1_rc;
	float moveSpeed;


	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;
	bool N1_isAlive;

	NpcState1 N1_state;
	NpcSee1 N1_see;
	FPOINT N1_ScreenPos;

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
	inline void SetPosN1(FPOINT pos) { this->N1_pos = pos; }
	inline void SetTargetN1(player* play) { this->play = play; }
	inline int GetSizeN1() { return this->N1_size; }
	inline void SetIsAliveN1(bool isAlive) { this->N1_isAlive = isAlive; }
	inline bool GetIsAliveN1() { return this->N1_isAlive; }
	//void SetN_Hp(int E_currhp) { this->B_currhp = E_currhp; }
	//int GetN_Hp() { return this->B_currhp; }

	FPOINT GetN1_Pos() { return this->N1_pos; }
	RECT GetN1_RC() { return this->N1_rc; }
	NpcSee1 GetNpcSee1() { return this->N1_see; }

};


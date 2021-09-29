#pragma once
#include "GameNode.h"

enum class BossState1
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class BossSee1
{
	DOWN,
	UP,
	LEFT,
	RIGHT,
	END
};

class StartScene;
class Image;
class player;
class Boss1
{
private:

	Image* B1_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT B1_pos;
	int B1_size;
	string name;
	RECT B1_rc;
	float moveSpeed;
	bool B1_isAlive;
	float B1_angle;

	int B1_maxhp;
	int B1_currhp;

	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;

	BossState1 B1_state;
	BossSee1 B1_see;
	FPOINT B1_ScreenPos;

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
	inline void SetPosB1(FPOINT pos) { this->B1_pos = pos; }
	inline void SetTargetB1(player* play) { this->play = play; }
	inline int GetSizeB1() { return this->B1_size; }
	inline void SetIsAliveB1(bool isAlive) { this->B1_isAlive = isAlive; }
	inline bool GetIsAliveB1() { return this->B1_isAlive; }
	void SetB1_Hp(int E_currhp) { this->B1_currhp = E_currhp; }
	int GetB1_Hp() { return this->B1_currhp; }

	FPOINT GetB1_Pos() { return this->B1_pos; }
	RECT GetB1_RC() { return this->B1_rc; }
	BossSee1 GetBossSee1() { return this->B1_see; }
};
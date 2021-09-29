#pragma once

#include "GameNode.h"

enum class EnemyState1
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class EnemySee1
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
class Enemy1 :public GameNode
{
private:

	Image* E1_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT E1_pos;
	int E1_size;
	string name;
	RECT E1_rc;
	float moveSpeed;
	bool E1_isAlive;
	float E1_angle;

	int E1_maxhp;
	int E1_currhp;

	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;

	EnemyState1 E1_state;
	EnemySee1 E1_see;
	FPOINT E1_ScreenPos;

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
	inline void SetPos1(FPOINT pos) { this->E1_pos = pos; }
	inline void SetTarget1(player* play) { this->play = play; }
	inline int GetSize1() { return this->E1_size; }
	inline void SetIsAlive1(bool isAlive) { this->E1_isAlive = isAlive; }
	inline bool GetIsAlive1() { return this->E1_isAlive; }
	void SetE1_Hp(int E1_currhp) { this->E1_currhp = E1_currhp; }
	int GetE1_Hp() { return this->E1_currhp; }
	float GetE1MoveSpeed() { return this->moveSpeed; }

	FPOINT GetE1_Pos() { return this->E1_pos; }
	RECT GetE1_RC() { return this->E1_rc; }
	EnemySee1 GetEnemySee1() { return this->E1_see; }
};


#pragma once
#include "GameNode.h"

enum class EnemyDState1
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class EnemyDSee1
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

class EnemyD1
{
private:
	Image* ED1_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT ED1_pos;
	int ED1_size;
	string name;
	RECT ED1_rc;
	float moveSpeed;
	bool ED1_isAlive;
	float ED1_angle;

	int ED1_maxhp;
	int ED1_currhp;

	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;

	EnemyDState1 ED1_state;
	EnemyDSee1 ED1_see;
	FPOINT ED1_ScreenPos;

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
	inline void SetPos(FPOINT pos) { this->ED1_pos = pos; }
	inline void SetTarget(player* play) { this->play = play; }
	inline int GetSize() { return this->ED1_size; }
	inline void SetIsAliveD1(bool isAlive) { this->ED1_isAlive = isAlive; }
	inline bool GetIsAliveD1() { return this->ED1_isAlive; }
	void SetED1_Hp(int ED1_currhp) { this->ED1_currhp = ED1_currhp; }
	int GetED1_Hp() { return this->ED1_currhp; }

	FPOINT GetED1_Pos() { return this->ED1_pos; }
	RECT GetED1_RC() { return this->ED1_rc; }
	EnemyDSee1 GetEnemyDSee1() { return this->ED1_see; }
};


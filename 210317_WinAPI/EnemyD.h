#pragma once
#include "GameNode.h"

enum class EnemyDState
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class EnemyDSee
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

class EnemyD
{
private:
	Image* ED_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT ED_pos;
	int ED_size;
	string name;
	RECT ED_rc;
	float moveSpeed;
	bool ED_isAlive;
	float ED_angle;

	int ED_maxhp;
	int ED_currhp;

	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;

	EnemyDState ED_state;
	EnemyDSee ED_see;
	FPOINT ED_ScreenPos;

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
	inline void SetPos(FPOINT pos) { this->ED_pos = pos; }
	inline void SetTarget(player* play) { this->play = play; }
	inline int GetSize() { return this->ED_size; }
	inline void SetIsAliveD(bool isAlive) { this->ED_isAlive = isAlive; }
	inline bool GetIsAliveD() { return this->ED_isAlive; }
	void SetED_Hp(int ED_currhp) { this->ED_currhp = ED_currhp; }
	int GetED_Hp() { return this->ED_currhp; }

	FPOINT GetED_Pos() { return this->ED_pos; }
	RECT GetED_RC() { return this->ED_rc; }
	EnemyDSee GetEnemyDSee() { return this->ED_see; }
};
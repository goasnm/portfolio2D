#pragma once
#include "GameNode.h"

// TODO : 업캐스팅, 다운캐스팅 설명

enum class EnemyState
{
	IDLE,
	MOVE,
	DEAD,
	END
};

enum class EnemySee
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
class Enemy : public GameNode
{
private:

	Image* E_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT E_pos;
	int E_size;
	string name;
	RECT E_rc;
	float moveSpeed;
	bool E_isAlive;
	float E_angle;

	int E_maxhp;
	int E_currhp;

	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;

	EnemyState E_state;
	EnemySee E_see;
	FPOINT E_ScreenPos;

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
	inline void SetPos(FPOINT pos) { this->E_pos = pos; }
	inline void SetTarget(player* play) { this->play = play; }
	inline int GetSize() { return this->E_size; }
	inline void SetIsAlive(bool isAlive) { this->E_isAlive = isAlive; }
	inline bool GetIsAlive() { return this->E_isAlive; }
	void SetE_Hp(int E_currhp) { this->E_currhp = E_currhp; }
	int GetE_Hp() { return this->E_currhp; }

	FPOINT GetE_Pos() { return this->E_pos; }
	RECT GetE_RC() { return this->E_rc; }
	EnemySee GetEnemySee() { return this->E_see; }
};
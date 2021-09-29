#pragma once
#include "GameNode.h"


enum class BossState
{
	IDLE,
	MOVE,
	DEAD,
	HIT,
	END
};

enum class BossSee
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
class Boss
{
private:

	Image* B_image;
	float currFrameX;
	float currFrameY;
	int updateCount;

	FPOINT B_pos;
	int B_size;
	string name;
	RECT B_rc;
	float moveSpeed;
	bool B_isAlive;
	float B_angle;

	int B_maxhp;
	int B_currhp;

	//GameNode* target;
	player* play;
	int dir;

	int fireCount;

	float seeTime;
	float moveTime;
	float stoptimer;
	BossState B_state;
	BossSee B_see;
	FPOINT B_ScreenPos;

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
	inline void SetPosB(FPOINT pos) { this->B_pos = pos; }
	inline void SetTargetB(player* play) { this->play = play; }
	inline int GetSizeB() { return this->B_size; }
	inline void SetIsAliveB(bool isAlive) { this->B_isAlive = isAlive; }
	void SetBossState(BossState B_state) { this->B_state = B_state; }
	void SetBossSee(BossSee B_see) { this->B_see = B_see; }
	void SetBossImg(Image* B_image) { this->B_image = B_image; }

	inline bool GetIsAliveB() { return this->B_isAlive; }
	void SetB_Hp(int E_currhp) { this->B_currhp = E_currhp; }
	int GetB_Hp() { return this->B_currhp; }

	Image* GetBossImg() { return this->B_image; }
	FPOINT GetB_Pos() { return this->B_pos; }
	RECT GetB_RC() { return this->B_rc; }
	BossSee GetBossSee() { return this->B_see; }
	BossState GetBossState() { return this->B_state; }
};


#pragma once
#include "ObjectCamera.h"


enum class playerState
{
	IDLE,
	MOVE,
	JUMP,
	ATT,
	ITEM,
	SLEEP,
	PUSH,
	PULL,
	SHIELDMOVE,
	SHIELDPUSH,
	GAIN,
	FALL,
	DEAD,
	DEAD_END,
	MOVEDOOR,
	Talk,
	HIT,
	END
};

enum class playerSee
{
	DOWN,
	UP,
	LEFT,
	RIGHT,
	END
};

class Inventory;
class playerUi;
class player : public ObjectCamera
{
private:
	// 속성 : 멤버변수
	FPOINT pos;
	FPOINT attPos;
	FPOINT ScreenPos;
	int size;
	float attackValue;
	string name;
	RECT P_rc;
	RECT Att_rc;
	RECT Shield_rc;
	
	float moveSpeed;
	float currFrameX;
	float currFrameY;
	float maxFrame;
	float timer;
	int currhp;
	int maxhp;

	playerState state;
	playerSee see;

	// UI Inventory
	//playerUi* p_Imag;

	Inventory* Inven;

	FPOINT cameraPos;
	FPOINT cmpos;

	Image* player;

	bool isCameraLock;
	bool isAlive;
	bool IsFinishAni;
	bool isfini = false;

	bool isJump = false;
	bool isshieldMove = false;

	float stoptimer;

public:
	HRESULT Init();
	void Release();		
	void Update();		
	void Render(HDC hdc);

	void Move();
	void normalAttack(int key);
	void shieldMove(int key);
	void Jump(int key);
	void Push();
	void Dead();

	bool GetisJump() { return this->isJump; }
	bool GetisshieldMove() { return this->isshieldMove; }

	// get, set
	void SetPos(FPOINT pos) {  this->pos = pos; }
	void SetPlayerImage(Image* player);/* {  this->player = player; }*/
	void SetmoveSpeed(float moveSpeed) {  this->moveSpeed = moveSpeed; }
	void SetPlayerCurrFreamX(float currFrameX) {  this->currFrameX = currFrameX; }
	void SetPlayerCurrFreamY(float currFrameY) {  this->currFrameX = currFrameY; }
	void SetPlayerState(playerState state) { this->state = state; }
	void SetShieldRC(RECT Shield_rc) { this->Shield_rc = Shield_rc; }
	void SetIsAlive(bool isAlive) { this->isAlive = isAlive; }

	bool GetIsAlive() { return this->isAlive; }
	RECT GetRC() { return this->P_rc; }
	RECT GetAttRC() { return this->Att_rc; }	
	RECT GetShieldRC() { return this->Shield_rc; }
	FPOINT GetPos() { return this->pos; }
	int GetHp() { return this->currhp; }
	void SetHp(int currhp) { this->currhp = currhp; }
	int GetMaxHp() { return this->maxhp; }
	int GetSize() { return this->size; }
	Image* GetPlayerImage() { return this->player; }
	playerSee GetPlayerSee() { return this->see; }
	playerState GetPlayerState() { return this->state; }
	float GetmoveSpeed() { return this->moveSpeed; }
	float GetPlayerCurrFreamX() { return this->currFrameX; }
	float GetPlayerCurrFreamY() { return this->currFrameY; }
	FPOINT GetScreenPos() { return this->ScreenPos; }


	void SetScreenPos(FPOINT ScreenPos) { this->ScreenPos = ScreenPos; }
	 
	void SetCameraLock(bool isCameraLock) { this->isCameraLock = isCameraLock; }
	bool GetCameraLock() { return this->isCameraLock; }

	bool GetIsFinishAnimation();
	bool GetisFini();
};


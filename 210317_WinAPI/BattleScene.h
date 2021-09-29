#pragma once
#include "GameNode.h"
#include "config.h"

//#define TILESIZE		48
//
//// ���� �׸��� ���� ����
//#define	TILE_X			10
//#define	TILE_Y			8



// ���� MainGame Ŭ������ ������ �̵�
class player;
class EnemyManager;
class Image;
class BattleScene : public GameNode
{
private:
	player* play;
	EnemyManager* enemyMgr;

	RECT P_rc;


	static TILE_INFO tileInfo[TILE_X * TILE_Y];

public:
	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);


	void CheckCollision();

	static void Load();
	virtual ~BattleScene() {};

	inline TILE_INFO GetTileInfo() { return this->tileInfo[TILE_X * TILE_Y]; }
	inline void SetTileInfo(TILE_INFO tileInfo) { this->tileInfo[TILE_X * TILE_Y] = tileInfo; }
};


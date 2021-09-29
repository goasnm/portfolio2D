#pragma once
#include "GameNode.h"

#define SAMPLE_TILE_X	10	
#define SAMPLE_TILE_Y	6	
#define TILESIZE		48

// ¸ÞÀÎ ±×¸®±â °ø°£ Á¤º¸
#define	TILE_X			10	//ÃÑ°³¼ö
#define	TILE_Y			8	//ÃÑ°³¼ö

enum class MAP_TYPE
{
	World,
	House1,	House2,	House3,	House4,	House5,	House6,	House7,
	Dungeon1,	Dungeon2,	Dungeon3,	Dungeon4,	Dungeon5,	Dungeon6,	Dungeon7,	Dungeon8,	Dungeon9,	Dungeon10,	
	Dungeon11,	Dungeon12,	Dungeon13,	Dungeon14,	Dungeon15,	Dungeon16,	Dungeon17,	Dungeon18, House8,
	End
};

class Image;
struct startPos
{
	Image* imag;
	Image* p_imag;
	FPOINT pos;

};

class Npc;
class Npc1;
class Npc2;
class Npc3;
class Npc4;
class Npc5;
class Npc6;
class Npc7;
class Inventory;
class playerUi;
class BattleScene;
class PixelCollision;
class player;
class EnemyD;
class EnemyD1;
class Enemy;
class Enemy1;
class Boss;
class Boss1;
class EnemyManager;
class EnemyD_Manager;
class EnemyD1_Manager;
class BossManager;
class NpcManager;
class StartScene : public GameNode
{
private:

	map < MAP_TYPE, startPos > MapLoad;

	static MAP_TYPE currPixBg;

	Image* pixBg;

	Image* bin;
	Image* bin2;
	Image* startImg;
	Image* worldMap;
	Image* pixelMap;
	Image* DungeonMap;
	Image* pixelDungeonMap;
	FPOINT pos;

	PixelCollision* pix;

	player* play;
	EnemyD* enemyD;
	EnemyD1* enemyD1;
	Enemy* enemy;
	Enemy1* enemy1;
	Boss* boss;
	Boss1* boss1;
	Npc* npc;
	Npc1* npc1;
	Npc2* npc2;
	Npc3* npc3;
	Npc4* npc4;
	Npc5* npc5;
	Npc6* npc6;
	Npc7* npc7;
	EnemyManager* E_mager;
	EnemyD_Manager* ED_mager;
	EnemyD1_Manager* ED1_mager;
	BossManager* B_mager;
	NpcManager* N_mager;
	//playerUi* p_Ui;
	//Inventory* p_Inven;

	float stopTimer;

	float currFrameX;
	float currFrameY;

	float invinTime;
	float invinTime1;
	float invinTime2;
	float invinTime3;
	float invinTime4;
	float invinTime5;

	static TILE_INFO tileInfo[TILE_X * TILE_Y];

public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);
	static void Load();

	void p_PixColli();
	void e_PixColli();
	void n_PixColli();
	void b_PixColli();
	void ed_PixColli();
	void ed1_PixColli();
	void p_eColli();
	void p_e1Colli();
	void p_dColli();
	void p_d1Colli();
	void p_bColli();
	void p_b1Colli();

	void p_ShieldColli();

	// ¸Ê <-> ¸Ê ÀÌµ¿ È®ÀÎ (ÇÈ¼¿Ãæµ¹)
	void LoadMap(COLORREF color);

	virtual ~StartScene() {};

	player* Getplayer() { return (this->play); }

	inline TILE_INFO GetTileInfo() { return this->tileInfo[TILE_X * TILE_Y]; }
	inline void SetTileInfo(TILE_INFO tileInfo) { this->tileInfo[TILE_X * TILE_Y] = tileInfo; }
	MAP_TYPE GetcurrPixBg() { return this->currPixBg; }


};
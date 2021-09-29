#include "StartScene.h"
#include "SceneManager.h"
#include "CommonFunction.h"
#include "Image.h"
#include "player.h"
#include "Npc.h"
#include "Npc1.h"
#include "Npc2.h"
#include "Npc3.h"
#include "Npc4.h"
#include "Npc5.h"
#include "Npc6.h"
#include "Npc7.h"
#include "Npc8.h"
#include "Npc9.h"
#include "Boss.h"
#include "Boss1.h"
#include "Enemy.h"
#include "Enemy1.h"
#include "EnemyD.h"
#include "EnemyD1.h"
#include "EnemyManager.h"
#include "EnemyD_Manager.h"
#include "EnemyD1_Manager.h"
#include "BossManager.h"
#include "BattleScene.h"
#include "NpcManager.h"
#include "playerUi.h"
#include "Inventory.h"
#include "TimerManager.h"

TILE_INFO StartScene::tileInfo[TILE_X * TILE_Y];

MAP_TYPE StartScene::currPixBg = MAP_TYPE::House1;


HRESULT StartScene::Init()
{
	bin = new Image();
	bin->Init("Image/BinArea.bmp", TILEMAPTOOLSIZE_X, TILEMAPTOOLSIZE_Y);

	bin2 = new Image();
	bin2->Init("Image/bin2.bmp", TILEMAPTOOLSIZE_X, TILEMAPTOOLSIZE_Y);


	srand(time(NULL));

	MainCamera::GetSingleton()->Init();

	// ¿ùµå¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ

	worldMap = ImageManager::GetSingleton()->AddImage("¿ùµå ¸Ê",
		"Image/Map/WorldMap_NoPix.bmp", 640 * 3, 1536 * 3, true, RGB(255, 0, 255));

	pixelMap = ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ¿ùµå ¸Ê",
		"Image/Map/WorldMap_pix.bmp", 640 * 3, 1536 * 3, true, RGB(255, 0, 255));

	// ´øÀü¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ

	ImageManager::GetSingleton()->AddImage("´øÀü_1 ¸Ê",
		"Image/Dungeon/Dungeon_1.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_1 ¸Ê",
		"Image/Dungeon/Dungeon_1_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_2 ¸Ê",
		"Image/Dungeon/Dungeon_2.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_2 ¸Ê",
		"Image/Dungeon/Dungeon_2_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_3 ¸Ê",
		"Image/Dungeon/Dungeon_3.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_3 ¸Ê",
		"Image/Dungeon/Dungeon_3_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_4 ¸Ê",
		"Image/Dungeon/Dungeon_4.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_4 ¸Ê",
		"Image/Dungeon/Dungeon_4_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_5 ¸Ê",
		"Image/Dungeon/Dungeon_5.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_5 ¸Ê",
		"Image/Dungeon/Dungeon_5_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_6 ¸Ê",
		"Image/Dungeon/Dungeon_6.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_6 ¸Ê",
		"Image/Dungeon/Dungeon_6_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));


	ImageManager::GetSingleton()->AddImage("´øÀü_7 ¸Ê",
		"Image/Dungeon/Dungeon_7.bmp", 480 * 3, 256 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_7 ¸Ê",
		"Image/Dungeon/Dungeon_7_pix.bmp", 480 * 3, 256 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_8 ¸Ê",
		"Image/Dungeon/Dungeon_8.bmp", 320 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_8 ¸Ê",
		"Image/Dungeon/Dungeon_8_pix.bmp", 320 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_9 ¸Ê",
		"Image/Dungeon/Dungeon_9.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_9 ¸Ê",
		"Image/Dungeon/Dungeon_9_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_10 ¸Ê",
		"Image/Dungeon/Dungeon_10.bmp", 160 * 3, 384 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_10 ¸Ê",
		"Image/Dungeon/Dungeon_10_pix.bmp", 160 * 3, 384 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_11 ¸Ê",
		"Image/Dungeon/Dungeon_11.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_11 ¸Ê",
		"Image/Dungeon/Dungeon_11_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_12 ¸Ê",
		"Image/Dungeon/Dungeon_12.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_12 ¸Ê",
		"Image/Dungeon/Dungeon_12_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_13 ¸Ê",
		"Image/Dungeon/Dungeon_13.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_13 ¸Ê",
		"Image/Dungeon/Dungeon_13_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_14 ¸Ê",
		"Image/Dungeon/Dungeon_14.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_14 ¸Ê",
		"Image/Dungeon/Dungeon_14_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_15 ¸Ê",
		"Image/Dungeon/Dungeon_15.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_15 ¸Ê",
		"Image/Dungeon/Dungeon_15_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_16 ¸Ê",
		"Image/Dungeon/Dungeon_16.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_16 ¸Ê",
		"Image/Dungeon/Dungeon_16_pix.bmp", 160 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_17 ¸Ê",
		"Image/Dungeon/Dungeon_17.bmp", 320 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_17 ¸Ê",
		"Image/Dungeon/Dungeon_17_pix.bmp", 320 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("´øÀü_18 ¸Ê",
		"Image/Dungeon/Dungeon_18.bmp", 320 * 3, 128 * 3, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ ´øÀü_18 ¸Ê",
		"Image/Dungeon/Dungeon_18_pix.bmp", 320 * 3, 128 * 3, true, RGB(255, 0, 255));

	// ¸¶À»¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ¤Ñ

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_1",
		"Image/Map/House_1.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_2",
		"Image/Map/House_2.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_3",
		"Image/Map/House_3.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_4",
		"Image/Map/House_4.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_5",
		"Image/Map/House_5.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_6",
		"Image/Map/House_6.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_7",
		"Image/Map/House_7.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));

	ImageManager::GetSingleton()->AddImage("ÇÈ¼¿ Ãæµ¹ Áý_8",
		"Image/Map/House_8.bmp", WINSIZE_X, WINSIZE_Y - 70, true, RGB(255, 0, 255));



	MapLoad.insert(make_pair(MAP_TYPE::World, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ¿ùµå ¸Ê"),
		ImageManager::GetSingleton()->FindImage("¿ùµå ¸Ê") , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90 } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon1, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_1 ¸Ê"),
		DungeonMap = ImageManager::GetSingleton()->FindImage("´øÀü_1 ¸Ê") , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90 } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon2, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_2 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_2 ¸Ê") , FPOINT{ WINSIZE_X / 2 + 90,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon3, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_3 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_3 ¸Ê") , FPOINT{ WINSIZE_X / 2 + 90,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon4, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_4 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_4 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 90  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon5, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_5 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_5 ¸Ê") , FPOINT{ WINSIZE_X / 2 + 90,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon6, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_6 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_6 ¸Ê") , FPOINT{ WINSIZE_X / 2 - 90,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon7, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_7 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_7 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon8, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_8 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_8 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon9, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_9 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_9 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon10, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_10 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_10 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 90  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon11, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_11 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_11 ¸Ê") , FPOINT{ WINSIZE_X / 2 - 90,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon12, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_12 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_12 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 90  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon13, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_13 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_13 ¸Ê") , FPOINT{ WINSIZE_X / 2 - 90,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon14, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_14 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_14 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 90  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon15, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_15 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_15 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 90 } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon16, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_16 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_16 ¸Ê") , FPOINT{ WINSIZE_X / 2 ,WINSIZE_Y / 2 + 90 } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon17, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_17 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_17 ¸Ê") , FPOINT{ WINSIZE_X / 2 + 90,WINSIZE_Y / 2  } }));
	MapLoad.insert(make_pair(MAP_TYPE::Dungeon18, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ ´øÀü_18 ¸Ê"),
		ImageManager::GetSingleton()->FindImage("´øÀü_18 ¸Ê") , FPOINT{ WINSIZE_X / 2 + 90,WINSIZE_Y / 2  } }));

	MapLoad.insert(make_pair(MAP_TYPE::House1, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_1"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90 } }));
	MapLoad.insert(make_pair(MAP_TYPE::House2, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_2"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90 } }));
	MapLoad.insert(make_pair(MAP_TYPE::House3, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_3"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90 } }));
	MapLoad.insert(make_pair(MAP_TYPE::House4, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_4"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90} }));
	MapLoad.insert(make_pair(MAP_TYPE::House5, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_5"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90} }));
	MapLoad.insert(make_pair(MAP_TYPE::House6, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_6"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90} }));
	MapLoad.insert(make_pair(MAP_TYPE::House7, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_7"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90} }));
	MapLoad.insert(make_pair(MAP_TYPE::House8, startPos{ ImageManager::GetSingleton()->FindImage("ÇÈ¼¿ Ãæµ¹ Áý_8"), nullptr , FPOINT{ WINSIZE_X / 2,WINSIZE_Y / 2 + 90} }));



	play = new player();
	play->Init();
	FPOINT playerpos = MapLoad[currPixBg].pos;
	playerpos.x = 1680;
	playerpos.y = 4400;
	play->SetPos(playerpos);

	E_mager = new EnemyManager();
	E_mager->Init();

	ED_mager = new EnemyD_Manager();
	ED_mager->Init();

	ED1_mager = new EnemyD1_Manager();
	ED1_mager->Init();

	B_mager = new BossManager();
	B_mager->Init();

	//boss = new Boss();
	//boss->Init(pos);

	boss = B_mager->GetEnemy()[0];

	N_mager = new NpcManager();
	N_mager->Init();

	npc2 = new Npc2();
	npc2->Init(pos);
	npc3 = new Npc3();
	npc3->Init(pos);
	npc4 = new Npc4();
	npc4->Init(pos);
	npc5 = new Npc5();
	npc5->Init(pos);
	npc6 = new Npc6();
	npc6->Init(pos);
	npc7 = new Npc7();
	npc7->Init(pos);

	invinTime = 0;
	invinTime1 = 0;
	invinTime2 = 0;
	invinTime3 = 0;
	invinTime4 = 0;
	invinTime5 = 0;

	stopTimer = 0;

	currPixBg = MAP_TYPE::World;
	play->SetCameraLock(false); // currPixBg != MAP_TYPE::World ==> Ä«¸Þ¶ó Àá±À Ä«¸Þ¶ó »ç¿ëÇÒ‹š´Â false »ç¿ë¾ÈÇÏ¸é true

	startImg = ImageManager::GetSingleton()->AddImage("Å¸ÀÏ¸ÊÅø", "Image/Áý_111.bmp",
		160 * 3, 96 * 3, SAMPLE_TILE_X, SAMPLE_TILE_Y);

	Load();

	return S_OK;
}

void StartScene::Release()
{
	SAFE_RELEASE(bin);
	SAFE_RELEASE(bin2);
	SAFE_RELEASE(play);
	SAFE_RELEASE(npc);
	SAFE_RELEASE(npc2);
	SAFE_RELEASE(npc3);
	SAFE_RELEASE(npc4);
	SAFE_RELEASE(npc5);
	SAFE_RELEASE(npc6);
	SAFE_RELEASE(npc7);
	SAFE_RELEASE(E_mager);
	SAFE_RELEASE(B_mager);
	SAFE_RELEASE(ED_mager);
	SAFE_RELEASE(ED1_mager);

	MainCamera::GetSingleton()->Release();
}

void StartScene::Update()
{
	MainCamera::GetSingleton()->Update();

	if (invinTime >= 0)
	{
		invinTime -= TimerManager::GetSingleton()->GetElapsedTime();
	}
	if (invinTime1 >= 0)
	{
		invinTime1 -= TimerManager::GetSingleton()->GetElapsedTime();
	}
	if (invinTime2 >= 0)
	{
		invinTime2 -= TimerManager::GetSingleton()->GetElapsedTime();
	}
	if (invinTime3 >= 0)
	{
		invinTime3 -= TimerManager::GetSingleton()->GetElapsedTime();
	}
	if (invinTime4 >= 0)
	{
		invinTime4 -= TimerManager::GetSingleton()->GetElapsedTime();
	}
	if (invinTime5 >= 0)
	{
		invinTime5 -= TimerManager::GetSingleton()->GetElapsedTime();
	}

	if (!play->GetCameraLock())
	{
		if (currPixBg == MAP_TYPE::World)
		{
			E_mager->Update();
			N_mager->Update();
		}
		if (currPixBg == MAP_TYPE::Dungeon7)
		{
			ED_mager->Update();
		}
		if (currPixBg == MAP_TYPE::Dungeon8)
		{
			ED1_mager->Update();
		}
	}

	if (play->GetCameraLock())
	{
		if (currPixBg == MAP_TYPE::Dungeon13)
		{
			B_mager->Update();
		}

		if (currPixBg == MAP_TYPE::House2)
		{
			npc2->Update();
		}
		if (currPixBg == MAP_TYPE::House7)
		{
			npc3->Update();
			npc4->Update();
		}
		if (currPixBg == MAP_TYPE::House4)
		{
			npc5->Update();
		}
		if (currPixBg == MAP_TYPE::House5)
		{
			npc6->Update();
		}
		if (currPixBg == MAP_TYPE::House1)
		{
			npc7->Update();
		}
	}



	if (play)
	{

		play->Update();
		/*p_Inven->Update();*/

		// ¸Ê ³»¿¡¼­ ÇÃ·¹ÀÌ¾î, Àû°ú ¸Ê °£ Ãæµ¹
		p_PixColli();
		// ÇÃ·¹ÀÌ¾î <-> Àû °£ Ãæµ¹
		if (!play->GetCameraLock())
		{
			if (currPixBg == MAP_TYPE::World)
			{
				p_eColli();
				p_e1Colli();
				n_PixColli();
				e_PixColli();
				p_ShieldColli();
			}

			if (currPixBg == MAP_TYPE::Dungeon7)
			{
				ed_PixColli();
				p_dColli();
			}
			if (currPixBg == MAP_TYPE::Dungeon8)
			{
				ed1_PixColli();
				p_d1Colli();
			}
		}

		if (play->GetCameraLock())
		{
			if (currPixBg == MAP_TYPE::Dungeon13)
			{
				p_bColli();
				p_b1Colli();
				b_PixColli();
			}
		}

		// ¸Ê <-> ¸Ê ÀÌµ¿ È®ÀÎ (ÇÈ¼¿Ãæµ¹)
		COLORREF color;
		int R, G, B;
		color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
			play->GetPos().x, play->GetPos().y);

		R = GetRValue(color);
		G = GetGValue(color);
		B = GetBValue(color);

		LoadMap(color);

		if (R == 1 && G == 1 && B == 0)
		{
			play->SetmoveSpeed(50);
		}
		else
		{
			play->SetmoveSpeed(300); // ¸¶Áö¸·¿¡ ÀÌ¼Ó 100À¸·Î ¹Ù²Ù±â
		}
	}
	
	if (!play->GetIsAlive())
	{
		SceneManager::GetSingleton()->ChangeScene("DeadEnd");
	}
	else if (boss->GetB_Hp()<=0)
	{
		stopTimer += TimerManager::GetSingleton()->GetElapsedTime();
		if (stopTimer >= 1)
		{
			SceneManager::GetSingleton()->ChangeScene("WinEnd");
		}
	}

}

void StartScene::Render(HDC hdc)
{
	bin->Render(hdc);

	//Ä«¸Þ¶óÀÌµ¿
	if (MapLoad[currPixBg].p_imag)
	{
		//¿ùµå¸Ê ´øÀü¸Ê ·Îµå
		if (play->GetCameraLock())
		{
			MapLoad[currPixBg].p_imag->MapRender(hdc, 0, 0, false, 1, 1);

		}
		else
		{
			FPOINT mainCamPos = MainCamera::GetSingleton()->GetMc_pos();
			MapLoad[currPixBg].p_imag->MapRender(hdc, MainCamera::GetSingleton()->GetMc_pos().x,
				MainCamera::GetSingleton()->GetMc_pos().y, false, 1, 1);
		}
	}
	else
	{
		// Å¸ÀÏ·Îµå(Áý¾È)
		for (int i = 0; i < TILE_X * TILE_Y; i++)
		{
			tileInfo[i].isAlive = true;
			if (tileInfo[i].isAlive)
			{
				startImg->FrameRender(hdc,
					tileInfo[i].rcTile.left,
					tileInfo[i].rcTile.top,
					tileInfo[i].frameX,
					tileInfo[i].frameY, false, 1.025);
			}
		}
	}

	if (!play->GetCameraLock())
	{
		if (currPixBg == MAP_TYPE::World)
		{
			E_mager->Render(hdc);
			N_mager->Render(hdc);
		}
		if (currPixBg == MAP_TYPE::Dungeon7)
		{
			ED_mager->Render(hdc);
		}
		if (currPixBg == MAP_TYPE::Dungeon8)
		{
			ED1_mager->Render(hdc);
		}
	}

	if (play->GetCameraLock())
	{
		if (currPixBg == MAP_TYPE::Dungeon13)
		{
			B_mager->Render(hdc);
		}
		if (currPixBg == MAP_TYPE::House2)
		{
			npc2->Render(hdc);
		}
		if (currPixBg == MAP_TYPE::House7)
		{
			npc3->Render(hdc);
			npc4->Render(hdc);
		}

		if (currPixBg == MAP_TYPE::House4)
		{
			npc5->Render(hdc);
		}
		if (currPixBg == MAP_TYPE::House5)
		{
			npc6->Render(hdc);
		}
		if (currPixBg == MAP_TYPE::House1)
		{
			npc7->Render(hdc);
		}
	}



	bin2->Render(hdc, WINSIZE_X - 481, WINSIZE_Y / 2 + 155);
	if (play)
	{
		play->SetIsAlive(true);
		play->Render(hdc);
	}

}

void StartScene::Load()
{

	if (currPixBg == MAP_TYPE::World)	return;

	int house = ((int)currPixBg) - 1;
	string fileName = "Save/saveMapData";
	fileName += to_string(house) + ".map";
	DWORD readBytes;
	HANDLE hFile = CreateFile(fileName.c_str(), GENERIC_READ, 0,
		0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (ReadFile(hFile, tileInfo, sizeof(TILE_INFO) * TILE_X * TILE_Y,
		&readBytes, NULL))
	{

	}
	else
	{
		MessageBox(g_hWnd, "ÀúÀåÆÄÀÏ ·Îµå ½ÇÆÐ", "½ÇÆÐ", MB_OK);
	}
	for (int i = 0; i < TILE_X * TILE_Y; i++)
	{
		tileInfo[i].rcTile.left *= 1;
		tileInfo[i].rcTile.top *= 1;
		tileInfo[i].rcTile.right *= 1;
		tileInfo[i].rcTile.bottom *= 1;
	}
	CloseHandle(hFile);
}

void StartScene::p_PixColli()
{
	//+, - , - +

	COLORREF color;
	int R, G, B, delta;
	float currPos;

	switch (play->GetPlayerSee())
	{
	case playerSee::DOWN:
		delta = 1;
		currPos = play->GetRC().bottom;
		break;
	case playerSee::UP:
		delta = -1;
		currPos = play->GetRC().top;
		break;
	case playerSee::LEFT:
		delta = -1;
		currPos = play->GetRC().left;
		break;
	case playerSee::RIGHT:
		delta = 1;
		currPos = play->GetRC().right;
		break;
	}

	for (int i = currPos - delta * 2; (delta > 0 && i < currPos + delta * 2) || (delta < 0 && i > currPos + delta * 2); i += delta)
	{
		for (int j = -1; j < 2; j++)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
			case playerSee::UP:
				color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
					play->GetPos().x + ((play->GetRC().right - play->GetRC().left) / 2) * j, i);
				break;
			case playerSee::LEFT:
			case playerSee::RIGHT:
				color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
					i, play->GetPos().y + ((play->GetRC().bottom - play->GetRC().top) / 2) * j);
				break;
			}
			R = GetRValue(color);
			G = GetGValue(color);
			B = GetBValue(color);

			if (R == 77 && G == 253 && B == 252)
			{
				// À§Ä¡ °íÁ¤
				FPOINT pos = play->GetPos();
				switch (play->GetPlayerSee())

				{
				case playerSee::DOWN:
					pos.x = play->GetPos().x;
					pos.y -= 2;
					break;
				case playerSee::UP:
					pos.x = play->GetPos().x;
					pos.y += 2;
					break;
				case playerSee::LEFT:
					pos.x += 2;
					pos.y = play->GetPos().y;
					break;
				case playerSee::RIGHT:
					pos.x -= 2;
					pos.y = play->GetPos().y;
					break;
				}
				play->Push();
				play->SetPos(pos);
				return;
			}
		}
	}
}

void StartScene::e_PixColli()
{
	//+, - , - +

	COLORREF color;
	int R, G, B, delta;
	float currE_Pos;
	vector<Enemy*>enemys = E_mager->GetEnemy();
	vector<Enemy1*>enemys1 = E_mager->GetEnemy1();

	for (Enemy* enemy : enemys)
	{

		switch (enemy->GetEnemySee())
		{
		case EnemySee::DOWN:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = enemy->GetE_Pos().y + 20;
			break;
		case EnemySee::UP:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = enemy->GetE_Pos().y - 20;
			break;
		case EnemySee::LEFT:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = enemy->GetE_Pos().x - 20;
			break;
		case EnemySee::RIGHT:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = enemy->GetE_Pos().x + 20;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (enemy->GetEnemySee())
				{
				case EnemySee::DOWN:
				case EnemySee::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						enemy->GetE_Pos().x + ((enemy->GetE_RC().right - enemy->GetE_RC().left) / 2) * j, i);
					break;
				case EnemySee::LEFT:
				case EnemySee::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, enemy->GetE_Pos().y + ((enemy->GetE_RC().bottom - enemy->GetE_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E_pos = enemy->GetE_Pos();
					switch (enemy->GetEnemySee())

					{
					case EnemySee::DOWN:
						E_pos.x = enemy->GetE_Pos().x;
						E_pos.y -= 2;
						break;
					case EnemySee::UP:
						E_pos.x = enemy->GetE_Pos().x;
						E_pos.y += 2;
						break;
					case EnemySee::LEFT:
						E_pos.x += 2;
						E_pos.y = enemy->GetE_Pos().y;
						break;
					case EnemySee::RIGHT:
						E_pos.x -= 2;
						E_pos.y = enemy->GetE_Pos().y;
						break;
					}
					enemy->SetPos(E_pos);
					return;
				}
			}
		}
	}


	for (Enemy1* enemy1 : enemys1)
	{

		switch (enemy1->GetEnemySee1())
		{
		case EnemySee1::DOWN:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = enemy1->GetE1_Pos().y + 20;
			break;
		case EnemySee1::UP:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = enemy1->GetE1_Pos().y - 20;
			break;
		case EnemySee1::LEFT:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = enemy1->GetE1_Pos().x - 20;
			break;
		case EnemySee1::RIGHT:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = enemy1->GetE1_Pos().x + 20;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (enemy1->GetEnemySee1())
				{
				case EnemySee1::DOWN:
				case EnemySee1::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						enemy1->GetE1_Pos().x + ((enemy1->GetE1_RC().right - enemy1->GetE1_RC().left) / 2) * j, i);
					break;
				case EnemySee1::LEFT:
				case EnemySee1::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, enemy1->GetE1_Pos().y + ((enemy1->GetE1_RC().bottom - enemy1->GetE1_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E1_pos = enemy1->GetE1_Pos();
					switch (enemy1->GetEnemySee1())

					{
					case EnemySee1::DOWN:
						E1_pos.x = enemy1->GetE1_Pos().x;
						E1_pos.y -= 2;
						break;
					case EnemySee1::UP:
						E1_pos.x = enemy1->GetE1_Pos().x;
						E1_pos.y += 2;
						break;
					case EnemySee1::LEFT:
						E1_pos.x += 2;
						E1_pos.y = enemy1->GetE1_Pos().y;
						break;
					case EnemySee1::RIGHT:
						E1_pos.x -= 2;
						E1_pos.y = enemy1->GetE1_Pos().y;
						break;
					}
					enemy1->SetPos1(E1_pos);
					return;
				}
			}
		}
	}
}

void StartScene::n_PixColli()
{
	//+, - , - +

	COLORREF color;
	int R, G, B, delta;
	float currE_Pos;
	vector<Npc*>Npcs = N_mager->GetNpc();
	vector<Npc1*>Npcs1 = N_mager->GetNpc1();

	for (Npc* npc : Npcs)
	{

		switch (npc->GetNpcSee())
		{
		case NpcSee::DOWN:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = npc->GetN_Pos().y + 20;
			break;
		case NpcSee::UP:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = npc->GetN_Pos().y - 20;
			break;
		case NpcSee::LEFT:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = npc->GetN_Pos().x - 20;
			break;
		case NpcSee::RIGHT:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = npc->GetN_Pos().x + 20;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (npc->GetNpcSee())
				{
				case NpcSee::DOWN:
				case NpcSee::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						npc->GetN_Pos().x + ((npc->GetN_RC().right - npc->GetN_RC().left) / 2) * j, i);
					break;
				case NpcSee::LEFT:
				case NpcSee::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, npc->GetN_Pos().y + ((npc->GetN_RC().bottom - npc->GetN_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E_pos = npc->GetN_Pos();
					switch (npc->GetNpcSee())
					{
					case NpcSee::DOWN:
						E_pos.x = npc->GetN_Pos().x;
						E_pos.y -= 2;
						break;
					case NpcSee::UP:
						E_pos.x = npc->GetN_Pos().x;
						E_pos.y += 2;
						break;
					case NpcSee::LEFT:
						E_pos.x += 2;
						E_pos.y = npc->GetN_Pos().y;
						break;
					case NpcSee::RIGHT:
						E_pos.x -= 2;
						E_pos.y = npc->GetN_Pos().y;
						break;
					}
					npc->SetPosN(E_pos);
					return;
				}
			}
		}
	}


	for (Npc1* npc1 : Npcs1)
	{

		switch (npc1->GetNpcSee1())
		{
		case NpcSee1::DOWN:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = npc1->GetN1_Pos().y + 20;
			break;
		case NpcSee1::UP:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = npc1->GetN1_Pos().y - 20;
			break;
		case NpcSee1::LEFT:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = npc1->GetN1_Pos().x - 20;
			break;
		case NpcSee1::RIGHT:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = npc1->GetN1_Pos().x + 20;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (npc1->GetNpcSee1())
				{
				case NpcSee1::DOWN:
				case NpcSee1::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						npc1->GetN1_Pos().x + ((npc1->GetN1_RC().right - npc1->GetN1_RC().left) / 2) * j, i);
					break;
				case NpcSee1::LEFT:
				case NpcSee1::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, npc1->GetN1_Pos().y + ((npc1->GetN1_RC().bottom - npc1->GetN1_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E1_pos = npc1->GetN1_Pos();
					switch (npc1->GetNpcSee1())

					{
					case NpcSee1::DOWN:
						E1_pos.x = npc1->GetN1_Pos().x;
						E1_pos.y -= 2;
						break;
					case NpcSee1::UP:
						E1_pos.x = npc1->GetN1_Pos().x;
						E1_pos.y += 2;
						break;
					case NpcSee1::LEFT:
						E1_pos.x += 2;
						E1_pos.y = npc1->GetN1_Pos().y;
						break;
					case NpcSee1::RIGHT:
						E1_pos.x -= 2;
						E1_pos.y = npc1->GetN1_Pos().y;
						break;
					}
					npc1->SetPosN1(E1_pos);
					return;
				}
			}
		}
	}
}

void StartScene::b_PixColli()
{
	//+, - , - +

	COLORREF color;
	int R, G, B, delta;
	float currE_Pos;
	vector<Boss*>bosss = B_mager->GetEnemy();
	vector<Boss1*>bosss1 = B_mager->GetEnemy1();

	for (Boss* boss : bosss)
	{

		switch (boss->GetBossSee())
		{
		case BossSee::DOWN:
			delta = 6;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = boss->GetB_Pos().y + 50;
			break;
		case BossSee::UP:
			delta = -6;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = boss->GetB_Pos().y - 50;
			break;
		case BossSee::LEFT:
			delta = -6;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = boss->GetB_Pos().x - 50;
			break;
		case BossSee::RIGHT:
			delta = 6;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = boss->GetB_Pos().x + 50;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (boss->GetBossSee())
				{
				case BossSee::DOWN:
				case BossSee::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						boss->GetB_Pos().x + ((boss->GetB_RC().right - boss->GetB_RC().left) / 2) * j, i);
					break;
				case BossSee::LEFT:
				case BossSee::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, boss->GetB_Pos().y + ((boss->GetB_RC().bottom - boss->GetB_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E_pos = boss->GetB_Pos();
					switch (boss->GetBossSee())

					{
					case BossSee::DOWN:
						E_pos.x = boss->GetB_Pos().x;
						E_pos.y -= 2;
						break;
					case BossSee::UP:
						E_pos.x = boss->GetB_Pos().x;
						E_pos.y += 2;
						break;
					case BossSee::LEFT:
						E_pos.x += 2;
						E_pos.y = boss->GetB_Pos().y;
						break;
					case BossSee::RIGHT:
						E_pos.x -= 2;
						E_pos.y = boss->GetB_Pos().y;
						break;
					}
					boss->SetPosB(E_pos);
					return;
				}
			}
		}
	}

	for (Boss1* boss1 : bosss1)
	{

		switch (boss1->GetBossSee1())
		{
		case BossSee1::DOWN:
			delta = 6;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = boss1->GetB1_Pos().y + 40;
			break;
		case BossSee1::UP:
			delta = -6;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = boss1->GetB1_Pos().y - 40;
			break;
		case BossSee1::LEFT:
			delta = -6;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = boss1->GetB1_Pos().x - 40;
			break;
		case BossSee1::RIGHT:
			delta = 6;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = boss1->GetB1_Pos().x + 40;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (boss1->GetBossSee1())
				{
				case BossSee1::DOWN:
				case BossSee1::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						boss1->GetB1_Pos().x + ((boss1->GetB1_RC().right - boss1->GetB1_RC().left) / 2) * j, i);
					break;
				case BossSee1::LEFT:
				case BossSee1::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, boss1->GetB1_Pos().y + ((boss1->GetB1_RC().bottom - boss1->GetB1_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E_pos = boss1->GetB1_Pos();
					switch (boss1->GetBossSee1())

					{
					case BossSee1::DOWN:
						E_pos.x = boss1->GetB1_Pos().x;
						E_pos.y -= 2;
						break;
					case BossSee1::UP:
						E_pos.x = boss1->GetB1_Pos().x;
						E_pos.y += 2;
						break;
					case BossSee1::LEFT:
						E_pos.x += 2;
						E_pos.y = boss1->GetB1_Pos().y;
						break;
					case BossSee1::RIGHT:
						E_pos.x -= 2;
						E_pos.y = boss1->GetB1_Pos().y;
						break;
					}
					boss1->SetPosB1(E_pos);
					return;
				}
			}
		}
	}
}

void StartScene::ed_PixColli()
{
	COLORREF color;
	int R, G, B, delta;
	float currE_Pos;
	vector<EnemyD*>enemysD = ED_mager->GetEnemy();
	for (EnemyD* enemyD : enemysD)
	{

		switch (enemyD->GetEnemyDSee())
		{
		case EnemyDSee::DOWN:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = enemyD->GetED_Pos().y + 20;
			break;
		case EnemyDSee::UP:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = enemyD->GetED_Pos().y - 20;
			break;
		case EnemyDSee::LEFT:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = enemyD->GetED_Pos().x - 20;
			break;
		case EnemyDSee::RIGHT:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = enemyD->GetED_Pos().x + 20;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (enemyD->GetEnemyDSee())
				{
				case EnemyDSee::DOWN:
				case EnemyDSee::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						enemyD->GetED_Pos().x + ((enemyD->GetED_RC().right - enemyD->GetED_RC().left) / 2) * j, i);
					break;
				case EnemyDSee::LEFT:
				case EnemyDSee::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, enemyD->GetED_Pos().y + ((enemyD->GetED_RC().bottom - enemyD->GetED_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252 || R == 0 && G == 0 && B == 59)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E1_pos = enemyD->GetED_Pos();
					switch (enemyD->GetEnemyDSee())

					{
					case EnemyDSee::DOWN:
						E1_pos.x = enemyD->GetED_Pos().x;
						E1_pos.y -= 2;
						break;
					case EnemyDSee::UP:
						E1_pos.x = enemyD->GetED_Pos().x;
						E1_pos.y += 2;
						break;
					case EnemyDSee::LEFT:
						E1_pos.x += 2;
						E1_pos.y = enemyD->GetED_Pos().y;
						break;
					case EnemyDSee::RIGHT:
						E1_pos.x -= 2;
						E1_pos.y = enemyD->GetED_Pos().y;
						break;
					}
					enemyD->SetPos(E1_pos);
					return;
				}
			}
		}
	}

}

void StartScene::ed1_PixColli()
{
	COLORREF color;
	int R, G, B, delta;
	float currE_Pos;
	vector<EnemyD1*>enemysD1 = ED1_mager->GetEnemy();
	for (EnemyD1* enemyD1 : enemysD1)
	{

		switch (enemyD1->GetEnemyDSee1())
		{
		case EnemyDSee1::DOWN:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().bottom;
			currE_Pos = enemyD1->GetED1_Pos().y + 20;
			break;
		case EnemyDSee1::UP:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().top;
			currE_Pos = enemyD1->GetED1_Pos().y - 20;
			break;
		case EnemyDSee1::LEFT:
			delta = -1;
			//currE_Pos = enemy->GetE_RC().left;
			currE_Pos = enemyD1->GetED1_Pos().x - 20;
			break;
		case EnemyDSee1::RIGHT:
			delta = 1;
			//currE_Pos = enemy->GetE_RC().right;
			currE_Pos = enemyD1->GetED1_Pos().x + 20;
			break;
		}

		for (int i = currE_Pos - delta * 2; (delta > 0 && i < currE_Pos + delta * 2) || (delta < 0 && i > currE_Pos + delta * 2); i += delta)
		{
			for (int j = -1; j < 2; j++)
			{
				switch (enemyD1->GetEnemyDSee1())
				{
				case EnemyDSee1::DOWN:
				case EnemyDSee1::UP:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						enemyD1->GetED1_Pos().x + ((enemyD1->GetED1_RC().right - enemyD1->GetED1_RC().left) / 2) * j, i);
					break;
				case EnemyDSee1::LEFT:
				case EnemyDSee1::RIGHT:
					color = GetPixel(MapLoad[currPixBg].imag->GetMemDC(),
						i, enemyD1->GetED1_Pos().y + ((enemyD1->GetED1_RC().bottom - enemyD1->GetED1_RC().top) / 2) * j);
					break;
				}
				R = GetRValue(color);
				G = GetGValue(color);
				B = GetBValue(color);

				if (R == 77 && G == 253 && B == 252 || R == 0 && G == 0 && B == 59)
				{
					// À§Ä¡ °íÁ¤
					FPOINT E1_pos = enemyD1->GetED1_Pos();
					switch (enemyD1->GetEnemyDSee1())

					{
					case EnemyDSee1::DOWN:
						E1_pos.x = enemyD1->GetED1_Pos().x;
						E1_pos.y -= 2;
						break;
					case EnemyDSee1::UP:
						E1_pos.x = enemyD1->GetED1_Pos().x;
						E1_pos.y += 2;
						break;
					case EnemyDSee1::LEFT:
						E1_pos.x += 2;
						E1_pos.y = enemyD1->GetED1_Pos().y;
						break;
					case EnemyDSee1::RIGHT:
						E1_pos.x -= 2;
						E1_pos.y = enemyD1->GetED1_Pos().y;
						break;
					}
					enemyD1->SetPos(E1_pos);
					return;
				}
			}
		}
	}
}

void StartScene::p_eColli()
{
	int Hp = play->GetHp();
	for (int i = 0; i < E_mager->GetEnemy().size(); i++)
	{
		if (RectInRect(play->GetRC(), E_mager->GetEnemy()[i]->GetE_RC()) && invinTime <= 0 && !play->GetisshieldMove())
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				play->SetPos({ play->GetPos().x, play->GetPos().y - 50 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::UP:
				play->SetPos({ play->GetPos().x, play->GetPos().y + 50 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::LEFT:
				play->SetPos({ play->GetPos().x + 50, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::RIGHT:
				play->SetPos({ play->GetPos().x - 50, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			}
		}


		int E_Hp = E_mager->GetEnemy()[i]->GetE_Hp();
		if (RectInRect(play->GetAttRC(), E_mager->GetEnemy()[i]->GetE_RC()) && invinTime1 <= 0)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				E_mager->GetEnemy()[i]->SetPos({ E_mager->GetEnemy()[i]->GetE_Pos().x , E_mager->GetEnemy()[i]->GetE_Pos().y + 50 });
				E_Hp -= 1;
				E_mager->GetEnemy()[i]->SetE_Hp(E_Hp);
				invinTime1 = 2;
				break;
			case playerSee::UP:
				E_mager->GetEnemy()[i]->SetPos({ E_mager->GetEnemy()[i]->GetE_Pos().x , E_mager->GetEnemy()[i]->GetE_Pos().y - 50 });
				E_Hp -= 1;
				E_mager->GetEnemy()[i]->SetE_Hp(E_Hp);
				invinTime1 = 2;
				break;
			case playerSee::LEFT:
				E_mager->GetEnemy()[i]->SetPos({ E_mager->GetEnemy()[i]->GetE_Pos().x - 50 , E_mager->GetEnemy()[i]->GetE_Pos().y });
				E_Hp -= 1;
				E_mager->GetEnemy()[i]->SetE_Hp(E_Hp);
				invinTime1 = 2;
				break;
			case playerSee::RIGHT:
				E_mager->GetEnemy()[i]->SetPos({ E_mager->GetEnemy()[i]->GetE_Pos().x + 50 , E_mager->GetEnemy()[i]->GetE_Pos().y });
				E_Hp -= 1;
				E_mager->GetEnemy()[i]->SetE_Hp(E_Hp);
				invinTime1 = 2;
				break;
			}
		}
	}
}

void StartScene::p_e1Colli()
{
	int Hp = play->GetHp();
	for (int i = 0; i < E_mager->GetEnemy1().size(); i++)
	{
		if (RectInRect(play->GetRC(), E_mager->GetEnemy1()[i]->GetE1_RC()) && invinTime <= 0)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				play->SetPos({ play->GetPos().x, play->GetPos().y - 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::UP:
				play->SetPos({ play->GetPos().x, play->GetPos().y + 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::LEFT:
				play->SetPos({ play->GetPos().x + 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::RIGHT:
				play->SetPos({ play->GetPos().x - 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			}
		}
		int E_Hp = E_mager->GetEnemy1()[i]->GetE1_Hp();
		if (RectInRect(play->GetAttRC(), E_mager->GetEnemy1()[i]->GetE1_RC()) && invinTime2 <= 0)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x , E_mager->GetEnemy1()[i]->GetE1_Pos().y + 50 });
				E_Hp -= 1;
				E_mager->GetEnemy1()[i]->SetE1_Hp(E_Hp);
				invinTime2 = 2;
				break;
			case playerSee::UP:
				E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x , E_mager->GetEnemy1()[i]->GetE1_Pos().y - 50 });
				E_Hp -= 1;
				E_mager->GetEnemy1()[i]->SetE1_Hp(E_Hp);
				invinTime2 = 2;
				break;
			case playerSee::LEFT:
				E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x - 50 , E_mager->GetEnemy1()[i]->GetE1_Pos().y });
				E_Hp -= 1;
				E_mager->GetEnemy1()[i]->SetE1_Hp(E_Hp);
				invinTime2 = 2;
				break;
			case playerSee::RIGHT:
				E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x + 50 , E_mager->GetEnemy1()[i]->GetE1_Pos().y });
				E_Hp -= 1;
				E_mager->GetEnemy1()[i]->SetE1_Hp(E_Hp);
				invinTime2 = 2;
				break;
			}
		}
	}
}

void StartScene::p_dColli()
{
	int Hp = play->GetHp();
	for (int i = 0; i < ED_mager->GetEnemy().size(); i++)
	{
		if (RectInRect(play->GetRC(), ED_mager->GetEnemy()[i]->GetED_RC()) && invinTime <= 0 && !play->GetisshieldMove())
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				play->SetPos({ play->GetPos().x, play->GetPos().y - 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::UP:
				play->SetPos({ play->GetPos().x, play->GetPos().y + 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::LEFT:
				play->SetPos({ play->GetPos().x + 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::RIGHT:
				play->SetPos({ play->GetPos().x - 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			}
		}
		int E_Hp = ED_mager->GetEnemy()[i]->GetED_Hp();
		if (RectInRect(play->GetAttRC(), ED_mager->GetEnemy()[i]->GetED_RC()) && invinTime3 <= 0)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				ED_mager->GetEnemy()[i]->SetPos({ ED_mager->GetEnemy()[i]->GetED_Pos().x , ED_mager->GetEnemy()[i]->GetED_Pos().y + 50 });
				E_Hp -= 1;
				ED_mager->GetEnemy()[i]->SetED_Hp(E_Hp);
				invinTime3 = 2;
				break;
			case playerSee::UP:
				ED_mager->GetEnemy()[i]->SetPos({ ED_mager->GetEnemy()[i]->GetED_Pos().x , ED_mager->GetEnemy()[i]->GetED_Pos().y - 50 });
				E_Hp -= 1;
				ED_mager->GetEnemy()[i]->SetED_Hp(E_Hp);
				invinTime3 = 2;
				break;
			case playerSee::LEFT:
				ED_mager->GetEnemy()[i]->SetPos({ ED_mager->GetEnemy()[i]->GetED_Pos().x - 50 , ED_mager->GetEnemy()[i]->GetED_Pos().y });
				E_Hp -= 1;
				ED_mager->GetEnemy()[i]->SetED_Hp(E_Hp);
				invinTime3 = 2;
				break;
			case playerSee::RIGHT:
				ED_mager->GetEnemy()[i]->SetPos({ ED_mager->GetEnemy()[i]->GetED_Pos().x + 50 , ED_mager->GetEnemy()[i]->GetED_Pos().y });
				E_Hp -= 1;
				ED_mager->GetEnemy()[i]->SetED_Hp(E_Hp);
				invinTime3 = 2;
				break;
			}
		}
	}
}

void StartScene::p_d1Colli()
{
	int Hp = play->GetHp();
	for (int i = 0; i < ED1_mager->GetEnemy().size(); i++)
	{
		if (RectInRect(play->GetRC(), ED1_mager->GetEnemy()[i]->GetED1_RC()) && invinTime <= 0 && !play->GetisshieldMove())
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				play->SetPos({ play->GetPos().x, play->GetPos().y - 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::UP:
				play->SetPos({ play->GetPos().x, play->GetPos().y + 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::LEFT:
				play->SetPos({ play->GetPos().x + 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::RIGHT:
				play->SetPos({ play->GetPos().x - 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			}
		}
		int E_Hp = ED1_mager->GetEnemy()[i]->GetED1_Hp();
		if (RectInRect(play->GetAttRC(), ED1_mager->GetEnemy()[i]->GetED1_RC()) && invinTime4 <= 0)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				ED1_mager->GetEnemy()[i]->SetPos({ ED1_mager->GetEnemy()[i]->GetED1_Pos().x , ED1_mager->GetEnemy()[i]->GetED1_Pos().y + 50 });
				E_Hp -= 1;
				ED1_mager->GetEnemy()[i]->SetED1_Hp(E_Hp);
				invinTime4 = 2;
				break;
			case playerSee::UP:
				ED1_mager->GetEnemy()[i]->SetPos({ ED1_mager->GetEnemy()[i]->GetED1_Pos().x , ED1_mager->GetEnemy()[i]->GetED1_Pos().y - 50 });
				E_Hp -= 1;
				ED1_mager->GetEnemy()[i]->SetED1_Hp(E_Hp);
				invinTime4 = 2;
				break;
			case playerSee::LEFT:
				ED1_mager->GetEnemy()[i]->SetPos({ ED1_mager->GetEnemy()[i]->GetED1_Pos().x - 50 , ED1_mager->GetEnemy()[i]->GetED1_Pos().y });
				E_Hp -= 1;
				ED1_mager->GetEnemy()[i]->SetED1_Hp(E_Hp);
				invinTime4 = 2;
				break;
			case playerSee::RIGHT:
				ED1_mager->GetEnemy()[i]->SetPos({ ED1_mager->GetEnemy()[i]->GetED1_Pos().x + 50 , ED1_mager->GetEnemy()[i]->GetED1_Pos().y });
				E_Hp -= 1;
				ED1_mager->GetEnemy()[i]->SetED1_Hp(E_Hp);
				invinTime4 = 2;
				break;
			}
		}
	}
}

void StartScene::p_bColli()
{
	int Hp = play->GetHp();
	for (int i = 0; i < B_mager->GetEnemy().size(); i++)
	{
		if (RectInRect(play->GetRC(), B_mager->GetEnemy()[i]->GetB_RC()) && invinTime <= 0)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				play->SetPos({ play->GetPos().x, play->GetPos().y - 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::UP:
				play->SetPos({ play->GetPos().x, play->GetPos().y + 5 });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::LEFT:
				play->SetPos({ play->GetPos().x + 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			case playerSee::RIGHT:
				play->SetPos({ play->GetPos().x - 5, play->GetPos().y });
				Hp -= 1;
				play->SetHp(Hp);
				invinTime = 2;
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
				play->SetPlayerState(playerState::HIT);
				break;
			}
		}
		int E_Hp = B_mager->GetEnemy()[i]->GetB_Hp();
		if (RectInRect(play->GetAttRC(), B_mager->GetEnemy()[i]->GetB_RC()) && invinTime5 <= 0)
		{
			switch (play->GetPlayerSee())
			{
			case playerSee::DOWN:
				B_mager->GetEnemy()[i]->SetPosB({ B_mager->GetEnemy()[i]->GetB_Pos().x , B_mager->GetEnemy()[i]->GetB_Pos().y });
				E_Hp -= 1;
				B_mager->GetEnemy()[i]->SetB_Hp(E_Hp);
				invinTime5 = 1;
				boss->SetBossImg(ImageManager::GetSingleton()->FindImage("MidBoss_Hit"));
				boss->SetBossState(BossState::HIT);
				break;
			case playerSee::UP:
				B_mager->GetEnemy()[i]->SetPosB({ B_mager->GetEnemy()[i]->GetB_Pos().x , B_mager->GetEnemy()[i]->GetB_Pos().y });
				E_Hp -= 1;
				B_mager->GetEnemy()[i]->SetB_Hp(E_Hp);
				invinTime5 = 1;
				boss->SetBossImg(ImageManager::GetSingleton()->FindImage("MidBoss_Hit"));
				boss->SetBossState(BossState::HIT);
				break;
			case playerSee::LEFT:
				B_mager->GetEnemy()[i]->SetPosB({ B_mager->GetEnemy()[i]->GetB_Pos().x , B_mager->GetEnemy()[i]->GetB_Pos().y });
				E_Hp -= 1;
				B_mager->GetEnemy()[i]->SetB_Hp(E_Hp);
				invinTime5 = 1;
				boss->SetBossImg(ImageManager::GetSingleton()->FindImage("MidBoss_Hit"));
				boss->SetBossState(BossState::HIT);
				break;
			case playerSee::RIGHT:
				B_mager->GetEnemy()[i]->SetPosB({ B_mager->GetEnemy()[i]->GetB_Pos().x  , B_mager->GetEnemy()[i]->GetB_Pos().y });
				E_Hp -= 1;
				B_mager->GetEnemy()[i]->SetB_Hp(E_Hp);
				invinTime5 = 1;
				boss->SetBossImg(ImageManager::GetSingleton()->FindImage("MidBoss_Hit"));
				boss->SetBossState(BossState::HIT);
				break;
			}
		}
	}
}

void StartScene::p_b1Colli()
{
	if (!play->GetisJump())
	{
		int Hp = play->GetHp();
		for (int i = 0; i < B_mager->GetEnemy1().size(); i++)
		{
			if (RectInRect(play->GetRC(), B_mager->GetEnemy1()[i]->GetB1_RC()) && invinTime <= 0)
			{
				switch (play->GetPlayerSee())
				{
				case playerSee::DOWN:
					play->SetPos({ play->GetPos().x, play->GetPos().y - 5 });
					Hp -= 1;
					play->SetHp(Hp);
					invinTime = 2;
					play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
					play->SetPlayerState(playerState::HIT);
					break;
				case playerSee::UP:
					play->SetPos({ play->GetPos().x, play->GetPos().y + 5 });
					Hp -= 1;
					play->SetHp(Hp);
					invinTime = 2;
					play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
					play->SetPlayerState(playerState::HIT);
					break;
				case playerSee::LEFT:
					play->SetPos({ play->GetPos().x + 5, play->GetPos().y });
					Hp -= 1;
					play->SetHp(Hp);
					invinTime = 2;
					play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
					play->SetPlayerState(playerState::HIT);
					break;
				case playerSee::RIGHT:
					play->SetPos({ play->GetPos().x - 5, play->GetPos().y });
					Hp -= 1;
					play->SetHp(Hp);
					invinTime = 2;
					play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Hit"));
					play->SetPlayerState(playerState::HIT);
					break;
				}
			}
		}
	}
}

void StartScene::p_ShieldColli()
{
	if (play->GetisshieldMove())
	{
		for (int i = 0; i < E_mager->GetEnemy1().size(); i++)
		{
			if (RectInRect(play->GetShieldRC(), E_mager->GetEnemy1()[i]->GetE1_RC()))
			{
				switch (play->GetPlayerSee())
				{
				case playerSee::DOWN:
					E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x , E_mager->GetEnemy1()[i]->GetE1_Pos().y + 1 });

					break;
				case playerSee::UP:
					E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x , E_mager->GetEnemy1()[i]->GetE1_Pos().y - 1 });

					break;
				case playerSee::LEFT:
					E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x - 1 , E_mager->GetEnemy1()[i]->GetE1_Pos().y });

					break;
				case playerSee::RIGHT:
					E_mager->GetEnemy1()[i]->SetPos1({ E_mager->GetEnemy1()[i]->GetE1_Pos().x + 1 , E_mager->GetEnemy1()[i]->GetE1_Pos().y });

					break;
				}
			}
		}

	}
}



void StartScene::LoadMap(COLORREF color)
{
	bool isLoad = false;
	int R, G, B;
	FPOINT moveTargetPos;

	R = GetRValue(color);
	G = GetGValue(color);
	B = GetBValue(color);

	// ÀÌµ¿
	if (R == 0 && G == 0 && B == 1)
	{
		moveTargetPos.x = 1225;
		moveTargetPos.y = 2550;

		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 2)
	{
		moveTargetPos.x = 1225;
		moveTargetPos.y = 2950;

		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 3)
	{
		moveTargetPos.x = 690;
		moveTargetPos.y = 3000;

		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 4)
	{
		moveTargetPos.x = 745;
		moveTargetPos.y = 2500;

		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 5)
	{
		moveTargetPos.x = 650;
		moveTargetPos.y = 2500;

		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 6)
	{
		moveTargetPos.x = 1225;
		moveTargetPos.y = 1800;

		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 7)
	{
		moveTargetPos.x = 1320;
		moveTargetPos.y = 1800;

		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 8)
	{
		currPixBg = MAP_TYPE::House1;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);

		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 9)
	{
		currPixBg = MAP_TYPE::House2;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 10)
	{
		currPixBg = MAP_TYPE::House3;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 11)
	{
		currPixBg = MAP_TYPE::House4;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 12)
	{
		currPixBg = MAP_TYPE::House5;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 13)
	{
		currPixBg = MAP_TYPE::House6;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 14)
	{
		currPixBg = MAP_TYPE::House7;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 15)
	{
		moveTargetPos.x = WINSIZE_X / 2 - 200;
		moveTargetPos.y = WINSIZE_Y / 2 - 50;
		currPixBg = MAP_TYPE::House7;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 16)
	{
		moveTargetPos.x = WINSIZE_X / 2 + 200;
		moveTargetPos.y = WINSIZE_Y / 2 - 50;
		currPixBg = MAP_TYPE::House6;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 0 && G == 0 && B == 16)
	{
		moveTargetPos.x = WINSIZE_X / 2 + 200;
		moveTargetPos.y = WINSIZE_Y / 2 - 50;
		currPixBg = MAP_TYPE::House8;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = true;
	}
	else if (R == 1 && G == 1 && B == 3)
	{
		moveTargetPos.x = WINSIZE_X / 2 + 200;
		moveTargetPos.y = WINSIZE_Y / 2 - 50;
		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 1 && G == 1 && B == 4)
	{
		moveTargetPos.x = 1700;
		moveTargetPos.y = 4000;
		currPixBg = MAP_TYPE::World;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
	}
	else if (R == 0 && G == 0 && B == 17)
	{
		currPixBg = MAP_TYPE::Dungeon1;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);

		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 38)
	{
		moveTargetPos.x = WINSIZE_X / 2;
		moveTargetPos.y = WINSIZE_Y / 2 - 150;
		currPixBg = MAP_TYPE::Dungeon1;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);

		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 59)
	{
		if (!play->GetisJump())
		{
			if (play->GetPlayerState() == playerState::FALL && play->GetIsFinishAnimation() == true)
			{

				currPixBg = MAP_TYPE::Dungeon1;
				play->SetPos(MapLoad[currPixBg].pos);
				play->SetCameraLock(true);
				isLoad = false;
				play->SetPlayerState(playerState::IDLE);
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link"));
				play->SetPlayerCurrFreamX(0);
			}
			else if (play->GetPlayerState() != playerState::FALL)
			{
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Fall"));
				play->SetPlayerState(playerState::FALL);
			}
		}
	}
	else if (R == 0 && G == 0 && B == 41)
	{
		currPixBg = MAP_TYPE::Dungeon4;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 39)
	{
		moveTargetPos.x = WINSIZE_X / 2 - 190;
		moveTargetPos.y = WINSIZE_Y / 2 - 40;
		currPixBg = MAP_TYPE::Dungeon4;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 42)
	{
		moveTargetPos.x = WINSIZE_X / 2 + 190;
		moveTargetPos.y = WINSIZE_Y / 2 - 40;
		currPixBg = MAP_TYPE::Dungeon4;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 21)
	{
		moveTargetPos.x = WINSIZE_X / 2 + 190;
		moveTargetPos.y = WINSIZE_Y / 2 - 40;
		currPixBg = MAP_TYPE::Dungeon5;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 43)
	{
		moveTargetPos.x = WINSIZE_X / 2;
		moveTargetPos.y = WINSIZE_Y / 2 - 160;
		currPixBg = MAP_TYPE::Dungeon5;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 40)
	{
		moveTargetPos.x = +240;
		moveTargetPos.y = +700;
		currPixBg = MAP_TYPE::Dungeon7;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 22)
	{

		moveTargetPos.x = WINSIZE_X / 2 - 190;
		moveTargetPos.y = WINSIZE_Y / 2 - 40;
		currPixBg = MAP_TYPE::Dungeon6;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 44)
	{

		moveTargetPos.x = WINSIZE_X / 2;
		moveTargetPos.y = WINSIZE_Y / 2 - 160;
		currPixBg = MAP_TYPE::Dungeon6;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 23)
	{
		moveTargetPos.x = +1200;
		moveTargetPos.y = +650;
		currPixBg = MAP_TYPE::Dungeon7;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 45)
	{
		moveTargetPos.x = +240;
		moveTargetPos.y = +80;
		currPixBg = MAP_TYPE::Dungeon7;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 47)
	{
		moveTargetPos.x = +1350;
		moveTargetPos.y = +570;
		currPixBg = MAP_TYPE::Dungeon7;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 24)
	{
		moveTargetPos.x = +240;
		moveTargetPos.y = +320;
		currPixBg = MAP_TYPE::Dungeon8;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 46)
	{
		moveTargetPos.x = +100;
		moveTargetPos.y = +140;
		currPixBg = MAP_TYPE::Dungeon8;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(false);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 25 /*|| R == 0 && G == 0 && B == 53  || R == 0 && G == 0 && B == 56*/)
	{
		moveTargetPos.x = +420;
		moveTargetPos.y = +140;
		currPixBg = MAP_TYPE::Dungeon9;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	//else if (R == 0 && G == 0 && B == 26 || R == 0 && G == 0 && B == 53)
	//{
	//	currPixBg = MAP_TYPE::Dungeon17;
	//	play->SetPos(MapLoad[currPixBg].pos);
	//	play->SetCameraLock(false);
	//	isLoad = false;
	//}
	//else if (R == 2 && G == 2 && B == 0)
	//{
	//	currPixBg = MAP_TYPE::Dungeon10;
	//	play->SetPos(MapLoad[currPixBg].pos);
	//	play->SetCameraLock(false);
	//	isLoad = false;
	//}
	else if (R == 0 && G == 0 && B == 27)
	{
		moveTargetPos.x = WINSIZE_X / 2 - 190;
		moveTargetPos.y = WINSIZE_Y / 2 - 40;
		currPixBg = MAP_TYPE::Dungeon11;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 49)
	{
		moveTargetPos.x = WINSIZE_X / 2 + 190;
		moveTargetPos.y = WINSIZE_Y / 2 - 40;
		currPixBg = MAP_TYPE::Dungeon11;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 28)
	{
		currPixBg = MAP_TYPE::Dungeon12;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 29)
	{

		moveTargetPos.x = WINSIZE_X / 2 - 190;
		moveTargetPos.y = WINSIZE_Y / 2 - 40;
		currPixBg = MAP_TYPE::Dungeon13;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 50)
	{
		moveTargetPos.x = WINSIZE_X / 2;
		moveTargetPos.y = WINSIZE_Y / 2 - 170;
		currPixBg = MAP_TYPE::Dungeon13;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 30)
	{
		currPixBg = MAP_TYPE::Dungeon14;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 51 || R == 0 && G == 0 && B == 58)
	{
		moveTargetPos.x = WINSIZE_X / 2;
		moveTargetPos.y = WINSIZE_Y / 2 - 170;
		currPixBg = MAP_TYPE::Dungeon14;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 31)
	{
		currPixBg = MAP_TYPE::Dungeon15;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 52)
	{
		moveTargetPos.x = WINSIZE_X / 2;
		moveTargetPos.y = WINSIZE_Y / 2 - 170;
		currPixBg = MAP_TYPE::Dungeon15;
		play->SetPos(moveTargetPos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 32)
	{
		currPixBg = MAP_TYPE::Dungeon16;
		play->SetPos(MapLoad[currPixBg].pos);
		play->SetCameraLock(true);
		isLoad = false;
	}
	else if (R == 0 && G == 0 && B == 57)
	{

		if (play->GetPlayerState() == playerState::FALL && play->GetIsFinishAnimation() == true)
		{
			moveTargetPos.x = WINSIZE_X / 2 + 20;
			moveTargetPos.y = WINSIZE_Y / 2 - 60;

			currPixBg = MAP_TYPE::Dungeon14;
			play->SetPos(moveTargetPos);
			play->SetCameraLock(true);
			isLoad = false;
			play->SetPlayerState(playerState::IDLE);
			play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link"));
			play->SetPlayerCurrFreamX(0);
		}
		else if (play->GetPlayerState() != playerState::FALL)
		{
			play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Fall"));
			play->SetPlayerState(playerState::FALL);
		}

	}
	else if (R == 1 && G == 1 && B == 1)
	{

		if (!play->GetisJump())
		{
			if (play->GetPlayerState() == playerState::FALL && play->GetIsFinishAnimation() == true)
			{
				moveTargetPos.x = 310;
				moveTargetPos.y = 2000;
				currPixBg = MAP_TYPE::World;
				play->SetPos(moveTargetPos);
				play->SetCameraLock(false);
				isLoad = false;
				play->SetPlayerState(playerState::IDLE);
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link"));
				play->SetPlayerCurrFreamX(0);
			}
			else if (play->GetPlayerState() != playerState::FALL)
			{
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Fall"));
				play->SetPlayerState(playerState::FALL);
			}
		}

	}
	else if (R == 1 && G == 1 && B == 2)
	{
		if (!play->GetisJump())
		{
			if (play->GetPlayerState() == playerState::FALL && play->GetIsFinishAnimation() == true)
			{
				moveTargetPos.x = 290;
				moveTargetPos.y = 3100;
				currPixBg = MAP_TYPE::World;
				play->SetPos(moveTargetPos);
				play->SetCameraLock(false);
				isLoad = false;
				play->SetPlayerState(playerState::IDLE);
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link"));
				play->SetPlayerCurrFreamX(0);
			}
			else if (play->GetPlayerState() != playerState::FALL)
			{
				play->SetPlayerImage(ImageManager::GetSingleton()->FindImage("Link_Fall"));
				play->SetPlayerState(playerState::FALL);
			}
		}
	}

	if (isLoad) Load();
}

// config.h

#pragma once
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "msimg32.lib")

#include <Windows.h>
#include <string>
#include <ctime>
#include <bitset>
#include <map>
#include <vector>

using namespace std;

typedef struct tagFPoint
{
	float x;
	float y;
} FPOINT, * PFPOINT;

#include "KeyManager.h"
#include "ImageManager.h"
#include "TimerManager.h"
#include "SceneManager.h"
#include "MainCamera.h"

#define WINSIZE_X	481
#define WINSIZE_Y	450
#define TILEMAPTOOLSIZE_X	1620
#define TILEMAPTOOLSIZE_Y	900
#define ASTARSIZE_X	1620
#define ASTARSIZE_Y	900

/*
	집 안에 크기 셈플타일 10/6/48 , 메인 10/8
*/

#define SAMPLE_TILE_X	10	
#define SAMPLE_TILE_Y	6	
#define TILESIZE		48

// 메인 그리기 공간 정보
#define	TILE_X			10	//총개수
#define	TILE_Y			8	//총개수


#define PI			3.141592f
#define DegToRad(x)	((x) * PI / 180.0f)
#define SAFE_DELETE(p) { if (p) { delete p; p = nullptr; } }
#define SAFE_RELEASE(p) { if (p) { p->Release(); delete p; p = nullptr; } }

enum TILEOPTION
{
	BRICK, WATER, IRON, GRASS, ICE, COMMANDER, FLAG, BLANK
};



typedef struct tagTile
{
	RECT rcTile;
	int frameX;
	int frameY;
	bool isAlive;
} TILE_INFO;;

//typedef tagFPoint FPOINT2;
//typedef tagFPoint* PFPOINT2;

extern HWND g_hWnd;
extern HINSTANCE g_hInstance;
extern POINT g_ptMouse;
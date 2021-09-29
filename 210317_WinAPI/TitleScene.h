#pragma once
#include "GameNode.h"

class TileMapTool;
class Button;
class Image;
class TitleScene:public GameNode
{
private:
	TileMapTool* tilemapTool;
	Image* titleImage;
	POINT pos;
	int selectMode;
	int currFrame;
	int titleTimer;



public:

	virtual HRESULT Init();
	virtual void Release();
	virtual void Update();
	virtual void Render(HDC hdc);

	POINT GetPos() { return this->pos; }

	virtual ~TitleScene() {};



};


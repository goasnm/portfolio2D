#pragma once
#include "GameNode.h"

class Image;
class player;
class ObjectCamera : public GameNode
{
protected:
	FPOINT C_pos;
	FPOINT C_worldPos;
	RECT C_rc;

	player* play;
	Image* C_img;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	virtual ~ObjectCamera() {};
};


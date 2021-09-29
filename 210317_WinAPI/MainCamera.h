#pragma once
#include "config.h"
#include "Singleton.h"
//#include "ObjectCamera.h"

//class Image;
class MainCamera : public Singleton<MainCamera>
{
	FPOINT Mc_pos;
	RECT Mc_rc;

public:
	HRESULT Init();
	void Release();
	void Update();
	void Render(HDC hdc);

	FPOINT GetMc_pos() { return this->Mc_pos; }
	void SetMc_pos(FPOINT Mc_pos) { this->Mc_pos = Mc_pos; }
};
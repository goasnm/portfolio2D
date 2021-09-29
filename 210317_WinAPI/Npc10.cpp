#include "Npc10.h"
#include "player.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Npc10::Init(FPOINT pos)
{

	N_state = NpcState10::IDLE;
	N_see = NpcSee10::LEFT;

	ImageManager::GetSingleton()->AddImage("OwlNormal", "Image/Npc/Npc_OwlNormal.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	N_image = ImageManager::GetSingleton()->FindImage("OwlNormal");

	if (N_image == nullptr)
	{
		MessageBox(g_hWnd, "Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}

	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;
	N_pos.x = WINSIZE_X / 2;
	N_pos.y = WINSIZE_Y / 2;

	N_pos = pos;

	N_size = 100;
	name = "NormalEnemy";
	N_rc = GetRectToCenter(N_pos.x, N_pos.y, N_size, N_size);

	moveSpeed = 100;		// 보스 이속 500 정도로바꾸기
	N_isAlive = true;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;

	fireCount = 0;

	return S_OK;
}

void Npc10::Release()
{
}

void Npc10::Update()
{
	if (N_isAlive)
	{
		N_rc = GetRectToCenter(N_pos.x, N_pos.y, N_size, N_size);

		if (moveTime > 1)
		{
			N_state = NpcState10::MOVE;
		}
		if (moveTime > 3)
		{
			N_state = NpcState10::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void Npc10::Render(HDC hdc)
{
	if (N_isAlive)
	{
		N_ScreenPos.x = N_pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
		N_ScreenPos.y = N_pos.y - MainCamera::GetSingleton()->GetMc_pos().y;


		if (N_image)
		{
			N_image->FrameRender(hdc, N_ScreenPos.x, N_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B_ScreenPos.x, B_ScreenPos.y, B_size, B_size);
		}
	}
}

void Npc10::Move()
{
	if (N_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (N_image)
		{
			if (N_state == NpcState10::MOVE && N_see == NpcSee10::DOWN)
			{
				//N2_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}

			if (N_state == NpcState10::MOVE && N_see == NpcSee10::UP)
			{
				//N2_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}

			if (N_state == NpcState10::MOVE && N_see == NpcSee10::LEFT)
			{
				//N2_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}

			if (N_state == NpcState10::MOVE && N_see == NpcSee10::RIGHT)
			{
				//N2_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}
		}

	}
}

void Npc10::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (N_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				N_state = NpcState10::MOVE;
				N_see = NpcSee10::DOWN;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("OwlNormal");
				break;
			case 1:
				N_state = NpcState10::MOVE;
				N_see = NpcSee10::UP;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("OwlNormal");
				break;
			case 2:

				N_state = NpcState10::MOVE;
				N_see = NpcSee10::LEFT;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("OwlNormal");
				break;
			case 3:

				N_state = NpcState10::MOVE;
				N_see = NpcSee10::RIGHT;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("OwlNormal");
				break;
			}
			seeTime = 0;

		}
	}
}

void Npc10::Dead()
{
}

void Npc10::HorizonMove()
{
}

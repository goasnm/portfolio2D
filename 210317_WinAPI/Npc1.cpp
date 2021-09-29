#include "Npc1.h"
#include "player.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Npc1::Init(FPOINT pos)
{
	N1_state = NpcState1::IDLE;
	N1_see = NpcSee1::LEFT;

	ImageManager::GetSingleton()->AddImage("Animals_2", "Image/Npc/Npc_Animals_2.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	N1_image = ImageManager::GetSingleton()->FindImage("Animals_2");

	if (N1_image == nullptr)
	{
		MessageBox(g_hWnd, "Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}

	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;
	N1_pos.x = WINSIZE_X / 2;
	N1_pos.y = WINSIZE_Y / 2;

	N1_pos = pos;

	N1_size = 10;
	name = "NormalEnemy";
	N1_rc = GetRectToCenter(N1_pos.x, N1_pos.y, N1_size, N1_size);

	moveSpeed = 10;		// 보스 이속 500 정도로바꾸기
	N1_isAlive = true;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;

	fireCount = 0;

	return S_OK;
}

void Npc1::Release()
{
}

void Npc1::Update()
{
	if (N1_isAlive)
	{
		N1_rc = GetRectToCenter(N1_pos.x, N1_pos.y, N1_size, N1_size);

		if (moveTime > 1)
		{
			N1_state = NpcState1::MOVE;
		}
		if (moveTime > 3)
		{
			N1_state = NpcState1::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void Npc1::Render(HDC hdc)
{
	if (N1_isAlive)
	{
		N1_ScreenPos.x = N1_pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
		N1_ScreenPos.y = N1_pos.y - MainCamera::GetSingleton()->GetMc_pos().y;


		if (N1_image)
		{
			N1_image->FrameRender(hdc, N1_ScreenPos.x, N1_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B_ScreenPos.x, B_ScreenPos.y, B_size, B_size);
		}
	}
}

void Npc1::Move()
{
	if (N1_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (N1_image)
		{
			if (N1_state == NpcState1::MOVE && N1_see == NpcSee1::DOWN)
			{
				N1_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N1_image->GetmaxFrameX();
			}

			if (N1_state == NpcState1::MOVE && N1_see == NpcSee1::UP)
			{
				N1_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N1_image->GetmaxFrameX();
			}

			if (N1_state == NpcState1::MOVE && N1_see == NpcSee1::LEFT)
			{
				N1_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N1_image->GetmaxFrameX();
			}

			if (N1_state == NpcState1::MOVE && N1_see == NpcSee1::RIGHT)
			{
				N1_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N1_image->GetmaxFrameX();
			}
		}

	}
}

void Npc1::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (N1_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				N1_state = NpcState1::MOVE;
				N1_see = NpcSee1::DOWN;
				currFrameX = 0;
				currFrameY = (int)N1_see;

				N1_image = ImageManager::GetSingleton()->FindImage("Animals_2");
				break;
			case 1:
				N1_state = NpcState1::MOVE;
				N1_see = NpcSee1::UP;
				currFrameX = 0;
				currFrameY = (int)N1_see;

				N1_image = ImageManager::GetSingleton()->FindImage("Animals_2");
				break;
			case 2:

				N1_state = NpcState1::MOVE;
				N1_see = NpcSee1::LEFT;
				currFrameX = 0;
				currFrameY = (int)N1_see;

				N1_image = ImageManager::GetSingleton()->FindImage("Animals_2");
				break;
			case 3:

				N1_state = NpcState1::MOVE;
				N1_see = NpcSee1::RIGHT;
				currFrameX = 0;
				currFrameY = (int)N1_see;

				N1_image = ImageManager::GetSingleton()->FindImage("Animals_2");
				break;
			}
			seeTime = 0;

		}

	}
}

void Npc1::Dead()
{
}

void Npc1::HorizonMove()
{
}

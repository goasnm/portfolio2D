#include "Npc5.h"
#include "player.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Npc5::Init(FPOINT pos)
{
	N_state = NpcState5::IDLE;
	N_see = NpcSee5::LEFT;

	ImageManager::GetSingleton()->AddImage("boom", "Image/Npc/Npc_boom.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	N_image = ImageManager::GetSingleton()->FindImage("boom");

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

	return E_NOTIMPL;
}

void Npc5::Release()
{
}

void Npc5::Update()
{
	if (N_isAlive)
	{
		N_rc = GetRectToCenter(N_pos.x, N_pos.y, N_size, N_size);

		if (moveTime > 1)
		{
			N_state = NpcState5::MOVE;
		}
		if (moveTime > 3)
		{
			N_state = NpcState5::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void Npc5::Render(HDC hdc)
{
	if (N_isAlive)
	{
		N_ScreenPos.x = WINSIZE_X / 2;
		N_ScreenPos.y = WINSIZE_Y / 2;


		if (N_image)
		{
			N_image->FrameRender(hdc, N_ScreenPos.x, N_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B_ScreenPos.x, B_ScreenPos.y, B_size, B_size);
		}
	}
}

void Npc5::Move()
{
	if (N_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (N_image)
		{
			if (N_state == NpcState5::MOVE && N_see == NpcSee5::DOWN)
			{
				N_pos.y +=  moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}

			if (N_state == NpcState5::MOVE && N_see == NpcSee5::UP)
			{
				N_pos.y -=  moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}

			if (N_state == NpcState5::MOVE && N_see == NpcSee5::LEFT)
			{
				N_pos.x -=  moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}

			if (N_state == NpcState5::MOVE && N_see == NpcSee5::RIGHT)
			{
				N_pos.x +=  moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N_image->GetmaxFrameX();
			}
		}

	}
}

void Npc5::See()
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
				N_state = NpcState5::MOVE;
				N_see = NpcSee5::DOWN;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("boom");
				break;
			case 1:
				N_state = NpcState5::MOVE;
				N_see = NpcSee5::UP;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("boom");
				break;
			case 2:

				N_state = NpcState5::MOVE;
				N_see = NpcSee5::LEFT;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("boom");
				break;
			case 3:

				N_state = NpcState5::MOVE;
				N_see = NpcSee5::RIGHT;
				currFrameX = 0;
				currFrameY = (int)N_see;

				N_image = ImageManager::GetSingleton()->FindImage("boom");
				break;
			}
			seeTime = 0;

		}
	}
}

void Npc5::Dead()
{
}

void Npc5::HorizonMove()
{
}

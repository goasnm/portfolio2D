#include "Npc4.h"
#include "player.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Npc4::Init(FPOINT pos)
{
	N4_state = NpcState4::IDLE;
	N4_see = NpcSee4::LEFT;

	ImageManager::GetSingleton()->AddImage("Papa", "Image/Npc/Npc_Papa.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	N4_image = ImageManager::GetSingleton()->FindImage("Papa");

	if (N4_image == nullptr)
	{
		MessageBox(g_hWnd, "Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}

	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;
	N4_pos.x = WINSIZE_X / 2;
	N4_pos.y = WINSIZE_Y / 2;

	N4_pos = pos;

	N4_size = 100;
	name = "NormalEnemy";
	N4_rc = GetRectToCenter(N4_pos.x, N4_pos.y, N4_size, N4_size);

	moveSpeed = 100;		// 보스 이속 500 정도로바꾸기
	N4_isAlive = true;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;

	fireCount = 0;

	return S_OK;
}

void Npc4::Release()
{
}

void Npc4::Update()
{
	if (N4_isAlive)
	{
		N4_rc = GetRectToCenter(N4_pos.x, N4_pos.y, N4_size, N4_size);

		if (moveTime > 1)
		{
			N4_state = NpcState4::MOVE;
		}
		if (moveTime > 3)
		{
			N4_state = NpcState4::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void Npc4::Render(HDC hdc)
{
	if (N4_isAlive)
	{
		N4_ScreenPos.x = WINSIZE_X / 2 -20;
		N4_ScreenPos.y = WINSIZE_Y / 2 - 20;


		if (N4_image)
		{
			N4_image->FrameRender(hdc, N4_ScreenPos.x, N4_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B_ScreenPos.x, B_ScreenPos.y, B_size, B_size);
		}
	}
}

void Npc4::Move()
{
	if (N4_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (N4_image)
		{
			if (N4_state == NpcState4::MOVE && N4_see == NpcSee4::DOWN)
			{
				//N2_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N4_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N4_image->GetmaxFrameX();
			}

			if (N4_state == NpcState4::MOVE && N4_see == NpcSee4::UP)
			{
				//N2_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N4_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N4_image->GetmaxFrameX();
			}

			if (N4_state == NpcState4::MOVE && N4_see == NpcSee4::LEFT)
			{
				//N2_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N4_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N4_image->GetmaxFrameX();
			}

			if (N4_state == NpcState4::MOVE && N4_see == NpcSee4::RIGHT)
			{
				//N2_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N4_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N4_image->GetmaxFrameX();
			}
		}

	}
}

void Npc4::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (N4_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				N4_state = NpcState4::MOVE;
				N4_see = NpcSee4::DOWN;
				currFrameX = 0;
				currFrameY = (int)N4_see;

				N4_image = ImageManager::GetSingleton()->FindImage("Papa");
				break;
			case 1:
				N4_state = NpcState4::MOVE;
				N4_see = NpcSee4::UP;
				currFrameX = 0;
				currFrameY = (int)N4_see;

				N4_image = ImageManager::GetSingleton()->FindImage("Papa");
				break;
			case 2:

				N4_state = NpcState4::MOVE;
				N4_see = NpcSee4::LEFT;
				currFrameX = 0;
				currFrameY = (int)N4_see;

				N4_image = ImageManager::GetSingleton()->FindImage("Papa");
				break;
			case 3:

				N4_state = NpcState4::MOVE;
				N4_see = NpcSee4::RIGHT;
				currFrameX = 0;
				currFrameY = (int)N4_see;

				N4_image = ImageManager::GetSingleton()->FindImage("Papa");
				break;
			}
			seeTime = 0;

		}
	}
}

void Npc4::Dead()
{
}

void Npc4::HorizonMove()
{
}

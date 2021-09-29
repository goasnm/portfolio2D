#include "Npc3.h"
#include "player.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Npc3::Init(FPOINT pos)
{
	N3_state = NpcState3::IDLE;
	N3_see = NpcSee3::LEFT;

	ImageManager::GetSingleton()->AddImage("Mama", "Image/Npc/Npc_Mama.bmp", 48 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	N3_image = ImageManager::GetSingleton()->FindImage("Mama");

	if (N3_image == nullptr)
	{
		MessageBox(g_hWnd, "Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}

	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;
	N3_pos.x = WINSIZE_X / 2;
	N3_pos.y = WINSIZE_Y / 2;

	N3_pos = pos;

	N3_size = 100;
	name = "NormalEnemy";
	N3_rc = GetRectToCenter(N3_pos.x, N3_pos.y, N3_size, N3_size);

	moveSpeed = 100;		// 보스 이속 500 정도로바꾸기
	N3_isAlive = true;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;

	fireCount = 0;

	return S_OK;
}

void Npc3::Release()
{
}

void Npc3::Update()
{
	if (N3_isAlive)
	{
		N3_rc = GetRectToCenter(N3_pos.x, N3_pos.y, N3_size, N3_size);

		if (moveTime > 1)
		{
			N3_state = NpcState3::MOVE;
		}
		if (moveTime > 3)
		{
			N3_state = NpcState3::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void Npc3::Render(HDC hdc)
{
	if (N3_isAlive)
	{
		N3_ScreenPos.x = WINSIZE_X / 2 - 180;
		N3_ScreenPos.y = WINSIZE_Y / 2 - 20;


		if (N3_image)
		{
			N3_image->FrameRender(hdc, N3_ScreenPos.x, N3_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B_ScreenPos.x, B_ScreenPos.y, B_size, B_size);
		}
	}
}

void Npc3::Move()
{
	if (N3_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (N3_image)
		{
			if (N3_state == NpcState3::MOVE && N3_see == NpcSee3::DOWN)
			{
				//N2_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N3_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N3_image->GetmaxFrameX();
			}

			if (N3_state == NpcState3::MOVE && N3_see == NpcSee3::UP)
			{
				//N2_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N3_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N3_image->GetmaxFrameX();
			}

			if (N3_state == NpcState3::MOVE && N3_see == NpcSee3::LEFT)
			{
				//N2_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N3_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N3_image->GetmaxFrameX();
			}

			if (N3_state == NpcState3::MOVE && N3_see == NpcSee3::RIGHT)
			{
				//N2_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N3_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N3_image->GetmaxFrameX();
			}
		}

	}
}

void Npc3::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (N3_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				N3_state = NpcState3::MOVE;
				N3_see = NpcSee3::DOWN;
				currFrameX = 0;
				currFrameY = (int)N3_see;

				N3_image = ImageManager::GetSingleton()->FindImage("Mama");
				break;
			case 1:
				N3_state = NpcState3::MOVE;
				N3_see = NpcSee3::UP;
				currFrameX = 0;
				currFrameY = (int)N3_see;

				N3_image = ImageManager::GetSingleton()->FindImage("Mama");
				break;
			case 2:

				N3_state = NpcState3::MOVE;
				N3_see = NpcSee3::LEFT;
				currFrameX = 0;
				currFrameY = (int)N3_see;

				N3_image = ImageManager::GetSingleton()->FindImage("Mama");
				break;
			case 3:

				N3_state = NpcState3::MOVE;
				N3_see = NpcSee3::RIGHT;
				currFrameX = 0;
				currFrameY = (int)N3_see;

				N3_image = ImageManager::GetSingleton()->FindImage("Mama");
				break;
			}
			seeTime = 0;

		}
	}
}

void Npc3::Dead()
{
}

void Npc3::HorizonMove()
{
}

#include "Npc2.h"
#include "player.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Npc2::Init(FPOINT pos)
{
	N2_state = NpcState2::IDLE;
	N2_see = NpcSee2::LEFT;

	ImageManager::GetSingleton()->AddImage("Grandpa", "Image/Npc/Npc_Grandpa.bmp", 32 * 3, 128 * 3, 2, 4, true, RGB(0, 57, 115));
	N2_image = ImageManager::GetSingleton()->FindImage("Grandpa");

	if (N2_image == nullptr)
	{
		MessageBox(g_hWnd, "Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}

	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;
	N2_pos.x = WINSIZE_X / 2;
	N2_pos.y = WINSIZE_Y / 2;

	N2_pos = pos;

	N2_size = 100;
	name = "NormalEnemy";
	N2_rc = GetRectToCenter(N2_pos.x, N2_pos.y, N2_size, N2_size);

	moveSpeed = 100;		// 보스 이속 500 정도로바꾸기
	N2_isAlive = true;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;

	fireCount = 0;

    return S_OK;
}

void Npc2::Release()
{
}

void Npc2::Update()
{
	if (N2_isAlive)
	{
		N2_rc = GetRectToCenter(N2_pos.x, N2_pos.y, N2_size, N2_size);

		if (moveTime > 1)
		{
			N2_state = NpcState2::MOVE;
		}
		if (moveTime > 3)
		{
			N2_state = NpcState2::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void Npc2::Render(HDC hdc)
{
	if (N2_isAlive)
	{
		N2_ScreenPos.x = WINSIZE_X / 2 -30;
		N2_ScreenPos.y = WINSIZE_Y / 2+10;


		if (N2_image)
		{
			N2_image->FrameRender(hdc, N2_ScreenPos.x, N2_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B_ScreenPos.x, B_ScreenPos.y, B_size, B_size);
		}
	}
}

void Npc2::Move()
{
	if (N2_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (N2_image)
		{
			if (N2_state == NpcState2::MOVE && N2_see == NpcSee2::DOWN)
			{
				//N2_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX +=  TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N2_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N2_image->GetmaxFrameX();
			}

			if (N2_state == NpcState2::MOVE && N2_see == NpcSee2::UP)
			{
				//N2_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX +=  TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N2_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N2_image->GetmaxFrameX();
			}

			if (N2_state == NpcState2::MOVE && N2_see == NpcSee2::LEFT)
			{
				//N2_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX +=  TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N2_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N2_image->GetmaxFrameX();
			}

			if (N2_state == NpcState2::MOVE && N2_see == NpcSee2::RIGHT)
			{
				//N2_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX +=  TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= N2_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % N2_image->GetmaxFrameX();
			}
		}

	}
}

void Npc2::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (N2_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				N2_state = NpcState2::MOVE;
				N2_see = NpcSee2::DOWN;
				currFrameX = 0;
				currFrameY = (int)N2_see;

				N2_image = ImageManager::GetSingleton()->FindImage("Grandpa");
				break;
			case 1:
				N2_state = NpcState2::MOVE;
				N2_see = NpcSee2::UP;
				currFrameX = 0;
				currFrameY = (int)N2_see;

				N2_image = ImageManager::GetSingleton()->FindImage("Grandpa");
				break;
			case 2:

				N2_state = NpcState2::MOVE;
				N2_see = NpcSee2::LEFT;
				currFrameX = 0;
				currFrameY = (int)N2_see;

				N2_image = ImageManager::GetSingleton()->FindImage("Grandpa");
				break;
			case 3:

				N2_state = NpcState2::MOVE;
				N2_see = NpcSee2::RIGHT;
				currFrameX = 0;
				currFrameY = (int)N2_see;

				N2_image = ImageManager::GetSingleton()->FindImage("Grandpa");
				break;
			}
			seeTime = 0;

		}
	}
}

void Npc2::Dead()
{
}

void Npc2::HorizonMove()
{
}

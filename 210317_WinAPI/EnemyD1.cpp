#include "EnemyD1.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT EnemyD1::Init(FPOINT pos)
{
	ED1_state = EnemyDState1::IDLE;
	ED1_see = EnemyDSee1::LEFT;

	ImageManager::GetSingleton()->AddImage("skul", "Image/mob/monster_skul.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	ED1_image = ImageManager::GetSingleton()->FindImage("skul");

	if (ED1_image == nullptr)
	{
		MessageBox(g_hWnd,
			"Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}
	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0; 
	ED1_pos.x = WINSIZE_X / 2;
	ED1_pos.y = WINSIZE_Y / 2;

	ED1_pos = pos;

	ED1_size = 30;
	name = "NormalEnemy";
	ED1_rc = GetRectToCenter(ED1_pos.x, ED1_pos.y, ED1_size, ED1_size);

	moveSpeed = 50;
	ED1_isAlive = true;
	ED1_angle = 0.0f;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;


	ED1_maxhp = 5;
	ED1_currhp = 5;


	fireCount = 0;

	return S_OK;
}

void EnemyD1::Release()
{
}

void EnemyD1::Update()
{
	if (ED1_isAlive)
	{
		ED1_rc = GetRectToCenter(ED1_pos.x, ED1_pos.y, ED1_size, ED1_size);

		if (moveTime > 1)
		{
			ED1_state = EnemyDState1::MOVE;
		}
		if (moveTime > 3)
		{
			ED1_state = EnemyDState1::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void EnemyD1::Render(HDC hdc)
{
	if (ED1_isAlive)
	{
		ED1_ScreenPos.x = ED1_pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
		ED1_ScreenPos.y = ED1_pos.y - MainCamera::GetSingleton()->GetMc_pos().y;

		if (ED1_image)
		{
			ED1_image->FrameRender(hdc, ED1_ScreenPos.x, ED1_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, ED1_ScreenPos.x, ED1_ScreenPos.y, ED1_size, ED1_size);
		}
	}
}

void EnemyD1::Move()
{
	if (ED1_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (ED1_image)
		{
			if (ED1_state == EnemyDState1::MOVE && ED1_see == EnemyDSee1::DOWN)
			{
				ED1_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED1_image->GetmaxFrameX();
			}

			if (ED1_state == EnemyDState1::MOVE && ED1_see == EnemyDSee1::UP)
			{
				ED1_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED1_image->GetmaxFrameX();
			}

			if (ED1_state == EnemyDState1::MOVE && ED1_see == EnemyDSee1::LEFT)
			{
				ED1_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED1_image->GetmaxFrameX();
			}

			if (ED1_state == EnemyDState1::MOVE && ED1_see == EnemyDSee1::RIGHT)
			{
				ED1_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED1_image->GetmaxFrameX();
			}
		}

	}
}

void EnemyD1::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (ED1_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				ED1_state = EnemyDState1::MOVE;
				ED1_see = EnemyDSee1::DOWN;
				currFrameX = 0;
				currFrameY = (int)ED1_see;

				ED1_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			case 1:
				ED1_state = EnemyDState1::MOVE;
				ED1_see = EnemyDSee1::UP;
				currFrameX = 0;
				currFrameY = (int)ED1_see;

				ED1_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			case 2:

				ED1_state = EnemyDState1::MOVE;
				ED1_see = EnemyDSee1::LEFT;
				currFrameX = 0;
				currFrameY = (int)ED1_see;

				ED1_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			case 3:

				ED1_state = EnemyDState1::MOVE;
				ED1_see = EnemyDSee1::RIGHT;
				currFrameX = 0;
				currFrameY = (int)ED1_see;

				ED1_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			}
			seeTime = 0;

		}

	}
}

void EnemyD1::Dead()
{
	if (ED1_currhp <= 0)
	{
		ED1_isAlive = false;
	}

}

void EnemyD1::HorizonMove()
{
	if (ED1_pos.x > WINSIZE_X || ED1_pos.x < 0)
	{
		dir *= -1;
	}
	ED1_pos.x += moveSpeed * dir;
}

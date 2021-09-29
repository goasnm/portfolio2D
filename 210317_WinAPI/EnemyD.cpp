#include "EnemyD.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT EnemyD::Init(FPOINT pos)
{
    ED_state = EnemyDState::IDLE;
    ED_see = EnemyDSee::LEFT;

    ImageManager::GetSingleton()->AddImage("skul", "Image/mob/monster_skul.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
    ED_image = ImageManager::GetSingleton()->FindImage("skul");

	if (ED_image == nullptr)
	{
		MessageBox(g_hWnd,
			"Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}
	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;

	ED_pos.x = WINSIZE_X / 2;
	ED_pos.y = WINSIZE_Y / 2;

	ED_pos = pos;

	ED_size = 30;
	name = "NormalEnemy";
	ED_rc = GetRectToCenter(ED_pos.x, ED_pos.y, ED_size, ED_size);

	moveSpeed = 50;
	ED_isAlive = true;
	ED_angle = 0.0f;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;


	ED_maxhp = 5;
	ED_currhp = 5;


	fireCount = 0;


    return E_NOTIMPL;
}

void EnemyD::Release()
{
}

void EnemyD::Update()
{
	if (ED_isAlive)
	{
		ED_rc = GetRectToCenter(ED_pos.x, ED_pos.y, ED_size, ED_size);

		if (moveTime > 1)
		{
			ED_state = EnemyDState::MOVE;
		}
		if (moveTime > 3)
		{
			ED_state = EnemyDState::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void EnemyD::Render(HDC hdc)
{

	if (ED_isAlive)
	{
		ED_ScreenPos.x = ED_pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
		ED_ScreenPos.y = ED_pos.y - MainCamera::GetSingleton()->GetMc_pos().y;

		if (ED_image)
		{
			ED_image->FrameRender(hdc, ED_ScreenPos.x, ED_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, ED_ScreenPos.x, ED_ScreenPos.y, ED_size, ED_size);
		}
	}
}

void EnemyD::Move()
{
	if (ED_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (ED_image)
		{
			if (ED_state == EnemyDState::MOVE && ED_see == EnemyDSee::DOWN)
			{
				ED_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED_image->GetmaxFrameX();
			}

			if (ED_state == EnemyDState::MOVE && ED_see == EnemyDSee::UP)
			{
				ED_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED_image->GetmaxFrameX();
			}

			if (ED_state == EnemyDState::MOVE && ED_see == EnemyDSee::LEFT)
			{
				ED_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED_image->GetmaxFrameX();
			}

			if (ED_state == EnemyDState::MOVE && ED_see == EnemyDSee::RIGHT)
			{
				ED_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= ED_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % ED_image->GetmaxFrameX();
			}
		}

	}
}

void EnemyD::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (ED_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				ED_state = EnemyDState::MOVE;
				ED_see = EnemyDSee::DOWN;
				currFrameX = 0;
				currFrameY = (int)ED_see;

				ED_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			case 1:
				ED_state = EnemyDState::MOVE;
				ED_see = EnemyDSee::UP;
				currFrameX = 0;
				currFrameY = (int)ED_see;

				ED_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			case 2:

				ED_state = EnemyDState::MOVE;
				ED_see = EnemyDSee::LEFT;
				currFrameX = 0;
				currFrameY = (int)ED_see;

				ED_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			case 3:

				ED_state = EnemyDState::MOVE;
				ED_see = EnemyDSee::RIGHT;
				currFrameX = 0;
				currFrameY = (int)ED_see;

				ED_image = ImageManager::GetSingleton()->FindImage("skul");
				break;
			}
			seeTime = 0;

		}

	}
}

void EnemyD::Dead()
{
	if (ED_currhp <= 0)
	{
		ED_isAlive = false;
	}

}

void EnemyD::HorizonMove()
{
	if (ED_pos.x > WINSIZE_X || ED_pos.x < 0)
	{
		dir *= -1;
	}
	ED_pos.x += moveSpeed * dir;
}

#include "Enemy.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Enemy::Init(FPOINT pos)
{
	E_state = EnemyState::IDLE;
	E_see = EnemySee::DOWN;

	ImageManager::GetSingleton()->AddImage("Moblinr", "Image/mob/monste_Moblinr.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	E_image = ImageManager::GetSingleton()->FindImage("Moblinr");



	ImageManager::GetSingleton()->AddImage("Crab", "Image/mob/monste_Crab.bmp", 32 * 3, 16 * 3, 2, 2, true, RGB(0, 57, 115));
	ImageManager::GetSingleton()->FindImage("Crab");

	if (E_image == nullptr)
	{
		MessageBox(g_hWnd,
			"Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}

	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;

	E_pos.x = WINSIZE_X/2;
	E_pos.y = WINSIZE_Y/2;

	E_pos = pos;

	E_size = 10;
	name = "NormalEnemy";
	E_rc = GetRectToCenter(E_pos.x, E_pos.y, E_size, E_size);

	moveSpeed = 50;
	E_isAlive = true;
	E_angle = 0.0f;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;


	E_maxhp = 2;
	E_currhp = 2;


	fireCount = 0;

	return S_OK;
}

void Enemy::Release()
{
}

void Enemy::Update()
{
	if (E_isAlive)
	{
		E_rc = GetRectToCenter(E_pos.x, E_pos.y, E_size, E_size);

		if (moveTime > 1)
		{
			E_state = EnemyState::MOVE;
		}
		if (moveTime > 3)
		{
			E_state = EnemyState::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

	}
}

void Enemy::Render(HDC hdc)
{
	if (E_isAlive)
	{
		E_ScreenPos.x = E_pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
		E_ScreenPos.y = E_pos.y - MainCamera::GetSingleton()->GetMc_pos().y;

		if (E_image)
		{
			E_image->FrameRender(hdc, E_ScreenPos.x, E_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, E_ScreenPos.x, E_ScreenPos.y, E_size, E_size);
		}
	}
}

void Enemy::Move()
{
	if (E_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (E_image)
		{
			if (E_state == EnemyState::MOVE && E_see == EnemySee::DOWN)
			{
				E_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= E_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % E_image->GetmaxFrameX();
			}

			if (E_state == EnemyState::MOVE && E_see == EnemySee::UP)
			{
				E_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= E_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % E_image->GetmaxFrameX();
			}

			if (E_state == EnemyState::MOVE && E_see == EnemySee::LEFT)
			{
				E_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= E_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % E_image->GetmaxFrameX();
			}

			if (E_state == EnemyState::MOVE && E_see == EnemySee::RIGHT)
			{
				E_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= E_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % E_image->GetmaxFrameX();
			}
		}

	}
}

void Enemy::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (E_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				E_state = EnemyState::MOVE;
				E_see = EnemySee::DOWN;
				currFrameX = 0;
				currFrameY = (int)E_see;

				E_image = ImageManager::GetSingleton()->FindImage("Moblinr");
				break;
			case 1:
				E_state = EnemyState::MOVE;
				E_see = EnemySee::UP;
				currFrameX = 0;
				currFrameY = (int)E_see;

				E_image = ImageManager::GetSingleton()->FindImage("Moblinr");
				break;
			case 2:

				E_state = EnemyState::MOVE;
				E_see = EnemySee::LEFT;
				currFrameX = 0;
				currFrameY = (int)E_see;

				E_image = ImageManager::GetSingleton()->FindImage("Moblinr");
				break;
			case 3:

				E_state = EnemyState::MOVE;
				E_see = EnemySee::RIGHT;
				currFrameX = 0;
				currFrameY = (int)E_see;

				E_image = ImageManager::GetSingleton()->FindImage("Moblinr");
				break;
			}
			seeTime = 0;

		}

	}
}

void Enemy::Dead()
{
	if (E_currhp <= 0)
	{
		E_isAlive = false;
	}

}

void Enemy::HorizonMove()
{
	if (E_pos.x > WINSIZE_X || E_pos.x < 0)
	{
		dir *= -1;
	}
	E_pos.x += moveSpeed * dir;
}

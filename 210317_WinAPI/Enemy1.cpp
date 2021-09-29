#include "Enemy1.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Enemy1::Init(FPOINT pos)
{
    E1_state = EnemyState1::IDLE;
    E1_see = EnemySee1::LEFT;

    ImageManager::GetSingleton()->AddImage("Seaurchin", "Image/mob/monste_Seaurchin.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
	E1_image = ImageManager::GetSingleton()->FindImage("Seaurchin");

    if (E1_image == nullptr)
    {
        MessageBox(g_hWnd,
            "Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
        return E_FAIL;
    }
	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;

	E1_pos.x = WINSIZE_X / 2;
	E1_pos.y = WINSIZE_Y / 2;

	E1_pos = pos;

	E1_size = 30;
	name = "NormalEnemy";
	E1_rc = GetRectToCenter(E1_pos.x, E1_pos.y, E1_size, E1_size);

	moveSpeed = 50;
	E1_isAlive = true;
	E1_angle = 0.0f;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;


	E1_maxhp = 1;
	E1_currhp = 1;


	fireCount = 0;

    return S_OK;
}

void Enemy1::Release()
{
}

void Enemy1::Update()
{
	if (E1_isAlive)
	{
		E1_rc = GetRectToCenter(E1_pos.x, E1_pos.y, E1_size, E1_size);

		if (moveTime > 1)
		{
			E1_state = EnemyState1::MOVE;
		}
		if (moveTime > 2)
		{
			E1_state = EnemyState1::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		//Move();

	}
}

void Enemy1::Render(HDC hdc)
{
	if (E1_isAlive)
	{
		E1_ScreenPos.x = E1_pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
		E1_ScreenPos.y = E1_pos.y - MainCamera::GetSingleton()->GetMc_pos().y;

		if (E1_image)
		{
			E1_image->FrameRender(hdc, E1_ScreenPos.x, E1_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, E1_ScreenPos.x, E1_ScreenPos.y, E1_size, E1_size);
		}
	}
}

void Enemy1::Move()
{
	if (E1_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (E1_image)
		{

			if (E1_state == EnemyState1::MOVE && E1_see == EnemySee1::LEFT)
			{
				E1_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= E1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % E1_image->GetmaxFrameX();
			}

			if (E1_state == EnemyState1::MOVE && E1_see == EnemySee1::RIGHT)
			{
				E1_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= E1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % E1_image->GetmaxFrameX();
			}
		}

	}
}

void Enemy1::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (E1_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:

				E1_state = EnemyState1::MOVE;
				E1_see = EnemySee1::LEFT;
				currFrameX = 0;
				currFrameY = (int)E1_see;

				E1_image = ImageManager::GetSingleton()->FindImage("Seaurchin");
				break;
			case 1:

				E1_state = EnemyState1::MOVE;
				E1_see = EnemySee1::RIGHT;
				currFrameX = 0;
				currFrameY = (int)E1_see;

				E1_image = ImageManager::GetSingleton()->FindImage("Seaurchin");
				break;
			}
			seeTime = 0;

		}

	}
}

void Enemy1::Dead()
{
	if (E1_currhp <= 0)
	{
		E1_isAlive = false;
	}

}

void Enemy1::HorizonMove()
{
	if (E1_pos.x > WINSIZE_X || E1_pos.x < 0)
	{
		dir *= -1;
	}
	E1_pos.x += moveSpeed * dir;
}

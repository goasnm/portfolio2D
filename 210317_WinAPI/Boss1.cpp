#include "Boss1.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Boss1::Init(FPOINT pos)
{
    B1_state = BossState1::IDLE;
    B1_see = BossSee1::LEFT;

    ImageManager::GetSingleton()->AddImage("BossBar", "Image/MidBoss/MidBoss_Bar1.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));
    B1_image = ImageManager::GetSingleton()->FindImage("BossBar");

    if (B1_image == nullptr)
    {
        MessageBox(g_hWnd,
            "Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
        return E_FAIL;
    }
    currFrameX = 0;
    currFrameY = 0;
    updateCount = 0;

	B1_pos.x = WINSIZE_X / 2;
	B1_pos.y = WINSIZE_Y / 2;

	B1_pos = pos;

	B1_size = 30;
	name = "NormalEnemy";
	B1_rc = GetRectToCenter(B1_pos.x, B1_pos.y, B1_size, B1_size);

	moveSpeed = 50;
	B1_isAlive = true;
	B1_angle = 0.0f;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;


	B1_maxhp = 1;
	B1_currhp = 1;


	fireCount = 0;

	return S_OK;
}

void Boss1::Release()
{
}

void Boss1::Update()
{
	if (B1_isAlive)
	{
		B1_rc = GetRectToCenter(B1_pos.x, B1_pos.y, B1_size, B1_size);

		if (moveTime > 1)
		{
			B1_state = BossState1::MOVE;
		}
		if (moveTime > 2)
		{
			B1_state = BossState1::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

		//HorizonMove();
	}
}

void Boss1::Render(HDC hdc)
{
	if (B1_isAlive)
	{
		B1_ScreenPos.x = B1_pos.x;
		B1_ScreenPos.y = B1_pos.y;

		if (B1_image)
		{
			B1_image->FrameRender(hdc, B1_ScreenPos.x, B1_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B1_ScreenPos.x, B1_ScreenPos.y, B1_size, B1_size);
		}
	}
}

void Boss1::Move()
{
	if (B1_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (B1_image)
		{

			if (B1_state == BossState1::MOVE && B1_see == BossSee1::LEFT)
			{
				B1_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= B1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % B1_image->GetmaxFrameX();
			}

			if (B1_state == BossState1::MOVE && B1_see == BossSee1::RIGHT)
			{
				B1_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= B1_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % B1_image->GetmaxFrameX();
			}
		}

	}
}

void Boss1::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (B1_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:

				B1_state = BossState1::MOVE;
				B1_see = BossSee1::LEFT;
				currFrameX = 0;
				currFrameY = (int)B1_see;

				B1_image = ImageManager::GetSingleton()->FindImage("BossBar");
				break;
			case 1:

				B1_state = BossState1::MOVE;
				B1_see = BossSee1::RIGHT;
				currFrameX = 0;
				currFrameY = (int)B1_see;

				B1_image = ImageManager::GetSingleton()->FindImage("BossBar");
				break;
			}
			seeTime = 0;

		}

	}
}

void Boss1::Dead()
{
}

void Boss1::HorizonMove()
{
	if (B1_pos.x > WINSIZE_X || B1_pos.x < 0)
	{
		dir *= -1;
	}
	B1_pos.x += moveSpeed * dir;
}

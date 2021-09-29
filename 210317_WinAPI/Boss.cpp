#include "Boss.h"
#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "StartScene.h"
#include <ctime>

HRESULT Boss::Init(FPOINT pos)
{
	B_state = BossState::IDLE;
	B_see = BossSee::LEFT;

	//이미지교체
	ImageManager::GetSingleton()->AddImage("MidBoss", "Image/MidBoss/MidBoss_Move1.bmp", 72 * 3, 128 * 3, 3, 4, true, RGB(0, 57, 115));
	B_image = ImageManager::GetSingleton()->FindImage("MidBoss");

	ImageManager::GetSingleton()->AddImage("MidBoss_Hit", "Image/MidBoss/MidBoss_Hit.bmp", 96 * 3, 128 * 3, 4, 4, true, RGB(0, 57, 115));
	ImageManager::GetSingleton()->FindImage("MidBoss_Hit");

	if (B_image == nullptr)
	{
		MessageBox(g_hWnd,"Enemy에 해당하는 이미지가 추가되지 않았음!", "경고", MB_OK);
		return E_FAIL;
	}
	currFrameX = 0;
	currFrameY = 0;
	updateCount = 0;
	B_pos.x = WINSIZE_X / 2;
	B_pos.y = WINSIZE_Y / 2;

	B_pos = pos;

	B_size = 50;
	name = "NormalEnemy";
	B_rc = GetRectToCenter(B_pos.x, B_pos.y, B_size, B_size);

	moveSpeed = 200;		// 보스 이속 500 정도로바꾸기
	B_isAlive = true;
	B_angle = 0.0f;
	play = nullptr;
	dir = 1;
	seeTime = 0;
	moveTime = 0;

	B_maxhp = 40;
	B_currhp = 40;

	stoptimer = 0;

	fireCount = 0;
    return S_OK;
}

void Boss::Release()
{
}

void Boss::Update()
{
	if (B_isAlive)
	{
		B_rc = GetRectToCenter(B_pos.x, B_pos.y+50, B_size, B_size);

		if (moveTime > 1)
		{
			B_state = BossState::MOVE;
		}
		if (moveTime > 3)
		{
			B_state = BossState::IDLE;
			moveTime = 0;
		}


		Dead();

		See();

		Move();

		switch (B_state)
		{
		case BossState::HIT:
			// 아이템 프레임 x 증가 이후 Idle로 초기화
			currFrameX += 5 * TimerManager::GetSingleton()->GetElapsedTime();
			if (currFrameX >= B_image->GetmaxFrameX())
			{
				currFrameX = 0;
				currFrameY = (int)B_see;
				B_state = BossState::IDLE;
				B_image = ImageManager::GetSingleton()->FindImage("MidBoss");
			}
			break;
		}
	}
}

void Boss::Render(HDC hdc)
{
	if (B_isAlive)
	{
		B_ScreenPos.x = B_pos.x;
		B_ScreenPos.y = B_pos.y;

		if (B_image)
		{
			B_image->FrameRender(hdc, B_ScreenPos.x, B_ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
			//RenderRectToCenter(hdc, B_ScreenPos.x, B_ScreenPos.y, B_size, B_size);
		}
	}
}

void Boss::Move()
{
	if (B_isAlive)
	{
		moveTime += TimerManager::GetSingleton()->GetElapsedTime();

		if (B_image)
		{
			if (B_state == BossState::MOVE && B_see == BossSee::DOWN)
			{
				B_pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= B_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % B_image->GetmaxFrameX();
			}

			if (B_state == BossState::MOVE && B_see == BossSee::UP)
			{
				B_pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= B_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % B_image->GetmaxFrameX();
			}

			if (B_state == BossState::MOVE && B_see == BossSee::LEFT)
			{
				B_pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= B_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % B_image->GetmaxFrameX();
			}

			if (B_state == BossState::MOVE && B_see == BossSee::RIGHT)
			{
				B_pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
				currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
				if (currFrameX >= B_image->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % B_image->GetmaxFrameX();
			}
		}

	}
}

void Boss::See()
{
	seeTime += TimerManager::GetSingleton()->GetElapsedTime();

	if (B_isAlive)
	{
		if (seeTime > 3)
		{
			int random = rand() % 4;
			switch (random)
			{
			case 0:
				B_state = BossState::MOVE;
				B_see = BossSee::DOWN;
				currFrameX = 0;
				currFrameY = (int)B_see;

				B_image = ImageManager::GetSingleton()->FindImage("MidBoss");
				break;
			case 1:
				B_state = BossState::MOVE;
				B_see = BossSee::UP;
				currFrameX = 0;
				currFrameY = (int)B_see;

				B_image = ImageManager::GetSingleton()->FindImage("MidBoss");
				break;
			case 2:

				B_state = BossState::MOVE;
				B_see = BossSee::LEFT;
				currFrameX = 0;
				currFrameY = (int)B_see;

				B_image = ImageManager::GetSingleton()->FindImage("MidBoss");
				break;
			case 3:

				B_state = BossState::MOVE;
				B_see = BossSee::RIGHT;
				currFrameX = 0;
				currFrameY = (int)B_see;

				B_image = ImageManager::GetSingleton()->FindImage("MidBoss");
				break;
			}
			seeTime = 0;
		}
	}
}

void Boss::Dead()
{
	if (B_currhp <= 0)
	{

		stoptimer += TimerManager::GetSingleton()->GetElapsedTime();
		if (stoptimer > 1)
		{
			B_isAlive = false;
		}
	}
	
}

void Boss::HorizonMove()
{
	if (B_pos.x > WINSIZE_X || B_pos.x < 0)
	{
		dir *= -1;
	}
	B_pos.x += moveSpeed * dir;
}


#include "CommonFunction.h"
#include "player.h"
#include "Image.h"
#include "playerUi.h"
#include "Inventory.h"
#include "MainCamera.h"

//유한상태머신 으로 사용

HRESULT player::Init()
{
	state = playerState::IDLE;
	see = playerSee::DOWN;

	ImageManager::GetSingleton()->AddImage("Link_sleep_1", "Image/player/player_sleep_1.bmp", 176 * 3, 16 * 3, 11, 1, true, RGB(0, 57, 115));
	player = ImageManager::GetSingleton()->FindImage("Link_sleep_1");

	ImageManager::GetSingleton()->AddImage("Link", "Image/player/player_NormalMove.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_Hit", "Image/player/player_Hit.bmp", 64 * 3, 64 * 3, 4, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_Jump", "Image/player/player_Jump.bmp", 48 * 3, 64 * 3, 3, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_Push", "Image/player/player_Push.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_Pull", "Image/player/player_Pull.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_ShieldMove", "Image/player/player_ShieldMove.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_UseItem", "Image/player/player_UseItem.bmp", 32 * 3, 64 * 3, 2, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_dead", "Image/player/player_dead.bmp", 80 * 3, 64 * 3, 5, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_Fall", "Image/player/player_Fall.bmp", 48 * 3, 64 * 3, 3, 4, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_Gain", "Image/player/player_Gain.bmp", 32 * 3, 16 * 3, 2, 1, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("Link_DungeonMoveDoor", "Image/player/player_DungeonMoveDoor.bmp", 32 * 3, 16 * 3, 2, 1, true, RGB(0, 57, 115));

	ImageManager::GetSingleton()->AddImage("normalAtt", "Image/player/playerNormalAtt.bmp", 96 * 3.7, 128 * 3.7, 3, 4, true, RGB(0, 57, 115));

	// hp 깍이는지 확인 하기위해 써둔거
	maxhp = 20;
	currhp = 10;

	//p_Imag = new playerUi();
	//p_Imag->Init();
	//p_Imag->Setplayer(this);

	Inven = new Inventory();
	Inven->Init(this);


	pos.x = WINSIZE_X / 2;
	pos.y = WINSIZE_Y / 2;
	size = 30;
	attackValue = 10;
	name = "Link";
	P_rc = GetRectToCenter(pos.x, pos.y, size, size);
	Att_rc = GetRectToCenter(pos.x, pos.y, 100, 100);
	Shield_rc = GetRectToCenter(pos.x, pos.y, 70, 70);
	attPos = { 0,0 };

	moveSpeed = 100;
	currFrameX = 0;
	currFrameY = 0;
	timer = 0;
	stoptimer = 0;
	isAlive = true;

	ScreenPos.x = pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
	ScreenPos.y = pos.y - MainCamera::GetSingleton()->GetMc_pos().y;

	return S_OK;
}

void player::Release()
{
	SAFE_RELEASE(Inven);
}

void player::Update()
{
	Shield_rc = GetRectToCenter(pos.x, pos.y, 70, 70);
	//P_rc = GetRectToCenter(pos.x, pos.y, player->GetFrameWidth(), player->GetFrameHeight());
	if (isAlive)
	{
		Move();
		Dead();

		switch (Inven->SleleWeapon_A())
		{
		case Weapon::SWORD:
			normalAttack('Z');
			break;
		case Weapon::SHIELD:
			shieldMove('Z');
			break;
		case Weapon::MAGICFEATER:
			Jump('Z');
			break;
		}
		switch (Inven->SleleWeapon_D())
		{
		case Weapon::SWORD:
			normalAttack('C');
			break;
		case Weapon::SHIELD:
			shieldMove('C');
			break;
		case Weapon::MAGICFEATER:
			Jump('C');
			break;
		}

		Inven->Update();

		switch (state)
		{
		case playerState::MOVE:
			break;
		case playerState::JUMP:
			break;
		case playerState::ATT:
			break;
		case playerState::FALL:
			// 아이템 프레임 x 증가 이후 Idle로 초기화
			currFrameX += 1.5f * TimerManager::GetSingleton()->GetElapsedTime();
			if (currFrameX >= player->GetmaxFrameX())
			{
				currFrameX = player->GetmaxFrameX();
				currFrameY = (int)see;
				//state = playerState::IDLE;
				//player = ImageManager::GetSingleton()->FindImage("Link");
			}
			break;
		case playerState::ITEM:
		case playerState::SLEEP:
		case playerState::GAIN:
		case playerState::HIT:
			// 아이템 프레임 x 증가 이후 Idle로 초기화
			currFrameX += 1.5f * TimerManager::GetSingleton()->GetElapsedTime();
			if (currFrameX >= player->GetmaxFrameX())
			{
				currFrameX = 0;
				currFrameY = (int)see;
				state = playerState::IDLE;
				player = ImageManager::GetSingleton()->FindImage("Link");
			}
			break;
		case playerState::PUSH:
			currFrameX += 5 * TimerManager::GetSingleton()->GetElapsedTime();
			if (currFrameX >= player->GetmaxFrameX())
			{
				currFrameX = 0;
			}
			break;
		case playerState::PULL:
			break;
		case playerState::SHIELDMOVE:
			break;
		case playerState::SHIELDPUSH:
			break;
		case playerState::DEAD:			
			currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
			if (currFrameX >= player->GetmaxFrameX())
			{
				currFrameX = player->GetmaxFrameX();
				currFrameY = (int)see;
				currFrameX = 4;				
			}
			break;
		case playerState::DEAD_END:
		case playerState::MOVEDOOR:
			break;
		}

		P_rc = GetRectToCenter(pos.x, pos.y, size, size);

		
		if (state == playerState::ATT)
		{
			Att_rc = GetRectToCenter(pos.x, pos.y, 100, 100);
		}
		else
		{

			Att_rc = GetRectToCenter(0, 0, 0, 0);
		}
		cameraPos.x = pos.x - WINSIZE_X / 2;
		cameraPos.y = pos.y - WINSIZE_Y / 2;
		MainCamera::GetSingleton()->SetMc_pos(cameraPos);
	}
}

void player::Render(HDC hdc)
{
	//cmpos = MainCamera::GetSingleton()->GetMc_pos();

	//FPOINT ScreenPos;
	if (isAlive)
	{

		if (isCameraLock)
		{
			ScreenPos.x = pos.x;
			ScreenPos.y = pos.y;
		}
		else
		{
			ScreenPos.x = pos.x - MainCamera::GetSingleton()->GetMc_pos().x;
			ScreenPos.y = pos.y - MainCamera::GetSingleton()->GetMc_pos().y;
		}
		if (player)
		{
			if (state == playerState::ATT || state == playerState::JUMP)
			{
				player->FrameRender(hdc, ScreenPos.x + attPos.x, ScreenPos.y + attPos.y, (int)currFrameX, (int)currFrameY, true);
				//RenderRectToCenter(hdc, ScreenPos.x, ScreenPos.y,50,50);

			}
			else
			{
				player->FrameRender(hdc, ScreenPos.x, ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
				//Rectangle(hdc,shape.left,shape.top,shape.right,shape.bottom);
			}

			if (state == playerState::SHIELDMOVE)
			{
				player->FrameRender(hdc, ScreenPos.x, ScreenPos.y, (int)currFrameX, (int)currFrameY, true);
				//RenderRectToCenter(hdc, ScreenPos.x, ScreenPos.y, 50, 50);
			}

			if (state == playerState::Talk)
			{
				//Rectangle(hdc, P_rc.left, P_rc.top, P_rc.right, P_rc.bottom);
			}
		}
		Inven->Render(hdc);
	}
}


void player::Move()
{
	if (isAlive)
	{
		if (player)
		{
			if (state != playerState::ATT)
			{
				if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_DOWN))
				{
					if ((state == playerState::MOVE || state == playerState::PUSH) && see == playerSee::DOWN)
					{
						if (state == playerState::PUSH)
						{
							player = ImageManager::GetSingleton()->FindImage("Link");
						}
						state = playerState::IDLE;
					}
				}
				else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_DOWN))
				{
					if (state == playerState::IDLE)
					{
						state = playerState::MOVE;
						see = playerSee::DOWN;
						currFrameX = 0;
						currFrameY = (int)see;

						player = ImageManager::GetSingleton()->FindImage("Link");
					}

					if ((state == playerState::MOVE || state == playerState::SHIELDMOVE || state == playerState::JUMP) && see == playerSee::DOWN)
					{
						pos.y += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
						currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
						if (currFrameX >= player->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % player->GetmaxFrameX();
					}
				}

				if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_UP))
				{
					if ((state == playerState::MOVE || state == playerState::PUSH) && see == playerSee::UP)
					{
						if (state == playerState::PUSH)
						{
							player = ImageManager::GetSingleton()->FindImage("Link");
						}
						state = playerState::IDLE;
					}
				}
				else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_UP))
				{
					if (state == playerState::IDLE)
					{
						state = playerState::MOVE;
						see = playerSee::UP;
						currFrameX = 0;
						currFrameY = (int)see;
						player = ImageManager::GetSingleton()->FindImage("Link");
					}

					if ((state == playerState::MOVE || state == playerState::SHIELDMOVE || state == playerState::JUMP) && see == playerSee::UP)
					{
						pos.y -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
						currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
						if (currFrameX >= player->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % player->GetmaxFrameX();
					}
				}

				if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_LEFT))
				{
					if ((state == playerState::MOVE || state == playerState::PUSH) && see == playerSee::LEFT)
					{
						if (state == playerState::PUSH)
						{
							player = ImageManager::GetSingleton()->FindImage("Link");
						}
						state = playerState::IDLE;
					}
				}
				else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_LEFT))
				{
					if (state == playerState::IDLE)
					{
						state = playerState::MOVE;
						see = playerSee::LEFT;
						currFrameX = 0;
						currFrameY = (int)see;
						player = ImageManager::GetSingleton()->FindImage("Link");
					}
					if ((state == playerState::MOVE || state == playerState::SHIELDMOVE || state == playerState::JUMP) && see == playerSee::LEFT)
					{
						pos.x -= moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
						currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
						if (currFrameX >= player->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % player->GetmaxFrameX();
					}
				}

				if (KeyManager::GetSingleton()->IsOnceKeyUp(VK_RIGHT))
				{
					if ((state == playerState::MOVE || state == playerState::PUSH) && see == playerSee::RIGHT)
					{
						if (state == playerState::PUSH)
						{
							player = ImageManager::GetSingleton()->FindImage("Link");
						}
						state = playerState::IDLE;
					}
				}
				else if (KeyManager::GetSingleton()->IsStayKeyDown(VK_RIGHT))
				{
					if (state == playerState::IDLE)
					{
						state = playerState::MOVE;
						see = playerSee::RIGHT;
						currFrameX = 0;
						currFrameY = (int)see;
						player = ImageManager::GetSingleton()->FindImage("Link");
					}
					if ((state == playerState::MOVE || state == playerState::SHIELDMOVE || state == playerState::JUMP) && see == playerSee::RIGHT)
					{
						pos.x += moveSpeed * TimerManager::GetSingleton()->GetElapsedTime();
						currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
						if (currFrameX >= player->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % player->GetmaxFrameX();
					}
				}
			}
		}

	}

}

void player::normalAttack(int key)
{
	if (KeyManager::GetSingleton()->IsOnceKeyUp(key))
	{
		currFrameX = 0;
		state = playerState::IDLE;
		player = ImageManager::GetSingleton()->FindImage("Link");
	}
	else if (KeyManager::GetSingleton()->IsOnceKeyDown(key))
	{
		state = playerState::ATT;
		currFrameX = 0;

		player = ImageManager::GetSingleton()->FindImage("normalAtt");
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(key))
	{
		currFrameX += 10 * TimerManager::GetSingleton()->GetElapsedTime();
		if (currFrameX >= player->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % player->GetmaxFrameX();
		switch (see)
		{
		case playerSee::DOWN:
			attPos.x = -20;
			attPos.y = +30;
			break;
		case playerSee::UP:
			attPos.x = +20;
			attPos.y = -30;
			break;
		case playerSee::LEFT:
			attPos.x = -17;
			attPos.y = -30;
			break;
		case playerSee::RIGHT:
			attPos.x = +17;
			attPos.y = -30;

			break;
		}
	}

}

void player::shieldMove(int key)
{
	Shield_rc = GetRectToCenter(pos.x, pos.y, 80, 80);
	if (KeyManager::GetSingleton()->IsOnceKeyUp(key))
	{
		isshieldMove = false;
		currFrameX = 0;
		state = playerState::IDLE;
		player = ImageManager::GetSingleton()->FindImage("Link");
	}
	else if (KeyManager::GetSingleton()->IsOnceKeyDown(key))
	{
		isshieldMove = true;
		state = playerState::SHIELDMOVE;
		currFrameX = 0;

		player = ImageManager::GetSingleton()->FindImage("Link_ShieldMove");
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(key))
	{
		isshieldMove = true;
		currFrameX += TimerManager::GetSingleton()->GetElapsedTime();
		if (currFrameX >= player->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % player->GetmaxFrameX();
	}
}

void player::Jump(int key)
{
	if (KeyManager::GetSingleton()->IsOnceKeyUp(key))
	{
		isJump = false;
		timer = 0;
		currFrameX = 0;
		state = playerState::IDLE;
		player = ImageManager::GetSingleton()->FindImage("Link");
	}
	else if (KeyManager::GetSingleton()->IsOnceKeyDown(key))
	{
		isJump = true;
		state = playerState::JUMP;
		currFrameX = 0;
		player = ImageManager::GetSingleton()->FindImage("Link_Jump");
	}
	else if (KeyManager::GetSingleton()->IsStayKeyDown(key))
	{
		isJump = true;
		currFrameX += 5 * TimerManager::GetSingleton()->GetElapsedTime();
		timer += TimerManager::GetSingleton()->GetElapsedTime();
		if (currFrameX >= player->GetmaxFrameX()) currFrameX = ((int)(currFrameX)) % player->GetmaxFrameX();

		if (timer >= 2)
		{
			currFrameX = 0;
			currFrameY = (int)see;
			state = playerState::IDLE;
			player = ImageManager::GetSingleton()->FindImage("Link");
		}

		switch (see)
		{
		case playerSee::DOWN:
			attPos.x = 0;
			attPos.y = -15;
			break;
		case playerSee::UP:
			attPos.x = 0;
			attPos.y = -15;
			break;
		case playerSee::LEFT:
			attPos.y = -30;
			break;
		case playerSee::RIGHT:
			attPos.y = -30;
			break;
		}
	}
}

void player::Push()
{
	if (state == playerState::MOVE)
	{
		timer = 0;
		currFrameX = 0;
		state = playerState::PUSH;
		player = ImageManager::GetSingleton()->FindImage("Link_Push");
	}
}


void player::Dead()
{
	if (currhp <= 0)
	{
		state = playerState::DEAD;
		player = ImageManager::GetSingleton()->FindImage("Link_dead");
		IsFinishAni = true;	

		if (GetIsFinishAnimation() )
		{
			stoptimer += TimerManager::GetSingleton()->GetElapsedTime();
			if (stoptimer > 1)
			{
				isAlive = false;
			}
		}
	}
}

void player::SetPlayerImage(Image* player)
{
	this->player = player;
}

bool player::GetIsFinishAnimation()
{
	if (currFrameX <= 0)	
		return false;
	if((int)currFrameX >= player->GetmaxFrameX() - 1)
		return true;

	return false;
}

bool player::GetisFini()
{
	if (currFrameX <= 0)
		return false;
	if ((int)currFrameX >= player->GetmaxFrameX())
		return true;

	return false;
}

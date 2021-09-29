#include "BattleScene.h"
#include "Player.h"
#include "Enemy.h"
#include "EnemyManager.h"
#include "Missile.h"
#include "Image.h"
#include "Iori.h"
#include "CommonFunction.h"


HRESULT BattleScene::Init()
{
	play = new player();
	play->Init();

	enemyMgr = new EnemyManager();
	enemyMgr->Init();

	P_rc = GetRectToCenter(play->GetPos().x, play->GetPos().y, play->GetSize(), play->GetSize());

	return S_OK;
}

void BattleScene::Release()
{
	SAFE_RELEASE(play);
	SAFE_RELEASE(enemyMgr);
}

void BattleScene::Update()
{
}

void BattleScene::Render(HDC hdc)
{

	if (play)
	{
		GetRectToCenter(play->GetPos().x, play->GetPos().y, play->GetSize()+100, play->GetSize()+100);
	}

}

void BattleScene::CheckCollision()
{
	// 利 <-> 攀农 固荤老 
	float distance;
	FPOINT enemyPos;
	FPOINT missilePos;
	float x, y;
	int r1, r2;

	//for (int i = 0; i < enemyCount; i++)
	//{
	//	if (enemy[i].GetIsAlive() == false)	continue;

	//	for (int j = 0; j < tank->GetMissileCount(); j++)
	//	{
	//		if (missileArray[j].GetIsFired() == false)	continue;

	//		enemyPos = enemy[i].GetPos();
	//		missilePos = missileArray[j].GetPos();

	//		x = enemyPos.x - missilePos.x;
	//		y = enemyPos.y - missilePos.y;

	//		distance = sqrtf(x * x + y * y);

	//		r1 = enemy[i].GetSize() / 2;
	//		r2 = missileArray[j].GetSize() / 2;

	//		if (distance <= r1 + r2)
	//		{
	//			enemy[i].SetIsAlive(false);
	//			missileArray[j].SetIsFired(false);
	//			break;
	//		}
	//	}
	//}

	// 利 <-> 攀农

	// 利 固荤老 <-> 攀农

	// 利 固荤老 <-> 攀农 固荤老
}

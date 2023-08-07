#include "CTankEnemy.h"
#include"LessonX.h"

CTankEnemy::CTankEnemy(const char* szName): CWeapon(szName) // 对构造函数进行实现
{
    // m_iDir = 0;
    // m_fSpeedX = 0.f;
    // m_fSpeedY = 0.f;
    // m_iHp = 2;
    iDir=0;
	m_fChangeDirTime=0.f;
	m_fBulletCreateTime=0.f;
}
void CTankEnemy::Init(){
    int iPos = CSystem::RandomRange(0,2);
		float fPosX;
		SetDir(2);
		SetHp(2);
		switch (iPos)
		{
			case 0:
					fPosX = -24.f;
				break;
			case 1:
					fPosX = 0.f ;
				break;
			case 2:
					fPosX = 24.f;
				break;
			default:
					break;
		}
		SetSpritePosition(fPosX,-20.f);
		SetSpriteLinearVelocity(0.f,8.f);
		SetSpriteCollisionActive(1,1); //设置可以接受和发送碰撞
		SetSpriteRotation(float(90*GetDir()));
		SetSpriteWorldLimit(WORLD_LIMIT_NULL,-26, -22, 26, 22);

}
void CTankEnemy::OnMove()
{
        switch (iDir)
        {
                case 0://涓?
					SetSpeedX(0);
					SetSpeedY(-8);
					break;
				case 1://鍙?

					SetSpeedX(8);
					SetSpeedY(0);
					break;
				case 2://涓?

					SetSpeedX(0);
					SetSpeedY(8);
					break;
				case 3://宸?

					SetSpeedX(-8);
					SetSpeedY(0);
					break;
            }

			SetDir(iDir);

			SetSpriteRotation(float(90*GetDir())); //鐢ㄦ柟鍚戝€间箻浜?0寰楀埌绮剧伒鏃嬭浆搴︽暟

			SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());

			if(GetDir()==0 || GetDir()==1  || GetDir()==2)
            {
                iDir = GetDir()+1;
            }
            else //濡傛灉鏂瑰悜鍊肩瓑浜?,璁句负0
            {
                iDir = 0;
            }

}
CTankEnemy::~CTankEnemy()
{
    //dtor
}
void CTankEnemy::OnMove(float fDeltaTime)
{
	m_fChangeDirTime+=fDeltaTime;
	if(m_fChangeDirTime>2.0f)
	{	
			OnMove();
			m_fChangeDirTime = 0.f;
	}
}
void CTankEnemy::OnFire(float fDeltaTime)
{
		m_fBulletCreateTime+=fDeltaTime;
		if(m_fBulletCreateTime>3.0f)
		{
			m_fBulletCreateTime = 0.0f;
			float x,y;
			x = GetSpritePositionX();
			y = GetSpritePositionY();
			switch(GetDir())
			{
			case 0:
				y=y-GetSpriteHeight()/2-1;
				break;
			case 1:
				x=x+GetSpriteWidth()/2+1;	
				break;
			case 2:
				y=y+GetSpriteHeight()/2+1;
				break;
			case 3:
				x=x-GetSpriteWidth()/2-1;
				break;
			}
			g_GameMain.AddBullet(GetDir(),x,y,0);
		}
}


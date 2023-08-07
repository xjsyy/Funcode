# <center>黄金矿工功能介绍</center>

### 随机产生金块、石头和炸弹

![image-20230423183651701](C:\Users\XJSYY\AppData\Roaming\Typora\typora-user-images\image-20230423183651701.png)

```C++
//以石头为例    
for(iRLoop=0;iRLoop<4;iRLoop++){
        iRSize=5;
        char *tmpName3;
        tmpName3 = CSystem::MakeSpriteName("Rock", iRLoop); // 生成石头名字
        CSprite *tmpSprite3 = new CSprite(tmpName3);
        tmpSprite3->CloneSprite("rockTemplate");
        tmpSprite3->SetSpriteWidth(iRSize);  // 设置石头的宽度
        tmpSprite3->SetSpriteHeight(iRSize); // 设置石头的高度
        iRPosX = CSystem::RandomRange(m_fRockBornMinX, m_fRockBornMaxX);
        iRPosY = CSystem::RandomRange(m_fRockBornMinY, m_fRockBornMaxY);
        tmpSprite3->SetSpritePosition(iRPosX, iRPosY);
        tmpSprite3->SetSpriteCollisionReceive(true);
    }
```

### 钩子摆动

![image-20230423183812216](C:\Users\XJSYY\AppData\Roaming\Typora\typora-user-images\image-20230423183812216.png)

```c++
    m_iHookState = 0; 	// 初始情况下使钩子旋转
    m_fHookSpeed = 20.f;
```

### 抓取金块![image-20230423184459274](C:\Users\XJSYY\AppData\Roaming\Typora\typora-user-images\image-20230423184459274.png)

```C++
//钩子与金块的碰撞函数   
if (strcmp(szSrcName, "goldhook") == 0 && strstr(szTarName, "GoldBlock") != NULL)
    {
        m_gotGold=FindGoldSpriteByName(szTarName); // 在golds中查找是否存在对应的金块，并返回CSprite*指针指向该金块
        if (m_gotGold != NULL)
        {
            m_gotGold->SpriteMountToSpriteLinkPoint("goldhook", 2);                      // 将金块锚定在钩子上
            goldHook->SpriteMoveTo(m_fHookStartPosX, m_fHookStartPosY, m_fHookSpeed, 1); // 使钩子向初始位置移动，即回拉
            goldMan->AnimateSpritePlayAnimation("GolderManAnimation3", false);           // 播放拉金块的动作
            m_iHookState = 2;		                                                     //表示金块回拉的状态
        }
    }
```


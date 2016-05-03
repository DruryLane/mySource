﻿#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "GameManager.h"
#include "Box2D/Box2D.h"
#include "BilliardBall.h"

class GameScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(GameScene);

	void doMsgReceived(Ref* obj);
	void tick(float dt);
	bool createBox2dWorld();
		void initBox2dWorld(b2Vec2 g);
		void initBall();
	void initBackGround();
	void initCue();
	
	~GameScene();

	virtual void onEnter();
	virtual void onExit();
	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);

	Size winSize;
	b2World* _world;

	BilliardBall* playerBall1;
	BilliardBall* playerBall2;
	BilliardBall* otherBall1;
	BilliardBall* otherBall2;
	Sprite* pCue;
	Sprite* pCueBox;
	Sprite* pCuePower;
	Vec2 force;

	float power;
	float gRotation;
	bool bSelect;
};

#endif // __GAME_SCENE_H__

//
//  PlayerInput.cpp
//  SharkMan
//
//  Created by 张靖 on 15/11/21.
//
//

#include "PlayerInput.h"
#include "Constants.h"
#include "CCMoveBy3D.h"
USING_NS_CC;

PlayerInput::PlayerInput(SharkMan* player)
{
    this->player = player;
}

void PlayerInput::handleTouchBegan(Vec2 position)
{
    this->beganPos = std::move(position);
}

void PlayerInput::handleTouchEnded(Vec2 position)
{
    this->endedPos = std::move(position);
    
    Vec2 diff = endedPos - beganPos;
    diff.normalize();
    auto a = std::move(Vec2(1, 0));
    auto result = Vec2::dot(diff, a);
    
    const int TURN_LEFT = 1;
    const int TURN_RIGHT = 2;
    if (std::abs(result) > ACTION_SLOP) {
        if (result > 0)
        {
            if (player->getSprite3D()->getPositionX() < 10
                && !player->getSprite3D()->getActionByTag(TURN_RIGHT)
                && !player->getSprite3D()->getActionByTag(TURN_LEFT)) {
                auto action = MoveBy3D::create(0.2, Vec3(10, 0, 0), false);
                action->setTag(TURN_RIGHT);
                player->getSprite3D()->runAction(action);
            }
            CCLOG("right");
        } else
        {
            
            if (player->getSprite3D()->getPositionX() > -10
                && !player->getSprite3D()->getActionByTag(TURN_RIGHT)
                && !player->getSprite3D()->getActionByTag(TURN_LEFT)) {
                auto action = MoveBy3D::create(0.2, Vec3(-10, 0, 0), false);
                action->setTag(TURN_LEFT);
                player->getSprite3D()->runAction(action);
            }
            CCLOG("left");
        }
    } else
    {
        if (diff.y > 0)
        {
            CCLOG("up");
        } else
        {
            CCLOG("down");
        }
    }
}
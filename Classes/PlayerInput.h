//
//  PlayerInput.hpp
//  SharkMan
//
//  Created by 张靖 on 15/11/21.
//
//

#ifndef __PLAYER_INPUT_H__
#define __PLAYER_INPUT_H__

#include "cocos2d.h"
#include "SharkMan.h"

class PlayerInput
{
public:
    PlayerInput(SharkMan* player);
    void handleTouchBegan(cocos2d::Vec2 position);
    void handleTouchEnded(cocos2d::Vec2 position);
    
private:
    SharkMan* player;
    cocos2d::Vec2 beganPos;
    cocos2d::Vec2 endedPos;
};

#endif /* __PLAYER_INPUT_H__ */

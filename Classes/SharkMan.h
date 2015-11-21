//
//  SharkMan.hpp
//  SharkMan
//
//  Created by 张靖 on 15/11/15.
//
//

#ifndef __SHARK_MAN_H__
#define __SHARK_MAN_H__

#include <cocos2d.h>

class SharkMan
{
public:
    SharkMan();
    cocos2d::Sprite3D* getSprite3D();
private:
    cocos2d::Sprite3D* sharkMan;
};

#endif /* __SHARK_MAN_H__ */

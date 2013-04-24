//
//  ImageBox.h
//  CCGUI
//
//  Created by CrazyApps on 13-4-21.
//
//

#ifndef __CCGUI__ImageBox__
#define __CCGUI__ImageBox__

#include "Widget.h"

_CCGUI_NAMESPACE_BEGIN

//a widget has an image as background
class ImageBox:public Widget
{
public:
    ImageBox();
    virtual ~ImageBox();
public:
    static ImageBox * create(std::string name);
public:
    virtual void setContentSize(const cocos2d::CCSize &contentSize);
public:
    //sprite texture
    void setBackSprite(cocos2d::CCNode * sprite);
    cocos2d::CCNode * getBackSprite();
private:
    cocos2d::CCNode * m_backSprite;
};

_CCGUI_NAMESPACE_END
#endif 

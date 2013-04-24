//
//  ImageBox.cpp
//  CCGUI
//
//  Created by CrazyApps on 13-4-21.
//
//

#include "ImageBox.h"

using namespace cocos2d;

_CCGUI_NAMESPACE_BEGIN



ImageBox::ImageBox()
{
    TouchNode::setTouchable(false);
}

ImageBox::~ImageBox()
{
    
}

ImageBox * ImageBox::create(std::string name)
{
    ImageBox * box = new ImageBox();
    if(box && box->init()){
        box->setName(name);
        box->autorelease();
        return box;
    }
    delete box;
    return box;
}

void ImageBox::setContentSize(const cocos2d::CCSize &contentSize)
{
    if(m_backSprite){
        m_backSprite->setPosition(CCPointMake(contentSize.width/2, contentSize.height/2));
    }
    Widget::setContentSize(contentSize);
}


void ImageBox::setBackSprite(cocos2d::CCNode * sprite)
{
    assert(sprite->getParent() == NULL);
    if(m_backSprite){
        m_backSprite->removeFromParentAndCleanup(true);
    }
    
    m_backSprite = sprite;
    CCSize size = getContentSize();
    sprite->setPosition(CCPointMake(size.width/2, size.height/2));
    CCNode::addChild(m_backSprite);
}

cocos2d::CCNode * ImageBox::getBackSprite()
{
    return m_backSprite;
}







_CCGUI_NAMESPACE_END





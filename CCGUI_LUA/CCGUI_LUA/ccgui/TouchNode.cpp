//
//  TouchNode.cpp
//  BodhiShoot
//
//  Created by dansen on 13-4-19.
//
//

#include "TouchNode.h"

_CCGUI_NAMESPACE_BEGIN
using namespace cocos2d;


TouchNode::TouchNode():
m_touchable(true),
m_priority(CPRI_NORMAL),
m_living(true)
{
    
}

void TouchNode::setLiving(bool living)
{
    m_living = living;
}

bool TouchNode::isLiving()
{
    return m_living;
}

bool TouchNode::isTouchable()
{
    return m_touchable;
}

void TouchNode::enableTouch(bool enable)
{
    m_touchable = enable;
}

bool TouchNode::containsTouchLocation(CCTouch* touch)
{
    //计算自己的大小（相对于父节点）
    //直接从touch转换成父节点中的坐标
    return this->boundingBox().containsPoint(this->getParent()->convertTouchToNodeSpace(touch));
}

void TouchNode::onEnter()
{
    //reg touch
    CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, m_priority, true);
	CCNode::onEnter();
}

void TouchNode::onExit()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->removeDelegate(this);
	CCNode::onExit();
    setLiving(false);
}


_CCGUI_NAMESPACE_END


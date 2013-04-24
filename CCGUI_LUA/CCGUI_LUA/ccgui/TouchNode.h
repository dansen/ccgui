//
//  TouchNode.h
//  BodhiShoot
//
//  Created by dansen on 13-4-19.
//
//

#ifndef __BodhiShoot__TouchNode__
#define __BodhiShoot__TouchNode__

#include "CCGUIDef.h"
#include "CCGUIObjectZeroInit.h"

_CCGUI_NAMESPACE_BEGIN

enum CCGUIPriority{
    CPRI_LOWEST = -1000,
    CPRI_LOW = -1200,
    CPRI_NORMAL = -1500,
    CPRI_HIGH = -1800,
    CPRI_HIGHEST = -2000
};

class TouchNode : public cocos2d::CCNode,public cocos2d::CCTargetedTouchDelegate, public CCGUIObjectZeroInit
{
public:
    bool isTouchable(); //是否接受点击
    void enableTouch(bool enable);
public:
    virtual void onEnter();
    virtual void onExit();
public:
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent) = 0;
protected:
    bool containsTouchLocation(cocos2d::CCTouch* touch);
public:
    TouchNode();
    //name
    CC_SYNTHESIZE(std::string, m_name, Name);
    //pri
    CC_SYNTHESIZE(int, m_priority, Priority);
private:
    bool m_touchable;
private:
    bool m_living;
public:
    void setLiving(bool living);
    bool isLiving();
};

_CCGUI_NAMESPACE_END


#endif /* defined(__BodhiShoot__TouchNode__) */

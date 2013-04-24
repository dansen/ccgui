//
//  ScrollView.h
//  CCGUI
//
//  Created by CrazyApps on 13-4-20.
//
//

#ifndef __CCGUI__ScrollView__
#define __CCGUI__ScrollView__

#include "cocos-ext.h"
#include "Widget.h"
_CCGUI_NAMESPACE_BEGIN

class ScrollView:public Widget
{
public:
    ScrollView();
    ~ScrollView();
public:
    virtual void touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
public:
    static ScrollView * create(std::string name);
    static ScrollView * create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize);

    virtual void setContentSize(const cocos2d::CCSize &contentSize);
    //canvas size and view offset
    Widget * getCanvas();
    void setCanvas(Widget * canvas);
    
    void setViewOffset(cocos2d::CCPoint point);
    cocos2d::CCPoint getViewOffset();
    //v or h
    void 	setVisibleVScroll(bool _value);
    bool 	isVisibleVScroll();
    void 	setVisibleHScroll(bool _value);
    bool 	isVisibleHScroll();
    void    setDirection(cocos2d::extension::CCScrollViewDirection direction);
protected:
    bool init();
    void updateScrollView();
protected:
    Widget * m_canvas;
    cocos2d::extension::CCScrollView * m_scrollView;
};




_CCGUI_NAMESPACE_END
#endif 

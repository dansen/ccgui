//
//  WidgetManager.h
//  CCGUI
//
//  Created by dansen on 13-4-19.
//
//

#ifndef __CCGUI__WidgetManager__
#define __CCGUI__WidgetManager__

#include "CCGUIDef.h"
#include "CCGUISingleton.h"
_CCGUI_NAMESPACE_BEGIN

class Widget;
class WidgetManager;

Widget * widget_manager_init(cocos2d::CCNode * node, int zorder);
void widget_manager_release();

class WidgetManager:public CCGUISingleton<WidgetManager>
{
public:
    void addTouchWidget(Widget * widget);
    bool touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    void touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
public:
    Widget * init(cocos2d::CCNode * node, int zorder);
    void release();
public:
private:
    CC_SYNTHESIZE_READONLY(Widget *, m_rootWidget, RootWidget);
    //for touch handle
    Widget * m_activeWidget;
    std::list<Widget*> m_touchWidgets;
    typedef std::list<Widget*>::iterator TOUCH_WIDGET_ITR;
};

_CCGUI_NAMESPACE_END
#endif

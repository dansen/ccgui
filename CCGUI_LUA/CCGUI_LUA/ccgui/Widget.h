//
//  Widget.h
//  CCGUI
//
//  Created by dansen on 13-4-19.
//
//

#ifndef __CCGUI__Widget__
#define __CCGUI__Widget__

#include "TouchNode.h"

_CCGUI_NAMESPACE_BEGIN


enum WidgetType{
    WT_WIDGET = 0,
    WT_SCROLL_VIEW = 1,
};

class Widget : public TouchNode
{
public:
    /******************lua module****************/
    //lua touch handle
    void touchBegin(cocos2d::LUA_FUNCTION handle);
    void touchMove(cocos2d::LUA_FUNCTION handle);
    void touchEnd(cocos2d::LUA_FUNCTION handle);
    void touchCancel(cocos2d::LUA_FUNCTION handle);
    //get child
    Widget * get(const char * name);
    /****************end of lua module***********/
public:
    Widget * getChild(const char * name);
public:
    bool isFrontable(); //是否需要在点击时前置
    void enableFront(bool enable);
public:
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    //for manager call back
    virtual void touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
protected:
    Widget();
public:
    virtual ~Widget();
public:
    static Widget * create(std::string name);
    static Widget * create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize);
public:
    virtual void release();
public:
    virtual void setPosition (const cocos2d::CCPoint &position);
    virtual void setContentSize(const cocos2d::CCSize &contentSize);
    virtual void setTreeLevel(int level);
    int getTreeLevel();
    bool isChildOf(Widget * parent);
    //add child
    virtual void addWidget(Widget * child);
    virtual void removeWidget(Widget* child);
    virtual void clearWidgets();
    void replaceWidget(Widget * oldWidget, Widget * newWidget);
    virtual void active();
protected:
    bool init();
    void reorderWidgets();
    void active(Widget * child);
protected:
    WidgetType m_type;
private:
    //
    bool m_frontable;
    //
#ifdef CCGUI_DEBUG
    cocos2d::CCLayerGradient * m_backLayer;
#endif
    
    int m_treeLevel;
    CC_SYNTHESIZE(Widget * , m_parentWidget, ParentWidget);
    std::list<Widget *> m_children;
    typedef std::list<Widget *>::iterator CHILDREN_ITR;
    //touch handle
    cocos2d::LUA_FUNCTION m_luaTouchBeginHandle;
    cocos2d::LUA_FUNCTION m_luaTouchMoveHandle;
    cocos2d::LUA_FUNCTION m_luaTouchEndHandle;
    cocos2d::LUA_FUNCTION m_luaTouchCancelHandle;
};

_CCGUI_NAMESPACE_END

#endif 

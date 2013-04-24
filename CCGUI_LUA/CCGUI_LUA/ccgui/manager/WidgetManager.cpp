//
//  WidgetManager.cpp
//  CCGUI
//
//  Created by dansen on 13-4-19.
//
//

#include "WidgetManager.h"
#include "Widget.h"
using namespace cocos2d;

_CCGUI_NAMESPACE_BEGIN


Widget * widget_manager_init(cocos2d::CCNode * node, int zorder)
{
    return WidgetManager::sharedMgr()->init(node, zorder);
}

void widget_manager_release()
{
    WidgetManager::sharedMgr()->release();
}

void WidgetManager::addTouchWidget(Widget * widget)
{
    m_touchWidgets.push_back(widget);
}

bool WidgetManager::touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(m_touchWidgets.size() == 0){
        return false;
    }
    if(m_touchWidgets.size() == 1){
        m_activeWidget = *m_touchWidgets.begin();
        m_touchWidgets.erase(m_touchWidgets.begin());
        m_activeWidget->touchBegin(pTouch, pEvent);
        //bring his parents to top
        Widget * parent = m_activeWidget;
        while(parent != m_rootWidget){
            parent->active();
            parent = parent->getParentWidget();
        }
        
        return true;
    }
    
    m_activeWidget = *m_touchWidgets.begin();
    m_touchWidgets.erase(m_touchWidgets.begin());
    
    while(m_touchWidgets.size() > 0){
        Widget * cp = *m_touchWidgets.begin();
        assert(m_activeWidget != cp);
        m_touchWidgets.erase(m_touchWidgets.begin());
        //compare cp and active
        Widget * tac = m_activeWidget;
        Widget * tcp = cp;
        //equal
        while(tcp->getTreeLevel() > m_activeWidget->getTreeLevel()){
            tcp = tcp->getParentWidget();
        }

        while(tac->getTreeLevel() > cp->getTreeLevel()){
            tac = tac->getParentWidget();
        }
        //get up
        while(tcp->getParentWidget() != tac->getParentWidget()){
            tcp = tcp->getParentWidget();
            tac = tac->getParentWidget();
        }
        //ok,now tcp and tac is the left and right node
        //compare zorder
        if(tcp == tac){
            if(m_activeWidget->isChildOf(cp)){
                
            }else{
                m_activeWidget = cp;
            }
        }else{
            if(tac->getZOrder() < tcp->getZOrder()){
                m_activeWidget = cp;
            }else if(tac->getZOrder() == tcp->getZOrder()){
                printf("warning:set the zorder!\n");
            }
        }
        
    }
    
    m_activeWidget->touchBegin(pTouch, pEvent);
    
    if(!m_activeWidget->isLiving()){
        m_activeWidget = NULL;
    }else{
        //bring his parents to top
        Widget * parent = m_activeWidget;
        while(parent != m_rootWidget){
            parent->active();
            parent = parent->getParentWidget();
        }
    }
    
    return true;
}

void WidgetManager::touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(!m_activeWidget){
        return;
    }
    
    if(!m_activeWidget->isLiving()){
        m_activeWidget = NULL;
        return;
    }
    
    m_activeWidget->touchEnd(pTouch, pEvent);
    m_activeWidget = 0;
}

void WidgetManager::touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(!m_activeWidget){
        return;
    }
    
    if(!m_activeWidget->isLiving()){
        m_activeWidget = NULL;
        return;
    }
    
    m_activeWidget->touchCancelled(pTouch, pEvent);
}

void WidgetManager::touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(!m_activeWidget){
        return;
    }
    
    if(!m_activeWidget->isLiving()){
        m_activeWidget = NULL;
        return;
    }
    
    m_activeWidget->touchMove(pTouch, pEvent);
}

Widget * WidgetManager::init(CCNode * node, int zorder)
{
    m_rootWidget = Widget::create("root");
    //the root handle the touch event last
    m_rootWidget->setPriority(CPRI_LOWEST);
    m_activeWidget = 0;
    node->addChild(m_rootWidget, zorder);
    return m_rootWidget;
}

void WidgetManager::release()
{
    delete this;
}

_CCGUI_NAMESPACE_END
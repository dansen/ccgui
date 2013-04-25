//
//  Widget.cpp
//  CCGUI
//
//  Created by dansen on 13-4-19.
//
//

#include "Widget.h"
#include "WidgetManager.h"
#include "CCGUIUtil.h"

_CCGUI_NAMESPACE_BEGIN
using namespace cocos2d;
using namespace std;

Widget::Widget():
#ifdef CCGUI_DEBUG
m_backLayer(0),
#endif
m_treeLevel(0),
m_frontable(false),
m_luaTouchBeginHandle(0),
m_luaTouchMoveHandle(0),
m_luaTouchEndHandle(0),
m_luaTouchCancelHandle(0),
m_type(WT_WIDGET),
m_parentWidget(NULL)
{
    setTouchable(false);
}

Widget::~Widget()
{
    printf("widget %s destroyed.\n", getName().c_str());
}


void Widget::addWidget(Widget * child)
{
    child->m_parentWidget = this;
    child->setTreeLevel(this->m_treeLevel + 1);
    m_children.push_back(child);
    CCNode::addChild(child, m_children.size());
}

void Widget::removeWidget(Widget* child)
{
    for(CHILDREN_ITR itr = m_children.begin(); itr != m_children.end(); ++itr){
        if(child == *itr){
            m_children.erase(itr);
            CCNode::removeChild(child, true);
            break;
        }
    }
}

void Widget::replaceWidget(Widget * oldWidget,  Widget * newWidget)
{
    for(CHILDREN_ITR itr = m_children.begin(); itr != m_children.end(); ++itr){
        if(*itr == oldWidget){
            //(1)add newWidget into children
            m_children.insert(itr, newWidget);
            //(2)assign properties
            newWidget->m_parentWidget = this;
            newWidget->setTreeLevel(this->m_treeLevel + 1);
            newWidget->setTag(oldWidget->getTag());
            newWidget->setPosition(oldWidget->getPosition());
            newWidget->setContentSize(oldWidget->getContentSize());
            CCNode::addChild(newWidget, oldWidget->getZOrder());
            //(3)remove old
            removeWidget(oldWidget);
            break;
        }
    }
    
}

void Widget::active()
{
    m_parentWidget->active(this);
}

void Widget::reorderWidgets()
{
    int i=1;
    for(CHILDREN_ITR itr = m_children.begin(); itr != m_children.end(); ++itr, ++i){
        Widget * widget = *itr;
        widget->getParent()->reorderChild(widget, i);
    }
}

void Widget::active(Widget * child)
{
    if(isFrontable()){
        //(1)bring widget to front
        //erase from parent
        for(CHILDREN_ITR itr = m_children.begin(); itr != m_children.end(); ++itr){
            if(child == *itr){
                m_children.erase(itr);
                break;
            }
        }
        //add to parent
        m_children.push_back(child);
        //reorder parent
        reorderWidgets();
    }
    
}

void Widget::setTreeLevel(int level)
{
    //update tree level
    m_treeLevel = level;

    for(CHILDREN_ITR itr = m_children.begin(); itr != m_children.end(); ++itr){
        (*itr)->setTreeLevel(level+1);
    }
}

int Widget::getTreeLevel()
{
    return m_treeLevel;
}

bool Widget::isChildOf(Widget * parent)
{
    Widget * cp = this->getParentWidget();
    while(cp){
        if(parent == cp){
            return true;
        }
        cp = cp->getParentWidget();
    }
    return true;
}

bool Widget::init()
{
    //set size
    this->setAnchorPoint(CCPointMake(0.5f, 0.5f));
    this->setContentSize(cocos2d::CCSizeMake(0, 0));
    //init back with gray
#ifdef CCGUI_DEBUG
    int alpha = 50;
    m_backLayer = cocos2d::CCLayerGradient::create(cocos2d::ccc4(255, 255, 255, alpha), cocos2d::ccc4(100, 100,100, alpha));
    m_backLayer->setContentSize(getContentSize());
    m_backLayer->setAnchorPoint(CCPointMake(0.5f, 0.5f));
    this->addChild(m_backLayer);
#endif
    //
    return true;
}

void Widget::touchBegin(cocos2d::LUA_FUNCTION handle)
{
    setTouchable(true);
    m_luaTouchBeginHandle = handle;
}

void Widget::touchEnd(cocos2d::LUA_FUNCTION handle)
{
    setTouchable(true);
    m_luaTouchEndHandle = handle;
}

void Widget::touchMove(cocos2d::LUA_FUNCTION handle)
{
    setTouchable(true);
    m_luaTouchMoveHandle = handle;
}

void Widget::touchCancel(cocos2d::LUA_FUNCTION handle)
{
    setTouchable(true);
    m_luaTouchCancelHandle = handle;
}



//get child
Widget * Widget::get(const char * name)
{
    return getChild(name);
}

Widget * Widget::getChild(const char * name)
{
    for(CHILDREN_ITR itr = m_children.begin(); itr != m_children.end(); ++itr){
        Widget * child = *itr;
        if(child->getName() == name){
            return child;
        }else{
            Widget * son = child->getChild(name);
            if(son){
                return son;
            }
        }
    }
    
    return 0;
}

bool Widget::isFrontable()
{
    return m_frontable;
}

void Widget::enableFront(bool enable)
{
    m_frontable = enable;
}

Widget * Widget::create(string name)
{
    Widget * ret = new Widget();
    if (ret && ret->init())
    {
        ret->m_name = name;
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

Widget * Widget::create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize)
{
    Widget * widget = create(name);
    if(widget){
        widget->setPosition(position);
        widget->setContentSize(contentSize);
    }
    
    return widget;
}

void Widget::release()
{
    //release all its children
    for(CHILDREN_ITR itr = m_children.begin(); itr != m_children.end(); ++itr){
        (*itr)->release();
    }
    m_children.clear();
    //release myself
    CCNode::removeFromParentAndCleanup(true);
}

bool Widget::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    //
    if(!isTouchable()){
        return false;
    }
    //visiable
    for (CCNode *c = this; c != NULL; c = c->getParent())
    {
        if (c->isVisible() == false)
        {
            return false;
        }
    }
    //is child of ScrollView?
    for(Widget * w = this; w != NULL; w = w->getParentWidget()){
        if(w->m_type == WT_SCROLL_VIEW){
            if(!w->containsTouchLocation(pTouch)){
                return false;
            }
        }
    }
    
    //if is the root
    if(this == WidgetManager::sharedMgr()->getRootWidget()){
        //
        return WidgetManager::sharedMgr()->touchBegin(pTouch, pEvent);
    }
    //ignore those not in rect
	if ( !containsTouchLocation(pTouch) ) {
		return false;
	}
    
    //add the intesect node to pool
    WidgetManager::sharedMgr()->addTouchWidget(this);
    
	//得到当前touch处差值
    
    return false;
}

void Widget::ccTouchMoved(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
	//是否在精灵内部
    bool inSprite = containsTouchLocation(pTouch);
    WidgetManager::sharedMgr()->touchMove(pTouch, pEvent);
}

void Widget::ccTouchEnded(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    //是否在精灵内部
    bool inSprite = containsTouchLocation(pTouch);
	CCPoint touchPoint = pTouch->locationInView();
	//
    WidgetManager::sharedMgr()->touchEnd(pTouch, pEvent);
}
void Widget::ccTouchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    WidgetManager::sharedMgr()->touchCancelled(pTouch, pEvent);
}

static void touch(int handler,Widget * widget, cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    if(handler){
        cocos2d::CCLuaEngine * lua = cocos2d::CCLuaEngine::defaultEngine();
        lua->pushCCObject(widget, "Widget");
        lua->pushCCObject(pTouch, "CCTouch");
        lua->executeFunctionByHandler(handler, 2);
    }
}

void Widget::touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch begin %s...\n", getName().c_str());
    if(m_luaTouchBeginHandle){
        touch(m_luaTouchBeginHandle, this, pTouch, pEvent);
    }
}

void Widget::touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch end %s...\n", getName().c_str());
    if(m_luaTouchEndHandle){
        touch(m_luaTouchEndHandle, this, pTouch, pEvent);
    }
    
}

void Widget::touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch cancel %s...\n", getName().c_str());
    if(m_luaTouchCancelHandle){
        touch(m_luaTouchCancelHandle, this, pTouch, pEvent);
    }
    
}

void Widget::touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch move %s...\n", getName().c_str());
    if(m_luaTouchMoveHandle){
        touch(m_luaTouchMoveHandle, this, pTouch, pEvent);
    }
    
}

void Widget::setPosition (const cocos2d::CCPoint &position)
{
    CCNode::setPosition(position);
}

void Widget::setContentSize(const cocos2d::CCSize &contentSize)
{
#ifdef CCGUI_DEBUG
    //update back
    if(m_backLayer){
        m_backLayer->setContentSize(contentSize);
    }
#endif
    //
    CCNode::setContentSize(contentSize);
}


_CCGUI_NAMESPACE_END

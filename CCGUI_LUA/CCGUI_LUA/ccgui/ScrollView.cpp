//
//  ScrollView.cpp
//  CCGUI
//
//  Created by CrazyApps on 13-4-20.
//
//

#include "ScrollView.h"

using namespace cocos2d::extension;
_CCGUI_NAMESPACE_BEGIN

ScrollView::ScrollView()
{
    m_type = WT_SCROLL_VIEW;
}

ScrollView::~ScrollView()
{
    
}

bool ScrollView::init()
{
    m_scrollView = CCScrollView::create();
    this->addChild(m_scrollView, 10, 0);
    Widget::init();
    return true;
}

ScrollView * ScrollView::create(std::string name)
{
    ScrollView * view = new ScrollView();
    if(view && view->init()){
        view->setName(name);
        view->autorelease();
        return view;
    }
    delete view;
    return view;
}

ScrollView * ScrollView::create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize)
{
    ScrollView * view = create(name);
    if(view){
        view->setPosition(position);
        view->setContentSize(contentSize);
    }
    return view;
}

//the ScrollView content size is the CCScrollView's view size
void ScrollView::setContentSize(const cocos2d::CCSize &contentSize)
{
    m_scrollView->setViewSize(contentSize);
    Widget::setContentSize(contentSize);
    updateScrollView();
}

void ScrollView::updateScrollView()
{
    if(m_canvas){
        m_scrollView->setContentSize(m_canvas->getContentSize());
    }
}

//canvas size and view offset
Widget * ScrollView::getCanvas()
{
    return m_canvas;
} 

void ScrollView::setCanvas(Widget * canvas)
{
    if(m_canvas){
        printf("warning:canvas exist!\n");
        return;
    }
    m_canvas = canvas;
    //canvas is the child by CCScrollView
    m_scrollView->addChild(canvas, 0, 0);
    //is the sub of current widget
    canvas->setParentWidget(this);
    canvas->setTreeLevel(this->getTreeLevel() + 1);
    m_children.push_back(canvas);
    //
    m_scrollView->setViewSize(getContentSize());
    m_scrollView->setContentSize(m_canvas->getContentSize());
    m_scrollView->setClippingToBounds(true);
}

void ScrollView::setViewOffset(cocos2d::CCPoint offset)
{
    m_scrollView->setContentOffset(offset);
}

cocos2d::CCPoint ScrollView::getViewOffset()
{
    return m_scrollView->getContentOffset();
}
//v or h
void 	ScrollView::setVisibleVScroll(bool _value)
{
    //m_scrollView->setDirection();
}
bool 	ScrollView::isVisibleVScroll()
{
    //return m_scrollView->isBounceable();
    return false;
}
void 	ScrollView::setVisibleHScroll(bool _value)
{
    
}

void    ScrollView::setDirection(cocos2d::extension::CCScrollViewDirection direction)
{
    m_scrollView->setDirection(direction);
}

bool 	ScrollView::isVisibleHScroll()
{
    return false;
}

void ScrollView::touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch begin...%s\n", m_name.c_str());
    m_scrollView->ccTouchBegan(pTouch, pEvent);
}

void ScrollView::touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch end...%s\n", m_name.c_str());
    m_scrollView->ccTouchEnded(pTouch, pEvent);
}

void ScrollView::touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch cancel...%s\n", m_name.c_str());
    m_scrollView->ccTouchCancelled(pTouch, pEvent);
}

void ScrollView::touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    printf("touch move...%s\n", m_name.c_str());
    m_scrollView->ccTouchMoved(pTouch, pEvent);
}








_CCGUI_NAMESPACE_END













//
//  ItemBox.cpp
//  CCGUI_LUA
//
//  Created by dansen on 13-4-22.
//
//

#include "ItemBox.h"
_CCGUI_NAMESPACE_BEGIN
using namespace cocos2d;
using namespace cocos2d::extension;
#define ITEMBOX_DEFAULT_INTERVAL 5



ItemBox::ItemBox():
m_interval(ITEMBOX_DEFAULT_INTERVAL)
{
    m_canvas = NULL;
}

ItemBox::~ItemBox()
{
    
}

ItemBox * ItemBox::create(std::string name)
{
    ItemBox * box = new ItemBox();
    if(box && box->init()){
        box->setName(name);
        box->autorelease();
        return box;
    }
    delete box;
    return box;
}

bool ItemBox::init()
{
    //
    ScrollView::init();
    //set canvas
    ScrollView::setCanvas(CCGUI::Widget::create("canvas for item box"));
    ScrollView::setDirection(kCCScrollViewDirectionVertical);
    return true;
}

void ItemBox::updateCanvas()
{
    //update canvas content size
    int currentHeight = 0;
    int maxWidth = 0;
    
    for(ITEMS_ITR itr = m_items.begin(); itr != m_items.end(); ++itr){
        Widget * widget = *itr;
        widget->setPosition(CCPointMake(0, currentHeight));
        CCSize size = widget->getContentSize();
        currentHeight += size.height + ITEMBOX_DEFAULT_INTERVAL;
        
        if(size.width > maxWidth){
            maxWidth = size.width;
        }
    }
    
    if(m_canvas){
        m_canvas->setContentSize(CCSizeMake(maxWidth, currentHeight));
    }
    
    updateScrollView();
}

void ItemBox::setContentSize(const cocos2d::CCSize &contentSize)
{
    ScrollView::setContentSize(contentSize);
}

void ItemBox::addItem(Widget * item)
{
    //canvas自成一家，正常使用
    m_canvas->addWidget(item);
    m_items.push_back(item);
    item->setAnchorPoint(CCPointMake(0, 0));
    //data ok,then graphic
    //update canvas size
    updateCanvas();
}

void ItemBox::clearItems()
{
    m_canvas->clearWidgets();
    m_items.clear();
    updateCanvas();
}

void ItemBox::removeItem(int index)
{
    
}

void ItemBox::setCaption(std::string item)
{
    
}










_CCGUI_NAMESPACE_END








//
//  ListBox.cpp
//  CCGUI
//
//  Created by CrazyApps on 13-4-20.
//
//

#include "ListBox.h"
#include "TextBox.h"
_CCGUI_NAMESPACE_BEGIN
using namespace cocos2d;

ListBox * ListBox::create(std::string name)
{
    ListBox * box = new ListBox();
    if(box && box->init()){
        box->setName(name);
        box->autorelease();
        return box;
    }
    delete box;
    return box;
}


bool ListBox::init()
{
    m_itemSize.width = 200;
    m_itemSize.height = 20;
    //
    ScrollView::init();
    //set canvas
    ScrollView::setCanvas(CCGUI::Widget::create("canvas for list box"));
    return true;
}

void ListBox::onItemSizeChange()
{
    int i=0;
    for(ITEMS_ITR itr=m_items.begin(); itr != m_items.end(); ++itr){
        Widget * box = *itr;
        //calculate the position
        box->setContentSize(m_itemSize);
        box->setPosition(CCPointMake(0, m_itemSize.height*i++));
    }
    updateCanvas();
}

void ListBox::updateCanvas()
{
    //update canvas content size
    if(m_canvas){
        m_canvas->setContentSize(CCSizeMake(m_itemSize.width, m_itemSize.height*m_items.size()));
    }
    
    updateScrollView();
}

void ListBox::setContentSize(const cocos2d::CCSize &contentSize)
{
    m_itemSize = CCSizeMake(contentSize.width, m_itemSize.height);
    ScrollView::setContentSize(contentSize);
}

void ListBox::setItemHeight(int height)
{
    m_itemSize = CCSizeMake(getContentSize().width, height);
    onItemSizeChange();
}

void ListBox::addItem(std::string item)
{
    TextBox * box = TextBox::create(item);
    box->setText(item.c_str());
    //canvas自成一家，正常使用
    m_canvas->addWidget(box);
    m_items.push_back(box);
    box->setAnchorPoint(CCPointMake(0, 0));
    //data ok,then graphic
    //update canvas size
    updateCanvas();
    //calculate the position
    box->setContentSize(m_itemSize);
    box->setPosition(CCPointMake(0, m_itemSize.height*(m_items.size()-1)));
}

void ListBox::removeItem(int index)
{
    
}
void ListBox::updateItem(int index, std::string item)
{
    
}
void ListBox::setCaption(std::string item)
{
    
}










_CCGUI_NAMESPACE_END











//
//  ItemBox.h
//  CCGUI_LUA
//
//  Created by dansen on 13-4-22.
//
//

#ifndef __CCGUI_LUA__ItemBox__
#define __CCGUI_LUA__ItemBox__

#include "ScrollView.h"
_CCGUI_NAMESPACE_BEGIN

class TextBox;

class ItemBox : public ScrollView
{
public:
    ItemBox();
    ~ItemBox();
     static ItemBox * create(std::string name);
private:
    bool init();
public:
    virtual void setContentSize(const cocos2d::CCSize &contentSize);
    
    void addItem(Widget * item);
    void removeItem(int index);
    void clearItems();
    void setCaption(std::string item);
private:
    void updateCanvas();
private:
    int m_interval;
    TextBox * m_itemHead;
    std::list<Widget*> m_items;
    typedef std::list<Widget*>::iterator ITEMS_ITR;
};


_CCGUI_NAMESPACE_END

#endif 

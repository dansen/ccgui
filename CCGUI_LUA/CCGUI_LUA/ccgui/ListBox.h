//
//  ListBox.h
//  CCGUI
//
//  Created by CrazyApps on 13-4-20.
//
//

#ifndef __CCGUI__ListBox__
#define __CCGUI__ListBox__

#include "ScrollView.h"
_CCGUI_NAMESPACE_BEGIN

class TextBox;

class ListBox : public ScrollView
{
public:
    static ListBox * create(std::string name);
public:
    bool init();
public:
    virtual void setContentSize(const cocos2d::CCSize &contentSize);
    void addItem(std::string item);
    void removeItem(int index);
    void updateItem(int index, std::string item);
    void setCaption(std::string item);
    void setItemHeight(int height);
private:
    void onItemSizeChange();
    void updateCanvas();
private:
    cocos2d::CCSize m_itemSize;
    TextBox * m_itemHead;
    std::list<TextBox*> m_items;
    typedef std::list<TextBox*>::iterator ITEMS_ITR;
};


_CCGUI_NAMESPACE_END
#endif

//
//  MultiListBox.h
//  CCGUI
//
//  Created by CrazyApps on 13-4-20.
//
//

#ifndef __CCGUI__MultiListBox__
#define __CCGUI__MultiListBox__

#include "ScrollView.h"
_CCGUI_NAMESPACE_BEGIN

class TextBox;

class MultiListBox : public ScrollView
{
public:
    static MultiListBox * create(const std::string & name, int columnCount, int rowCount);
public:
    virtual void setContentSize(const cocos2d::CCSize &contentSize);
    //add a column
    void addColumn(const std::string & head, int width);
    void addRow();
    //set value at (row,col)
    void setItem(const char * item, int row, int col);
    //
private:
    bool init(int rowCount, int columnCount);
private:
    void updateTextPosition();
    void updateContentSize();
private:
    typedef std::vector<TextBox*> COLOUM_LIST;
    std::vector<COLOUM_LIST> m_rowBoxes;
    int m_rowCount;
    int m_columnCount;
    int m_itemHeight;
    std::vector<int> m_columnWidths;
};

_CCGUI_NAMESPACE_END
#endif

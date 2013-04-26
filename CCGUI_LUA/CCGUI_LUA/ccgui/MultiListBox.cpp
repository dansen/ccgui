//
//  MultiListBox.cpp
//  CCGUI
//
//  Created by CrazyApps on 13-4-20.
//
//

#include "MultiListBox.h"
#include "TextBox.h"

#define CCGUI_COLUMN_DEFAULT_WIDTH 102

_CCGUI_NAMESPACE_BEGIN
using namespace cocos2d;

MultiListBox * MultiListBox::create(const std::string & name, int columnCount, int rowCount)
{
    MultiListBox * box = new MultiListBox();
    if(box && box->init(rowCount, columnCount)){
        box->setName(name);
        box->autorelease();
        return box;
    }
    delete box;
    return box;
    return 0;
}

bool MultiListBox::init(int rowCount, int columnCount)
{
    m_itemHeight = 30;
    m_rowCount = rowCount;
    m_columnCount = columnCount;
    ScrollView::init();
    ScrollView::setCanvas(CCGUI::Widget::create("canvas for MultiListBox"));
    //(1) add column ListBox
    for(int i=0; i<m_rowCount; ++i){
        //(2)add row
        std::vector<TextBox*> rowList;
        for(int j=0; j<m_columnCount; ++j){
            char name[10];
            sprintf(name, "text%d-%d", i, j);
            TextBox * box = TextBox::create(name);
            box->setText(name);
            box->setAnchorPoint(CCPointMake(0, 0));
            box->setContentSize(CCSizeMake(CCGUI_COLUMN_DEFAULT_WIDTH, m_itemHeight));
            m_canvas->addWidget(box);
            rowList.push_back(box);
        }
        m_columnWidths.push_back(CCGUI_COLUMN_DEFAULT_WIDTH);
        m_rowBoxes.push_back(rowList);
    }
    //(3) update text box position
    updateTextPosition();
    //(4) update content size
    updateContentSize();
    //(5) set direction
    setDirection(extension::kCCScrollViewDirectionVertical);
    return true;
}

void MultiListBox::updateContentSize()
{
    //the width is decided by the list boxes's size
    //the height can be set by user
    int width = 0;
    int height = 0;
    for(int i=0; i<m_columnCount; ++i){
        width += m_rowBoxes[0][i]->getContentSize().width;
    }
    
    height = m_rowCount*m_itemHeight;
    m_canvas->setContentSize(CCSizeMake(width, height));
    ScrollView::setContentSize(CCSizeMake(width, getContentSize().height));
}

void MultiListBox::updateTextPosition()
{
    int currentX = 0;
    int currentY = 0;
    
    for(int i=0; i<m_rowBoxes.size(); ++i){
        std::vector<TextBox*> & rowList = m_rowBoxes[i];
        currentX = 0;
        for(int j=0; j<rowList.size(); ++j){
            rowList[j]->setPosition(CCPointMake(currentX, currentY));
            currentX += rowList[j]->getContentSize().width;
        }
        currentY += m_itemHeight;
    }
}

void MultiListBox::setContentSize(const cocos2d::CCSize &contentSize)
{
    ScrollView::setContentSize(contentSize);
}

void MultiListBox::addColumn(const std::string & head, int width)
{
    //(1) add column ListBox
    for(int i=0; i<m_rowCount; ++i){
        //(2)add row
        std::vector<TextBox*> & rowList = m_rowBoxes[i];
        int j = m_columnCount;
        char name[10];
        sprintf(name, "text%d-%d", i, j);
        TextBox * box = TextBox::create(name);
        box->setText(name);
        box->setAnchorPoint(CCPointMake(0, 0));
        box->setContentSize(CCSizeMake(width, m_itemHeight));
        m_canvas->addWidget(box);
        rowList.push_back(box);
    }
    m_columnWidths.push_back(width);
    ++m_columnCount;
    updateTextPosition();
    updateContentSize();
}

void MultiListBox::addRow()
{
    int i = m_rowCount++;
    //(2)add row
    std::vector<TextBox*> rowList;
    for(int j=0; j<m_columnCount; ++j){
        char name[10];
        sprintf(name, "text%d-%d", i, j);
        TextBox * box = TextBox::create(name);
        box->setText(name);
        box->setAnchorPoint(CCPointMake(0, 0));
        box->setContentSize(CCSizeMake(m_columnWidths[j], m_itemHeight));
        m_canvas->addWidget(box);
        rowList.push_back(box);
    }
    
    m_rowBoxes.push_back(rowList);
    
    //
    updateContentSize();
    updateTextPosition();
}

void MultiListBox::setItem(const char * item, int row, int col)
{
    if(row < m_rowCount && col < m_columnCount && row>=0 && col>=0){
        m_rowBoxes[row][col]->setText(item);
    }
}




_CCGUI_NAMESPACE_END
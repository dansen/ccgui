//
//  TextBox.cpp
//  BodhiShoot
//
//  Created by dansen on 13-4-19.
//
//

#include "TextBox.h"
#include "Widget.h"
using namespace cocos2d;
_CCGUI_NAMESPACE_BEGIN


void TextBox::setContentSize(const cocos2d::CCSize &contentSize)
{
    m_label->setDimensions(contentSize);
    Widget::setContentSize(contentSize);
}

bool TextBox::init()
{
    m_label = CCLabelTTF::create("SB了吧", "arial", 20, CCSizeMake(0, 0), kCCTextAlignmentCenter, kCCVerticalTextAlignmentCenter);
    m_label->setAnchorPoint(CCPointMake(0, 0));
    Widget::init();
    this->addChild(m_label);
    //default, TextBox does't accept touch event,call enableTouch(true) to accept touch^_^.
    enableTouch(false);
    return true;
}

TextBox * TextBox::create(std::string name)
{
    TextBox * box = new TextBox();
    if(box && box->init()){
        box->setName(name);
        box->autorelease();
        return box;
    }
    return 0;
}

void TextBox::setText(const char * text)
{
    m_label->setString(text);
    //update TextBox's content size
    Widget::setContentSize(m_label->getContentSize());
}

const char* TextBox::getText()
{
    return m_label->getString();
}
void TextBox::	setFontName (const char* fontName)
{
    m_label->setFontName(fontName);
}
const char* 	TextBox::getFontName ()
{
    return m_label->getFontName();
}

void 	TextBox::setFontSize(int _value)
{
    m_label->setFontSize(_value);
}
int 	TextBox::getFontSize ()
{
    return m_label->getFontSize();
}

void 	TextBox::setTextAlign (cocos2d::CCTextAlignment align)
{
    m_label->setHorizontalAlignment(align);
}

cocos2d::CCTextAlignment 	TextBox::getTextAlign ()
{
    m_label->getHorizontalAlignment();
}

void 	TextBox::setTextVAlign(cocos2d::CCVerticalTextAlignment align)
{
    m_label->setVerticalAlignment(align);
}

cocos2d::CCVerticalTextAlignment TextBox::getTextVAlign ()
{
    return m_label->getVerticalAlignment();
}

void 	TextBox::setTextColor(const cocos2d::ccColor3B &_value)
{
    m_label->setColor(_value);
}
const cocos2d::ccColor3B TextBox::getTextColour ()
{
    return m_label->getColor();
}





_CCGUI_NAMESPACE_END
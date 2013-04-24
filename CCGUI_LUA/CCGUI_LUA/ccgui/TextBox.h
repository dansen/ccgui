//
//  TextBox.h
//  BodhiShoot
//
//  Created by dansen on 13-4-19.
//
//

#ifndef __BodhiShoot__TextBox__
#define __BodhiShoot__TextBox__

#include "Widget.h"

_CCGUI_NAMESPACE_BEGIN

class TextBox:public Widget
{
public:
    virtual void setContentSize(const cocos2d::CCSize &contentSize);
public:
    bool init();
    void setText(const char * text);
    const char* getText();
    void 	setFontName (const char* fontName);
    const char* 	getFontName ();
    void 	setFontSize(int _value);
    int 	getFontSize();
    //align
    void 	setTextAlign(cocos2d::CCTextAlignment align);
    cocos2d::CCTextAlignment 	getTextAlign();
    
    void 	setTextVAlign(cocos2d::CCVerticalTextAlignment align);
    cocos2d::CCVerticalTextAlignment getTextVAlign();
    
    void 	setTextColor(const cocos2d::ccColor3B &_value);
    const cocos2d::ccColor3B getTextColour();
public:
    static TextBox * create(std::string name);
private:
    cocos2d::CCLabelTTF * m_label;
};

_CCGUI_NAMESPACE_END

#endif /* defined(__BodhiShoot__TextBox__) */

//
//  CEGUITextFieldTTF.cpp
//  CCGUI_LUA
//
//  Created by dansen on 13-4-23.
//
//

#include "CCGUITextFieldTTF.h"
#include "CCGUITextFieldDelegate.h"

_CCGUI_NAMESPACE_BEGIN

CCGUITextFieldTTF * CCGUITextFieldTTF::textFieldWithPlaceHolder(const char *placeholder, const cocos2d::CCSize& dimensions,
                                                 cocos2d::CCTextAlignment alignment, const char *fontName, float fontSize)
{
    CCGUITextFieldTTF *pRet = new CCGUITextFieldTTF();
    if(pRet && pRet->initWithPlaceHolder("", dimensions, alignment, fontName, fontSize))
    {
        pRet->autorelease();
        if (placeholder)
        {
            pRet->setPlaceHolder(placeholder);
        }
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

CCGUITextFieldTTF * CCGUITextFieldTTF::textFieldWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize)
{
    CCGUITextFieldTTF *pRet = new CCGUITextFieldTTF();
    if(pRet && pRet->initWithString("", fontName, fontSize))
    {
        pRet->autorelease();
        if (placeholder)
        {
            pRet->setPlaceHolder(placeholder);
        }
        return pRet;
    }
    CC_SAFE_DELETE(pRet);
    return NULL;
}

void CCGUITextFieldTTF::insertText(const char * text, int len)
{
    CCTextFieldTTF::insertText(text, len);
    CCGUITextFieldDelegate * delegate = static_cast<CCGUITextFieldDelegate*>(getDelegate());
    if(delegate){
        delegate->insertText(text, len);
    }
}

void CCGUITextFieldTTF::deleteBackward()
{
    CCTextFieldTTF::deleteBackward();
    CCGUITextFieldDelegate * delegate = static_cast<CCGUITextFieldDelegate*>(getDelegate());
    if(delegate){
        delegate->deleteBackward();
    }
}

void CCGUITextFieldTTF::keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
    CCGUITextFieldDelegate * delegate = static_cast<CCGUITextFieldDelegate*>(getDelegate());
    if(delegate){
        delegate->keyboardWillShow(info);
    }
}
void CCGUITextFieldTTF::keyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
    CCGUITextFieldDelegate * delegate = static_cast<CCGUITextFieldDelegate*>(getDelegate());
    if(delegate){
        delegate->keyboardDidShow(info);
    }
}
void CCGUITextFieldTTF::keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
    CCGUITextFieldDelegate * delegate = static_cast<CCGUITextFieldDelegate*>(getDelegate());
    if(delegate){
        delegate->keyboardWillHide(info);
    }
}
void CCGUITextFieldTTF::keyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
    CCGUITextFieldDelegate * delegate = static_cast<CCGUITextFieldDelegate*>(getDelegate());
    if(delegate){
        delegate->keyboardDidHide(info);
    }
}


_CCGUI_NAMESPACE_END








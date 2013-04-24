//
//  CEGUITextFieldTTF.h
//  CCGUI_LUA
//
//  Created by dansen on 13-4-23.
//
//

#ifndef __CCGUI_LUA__CEGUITextFieldTTF__
#define __CCGUI_LUA__CEGUITextFieldTTF__

#include "cocos2d.h"
#include "CCGUIDef.h"
//whatever,we do need a strongger text field to support EditBox.

_CCGUI_NAMESPACE_BEGIN

class CCGUITextFieldTTF : public cocos2d::CCTextFieldTTF
{
public:
    static CCGUITextFieldTTF * textFieldWithPlaceHolder(const char *placeholder, const cocos2d::CCSize& dimensions,
                                                     cocos2d::CCTextAlignment alignment, const char *fontName, float fontSize);
    static CCGUITextFieldTTF * textFieldWithPlaceHolder(const char *placeholder, const char *fontName, float fontSize);
protected:
    //////////////////////////////////////////////////////////////////////////
    // keyboard show/hide notification
    //////////////////////////////////////////////////////////////////////////
    virtual void keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info)  ;
    virtual void keyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& info)   ;
    virtual void keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info)  ;
    virtual void keyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& info)   ;
public:
    virtual void insertText(const char * text, int len);
    virtual void deleteBackward();
};

_CCGUI_NAMESPACE_END

#endif 

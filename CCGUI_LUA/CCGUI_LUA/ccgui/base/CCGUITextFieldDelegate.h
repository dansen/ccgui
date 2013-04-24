//
//  CCGUITextFieldDelegate.h
//  CCGUI_LUA
//
//  Created by dansen on 13-4-23.
//
//

#ifndef __CCGUI_LUA__CCGUITextFieldDelegate__
#define __CCGUI_LUA__CCGUITextFieldDelegate__
#include "CCGUIDef.h"
#include "cocos2d.h"

_CCGUI_NAMESPACE_BEGIN


class CCGUITextFieldDelegate:public cocos2d::CCTextFieldDelegate
{
public:
    virtual void keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info)  = 0;
    virtual void keyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& info)  = 0;
    virtual void keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info) = 0;
    virtual void keyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& info)  = 0;
    virtual void insertText(const char * text, int len) = 0;
    virtual void deleteBackward() = 0;
};


_CCGUI_NAMESPACE_END


#endif 

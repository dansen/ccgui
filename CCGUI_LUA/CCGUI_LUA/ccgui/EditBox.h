//
//  EditBox.h
//  BodhiShoot
//
//  Created by dansen on 13-4-19.
//
//

#ifndef __BodhiShoot__EditBox__
#define __BodhiShoot__EditBox__

#include "CCGUIDef.h"
#include "Widget.h"
#include "cocos2d.h"
#include "CCGUITextFieldTTF.h"
#include "CCGUITextFieldDelegate.h"
_CCGUI_NAMESPACE_BEGIN

class EditBox : public Widget, public CCGUITextFieldDelegate
{
public:
    EditBox();
    ~EditBox();
public:
    static EditBox * create(std::string name);
    static EditBox * create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize);
    
    virtual bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF * pSender);
    virtual bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF * pSender);
    virtual bool onTextFieldInsertText(cocos2d::CCTextFieldTTF * pSender, const char * text, int nLen);
    virtual bool onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF * pSender, const char * delText, int nLen);
    virtual void keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info) ;
    virtual void keyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& info)  ;
    virtual void keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info) ;
    virtual void keyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& info);
protected:
    bool init();
    virtual void touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    virtual void touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
public:
    virtual void setContentSize(const cocos2d::CCSize &contentSize);
    virtual void insertText(const char * text, int len);
    virtual void deleteBackward();
    virtual void onEnter();
    virtual void onExit();
    //the node will be moved up when the keyboard show
    void setMoveUpNode(Widget * widget);
private:
    void updateCaret(bool isKeyBoardShow);
private:
    CCGUITextFieldTTF * m_editTTF;
    cocos2d::CCLabelTTF * m_backLabel;
    cocos2d::CCSprite * m_caretSprite;
    Widget * m_moveUpWidget;
    float m_moveUpDeltaY;
};


_CCGUI_NAMESPACE_END


#endif 

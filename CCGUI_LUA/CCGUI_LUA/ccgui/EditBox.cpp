//
//  EditBox.cpp
//  CCGUI
//
//  Created by dansen on 13-4-19.
//
//

#include "EditBox.h"

#define CCGUI_CARET_INTERVAL 2
#define CCGUI_MOVE_UP_HEIGHT 20
#define CCGUI_MOVE_UP_SPEED 0.2f

using namespace cocos2d;

_CCGUI_NAMESPACE_BEGIN

class LineSprite:public CCSprite
{
public:
    float width;    //线条宽度
    CCPoint orgin;
    CCPoint dest;
    ccColor3B color;
public:
    //创建函数
    static LineSprite* create(CCPoint orgin, CCPoint dest, float width, ccColor3B color){
        LineSprite *pSprite = new LineSprite();
        if (pSprite && pSprite->init())
        {
            //
            pSprite->width = width;
            pSprite->orgin = orgin;
            pSprite->dest = dest;
            pSprite->color = color;
            //
            pSprite->autorelease();
            return pSprite;
        }
        CC_SAFE_DELETE(pSprite);
        return NULL;
    }
public:
    void draw(){
        glLineWidth(width);
        ccDrawColor4B(color.r, color.g, color.b, 1);
        ccDrawLine(orgin,  dest);
    }
};



EditBox::EditBox():
m_editTTF(0),
m_backLabel(0),
m_caretSprite(0)
{
    
}

EditBox::~EditBox()
{
    
}

EditBox * EditBox::create(std::string name)
{
    EditBox * box = new EditBox();
    if(box && box->init()){
        box->setName(name);
        box->autorelease();
        return box;
    }
    delete box;
    return box;
}

void EditBox::keyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
    updateCaret(true);
    //move up the node
    float keyboardHeight = 355;
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    if(size.width >= 1024){         //for ipad landscape
        keyboardHeight = 360;
    }else{                          //for iphone landscape
        keyboardHeight = 180;
    }
    
    float screenY = this->getParent()->convertToWorldSpace(getPosition()).y;
    m_moveUpDeltaY = keyboardHeight+CCGUI_MOVE_UP_HEIGHT - screenY;
    
    if(screenY >= keyboardHeight+CCGUI_MOVE_UP_HEIGHT){
        
    }else{
        //moveup
        m_moveUpWidget->runAction(CCMoveBy::create(CCGUI_MOVE_UP_SPEED, CCPointMake(0, m_moveUpDeltaY)));
    }
}

void EditBox::keyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
    
}

void EditBox::onEnter()
{
    Widget::onEnter();
    m_moveUpWidget = getParentWidget();
}

void EditBox::onExit()
{
    Widget::onExit();
}

void EditBox::keyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info)
{
    updateCaret(false);
    //moveup
    m_moveUpWidget->runAction(CCMoveBy::create(CCGUI_MOVE_UP_SPEED, CCPointMake(0, -m_moveUpDeltaY)));
}

void EditBox::keyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& info)
{ 
}

EditBox * EditBox::create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize)
{
    EditBox * box = create(name);
    if(box){
        box->setPosition(position);
        box->setContentSize(contentSize);
    }
    return box;
}

void EditBox::touchBegin(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    m_editTTF->attachWithIME();
    Widget::touchBegin(pTouch, pEvent);
}

void EditBox::touchEnd(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    Widget::touchEnd(pTouch, pEvent);
}

void EditBox::touchCancelled(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    Widget::touchCancelled(pTouch, pEvent);
}

void EditBox::touchMove(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    Widget::touchMove(pTouch, pEvent);
}

//当用户启动虚拟键盘时的回调函数
bool EditBox::onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF * pSender)
{
    return false;
}
//当用户关闭虚拟键盘时的回调函数
bool EditBox::onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF * pSender)
{
    return false;
}
//当用户进行输入时的回调函数
bool EditBox::onTextFieldInsertText(cocos2d::CCTextFieldTTF * pSender, const char * text, int nLen)
{
    return false;
}
//当用户删除文字时的回调函数
bool EditBox::onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF * pSender, const char * delText, int nLen)
{
    
    return false;
}

void EditBox::insertText(const char * text, int len)
{
    m_backLabel->setString(m_editTTF->getString());
    updateCaret(true);
}

void EditBox::deleteBackward()
{
    m_backLabel->setString(m_editTTF->getString());
    updateCaret(true);
}

void EditBox::updateCaret(bool isKeyBoardShow)
{
    if(isKeyBoardShow){
        if(!m_caretSprite->isVisible()){
            m_caretSprite->setVisible(true);
            CCBlink * blink = CCBlink::create(1.0, 1);
            m_caretSprite->runAction(CCRepeatForever::create(blink));
        }
    }else{
        m_caretSprite->stopAllActions();
        m_caretSprite->setVisible(false);
    }
    //set position
    CCSize size = m_backLabel->getContentSize();
    m_caretSprite->setPositionX(size.width);
    LineSprite * line = static_cast<LineSprite*>(m_caretSprite);
    line->dest = CCPointMake(0, size.height-CCGUI_CARET_INTERVAL);
}

bool EditBox::init()
{
    m_editTTF = CCGUITextFieldTTF::textFieldWithPlaceHolder("", CCSizeMake(0, 0), kCCTextAlignmentLeft, "arial", 20);
    m_editTTF->setAnchorPoint(CCPointMake(0, 0));
    m_editTTF->setDelegate(this);
    CCNode::addChild(m_editTTF);
    //init cursor
    m_caretSprite = LineSprite::create(CCPointMake(0, CCGUI_CARET_INTERVAL),
                                       CCPointMake(0, m_editTTF->getFontSize()-CCGUI_CARET_INTERVAL),
                                       3, m_editTTF->getColor());
    CCNode::addChild(m_caretSprite);
    //init back label,invisible
    m_backLabel = CCLabelTTF::create(m_editTTF->getString(), m_editTTF->getFontName(), m_editTTF->getFontSize());
    CCNode::addChild(m_backLabel);
    m_backLabel->setVisible(false);
    return Widget::init();
}

void EditBox::setContentSize(const cocos2d::CCSize &contentSize)
{
    m_editTTF->setContentSize(contentSize);
    m_backLabel->setContentSize(CCSizeMake(m_backLabel->getContentSize().width, contentSize.height));
    Widget::setContentSize(contentSize);
    //update caret
    updateCaret(false);
}

_CCGUI_NAMESPACE_END


//
//  Window.cpp
//  CCGUI
//
//  Created by dansen on 13-4-19.
//
//

#include "Window.h"

_CCGUI_NAMESPACE_BEGIN
using namespace std;

Window::Window()
{
    setTouchable(true);
}

Window::~Window()
{
    
}

Window * Window::create(string name)
{
    Window * ret = new Window();
    if (ret && ret->init())
    {
        ret->m_name = name;
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return NULL;
}

Window * Window::create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize)
{
    Window * ret = create(name);
    if(ret){
        ret->setPosition(position);
        ret->setContentSize(contentSize);
    }
    
    return ret;
}
_CCGUI_NAMESPACE_END









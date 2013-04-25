//
//  Window.h
//  CCGUI
//
//  Created by dansen on 13-4-19.
//
//

#ifndef __CCGUI__Window__
#define __CCGUI__Window__

//widget has the ability to accept touch event,but the ability is off by default.
//window is a widget that accept touch event 
//and in future design,window will be a powerful component just like mygui

#include "Widget.h"
_CCGUI_NAMESPACE_BEGIN

class Window:public Widget
{
public:
    static Window * create(std::string name);
    static Window * create(std::string name, cocos2d::CCPoint position, cocos2d::CCSize contentSize);
public:
    Window();
    virtual ~Window();
private:
    
};

_CCGUI_NAMESPACE_END
#endif 

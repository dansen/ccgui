//
//  CCGUIObjectZeroInit.h
//  CCGUI_LUA
//
//  Created by dansen on 13-4-24.
//
//

#ifndef __CCGUI_LUA__CCGUIObjectZeroInit__
#define __CCGUI_LUA__CCGUIObjectZeroInit__

#include "CCGUIDef.h"

_CCGUI_NAMESPACE_BEGIN

class CCGUIObjectZeroInit
{
public:
    static void * operator new(size_t size);
    static void operator delete (void * p);
};

_CCGUI_NAMESPACE_END

#endif 

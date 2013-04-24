//
//  CCGUIObjectZeroInit.cpp
//  CCGUI_LUA
//
//  Created by dansen on 13-4-24.
//
//

#include "CCGUIObjectZeroInit.h"

_CCGUI_NAMESPACE_BEGIN

void * CCGUIObjectZeroInit::operator new(size_t size)
{
    void * storage = malloc(size);
    memset(storage, 0, size);
    
    if(storage == 0){
        throw std::bad_alloc();
    }
    
    return storage;
}

void CCGUIObjectZeroInit::operator delete (void * p)
{
    free(p);
}



_CCGUI_NAMESPACE_END







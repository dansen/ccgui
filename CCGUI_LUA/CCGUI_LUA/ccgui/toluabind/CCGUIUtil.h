//
//  CCUtil.h
//  CCGUI
//
//  Created by dansen on 13-3-20.
//
//
#ifndef __CCGUI_UTIL_H_
#define __CCGUI_UTIL_H_

#include "CCGUIDef.h"

_CCGUI_NAMESPACE_BEGIN

class CCValue:public cocos2d::CCObject
{
public:
    static CCValue * make();
    void putString(const char * s);
    void putNumber(double f);
    void putInt(int i);
    void putBool(bool b);
    
    std::string getString();
    double getNumber();
    int getInt();
    bool getBool();
private:
    std::queue<void *> m_values;
    void release();
};
class Subject
{
public:
    void notify(){
        for(OBS_ITR itr = m_handlers.begin(); itr!=m_handlers.end(); ++itr){
            cocos2d::CCLuaEngine * lua = cocos2d::CCLuaEngine::defaultEngine();
            lua->executeFunctionByHandler(*itr, 0);
        }
    }
    
    void attach(int handler){
        m_handlers.insert(handler);
    }
    
    void detach(int handler){
        m_handlers.erase(handler);
    }
private:
    std::set<int> m_handlers;
    typedef std::set<int>::iterator OBS_ITR;
};

class Util
{
public:
    //it's just a trick for tolua...
    static void * emptydata(){ return (void*)0x01;};
    //
    static std::string className(cocos2d::CCObject * o);
public:
    static void setNodePri(cocos2d::CCNode * node, int pri, bool isSwallow);
    static int getNodePri(cocos2d::CCNode * node);
    static cocos2d::CCAction * actionFunc(cocos2d::LUA_FUNCTION func, CCValue * v);
    //observer model
    static Subject * subject();
    //a better lc
    static int lc(int func, const char *sig, ...);
};

_CCGUI_NAMESPACE_END

#endif

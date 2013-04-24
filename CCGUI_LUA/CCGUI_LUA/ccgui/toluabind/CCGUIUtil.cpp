//
//  CCUtil.cpp
//  BodhiShoot
//
//  Created by dansen on 13-3-20.
//
//
#include "CCGUIUtil.h"

using namespace cocos2d;

_CCGUI_NAMESPACE_BEGIN

class LuaAction:public cocos2d::CCObject{
public:
    struct FuncParam{
        int m_func; //函数名
        CCValue * m_v;
    public:
        FuncParam(int f, CCValue * v){
            m_func = f;
            m_v = v;
        }
    };
public:
	void runLuaAction(cocos2d::CCNode * node, void * param_){
        FuncParam * p = (FuncParam*) param_;
        cocos2d::CCLuaEngine * lua = cocos2d::CCLuaEngine::defaultEngine();
        lua->pushCCObject(node, "CCNode");
        lua->pushCCObject(p->m_v, "CCValue");
        lua->executeFunctionByHandler(p->m_func, 2);
        delete p;
	}
};
//CCValue
CCValue * CCValue::make(){
    return new CCValue();
};
void CCValue::putInt(int i)
{
    m_values.push(new int(i));
}
void CCValue::putBool(bool b)
{
    m_values.push(new bool(b));
}
void CCValue::putString(const char * s)
{
    m_values.push(new std::string(s));
}
void CCValue::putNumber(double f)
{
    m_values.push(new double(f));
}
void CCValue::release()
{
    if(m_values.empty()){
        delete this;
    }
}
std::string CCValue::getString()
{
    std::string s(*(std::string*)m_values.front());
    delete (std::string*)m_values.front();
    m_values.pop();
    release();
    return s;
}
double CCValue::getNumber()
{
    double d = (*(double*)m_values.front());
    delete (double*)m_values.front();
    m_values.pop();
    release();
    return d;
}
bool CCValue::getBool()
{
    bool d = (*(bool*)m_values.front());
    delete (bool*)m_values.front();
    m_values.pop();
    release();
    return d;
}
int CCValue::getInt()
{
    int d = (*(int*)m_values.front());
    delete (int*)m_values.front();
    m_values.pop();
    release();
    return d;
}
Subject * Util::subject()
{
    return new Subject();
}
//CCUtil
cocos2d::CCAction * Util::actionFunc(cocos2d::LUA_FUNCTION func, CCValue * v)
{
    LuaAction::FuncParam * param = new LuaAction::FuncParam(func, v);
    cocos2d::CCAction * action = cocos2d::CCCallFuncND::create(NULL,callfuncND_selector(LuaAction::runLuaAction),param);
    return action;
}
std::string Util::className(cocos2d::CCObject * o)
{
    return typeid(*o).name();
}

int Util::getNodePri(cocos2d::CCNode * node)
{
    cocos2d::CCTouchDelegate * del = dynamic_cast<cocos2d::CCTouchDelegate*>(node);
    
    if(del){
        cocos2d::CCTouchDispatcher * dispatcher = cocos2d::CCDirector::sharedDirector()->getTouchDispatcher();
        CCTouchHandler * handler =  dispatcher->findHandler(del);
        return handler->getPriority();
    }else{
        return 0;
    }
}
void Util::setNodePri(cocos2d::CCNode * node, int pri, bool isSwallow)
{
    cocos2d::CCTouchDelegate * del = dynamic_cast<cocos2d::CCTouchDelegate*>(node);
    assert(del);
    cocos2d::CCTouchDispatcher * dispatcher = cocos2d::CCDirector::sharedDirector()->getTouchDispatcher();
    dispatcher->setPriority(pri, del);
    CCTouchHandler * handler =  dispatcher->findHandler(del);
    CCTargetedTouchHandler * swallow = dynamic_cast<CCTargetedTouchHandler*>(handler);
    
    if(swallow){
        swallow->setSwallowsTouches(isSwallow);
    }
}


int Util::lc(int func, const char *sig, ...)
{
    assert((func != 0));
    cocos2d::CCLuaEngine * lua = cocos2d::CCLuaEngine::defaultEngine();
    
	int narg = 0;
	va_list vl;
	va_start(vl, sig);
    
	while(sig && *sig) {
		if(*sig == 'd') {
            lua->pushFloat(va_arg(vl, double));
		} else if(*sig == 'i') {
            lua->pushInt(va_arg(vl, int));
		} else if(*sig == 's') {
            lua->pushString(va_arg(vl, char *));
		} else {
			printf("invalid option(%c)", *sig);
		}
		sig++;
		narg++;
	}
    return lua->executeFunctionByHandler(func, narg);
}
_CCGUI_NAMESPACE_END

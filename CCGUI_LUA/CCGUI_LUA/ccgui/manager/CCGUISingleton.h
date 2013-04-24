#ifndef CCGUI_SINGLETON_H_
#define CCGUI_SINGLETON_H_

#include "CCGUIDef.h"
#include "CCGUIObjectZeroInit.h"

_CCGUI_NAMESPACE_BEGIN

template<typename T>
class CCGUISingleton:public CCGUIObjectZeroInit
{
public:
	static T * sharedMgr(){
		return instance();
	}
	static T * instance(){
		static T t;
		return &t;
	}
public:
	CCGUISingleton(void){};
	~CCGUISingleton(void){};
};



_CCGUI_NAMESPACE_END


#endif
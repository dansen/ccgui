/*
** Lua binding: CCGUI
** Generated automatically by tolua++-1.0.92 on Wed Apr 24 17:54:25 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_CCGUI_open (lua_State* tolua_S);


#include "CCGUIToLua.h"
using namespace CCGUI;
using namespace cocos2d;
using namespace cocos2d::extension;
			

/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_cocos2d__CCPoint (lua_State* tolua_S)
{
 cocos2d::CCPoint* self = (cocos2d::CCPoint*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"CCPoint");
 tolua_usertype(tolua_S,"ImageBox");
 tolua_usertype(tolua_S,"CCTargetedTouchDelegate");
 tolua_usertype(tolua_S,"EditBox");
 tolua_usertype(tolua_S,"TouchNode");
 tolua_usertype(tolua_S,"ItemBox");
 tolua_usertype(tolua_S,"cocos2d::CCPoint");
 tolua_usertype(tolua_S,"CCSize");
 tolua_usertype(tolua_S,"cocos2d::LUA_FUNCTION");
 tolua_usertype(tolua_S,"CCBWidget");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"Widget");
 tolua_usertype(tolua_S,"ScrollView");
}

/* method: setName of class  TouchNode */
#ifndef TOLUA_DISABLE_tolua_CCGUI_TouchNode_setName00
static int tolua_CCGUI_TouchNode_setName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchNode",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchNode* self = (TouchNode*)  tolua_tousertype(tolua_S,1,0);
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setName'", NULL);
#endif
  {
   self->setName(name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getName of class  TouchNode */
#ifndef TOLUA_DISABLE_tolua_CCGUI_TouchNode_getName00
static int tolua_CCGUI_TouchNode_getName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchNode* self = (TouchNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getName'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getName();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isTouchable of class  TouchNode */
#ifndef TOLUA_DISABLE_tolua_CCGUI_TouchNode_isTouchable00
static int tolua_CCGUI_TouchNode_isTouchable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchNode* self = (TouchNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isTouchable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isTouchable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isTouchable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setTouchable of class  TouchNode */
#ifndef TOLUA_DISABLE_tolua_CCGUI_TouchNode_setTouchable00
static int tolua_CCGUI_TouchNode_setTouchable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"TouchNode",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  TouchNode* self = (TouchNode*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setTouchable'", NULL);
#endif
  {
   self->setTouchable(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setTouchable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __CCTargetedTouchDelegate__ of class  TouchNode */
#ifndef TOLUA_DISABLE_tolua_get_TouchNode___CCTargetedTouchDelegate__
static int tolua_get_TouchNode___CCTargetedTouchDelegate__(lua_State* tolua_S)
{
  TouchNode* self = (TouchNode*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__CCTargetedTouchDelegate__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<CCTargetedTouchDelegate*>(self), "CCTargetedTouchDelegate");
#else
   tolua_pushusertype(tolua_S,(void*)((CCTargetedTouchDelegate*)self), "CCTargetedTouchDelegate");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: getParentWidget of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_getParentWidget00
static int tolua_CCGUI_Widget_getParentWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getParentWidget'", NULL);
#endif
  {
   Widget* tolua_ret = (Widget*)  self->getParentWidget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getParentWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: get of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_get00
static int tolua_CCGUI_Widget_get00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'get'", NULL);
#endif
  {
   Widget* tolua_ret = (Widget*)  self->get(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'get'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchBegin of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_touchBegin00
static int tolua_CCGUI_Widget_touchBegin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::LUA_FUNCTION handle  = (LUA_FUNCTION)toluafix_ref_function(tolua_S,2,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchBegin'", NULL);
#endif
  {
   self->touchBegin(handle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchBegin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchMove of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_touchMove00
static int tolua_CCGUI_Widget_touchMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::LUA_FUNCTION handle  = (LUA_FUNCTION)toluafix_ref_function(tolua_S,2,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchMove'", NULL);
#endif
  {
   self->touchMove(handle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchEnd of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_touchEnd00
static int tolua_CCGUI_Widget_touchEnd00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::LUA_FUNCTION handle  = (LUA_FUNCTION)toluafix_ref_function(tolua_S,2,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchEnd'", NULL);
#endif
  {
   self->touchEnd(handle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchEnd'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: touchCancel of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_touchCancel00
static int tolua_CCGUI_Widget_touchCancel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  cocos2d::LUA_FUNCTION handle  = (LUA_FUNCTION)toluafix_ref_function(tolua_S,2,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'touchCancel'", NULL);
#endif
  {
   self->touchCancel(handle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'touchCancel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isFrontable of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_isFrontable00
static int tolua_CCGUI_Widget_isFrontable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isFrontable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isFrontable();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isFrontable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: enableFront of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_enableFront00
static int tolua_CCGUI_Widget_enableFront00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  bool enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'enableFront'", NULL);
#endif
  {
   self->enableFront(enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'enableFront'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_create00
static int tolua_CCGUI_Widget_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   Widget* tolua_ret = (Widget*)  Widget::create(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setPosition of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_setPosition00
static int tolua_CCGUI_Widget_setPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  const CCPoint* position = ((const CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setPosition'", NULL);
#endif
  {
   self->setPosition(*position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentSize of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_setContentSize00
static int tolua_CCGUI_Widget_setContentSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* contentSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentSize'", NULL);
#endif
  {
   self->setContentSize(*contentSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isChildOf of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_isChildOf00
static int tolua_CCGUI_Widget_isChildOf00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  Widget* parent = ((Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isChildOf'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isChildOf(parent);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isChildOf'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addWidget of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_addWidget00
static int tolua_CCGUI_Widget_addWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  Widget* child = ((Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addWidget'", NULL);
#endif
  {
   self->addWidget(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeWidget of class  Widget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Widget_removeWidget00
static int tolua_CCGUI_Widget_removeWidget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Widget",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Widget* self = (Widget*)  tolua_tousertype(tolua_S,1,0);
  Widget* child = ((Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeWidget'", NULL);
#endif
  {
   self->removeWidget(child);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeWidget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: widget_manager_init */
#ifndef TOLUA_DISABLE_tolua_CCGUI_widget_manager_init00
static int tolua_CCGUI_widget_manager_init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,1,0));
  int zorder = ((int)  tolua_tonumber(tolua_S,2,0));
  {
   Widget* tolua_ret = (Widget*)  widget_manager_init(node,zorder);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'widget_manager_init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* function: widget_manager_release */
#ifndef TOLUA_DISABLE_tolua_CCGUI_widget_manager_release00
static int tolua_CCGUI_widget_manager_release00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isnoobj(tolua_S,1,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   widget_manager_release();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'widget_manager_release'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  ImageBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ImageBox_create00
static int tolua_CCGUI_ImageBox_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"ImageBox",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   ImageBox* tolua_ret = (ImageBox*)  ImageBox::create(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"ImageBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentSize of class  ImageBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ImageBox_setContentSize00
static int tolua_CCGUI_ImageBox_setContentSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageBox",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageBox* self = (ImageBox*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* contentSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentSize'", NULL);
#endif
  {
   self->setContentSize(*contentSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setBackSprite of class  ImageBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ImageBox_setBackSprite00
static int tolua_CCGUI_ImageBox_setBackSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageBox",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageBox* self = (ImageBox*)  tolua_tousertype(tolua_S,1,0);
  CCNode* sprite = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setBackSprite'", NULL);
#endif
  {
   self->setBackSprite(sprite);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setBackSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBackSprite of class  ImageBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ImageBox_getBackSprite00
static int tolua_CCGUI_ImageBox_getBackSprite00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ImageBox",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ImageBox* self = (ImageBox*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBackSprite'", NULL);
#endif
  {
   CCNode* tolua_ret = (CCNode*)  self->getBackSprite();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBackSprite'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  CCBWidget */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCBWidget_create00
static int tolua_CCGUI_CCBWidget_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCBWidget",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  const char* filename = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   CCBWidget* tolua_ret = (CCBWidget*)  CCBWidget::create(name,filename);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCBWidget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentSize of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_setContentSize00
static int tolua_CCGUI_ScrollView_setContentSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* contentSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentSize'", NULL);
#endif
  {
   self->setContentSize(*contentSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getCanvas of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_getCanvas00
static int tolua_CCGUI_ScrollView_getCanvas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getCanvas'", NULL);
#endif
  {
   Widget* tolua_ret = (Widget*)  self->getCanvas();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Widget");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getCanvas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCanvas of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_setCanvas00
static int tolua_CCGUI_ScrollView_setCanvas00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  Widget* canvas = ((Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCanvas'", NULL);
#endif
  {
   self->setCanvas(canvas);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCanvas'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setViewOffset of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_setViewOffset00
static int tolua_CCGUI_ScrollView_setViewOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"CCPoint",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  CCPoint point = *((CCPoint*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setViewOffset'", NULL);
#endif
  {
   self->setViewOffset(point);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setViewOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getViewOffset of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_getViewOffset00
static int tolua_CCGUI_ScrollView_getViewOffset00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getViewOffset'", NULL);
#endif
  {
   cocos2d::CCPoint tolua_ret = (cocos2d::CCPoint)  self->getViewOffset();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((cocos2d::CCPoint)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"cocos2d::CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(cocos2d::CCPoint));
     tolua_pushusertype(tolua_S,tolua_obj,"cocos2d::CCPoint");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getViewOffset'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisibleVScroll of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_setVisibleVScroll00
static int tolua_CCGUI_ScrollView_setVisibleVScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool _value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisibleVScroll'", NULL);
#endif
  {
   self->setVisibleVScroll(_value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisibleVScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisibleVScroll of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_isVisibleVScroll00
static int tolua_CCGUI_ScrollView_isVisibleVScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisibleVScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVisibleVScroll();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisibleVScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setVisibleHScroll of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_setVisibleHScroll00
static int tolua_CCGUI_ScrollView_setVisibleHScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
  bool _value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setVisibleHScroll'", NULL);
#endif
  {
   self->setVisibleHScroll(_value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setVisibleHScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isVisibleHScroll of class  ScrollView */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ScrollView_isVisibleHScroll00
static int tolua_CCGUI_ScrollView_isVisibleHScroll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ScrollView",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ScrollView* self = (ScrollView*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'isVisibleHScroll'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->isVisibleHScroll();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isVisibleHScroll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setContentSize of class  ItemBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ItemBox_setContentSize00
static int tolua_CCGUI_ItemBox_setContentSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ItemBox",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemBox* self = (ItemBox*)  tolua_tousertype(tolua_S,1,0);
  const CCSize* contentSize = ((const CCSize*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setContentSize'", NULL);
#endif
  {
   self->setContentSize(*contentSize);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setContentSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: addItem of class  ItemBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ItemBox_addItem00
static int tolua_CCGUI_ItemBox_addItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ItemBox",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Widget",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemBox* self = (ItemBox*)  tolua_tousertype(tolua_S,1,0);
  Widget* item = ((Widget*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'addItem'", NULL);
#endif
  {
   self->addItem(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'addItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: removeItem of class  ItemBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ItemBox_removeItem00
static int tolua_CCGUI_ItemBox_removeItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ItemBox",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemBox* self = (ItemBox*)  tolua_tousertype(tolua_S,1,0);
  int index = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'removeItem'", NULL);
#endif
  {
   self->removeItem(index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'removeItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setCaption of class  ItemBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_ItemBox_setCaption00
static int tolua_CCGUI_ItemBox_setCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"ItemBox",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  ItemBox* self = (ItemBox*)  tolua_tousertype(tolua_S,1,0);
  std::string item = ((std::string)  tolua_tocppstring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'setCaption'", NULL);
#endif
  {
   self->setCaption(item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  EditBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_EditBox_create00
static int tolua_CCGUI_EditBox_create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EditBox",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   EditBox* tolua_ret = (EditBox*)  EditBox::create(name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EditBox");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: create of class  EditBox */
#ifndef TOLUA_DISABLE_tolua_CCGUI_EditBox_create01
static int tolua_CCGUI_EditBox_create01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"EditBox",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"CCPoint",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"CCSize",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  std::string name = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  CCPoint position = *((CCPoint*)  tolua_tousertype(tolua_S,3,0));
  CCSize contentSize = *((CCSize*)  tolua_tousertype(tolua_S,4,0));
  {
   EditBox* tolua_ret = (EditBox*)  EditBox::create(name,position,contentSize);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EditBox");
  }
 }
 return 1;
tolua_lerror:
 return tolua_CCGUI_EditBox_create00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_CCGUI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"TouchNode","TouchNode","CCNode",NULL);
  tolua_beginmodule(tolua_S,"TouchNode");
   tolua_function(tolua_S,"setName",tolua_CCGUI_TouchNode_setName00);
   tolua_function(tolua_S,"getName",tolua_CCGUI_TouchNode_getName00);
   tolua_function(tolua_S,"isTouchable",tolua_CCGUI_TouchNode_isTouchable00);
   tolua_function(tolua_S,"setTouchable",tolua_CCGUI_TouchNode_setTouchable00);
   tolua_variable(tolua_S,"__CCTargetedTouchDelegate__",tolua_get_TouchNode___CCTargetedTouchDelegate__,NULL);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Widget","Widget","TouchNode",NULL);
  tolua_beginmodule(tolua_S,"Widget");
   tolua_function(tolua_S,"getParentWidget",tolua_CCGUI_Widget_getParentWidget00);
   tolua_function(tolua_S,"get",tolua_CCGUI_Widget_get00);
   tolua_function(tolua_S,"touchBegin",tolua_CCGUI_Widget_touchBegin00);
   tolua_function(tolua_S,"touchMove",tolua_CCGUI_Widget_touchMove00);
   tolua_function(tolua_S,"touchEnd",tolua_CCGUI_Widget_touchEnd00);
   tolua_function(tolua_S,"touchCancel",tolua_CCGUI_Widget_touchCancel00);
   tolua_function(tolua_S,"isFrontable",tolua_CCGUI_Widget_isFrontable00);
   tolua_function(tolua_S,"enableFront",tolua_CCGUI_Widget_enableFront00);
   tolua_function(tolua_S,"create",tolua_CCGUI_Widget_create00);
   tolua_function(tolua_S,"setPosition",tolua_CCGUI_Widget_setPosition00);
   tolua_function(tolua_S,"setContentSize",tolua_CCGUI_Widget_setContentSize00);
   tolua_function(tolua_S,"isChildOf",tolua_CCGUI_Widget_isChildOf00);
   tolua_function(tolua_S,"addWidget",tolua_CCGUI_Widget_addWidget00);
   tolua_function(tolua_S,"removeWidget",tolua_CCGUI_Widget_removeWidget00);
  tolua_endmodule(tolua_S);
  tolua_function(tolua_S,"widget_manager_init",tolua_CCGUI_widget_manager_init00);
  tolua_function(tolua_S,"widget_manager_release",tolua_CCGUI_widget_manager_release00);
  tolua_cclass(tolua_S,"ImageBox","ImageBox","Widget",NULL);
  tolua_beginmodule(tolua_S,"ImageBox");
   tolua_function(tolua_S,"create",tolua_CCGUI_ImageBox_create00);
   tolua_function(tolua_S,"setContentSize",tolua_CCGUI_ImageBox_setContentSize00);
   tolua_function(tolua_S,"setBackSprite",tolua_CCGUI_ImageBox_setBackSprite00);
   tolua_function(tolua_S,"getBackSprite",tolua_CCGUI_ImageBox_getBackSprite00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCBWidget","CCBWidget","Widget",NULL);
  tolua_beginmodule(tolua_S,"CCBWidget");
   tolua_function(tolua_S,"create",tolua_CCGUI_CCBWidget_create00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ScrollView","ScrollView","Widget",NULL);
  tolua_beginmodule(tolua_S,"ScrollView");
   tolua_function(tolua_S,"setContentSize",tolua_CCGUI_ScrollView_setContentSize00);
   tolua_function(tolua_S,"getCanvas",tolua_CCGUI_ScrollView_getCanvas00);
   tolua_function(tolua_S,"setCanvas",tolua_CCGUI_ScrollView_setCanvas00);
   tolua_function(tolua_S,"setViewOffset",tolua_CCGUI_ScrollView_setViewOffset00);
   tolua_function(tolua_S,"getViewOffset",tolua_CCGUI_ScrollView_getViewOffset00);
   tolua_function(tolua_S,"setVisibleVScroll",tolua_CCGUI_ScrollView_setVisibleVScroll00);
   tolua_function(tolua_S,"isVisibleVScroll",tolua_CCGUI_ScrollView_isVisibleVScroll00);
   tolua_function(tolua_S,"setVisibleHScroll",tolua_CCGUI_ScrollView_setVisibleHScroll00);
   tolua_function(tolua_S,"isVisibleHScroll",tolua_CCGUI_ScrollView_isVisibleHScroll00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"ItemBox","ItemBox","ScrollView",NULL);
  tolua_beginmodule(tolua_S,"ItemBox");
   tolua_function(tolua_S,"setContentSize",tolua_CCGUI_ItemBox_setContentSize00);
   tolua_function(tolua_S,"addItem",tolua_CCGUI_ItemBox_addItem00);
   tolua_function(tolua_S,"removeItem",tolua_CCGUI_ItemBox_removeItem00);
   tolua_function(tolua_S,"setCaption",tolua_CCGUI_ItemBox_setCaption00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"EditBox","EditBox","Widget",NULL);
  tolua_beginmodule(tolua_S,"EditBox");
   tolua_function(tolua_S,"create",tolua_CCGUI_EditBox_create00);
   tolua_function(tolua_S,"create",tolua_CCGUI_EditBox_create01);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_CCGUI (lua_State* tolua_S) {
 return tolua_CCGUI_open(tolua_S);
};
#endif


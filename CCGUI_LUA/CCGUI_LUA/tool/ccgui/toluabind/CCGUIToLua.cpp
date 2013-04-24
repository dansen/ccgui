/*
** Lua binding: CCGUI
** Generated automatically by tolua++-1.0.92 on Mon Apr 22 13:52:39 2013.
*/

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "tolua++.h"

/* Exported function */
TOLUA_API int  tolua_CCGUI_open (lua_State* tolua_S);

#include "CCGUIToLua.h"
#include "MCCUtil.h"
#include "CCUtil.h"

/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"MCCUtil");
 tolua_usertype(tolua_S,"std::vector<std::string>");
 tolua_usertype(tolua_S,"CCNode");
 tolua_usertype(tolua_S,"Subject");
 tolua_usertype(tolua_S,"CCAction");
 tolua_usertype(tolua_S,"LUA_FUNCTION");
 tolua_usertype(tolua_S,"CCObject");
 tolua_usertype(tolua_S,"CCUtil");
 tolua_usertype(tolua_S,"CCValue");
}

/* method: make of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_make00
static int tolua_CCGUI_CCValue_make00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   CCValue* tolua_ret = (CCValue*)  CCValue::make();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'make'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putString of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_putString00
static int tolua_CCGUI_CCValue_putString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
  const char* s = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putString'", NULL);
#endif
  {
   self->putString(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putNumber of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_putNumber00
static int tolua_CCGUI_CCValue_putNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
  double f = ((double)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putNumber'", NULL);
#endif
  {
   self->putNumber(f);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putInt of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_putInt00
static int tolua_CCGUI_CCValue_putInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
  int i = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putInt'", NULL);
#endif
  {
   self->putInt(i);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: putBool of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_putBool00
static int tolua_CCGUI_CCValue_putBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
  bool b = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'putBool'", NULL);
#endif
  {
   self->putBool(b);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'putBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getString of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_getString00
static int tolua_CCGUI_CCValue_getString00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getString'", NULL);
#endif
  {
   std::string tolua_ret = (std::string)  self->getString();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getString'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNumber of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_getNumber00
static int tolua_CCGUI_CCValue_getNumber00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getNumber'", NULL);
#endif
  {
   double tolua_ret = (double)  self->getNumber();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNumber'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getInt of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_getInt00
static int tolua_CCGUI_CCValue_getInt00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getInt'", NULL);
#endif
  {
   int tolua_ret = (int)  self->getInt();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getInt'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getBool of class  CCValue */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCValue_getBool00
static int tolua_CCGUI_CCValue_getBool00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"CCValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCValue* self = (CCValue*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getBool'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->getBool();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getBool'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: notify of class  Subject */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Subject_notify00
static int tolua_CCGUI_Subject_notify00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Subject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Subject* self = (Subject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'notify'", NULL);
#endif
  {
   self->notify();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'notify'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: attach of class  Subject */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Subject_attach00
static int tolua_CCGUI_Subject_attach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Subject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Subject* self = (Subject*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = *((LUA_FUNCTION*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'attach'", NULL);
#endif
  {
   self->attach(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'attach'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: detach of class  Subject */
#ifndef TOLUA_DISABLE_tolua_CCGUI_Subject_detach00
static int tolua_CCGUI_Subject_detach00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Subject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Subject* self = (Subject*)  tolua_tousertype(tolua_S,1,0);
  LUA_FUNCTION handler = *((LUA_FUNCTION*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'detach'", NULL);
#endif
  {
   self->detach(handler);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'detach'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: className of class  CCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCUtil_className00
static int tolua_CCGUI_CCUtil_className00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCUtil",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCObject* o = ((CCObject*)  tolua_tousertype(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  CCUtil::className(o);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'className'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: emptydata of class  CCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCUtil_emptydata00
static int tolua_CCGUI_CCUtil_emptydata00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   void* tolua_ret = (void*)  CCUtil::emptydata();
   tolua_pushuserdata(tolua_S,(void*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'emptydata'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setNodePri of class  CCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCUtil_setNodePri00
static int tolua_CCGUI_CCUtil_setNodePri00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCUtil",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  int pri = ((int)  tolua_tonumber(tolua_S,3,0));
  bool isSwallow = ((bool)  tolua_toboolean(tolua_S,4,0));
  {
   CCUtil::setNodePri(node,pri,isSwallow);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setNodePri'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getNodePri of class  CCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCUtil_getNodePri00
static int tolua_CCGUI_CCUtil_getNodePri00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCUtil",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"CCNode",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  CCNode* node = ((CCNode*)  tolua_tousertype(tolua_S,2,0));
  {
   int tolua_ret = (int)  CCUtil::getNodePri(node);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getNodePri'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: actionFunc of class  CCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCUtil_actionFunc00
static int tolua_CCGUI_CCUtil_actionFunc00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCUtil",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"CCValue",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  LUA_FUNCTION func = *((LUA_FUNCTION*)  tolua_tousertype(tolua_S,2,0));
  CCValue* v = ((CCValue*)  tolua_tousertype(tolua_S,3,0));
  {
   CCAction* tolua_ret = (CCAction*)  CCUtil::actionFunc(func,v);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"CCAction");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'actionFunc'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: subject of class  CCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_CCUtil_subject00
static int tolua_CCGUI_CCUtil_subject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"CCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Subject* tolua_ret = (Subject*)  CCUtil::subject();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Subject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'subject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: bundleUrl of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_bundleUrl00
static int tolua_CCGUI_MCCUtil_bundleUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  MCCUtil::bundleUrl();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'bundleUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: documentUrl of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_documentUrl00
static int tolua_CCGUI_MCCUtil_documentUrl00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  MCCUtil::documentUrl();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'documentUrl'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: jclock of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_jclock00
static int tolua_CCGUI_MCCUtil_jclock00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   double tolua_ret = (double)  MCCUtil::jclock();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'jclock'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getMacAddress of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_getMacAddress00
static int tolua_CCGUI_MCCUtil_getMacAddress00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   std::string tolua_ret = (std::string)  MCCUtil::getMacAddress();
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getMacAddress'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isIPad of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_isIPad00
static int tolua_CCGUI_MCCUtil_isIPad00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  MCCUtil::isIPad();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isIPad'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: isEnglish of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_isEnglish00
static int tolua_CCGUI_MCCUtil_isEnglish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   bool tolua_ret = (bool)  MCCUtil::isEnglish();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'isEnglish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: checkNet of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_checkNet00
static int tolua_CCGUI_MCCUtil_checkNet00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   int tolua_ret = (int)  MCCUtil::checkNet();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'checkNet'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showAlert of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_showAlert00
static int tolua_CCGUI_MCCUtil_showAlert00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* title = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* msg = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   MCCUtil::showAlert(title,msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showAlert'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: showHub of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_showHub00
static int tolua_CCGUI_MCCUtil_showHub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string msg = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   MCCUtil::showHub(msg);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'showHub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: hideHub of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_hideHub00
static int tolua_CCGUI_MCCUtil_hideHub00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   MCCUtil::hideHub();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'hideHub'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: download of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_download00
static int tolua_CCGUI_MCCUtil_download00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"LUA_FUNCTION",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string url = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string saveFile = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  LUA_FUNCTION scriptName = *((LUA_FUNCTION*)  tolua_tousertype(tolua_S,4,0));
  {
   MCCUtil::download(url,saveFile,scriptName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'download'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getData of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_getData00
static int tolua_CCGUI_MCCUtil_getData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  {
   std::string tolua_ret = (std::string)  MCCUtil::getData(key);
   tolua_pushcppstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getArray of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_getArray00
static int tolua_CCGUI_MCCUtil_getArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::vector<std::string>* arr = ((std::vector<std::string>*)  tolua_tousertype(tolua_S,3,0));
  {
   MCCUtil::getArray(key,*arr);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setArray of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_setArray00
static int tolua_CCGUI_MCCUtil_setArray00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<std::string>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::vector<std::string>* arr = ((std::vector<std::string>*)  tolua_tousertype(tolua_S,3,0));
  {
   MCCUtil::setArray(key,*arr);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setArray'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: setData of class  MCCUtil */
#ifndef TOLUA_DISABLE_tolua_CCGUI_MCCUtil_setData00
static int tolua_CCGUI_MCCUtil_setData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"MCCUtil",0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,2,0,&tolua_err) ||
     !tolua_iscppstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  std::string key = ((std::string)  tolua_tocppstring(tolua_S,2,0));
  std::string value = ((std::string)  tolua_tocppstring(tolua_S,3,0));
  {
   MCCUtil::setData(key,value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'setData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_CCGUI_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_cclass(tolua_S,"CCValue","CCValue","",NULL);
  tolua_beginmodule(tolua_S,"CCValue");
   tolua_function(tolua_S,"make",tolua_CCGUI_CCValue_make00);
   tolua_function(tolua_S,"putString",tolua_CCGUI_CCValue_putString00);
   tolua_function(tolua_S,"putNumber",tolua_CCGUI_CCValue_putNumber00);
   tolua_function(tolua_S,"putInt",tolua_CCGUI_CCValue_putInt00);
   tolua_function(tolua_S,"putBool",tolua_CCGUI_CCValue_putBool00);
   tolua_function(tolua_S,"getString",tolua_CCGUI_CCValue_getString00);
   tolua_function(tolua_S,"getNumber",tolua_CCGUI_CCValue_getNumber00);
   tolua_function(tolua_S,"getInt",tolua_CCGUI_CCValue_getInt00);
   tolua_function(tolua_S,"getBool",tolua_CCGUI_CCValue_getBool00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"Subject","Subject","",NULL);
  tolua_beginmodule(tolua_S,"Subject");
   tolua_function(tolua_S,"notify",tolua_CCGUI_Subject_notify00);
   tolua_function(tolua_S,"attach",tolua_CCGUI_Subject_attach00);
   tolua_function(tolua_S,"detach",tolua_CCGUI_Subject_detach00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"CCUtil","CCUtil","",NULL);
  tolua_beginmodule(tolua_S,"CCUtil");
   tolua_function(tolua_S,"className",tolua_CCGUI_CCUtil_className00);
   tolua_function(tolua_S,"emptydata",tolua_CCGUI_CCUtil_emptydata00);
   tolua_function(tolua_S,"setNodePri",tolua_CCGUI_CCUtil_setNodePri00);
   tolua_function(tolua_S,"getNodePri",tolua_CCGUI_CCUtil_getNodePri00);
   tolua_function(tolua_S,"actionFunc",tolua_CCGUI_CCUtil_actionFunc00);
   tolua_function(tolua_S,"subject",tolua_CCGUI_CCUtil_subject00);
  tolua_endmodule(tolua_S);
  tolua_cclass(tolua_S,"MCCUtil","MCCUtil","",NULL);
  tolua_beginmodule(tolua_S,"MCCUtil");
   tolua_function(tolua_S,"bundleUrl",tolua_CCGUI_MCCUtil_bundleUrl00);
   tolua_function(tolua_S,"documentUrl",tolua_CCGUI_MCCUtil_documentUrl00);
   tolua_function(tolua_S,"jclock",tolua_CCGUI_MCCUtil_jclock00);
   tolua_function(tolua_S,"getMacAddress",tolua_CCGUI_MCCUtil_getMacAddress00);
   tolua_function(tolua_S,"isIPad",tolua_CCGUI_MCCUtil_isIPad00);
   tolua_function(tolua_S,"isEnglish",tolua_CCGUI_MCCUtil_isEnglish00);
   tolua_function(tolua_S,"checkNet",tolua_CCGUI_MCCUtil_checkNet00);
   tolua_function(tolua_S,"showAlert",tolua_CCGUI_MCCUtil_showAlert00);
   tolua_function(tolua_S,"showHub",tolua_CCGUI_MCCUtil_showHub00);
   tolua_function(tolua_S,"hideHub",tolua_CCGUI_MCCUtil_hideHub00);
   tolua_function(tolua_S,"download",tolua_CCGUI_MCCUtil_download00);
   tolua_function(tolua_S,"getData",tolua_CCGUI_MCCUtil_getData00);
   tolua_function(tolua_S,"getArray",tolua_CCGUI_MCCUtil_getArray00);
   tolua_function(tolua_S,"setArray",tolua_CCGUI_MCCUtil_setArray00);
   tolua_function(tolua_S,"setData",tolua_CCGUI_MCCUtil_setData00);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_CCGUI (lua_State* tolua_S) {
 return tolua_CCGUI_open(tolua_S);
};
#endif


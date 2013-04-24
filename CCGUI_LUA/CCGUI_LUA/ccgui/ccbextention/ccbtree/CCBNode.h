//
//  CCBNode.h
//  UICodeGenerator
//
//  Created by dansen on 13-4-9.
//  Copyright (c) 2013年 bodhi. All rights reserved.
//

#ifndef __UICodeGenerator__CCBNode__
#define __UICodeGenerator__CCBNode__

#include <vector>
#include <string>

enum CCBNodeType{
    CT_NODE = 0,
    CT_SPRITE = 1,
    CT_SPRITE9 = 2,
    CT_SCROLL_VIEW = 3,
    CT_MENU = 4,
    CT_MENUITEM = 5,
    CT_LAYER = 6,
    CT_LABELTTF = 7,
};

struct CCBNodeProperty{
    CCBNodeType type;
    //we don't use cocos2d's CCPoint here because we wanna a pure ccb parser.
    float x;
    float y;
    float anchorX;
    float anchorY;
    float sx; //size.width
    float sy; //size.height
    float scaleX;
    float scaleY;
    float preferX;
    float preferY;
    std::string plist;
    std::string frameName;
    std::string touchHandle;
    //for label
    std::string text;
    CCBNodeProperty():x(0),y(0),sx(0),sy(0),anchorX(0.0f),anchorY(0.0f),scaleX(1),scaleY(1){}
};

struct CCBNode
{
    CCBNodeProperty * property;
    std::string name; //
    std::string typeName; //CCLayer, CCNode...
    std::string displayName; //
    int level;  //tree node level
    int tag;    //tag
    std::string script; //lua script
    
    std::vector<CCBNode*> children;
    typedef std::vector<CCBNode*>::iterator CCB_CHILDREN_ITR;
    CCBNode * parent;
    CCBNode():level(0),tag(0),parent(0){}
};

CCBNode * node_new(std::string name, CCBNode * parent, int level);
void node_release(CCBNode * node);

#endif  

//
//  CCBWidget.cpp
//  CCGUI
//
//  Created by CrazyApps on 13-4-21.
//
//

#include "CCBWidget.h"
#include "ScrollView.h"
#include "ItemBox.h"
#include "CCBFile.h"
#include "TextBox.h"
#include "ImageBox.h"
#include "Window.h"
using namespace cocos2d;
_CCGUI_NAMESPACE_BEGIN

static void _assignProperty(Widget * child, CCBNodeProperty * p)
{
    //position
    child->setPosition(CCPointMake(p->x, p->y));
    //anchor
    child->setAnchorPoint(CCPointMake(p->anchorX, p->anchorY));
    //scale
    child->setScaleX(p->scaleX);
    child->setScaleY(p->scaleY);
    //size
    
    //texture
    if(p->frameName.empty() == false){
        CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile(p->plist.c_str());
        if(p->type == CT_SPRITE9){
            CCSpriteFrame * frame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(p->frameName.c_str());
            dynamic_cast<ImageBox*>(child)->setBackSprite(cocos2d::extension::CCScale9Sprite::createWithSpriteFrame(frame));
        }else if(p->type == CT_SPRITE || p->type == CT_MENUITEM){
            dynamic_cast<ImageBox*>(child)->setBackSprite(CCSprite::createWithSpriteFrameName(p->frameName.c_str()));
        }else{
            printf("warning:unknow frame type %s\n", p->frameName.c_str());
        }
    }
    //content size
    if(p->type == CT_SPRITE || p->type == CT_MENUITEM){
        child->setContentSize(dynamic_cast<ImageBox*>(child)->getBackSprite()->getContentSize());
    }
    //s9s prefer size
    if(p->type == CT_SPRITE9){
        cocos2d::extension::CCScale9Sprite * sprite =
            dynamic_cast<cocos2d::extension::CCScale9Sprite *>(dynamic_cast<ImageBox*>(child)->getBackSprite());
        sprite->setPreferredSize(CCSizeMake(p->preferX, p->preferY));
        sprite->setAnchorPoint(CCPointMake(p->anchorX, p->anchorY));
    }
}

static Widget * _createFromNode(CCBNode * node)
{
    Widget * widget = 0;
    CCBNodeType type = node->property->type;
    if(type == CT_SPRITE){
        widget = ImageBox::create(node->displayName.c_str());
    }else if(type == CT_SCROLL_VIEW){
        widget = ScrollView::create(node->displayName.c_str());
        widget->setContentSize(CCSizeMake(node->property->sx, node->property->sy));
    }else if(type == CT_NODE){
        widget = Widget::create(node->displayName.c_str());
    }else if(type == CT_LAYER){
        widget = Window::create(node->displayName.c_str());
        widget->setContentSize(CCSizeMake(node->property->sx, node->property->sy));
        widget->setAnchorPoint(CCPointMake(node->property->anchorX, node->property->anchorY));
        widget->setPosition(CCPointMake(node->property->x, node->property->y));
        widget->ignoreAnchorPointForPosition(true);
    }else if(type == CT_SPRITE9){
        widget = ImageBox::create(node->displayName.c_str());
        
    }else if(type == CT_LABELTTF){
        TextBox * box = TextBox::create(node->displayName.c_str());
        box->setText(node->property->text.c_str());
        widget = box;
    }else if(type == CT_MENUITEM){
        widget = ImageBox::create(node->displayName.c_str());
    }else if(type == CT_MENU){
        widget = Widget::create(node->displayName.c_str());
    }else{
        widget = Widget::create(node->displayName.c_str());
        printf("warnig:unknow node type %s\n", node->typeName.c_str());
    }
    
    for(CCBNode::CCB_CHILDREN_ITR itr = node->children.begin(); itr != node->children.end(); ++itr){
        Widget * child = _createFromNode(*itr);
        CCBNodeProperty * p = (*itr)->property;
        _assignProperty(child, p);
        //printf("add child %s(%s) at %.2f %.2f\n",(*itr)->displayName.c_str(), (*itr)->name.c_str(), p->x, p->y);
        widget->addWidget(child);
    }
    
    return widget;
}


static Widget * _createFromRootNode(CCBNode * root)
{
    Widget * rootWidget = Widget::create(root->displayName.c_str());
    //the root handle the touch event last
    rootWidget->setPriority(CPRI_LOWEST);
    
    for(CCBNode::CCB_CHILDREN_ITR itr = root->children.begin(); itr != root->children.end(); ++itr){
        Widget * widget = _createFromNode(*itr);
        CCBNodeProperty * p = (*itr)->property;
        _assignProperty(widget, p);
        //printf("add child %s(%s) at %.2f %.2f\n",(*itr)->displayName.c_str(), (*itr)->name.c_str(), p->x, p->y);
        rootWidget->addWidget(widget);
    }
    
    return rootWidget;
}

CCBWidget * CCBWidget::create(std::string name, const char * ccbfileName)
{
    CCBWidget * box = new CCBWidget();
    if(box && box->init(ccbfileName)){
        box->setName(name);
        box->autorelease();
        return box;
    }
    delete box;
    return box;
}

bool CCBWidget::init(const char * filename)
{
    CCBFile * file = ccb_init(CCFileUtils::sharedFileUtils()->fullPathFromRelativePath(filename));
    m_widget = _createFromRootNode(file->tree->root);
    addWidget(m_widget);
    ccb_release(file);
    return true;
}

_CCGUI_NAMESPACE_END











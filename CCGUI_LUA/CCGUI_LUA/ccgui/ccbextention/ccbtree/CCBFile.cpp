//
//  CCBFile.cpp
//  UICodeGenerator
//
//  Created by dansen on 13-4-9.
//  Copyright (c) 2013年 bodhi. All rights reserved.
//
#include <fstream>
#include "CCBFile.h"
#include "tinyxml2.h"


static void _ccb_parse_array(tinyxml2::XMLElement * array, CCBNode * ccb);
static void _ccb_parse_dict(tinyxml2::XMLElement * dict, CCBNode * ccb);
static void _ccb_parse_property(tinyxml2::XMLElement * dict, CCBNode * ccb);
static void _gen_update(std::ofstream & ofs,CCBFile * file, const char * table);
static void _gen_release(std::ofstream & ofs,CCBFile * file, const char * table);

static void _ccb_parse_array(tinyxml2::XMLElement * array, CCBNode * ccb)
{
    tinyxml2::XMLElement * dict = array->FirstChildElement("dict");
    while(dict){
        _ccb_parse_dict(dict, ccb);
        dict = dict->NextSiblingElement("dict");
    }
}

static void _ccb_parse_dict(tinyxml2::XMLElement * dict, CCBNode * ccb)
{
    tinyxml2::XMLElement * key = dict->FirstChildElement("key");
    
    CCBNode * currentNode = ccb;
    //root
    while(key){
        tinyxml2::XMLElement * value = key->NextSiblingElement();
        if(value){
            
            if(value->Name() == std::string("dict")){
                _ccb_parse_dict(value, currentNode);
            }
            if(value->Name() == std::string("array")){
                _ccb_parse_array(value, currentNode);
            }
            if(key->GetText() == std::string("baseClass")){
                currentNode = node_new(value->GetText(), currentNode, currentNode->level+1);
                currentNode->typeName = value->GetText();
                if(currentNode->typeName == "CCSprite"){
                    currentNode->property->type = CT_SPRITE;
                }else if(currentNode->typeName == "CCLayer"){
                    currentNode->property->type = CT_LAYER;
                }else if(currentNode->typeName == "CCNode"){
                    currentNode->property->type = CT_NODE;
                }else if(currentNode->typeName == "CCScale9Sprite"){
                    currentNode->property->type = CT_SPRITE9;
                }else if(currentNode->typeName == "CCScrollView"){
                    currentNode->property->type = CT_SCROLL_VIEW;
                }else if(currentNode->typeName == "CCMenu"){
                    currentNode->property->type = CT_MENU;
                }else if(currentNode->typeName == "CCMenuItemImage"){
                    currentNode->property->type = CT_MENUITEM;
                }else if(currentNode->typeName == "CCLabelTTF"){
                    currentNode->property->type = CT_LABELTTF;
                }else{
                    printf("warning:unknow type %s\n", currentNode->typeName.c_str());
                }
            }
            
            if(key->GetText() == std::string("displayName")){
                currentNode->displayName = value->GetText();
            }
            
            if(value->GetText()){
                if(key->GetText() == std::string("customClass")){
                    currentNode->property->touchHandle = value->GetText();
                }
                
                if(value->GetText()== std::string("tag")){
                    currentNode->tag = atoi(value->NextSiblingElement("integer")->GetText());
                }
                if(value->GetText()== std::string("Block")){
                    tinyxml2::XMLElement * script = value->NextSiblingElement("array")->FirstChildElement("string");
                    
                    if(script->GetText() == 0){
                        printf("warning:CCMenuItemImage '%s' does not have script function!\n", currentNode->displayName.c_str());
                        currentNode->script = currentNode->displayName.c_str();
                    }else{
                        currentNode->script = script->GetText();
                    }
                }
                if(value->GetText() == std::string("Position")){
                    tinyxml2::XMLElement * x = value->NextSiblingElement("array")->FirstChildElement("real");
                    tinyxml2::XMLElement * y = x->NextSiblingElement("real");
                    currentNode->property->x = atoi(x->GetText());
                    currentNode->property->y = atoi(y->GetText());
                }
                if(value->GetText() == std::string("SpriteFrame")){
                    tinyxml2::XMLElement * plist = value->NextSiblingElement("array")->FirstChildElement("string");
                    tinyxml2::XMLElement * frameName = plist->NextSiblingElement("string");
                    
                    if(plist->GetText()){
                        currentNode->property->plist = plist->GetText();
                        currentNode->property->frameName = frameName->GetText();
                    }
                }
                if(value->GetText() == std::string("contentSize")){
                    tinyxml2::XMLElement * sx = value->NextSiblingElement("array")->FirstChildElement("real");
                    tinyxml2::XMLElement * sy = sx->NextSiblingElement("real");
                    
                    if(sx->GetText()){
                        currentNode->property->sx = atof(sx->GetText());
                        currentNode->property->sy = atof(sy->GetText());
                    }
                }
                if(value->GetText() == std::string("Text")){
                    tinyxml2::XMLElement * text = value->NextSiblingElement("string");
                    
                    if(text->GetText()){
                        currentNode->property->text = text->GetText();
                    }
                }
                if(value->GetText() == std::string("scale")){
                    tinyxml2::XMLElement * text = value->NextSiblingElement("string");
                    
                    if(text->GetText() == std::string("ScaleLock")){
                        tinyxml2::XMLElement * sx = value->NextSiblingElement("array")->FirstChildElement("real");
                        tinyxml2::XMLElement * sy = sx->NextSiblingElement("real");
                        currentNode->property->scaleX = atof(sx->GetText());
                        currentNode->property->scaleY = atof(sy->GetText());
                    }
                }
                if(value->GetText() == std::string("preferedSize")){
                    tinyxml2::XMLElement * text = value->NextSiblingElement("string");
                    tinyxml2::XMLElement * px = text->NextSiblingElement("array")->FirstChildElement("real");
                    tinyxml2::XMLElement * py = px->NextSiblingElement("real");
                    currentNode->property->preferX = atof(px->GetText());
                    currentNode->property->preferY = atof(py->GetText());
                }
                if(value->GetText() == std::string("anchorPoint")){
                    tinyxml2::XMLElement * text = value->NextSiblingElement("string");
                    tinyxml2::XMLElement * x = text->NextSiblingElement("array")->FirstChildElement("real");
                    tinyxml2::XMLElement * y = x->NextSiblingElement("real");
                    currentNode->property->anchorX = atof(x->GetText());
                    currentNode->property->anchorY = atof(y->GetText());
                }
            }
        }
        
        key = key->NextSiblingElement("key");
    }
}

CCBFile * ccb_init(const char * ccbfile)
{
    tinyxml2::XMLDocument doc;
    
    if(doc.LoadFile(ccbfile)){
        return 0;
    }
    
    tinyxml2::XMLElement * dict = doc.RootElement()->FirstChildElement("dict");
    CCBFile * ccb = new CCBFile();
    ccb->name = ccbfile;
    ccb->path = ccbfile;
    ccb->name = ccb->name.replace(ccb->name.size()-4, 4, "");
    ccb->tree = tree_new();
    _ccb_parse_dict(dict, ccb->tree->root);
    return ccb;
}

void ccb_release(CCBFile * file)
{
    if(file){
        tree_release(file->tree);
        delete file;
        file = 0;
    }
}

static void _ccb_load_type(CCBNode * parent, std::vector<CCBNode*> & menus, const char * type)
{
    if(parent == 0){
        return;
    }
    if(parent->typeName == std::string(type)){
        menus.push_back(parent);
    }
    for(int i=0; i<parent->children.size(); ++i){
        _ccb_load_type(parent->children[i], menus, type);
    }
}

static void _ccb_load_menu(CCBNode * parent, std::vector<CCBNode*> & menus)
{
    _ccb_load_type(parent, menus, "CCMenuItemImage");
}

static std::string _ccb_analysis_tags(CCBNode * node)
{
    CCBNode * p = node;
    char tmp[32] = "";
    char tmp2[32] = "";
    while(p->parent->parent){
        sprintf(tmp2, "%d, %s", p->tag, tmp);
        sprintf(tmp, "%s" , tmp2);
        p = p->parent;
    }
    tmp[strlen(tmp)-2] = '\0';
    return tmp;
}
static void _gen_head(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    
    ofs<<"--code generated by UICodeGenerator.\n\n";
    //table file
    sprintf(tmp,"%s = {\n\t%sUI = nil, \n\tparentUI = nil,\n}\n\n", table, table);
    ofs<<tmp;
}
static void _gen_s9sprite(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    std::vector<CCBNode*> spr9s;
    _ccb_load_type(file->tree->root, spr9s, "CCScale9Sprite");
    ofs<<"\n\t--scale9sprites\n";
    for(int i=0; i<spr9s.size(); ++i){
        CCBNode * node = spr9s[i];
        std::string tags = _ccb_analysis_tags(node);
        char varName[64];
        bool eq = node->displayName==node->typeName;
        if(eq){
            sprintf(varName, "%s%d", "scale9spr", i+1);
        }else{
            sprintf(varName, "%s", node->displayName.c_str());
        }
        
        sprintf(tmp, "\t%s.%s = getScaleSpriteByTags(%s.%sUI, %s)\n",table, varName, table, table, tags.c_str());
        printf("%s", tmp);
        ofs<<tmp;
    }
}
static void _gen_sprite(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    std::vector<CCBNode*> sprites;
    _ccb_load_type(file->tree->root, sprites, "CCSprite");
    ofs<<"\n\t--sprites\n";
    for(int i=0; i<sprites.size(); ++i){
        CCBNode * node = sprites[i];
        std::string tags = _ccb_analysis_tags(node);
        char varName[64];
        bool eq = node->displayName==node->typeName;
        if(eq){
            sprintf(varName, "%s%d", "sprite", i+1);
        }else{
            sprintf(varName, "%s", node->displayName.c_str());
        }
        
        sprintf(tmp, "\t%s.%s = getSpriteByTags(%s.%sUI, %s)\n",table, varName, table, table, tags.c_str());
        printf("%s", tmp);
        ofs<<tmp;
    }
}
static void _gen_menu(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    std::vector<CCBNode*> menus;
    _ccb_load_menu(file->tree->root, menus);
    
    ofs<<"\n\t--menus\n";
    for(int i=0; i<menus.size(); ++i){
        CCBNode * node = menus[i];
        ofs<<"\tlocal function "<<node->script<<"(m, s)\n";
        ofs<<"\t\tif s~=3 then return end\n";
        ofs<<"\tend\n";
        ofs<<"\n";
    }
    for(int i=0; i<menus.size(); ++i){
        CCBNode * node = menus[i];
        std::string tags = _ccb_analysis_tags(node);
        char varName[64];
        bool eq = node->displayName==node->typeName;
        if(eq){
            sprintf(varName, "%s%d", "menu", i+1);
        }else{
            sprintf(varName, "%s", node->displayName.c_str());
        }
        
        sprintf(tmp, "\t%s.%s = getBtnByTagsEx(%s.%sUI, 1, %s, %s)\n",table, varName, table, table, node->script.c_str(), tags.c_str());
        printf("%s", tmp);
        ofs<<tmp;
    }
}
static void _gen_scroll(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    ofs<<"\n\t--scrolls\n";
    std::vector<CCBNode*> scrolls;
    _ccb_load_type(file->tree->root, scrolls, "CCScrollView");
    for(int i=0; i<scrolls.size(); ++i){
        CCBNode * node = scrolls[i];
        std::string tags = _ccb_analysis_tags(node);
        
        char varName[64];
        bool eq = node->displayName==node->typeName;
        if(eq){
            sprintf(varName, "%s%d", "scroll", i+1);
        }else{
            sprintf(varName, "%s", node->displayName.c_str());
        }
        
        sprintf(tmp, "\t%s.%s = getScrollByTagsEx(%s.%sUI, 2, %s)\n\n",table, varName, table, table, tags.c_str());
        printf("%s", tmp);
        ofs<<tmp;
    }
}
static void _gen_label(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    ofs<<"\n\t--labels\n";
    std::vector<CCBNode*> labels;
    _ccb_load_type(file->tree->root, labels, "CCLabelTTF");
    for(int i=0; i<labels.size(); ++i){
        CCBNode * node = labels[i];
        std::string tags = _ccb_analysis_tags(node);
        
        char varName[64];
        bool eq = node->displayName==node->typeName;
        if(eq){
            sprintf(varName, "%s%d", "label", i+1);
        }else{
            sprintf(varName, "%s", node->displayName.c_str());
        }
        
        sprintf(tmp, "\t%s.%s = getLabelByTags(%s.%sUI, %s)\n",table, varName, table, table, tags.c_str());
        printf("%s", tmp);
        ofs<<tmp;
    }
}
static void _gen_init_begin(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    //init
    sprintf(tmp, "function %s.init(ui)\n", table);
    ofs<<tmp;
    //copy
    sprintf(tmp, "\tlocal %s = util:deepCopy(%s)\n", table, table);
    ofs<<tmp;
    //
    CCBNode * top = file->tree->root->children[0];
    
    if(top->typeName == "CCLayer"){
        sprintf(tmp,"\t%s.parentUI = ui\n\t%s.%sUI = util:loadLayer(\"%si\", %s.parentUI, true)\n",
                table, table, table, file->path.c_str(), table);
    }else if(top->typeName == "CCNode"){
        sprintf(tmp,"\t%s.parentUI = ui\n\t%s.%sUI = util:loadNode(\"%si\", %s.parentUI)\n",
                table, table, table, file->path.c_str(), table);
    }else{
        printf("%s not support!", top->typeName.c_str());
        return;
    }
    ofs<<tmp;
}
static void _gen_init_end(std::ofstream & ofs,CCBFile * file, const char * table)
{
    //update function
    _gen_update(ofs, file, table);
    //release function
    _gen_release(ofs, file, table);
    char tmp[1024] = "";
    sprintf(tmp, "\n\t--return\n\treturn %s\nend\n\n", table);
    ofs<<tmp;
}
static void _gen_update(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    sprintf(tmp, "\t--update\n\tfunction %s.update(data)\n\n\tend\n", table);
    ofs<<tmp;
}
static void _gen_release(std::ofstream & ofs,CCBFile * file, const char * table)
{
    char tmp[1024] = "";
    sprintf(tmp, "\t--release\n\tfunction %s.release()\n\t\tutil:removeNode(%s.%sUI)\n\tend",table, table, table);
    ofs<<tmp;
}

void ccb_luacode(CCBFile * file, const char * luafile, const char * table)
{
    if(!file){
        return;
    }
    
    std::ofstream ofs(luafile);
    char tmp[1024] = "";
    _gen_head(ofs,file, table);

    //init function
    _gen_init_begin(ofs, file, table);
    //spr9
    _gen_s9sprite(ofs, file, table);
    //sprites
    _gen_sprite(ofs, file, table);
    //menus
    _gen_menu(ofs, file, table);
    //labels
    _gen_label(ofs, file, table);
    //scroll view
    _gen_scroll(ofs, file, table);
    //end
    _gen_init_end(ofs, file, table);
    
    ofs.close();
}

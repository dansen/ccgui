//
//  CCBFile.h
//  UICodeGenerator
//
//  Created by dansen on 13-4-9.
//  Copyright (c) 2013年 bodhi. All rights reserved.
//

#ifndef __UICodeGenerator__CCBFile__
#define __UICodeGenerator__CCBFile__

#include "CCBTree.h"

struct CCBFile{
    int level;
    std::string path;
    std::string name;
    CCBTree * tree;
    CCBFile():level(0),tree(0){}
};

CCBFile * ccb_init(const char * ccbfile);
void ccb_release(CCBFile * file);
void ccb_luacode(CCBFile * file, const char * luafile, const char * table);

#endif

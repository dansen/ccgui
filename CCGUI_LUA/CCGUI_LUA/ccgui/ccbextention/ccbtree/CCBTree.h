//
//  CCBTree.h
//  UICodeGenerator
//
//  Created by dansen on 13-4-9.
//  Copyright (c) 2013年 bodhi. All rights reserved.
//

#ifndef __UICodeGenerator__CCBTree__
#define __UICodeGenerator__CCBTree__

#include "CCBNode.h"

struct CCBTree{
    CCBNode * root;
    CCBTree():root(0){}
};


CCBTree * tree_new();
void tree_release(CCBTree * tree);



#endif  

//
//  CCBTree.cpp
//  UICodeGenerator
//
//  Created by dansen on 13-4-9.
//  Copyright (c) 2013年 bodhi. All rights reserved.
//

#include "CCBTree.h"


CCBTree * tree_new()
{
    CCBTree * tree = new CCBTree();
    tree->root = node_new("root", 0, 0);
    return tree;
}
void tree_release(CCBTree * tree)
{
    if(tree){
        node_release(tree->root);
        delete tree;
        tree = 0;
    }
}












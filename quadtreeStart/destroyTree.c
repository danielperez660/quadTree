#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "treeStructure.h"
#include "writeTree.h"
#include "buildTree.h"

void destroyTree(Node *node){

    int i;

    if(node->child[0] == NULL){
    	free(node);
    }else{
    	for (i = 0; i < 4; ++i){
    		destroyTree(node->child[i]);
    	}
    	free(node);
    }

	return;
}

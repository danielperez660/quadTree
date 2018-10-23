#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "treeStructure.h"
#include "writeTree.h"
#include "buildTree.h"

void growTree(Node *node, FILE *fp, int x){

	int i;

  //Checks if the maximum size has been reached
  if(node->level > x){
    return;
  }

  if(node->child[0] == NULL){
    makeChildren(node);
    writeNode(fp, node, x);
  }else{
    for (i = 0; i < 4; ++i){
    	growTree(node->child[i], fp, x);
    }
  }

  return;
}

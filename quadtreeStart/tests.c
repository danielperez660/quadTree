#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "treeStructure.h"
#include "writeTree.h"
#include "buildTree.h"
#include "destroyTree.h"
#include "valueTree.h"

void task1() {

  Node *head;

  // make the head node
  head = makeNode(0.0,0.0, 0);

  //make a tree, Full level 2 tree
  makeChildren(head);
  makeChildren(head->child[0]);
  makeChildren(head->child[1]);
  makeChildren(head->child[2]);
  makeChildren(head->child[3]);

  //make a tree, non uniform level 3 tree
  makeChildren((head->child[2])->child[0]);
  makeChildren((head->child[3])->child[2]);

  //print the tree for Gnuplot
  writeTree(head);

  //destroys tree at the end of the program
  destroyTree(head);

  return;
}

void task2(){

  Node *head;

  // make the head node
  head = makeNode(0.0,0.0, 0);

  makeChildren(head);
  makeChildren(head->child[0]);
  makeChildren(head->child[1]);
  makeChildren(head->child[2]);
  makeChildren(head->child[3]);

  //make a tree, non uniform level 3 tree
  makeChildren((head->child[2])->child[0]);
  makeChildren((head->child[3])->child[2]);

  //print the tree for Gnuplot
  writeTree(head);

  //goes to leaf nodes and grows them by 1 level
  FILE *fp = fopen("quad.out","w");
  growTree(head , fp, 7);
  fclose(fp);

  //destroys tree at the end of the program
  destroyTree(head);

  return;
}

void task3(int y){
  Node *head;

  int i = 0;

  //make a tree, Full level 2 tree
  head = makeNode(0.0,0.0, 0);

  makeChildren(head);
  makeChildren(head->child[0]);
  makeChildren(head->child[1]);
  makeChildren(head->child[2]);
  makeChildren(head->child[3]);

  //make a tree, non uniform level 3 tree
  makeChildren((head->child[2])->child[0]);
  makeChildren((head->child[3])->child[2]);

  //Creates a max y level tree
  for(i; i < 7; i ++){
    FILE *fp = fopen("quad.out","w");
    growTree( head , fp, y-1);
    fclose(fp);
  }

  //print the tree for Gnuplot
  writeTree(head);

  //destroys tree at the end of the program
  destroyTree(head);

  return;
}

void task4_2(Node *node, FILE *fp, int *counter, double tol, int choice){
  int i;

  //Loops through the entire tree finding leaf nodes
  if(node->child[0] == NULL){
    if(indicator(node, tol ,choice) == false){
      makeChildren(node);
      writeNode(fp, node, 10);
      *counter+=1;
    }
  }else{
    for (i = 0; i < 4; ++i){
    	task4_2(node->child[i], fp, counter, tol, choice);
    }
  }
  return;
}

void task4(double tol, int choice){
    Node *head;
    int counter = 0;
    int prev, temp;

    //make a tree, Full level 2 tree
    head = makeNode(0.0,0.0, 0);

    makeChildren(head);
    makeChildren(head->child[0]);
    makeChildren(head->child[1]);
    makeChildren(head->child[2]);
    makeChildren(head->child[3]);

    //Runs the leaf finding algorythm
    FILE *fp = fopen("quad.out","w");

    //Checks that the change to the counter is 0, if it is 0 then the program does not run
    do{
      task4_2(head, fp, &counter, tol, choice);
      temp = counter - prev;
      prev = counter;
      counter = 0;
    }while(temp != 0);

    fclose(fp);

    //print the tree for Gnuplot
    writeTree(head);

    //destroys tree at the end of the program
    destroyTree(head);

    return;
}

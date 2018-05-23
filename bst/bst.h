/*
 * Generic binary search tree (bst) TDA interface
 * 'data' is a pointer to some data struct that allegedly
 * holds some data. This TDA uses 'queue' TDA to implemnent
 * the
 *
 * Behold the macro 'QDEQUEUE' inside the 'stack_macros.h' file
  * since it handles the way the data is treated. Is important
 * to remark that on 'dequeing' (queueDeq) the node of the list
 * is free'd. In that case what you'd do with 'data' (which happens
 * to be inside the node being release)? Enter'QDEQUEUE'
 *
 * Behold the bst_macros.h file, there should be some interesting macros
 * to control the behavior when doing some common operations on the tree
 *
 * For level order tour a queue is requiered. So compile with:
 * gcc -g -Wall -o bst bst/main.c bst/bst.c queue/queue.c linked_list/linked_list.c
 *
 */

#ifndef _BST_H_
#define _BST_H_
#include <sys/types.h>
#include "../queue/queue.h"

typedef struct bstn {
    void *data;
    struct bstn *left;
    struct bstn *right;
    struct bstn *parent;
} BSTNODE;

PUBLIC BSTNODE *bstInsert(BSTNODE *tree, void *data);
PUBLIC BSTNODE *bstSearch(BSTNODE *tree, void *data);
PUBLIC BSTNODE *bstSearchParent(BSTNODE *tree, BSTNODE *node);
PUBLIC BSTNODE *bstFindMax(BSTNODE *tree);
PUBLIC BSTNODE *bstFindMin(BSTNODE *tree);

PUBLIC int bstFindHeight(BSTNODE *tree);
PUBLIC int bstFindDepth(BSTNODE *tree, BSTNODE *node);

PUBLIC void bstDelete(BSTNODE *tree, void *data);
PUBLIC void bstPreOrder(BSTNODE *tree);
PUBLIC void bstInOrder(BSTNODE *tree);
PUBLIC void bstLevelOrder(BSTNODE *tree, void *unk);
PUBLIC void bstPostOrder(BSTNODE *tree);
PUBLIC void *bstDealloc(BSTNODE *tree);
PUBLIC u_short bstIsLeaf(BSTNODE *tree);

#endif // _BST_H_

/* Macros */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Own includes */
#include "bst.h"
#include "bst_macros.h"

/* Enums & Structs */

/* Glocal variables */

/* Private prototypes */
PRIVATE void _bstLevelOrder(BSTNODE *tree, QUEUE *queue, void *unk);
PRIVATE BSTNODE *_bstInsert(BSTNODE *tree, void *data);

/* Functions definitions */
PUBLIC BSTNODE *bstInsert(BSTNODE *tree, void *data)
{
        if (tree == NULL)
                return _bstInsert(tree, data);
        else if (CMPFUNC(data, tree->data, _LESSER_)) {
                tree->left = bstInsert(tree->left, data);
                tree->left->parent = tree;
        } else {
                tree->right = bstInsert(tree->right, data);
                tree->right->parent = tree;
        }
        return tree;
}

PUBLIC BSTNODE *bstSearch(BSTNODE *tree, void *data)
{
        if (tree == NULL || data == NULL)
                return NULL;
        if (CMPFUNC(data, tree->data, _EQUAL_))
                return tree;
        else if (CMPFUNC(data, tree->data, _LESSER_))
                return bstSearch(tree->left, data);
        else
                return bstSearch(tree->right, data);
}

PUBLIC u_short bstIsLeaf(BSTNODE *tree)
{
        if(tree == NULL || (tree->left == NULL && tree->right == NULL))
                return TRUE;
        return FALSE;
}

PUBLIC void bstDelete(BSTNODE *tree, void *data)
{
    /*
     * If tree is only a leaf then do nothing because that
     * would leave dangling pointers (like the one that is
     * used in bstDealloc())
     */
        u_short sw;
        BSTNODE *del, *dSon, *aux;

        if (tree == NULL)
                return;
        sw = FALSE;
        dSon = NULL;
        del = bstSearch(tree, data);
        aux = del;

        if (bstIsLeaf(tree) || del == NULL)
                return;
        if (tree == del || (del->left != NULL && del->right != NULL)) {
                sw = TRUE;
                if (del->left != NULL)
                        del = bstFindMax(del->left);
                else
                        del = bstFindMin(del->right);
        }

        if (del->left != NULL)
                dSon = del->left;
        else
                dSon = del->right;

        if (sw)
                BSTREASSIGN(aux->data, del->data);
        #ifdef BSTFREEDATA
                BSTFREEDATA(del->data);
        #endif
        if (del->parent->left == del)
                del->parent->left = dSon;
        else
                del->parent->right = dSon;
        if (dSon != NULL)
                dSon->parent = del->parent;
        free(del);
}

PUBLIC int bstFindHeight(BSTNODE *tree)
{
        int hl, hr;

        if (tree == NULL)
                return -1;
        hl = bstFindHeight(tree->left) + 1;
        hr = bstFindHeight(tree->right) + 1;
        return hl > hr ? hl : hr;
}

PUBLIC int bstFindDepth(BSTNODE *tree, BSTNODE *node)
{
        int depth;

        depth = 0;
        if (tree == NULL || node == NULL)
                return -1;
        while (TRUE) {
                if (CMPFUNC(node->data, tree->data, _EQUAL_))
                        break;
                else if (CMPFUNC(node->data, tree->data, _LESSER_))
                        tree = tree->left;
                else
                        tree = tree->right;
                depth++;
        }
        return depth;
}

PUBLIC BSTNODE *bstFindMax(BSTNODE *tree)
{
        BSTNODE *righty;

        righty = tree;
        if (righty == NULL)
                return NULL;
        while(righty->right != NULL)
                righty = righty->right;
        return righty;
}

PUBLIC BSTNODE *bstFindMin(BSTNODE *tree)
{
        BSTNODE *lefty;

        lefty = tree;
        if (lefty == NULL)
                return NULL;
        while (lefty->left != NULL)
                lefty = lefty->left;
        return lefty;
}

PUBLIC void bstPreOrder(BSTNODE *tree)
{
        if (tree == NULL)
                return;
        #ifdef BSTPRINT
                if (tree->parent == NULL) {
                        BSTPRINT(tree->data, NULL);
                } else {
                        BSTPRINT(tree->data, tree->parent->data);
                }
        #endif
        bstPreOrder(tree->left);
        bstPreOrder(tree->right);
}

PUBLIC void bstInOrder(BSTNODE *tree)
{
        if (tree == NULL)
                return;
        bstInOrder(tree->left);
        #ifdef BSTPRINT
                if (tree->parent == NULL) {
                        BSTPRINT(tree->data, NULL);
                } else {
                        BSTPRINT(tree->data, tree->parent->data);
                }
        #endif
        bstInOrder(tree->right);
}

PUBLIC void bstPostOrder(BSTNODE *tree)
{
        if (tree == NULL)
                return;
        bstPostOrder(tree->left);
        bstPostOrder(tree->right);
        #ifdef BSTPRINT
                if (tree->parent == NULL) {
                        BSTPRINT(tree->data, NULL);
                } else {
                        BSTPRINT(tree->data, tree->parent->data);
                }
        #endif
}

PUBLIC void bstLevelOrder(BSTNODE *tree, void *unk)
{
        QUEUE *queue;

        queue = queueCreate();
        queueEnq(queue, tree);
        _bstLevelOrder(tree, queue, unk);
        queueDelete(queue);
}

PUBLIC void *bstDealloc(BSTNODE *tree)
{
        if (tree == NULL)
                return NULL;
        bstDealloc(tree->left);
        bstDealloc(tree->right);
        if (tree->data != NULL) {
                #ifdef BSTFREEDATA
                        BSTFREEDATA(tree->data);
                #endif
        }
        free(tree);
        return NULL;
}

PRIVATE BSTNODE *_bstInsert(BSTNODE *tree, void *data)
{
        BSTNODE *node;

        node = calloc(1, sizeof(BSTNODE));
        if (node == NULL)
                return NULL;
        node->data = data;
        node->parent = NULL;
        node->left = NULL;
        node->right = NULL;
        return node;
}

PRIVATE void _bstLevelOrder(BSTNODE *tree, QUEUE *queue, void *unk)
{
    /* breadth-first tour */

        BSTNODE *ptr;

        if (queue == NULL)
                return;
        ptr = (BSTNODE *)queueDeq(queue);
        if (ptr == NULL)
                return;
        if (ptr->left != NULL)
                queueEnq(queue, ptr->left);
        if (ptr->right != NULL)
                queueEnq(queue, ptr->right);
        BSTLEVELORDER(tree, ptr, unk);
        _bstLevelOrder(tree, queue, unk);
}

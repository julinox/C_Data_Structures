#ifndef _BST_MACROS_H_
#define _BST_MACROS_H_

#define BSTFREEDATA(data)
#define BSTREASSIGN(dest, src) dest = src
#define BSTLEVELORDER(tree, bstNode, unk) exampleFunc(tree, bstNode, unk)
#define BSTPRINT(data, pData) pData == NULL ? \
    printf("%d[], ", CAST data) : \
    printf("%d[%d], ", CAST data, CAST pData);
#define INT *(int *)
#define CAST INT
#define CMPFUNC(d1, d2, cmp) \
        cmp == _GREATER_ ? (CAST d1 > CAST d2 ? TRUE : FALSE) : \
        (cmp == _LESSER_ ? (CAST d1 < CAST d2 ? TRUE : FALSE) : \
        (CAST d1 == CAST d2 ? TRUE : FALSE))

void exampleFunc(BSTNODE *tree, BSTNODE *bstNode, void *unk)
{
    /*
     * Proof of concept function
     */
        int depth, *pDepth;

        pDepth = (int *) unk;
        depth = bstFindDepth(tree, bstNode);
        if (depth != *pDepth) {
                printf(" || ");
                (*pDepth)++;

        }
        printf("%d, ", CAST bstNode->data);
}

#endif // _BST_MACROS_H_

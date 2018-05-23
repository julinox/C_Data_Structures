/*
 * Generic double linked list TDA interface
 * 'data' is a pointer to some data struct that allegedly
 * holds some data. Macros inside the double linked_list_macros.h
 * will do the 'data' release/free management.
 */


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <sys/types.h>
#include "../ds_general_defs.h"

typedef struct dll {
        void *data;
        struct dll *next;
        struct dll *prev;
} DL_LIST;

PUBLIC DL_LIST *dLinkedListCreate();
PUBLIC DL_LIST *dLinkedListAddNode(DL_LIST *head, void *data);
PUBLIC DL_LIST *dLinkedListSearch(DL_LIST *head, void *data);

PUBLIC DL_LIST *dLinkedListDelete(DL_LIST *head);
PUBLIC void dLinkedListDeleteNode(DL_LIST *head, DL_LIST *node);
PUBLIC void dLinkedListPrint(DL_LIST *head);

#endif //_LINKED_LIST_H_

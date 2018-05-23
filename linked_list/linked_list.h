/*
 * Generic linked list TDA interface
 * 'data' is a pointer to some data struct that allegedly
 * holds some data. Macros inside the linked_list_macros.h
 * will do the 'data' release/free management.
 */


#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include <sys/types.h>
#include "../ds_general_defs.h"

typedef struct ll {
        void *data;
        struct ll *next;
} LIST;

PUBLIC LIST *linkedListCreate();
PUBLIC LIST *linkedListAddNode(LIST *head, void *data);
PUBLIC LIST *linkedListSearch(LIST *head, void *data);

PUBLIC LIST *linkedListDelete(LIST *head);
PUBLIC void linkedListDeleteNode(LIST *head, LIST *node);
PUBLIC void linkedListPrint(LIST *head);

#endif //_LINKED_LIST_H_

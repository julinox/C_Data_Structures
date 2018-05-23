/* Macros */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Own includes */
#include "double_linked_list.h"
#include "double_linked_list_macros.h"

/* Enums & Structs */

/* Glocal variables */

/* Private prototypes */

/* Functions definitions */
PUBLIC DL_LIST *dLinkedListCreate()
{
        DL_LIST *head;

        head = calloc(1, sizeof(DL_LIST));
        if (head == NULL)
                return NULL;
        head->data = NULL;
        head->next = NULL;
        head->prev = NULL;
        return head;
}

PUBLIC DL_LIST *dLinkedListDelete(DL_LIST *head)
{
        DL_LIST *aux, *dispose;

        if (head == NULL)
                return NULL;

        aux = head->next;
        dispose = aux;
        while (aux != NULL) {
                dispose = aux;
                aux = aux->next;
                #ifdef DLLFREEDATA
                        DLLFREEDATA(dispose->data);
                #endif
                free(dispose);
        }
        free(head);
        return NULL;
}

PUBLIC DL_LIST *dLinkedListAddNode(DL_LIST *head, void *data)
{
        DL_LIST *aux, *newNode;

        if (head == NULL)
                return 0;

        newNode = calloc(1, sizeof(DL_LIST));
        if (newNode == NULL)
                return newNode;
        aux = head;
        while (aux->next != NULL)
                aux = aux->next;
        newNode->data = data;
        newNode->next = NULL;
        newNode->prev = aux;
        aux->next = newNode;
        return newNode;
}

PUBLIC void dLinkedListDeleteNode(DL_LIST *head, DL_LIST *node)
{
        if (head == NULL || node == NULL || head == node)
                return;
        if (node->next == NULL) {
                node->prev->next = NULL;
        } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
        }
        #ifdef DLLFREEDATA
                DLLFREEDATA(node->data);
        #endif
        node->next = NULL;
        node->prev = NULL;
        free(node);
}

PUBLIC DL_LIST *dLinkedListSearch(DL_LIST *head, void *data)
{
        DL_LIST *node, *current;

        if (head == NULL || data == NULL)
                return NULL;

        node = NULL;
        current = head->next;
        while (current != NULL) {
                if (DLLCMPFUNC(data, current->data, _EQUAL_)) {
                        node = current;
                        break;
                }
                current = current->next;
        }
        return node;
}

PUBLIC void dLinkedListPrint(DL_LIST *head)
{
        DL_LIST *current;

        if (head == NULL)
                return;
        for (current = head->next; current != NULL; current = current->next) {
                #ifdef DLLPRINT
                        if (current->data != NULL)
                                DLLPRINT(current->data);
                #endif
        }
}

/* Macros */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Own includes */
#include "linked_list.h"
#include "linked_list_macros.h"

/* Enums & Structs */

/* Glocal variables */

/* Private prototypes */

/* Functions definitions */
PUBLIC LIST *linkedListCreate()
{
        LIST *head;

        head = calloc(1, sizeof(LIST));
        if (head == NULL)
                return NULL;
        head->data = NULL;
        head->next = NULL;
        return head;
}

PUBLIC LIST *linkedListDelete(LIST *head)
{
        LIST *aux, *dispose;

        if (head == NULL)
                return NULL;

        aux = head->next;
        dispose = aux;
        while (aux != NULL) {
                dispose = aux;
                aux = aux->next;
                #ifdef LLFREEDATA
                        LLFREEDATA(dispose->data);
                #endif
                free(dispose);
        }
        free(head);
        return NULL;
}

PUBLIC LIST *linkedListAddNode(LIST *head, void *data)
{
        LIST *aux, *newNode;

        if (head == NULL)
                return 0;

        newNode = calloc(1, sizeof(LIST));
        if (newNode == NULL)
                return newNode;
        aux = head;
        while (aux->next != NULL)
                aux = aux->next;
        newNode->data = data;
        newNode->next = NULL;
        aux->next = newNode;
        return newNode;
}

PUBLIC void linkedListDeleteNode(LIST *head, LIST *node)
{
        LIST *dispose, *prev;

        if (head == NULL || node == NULL)
                return;

        prev = head;
        dispose = head->next;
        while (dispose != NULL) {
                if (node == dispose) {
                        prev->next = dispose->next;
                        dispose->next = NULL;
                        #ifdef LLFREEDATA
                                LLFREEDATA(dispose);
                        #endif
                        free(dispose);
                        break;
                }
                prev = prev->next;
                dispose = dispose->next;
        }
}

PUBLIC LIST *linkedListSearch(LIST *head, void *data)
{
        LIST *node, *current;

        if (head == NULL || data == NULL)
                return NULL;

        node = NULL;
        current = head->next;
        while (current != NULL) {
                if (LLCMPFUNC(data, current->data, _EQUAL_)) {
                        node = current;
                        break;
                }
                current = current->next;
        }
        return node;
}

PUBLIC void linkedListPrint(LIST *head)
{
        LIST *current;

        if (head == NULL)
                return;
        for (current = head->next; current != NULL; current = current->next) {
                #ifdef LLPRINT
                        LLPRINT(current->data);
                #endif
        }
}

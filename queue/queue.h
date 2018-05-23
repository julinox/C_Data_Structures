/*
 * Generic queue TDA interface
 * 'data' is a pointer to some data struct that allegedly
 * holds some data. This TDA uses a linked list.
 *
 * Behold the macro 'QDEQUEUE' inside the 'stack_macros.h' file
 * since it handles the way the data is treated. Is important
 * to remark that on 'dequeing' (queueDeq) the node of the list
 * is free'd. In that case what you'd do with 'data' (which happens
 * to be inside the node being release)? Enter'QDEQUEUE'
 */

#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "../linked_list/linked_list.h"

typedef struct _queue_ {
        LIST *head;
} QUEUE;

PUBLIC QUEUE *queueCreate();
PUBLIC QUEUE *queueDelete(QUEUE *queue);
PUBLIC void queueEnq(QUEUE *queue, void *data);
PUBLIC void *queueDeq(QUEUE *queue);

#endif //_QUEUE_H_

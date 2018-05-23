/* Macros */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Own includes */
#include "queue.h"
#include "queue_macros.h"

/* Enums & Structs */

/* Glocal variables */

/* Private prototypes */

/* Functions definitions */
PUBLIC QUEUE *queueCreate()
{
        QUEUE *queue;

        queue = calloc(1, sizeof(QUEUE));
        if (queue == NULL)
                return NULL;
        queue->head = linkedListCreate();
        if (queue->head == NULL) {
                free(queue);
                return NULL;
        }
        return queue;
}

PUBLIC QUEUE *queueDelete(QUEUE *queue)
{
        if (queue == NULL)
                return NULL;
        linkedListDelete(queue->head);
        free(queue);
        return NULL;
}

PUBLIC void queueEnq(QUEUE *queue, void *data)
{
        linkedListAddNode(queue->head, data);
}

PUBLIC void *queueDeq(QUEUE *queue)
{
        void *data;
        LIST *dispose;

        if (queue == NULL || queue->head == NULL ||
            queue->head->next == NULL)
                return NULL;

        data = NULL;
        QDEQUEUE(data, queue->head->next->data);
        dispose = queue->head->next;
        linkedListDeleteNode(queue->head, dispose);
        return data;
}

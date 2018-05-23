/* Macros */

/* Includes */
#include <stdio.h>
#include <stdlib.h>

/* Own includes */
#include "stack.h"
#include "stack_macros.h"

/* Enums & Structs */

/* Glocal variables */

/* Private prototypes */

/* Functions definitions */
PUBLIC STACK *stackCreate()
{
        STACK *stack;

        stack = calloc(1, sizeof(STACK));
        if (stack == NULL)
                return NULL;
        stack->head = dLinkedListCreate();
        if (stack->head == NULL) {
                free(stack);
                return NULL;
        }
        stack->top = NULL;
        return stack;
}

PUBLIC STACK *stackDelete(STACK *stack)
{
        if (stack == NULL)
                return NULL;
        dLinkedListDelete(stack->head);
        stack->top = NULL;
        free(stack);
        return NULL;
}

PUBLIC void stackTop(STACK *stack, void *data)
{
        if (stack == NULL || stack->head == NULL)
                return;
        stack->top = dLinkedListAddNode(stack->head, data);
}

PUBLIC void *stackPop(STACK *stack)
{
        void *data;
        DL_LIST *dispose;

        if (stack == NULL || stack->head == NULL ||
            stack->top == NULL || stack->top->prev == NULL)
                return NULL;

        data = NULL;
        STACKPOP(data, stack->top->data);
        dispose = stack->top;
        stack->top = stack->top->prev;
        dLinkedListDeleteNode(stack->head, dispose);
        return data;
}

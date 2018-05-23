/*
 * Generic stack TDA interface
 * 'data' is a pointer to some data struct that allegedly
 * holds some data.
 *
 * This TDA uses a double linked list to simulate the stack
 * by simply having a pointer to the last element in a list
 * Why double linked list you may ask, and there is only
 * one practical reason for it: on 'popping' just go back
 * to the previous node.
 *
 * Behold the macro 'STACKPOP' inside the 'stack_macros.h' file
 * since it handles the way the data is treated. Is important
 * to remark that on 'popping' (stackPop) the node of the list
 * is free'd. In that case what you'd do with 'data' (which
 * happens to be inside the node being release)? Enter 'STACKPOP'
 */

#ifndef _STACK_H_
#define _STACK_H_
#include "../double_linked_list/double_linked_list.h"

typedef struct {
        DL_LIST *head;
        DL_LIST *top;
} STACK;

PUBLIC STACK *stackCreate();
PUBLIC STACK *stackDelete(STACK *stack);
PUBLIC void stackTop(STACK *stack, void *data);
PUBLIC void *stackPop(STACK *stack);

#endif //_STACK_H_

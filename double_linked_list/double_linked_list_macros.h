#ifndef _DOUBLE_LINKED_LIST_MACROS_H_
#define _DOUBLE_LINKED_LIST_MACROS_H_

#define INT *(int *)
#define CAST INT
#define DLLFREEDATA(data)
#define DLLPRINT(data) printf("%d, ", CAST data)

#define DLLCMPFUNC(d1, d2, cmp) \
        cmp == _GREATER_ ? (CAST d1 > CAST d2 ? TRUE : FALSE) : \
        (cmp == _LESSER_ ? (CAST d1 < CAST d2 ? TRUE : FALSE) : \
        (CAST d1 == CAST d2 ? TRUE : FALSE))

#endif // _DOUBLE_LINKED_LIST_MACROS_H_

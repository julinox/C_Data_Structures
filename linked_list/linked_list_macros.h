#ifndef _LINKED_LIST_MACROS_H_
#define _LINKED_LIST_MACROS_H_

#define INT *(int *)
#define CAST INT
#define LLFREEDATA(data)
#define LLPRINT(data) printf("%d, ", CAST data)

#define LLCMPFUNC(d1, d2, cmp) \
        cmp == _GREATER_ ? (CAST d1 > CAST d2 ? TRUE : FALSE) : \
        (cmp == _LESSER_ ? (CAST d1 < CAST d2 ? TRUE : FALSE) : \
        (CAST d1 == CAST d2 ? TRUE : FALSE))

#endif // _LINKED_LIST_MACROS_H_

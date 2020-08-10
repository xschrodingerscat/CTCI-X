

#ifndef __LGS_QUICK_SORT_H_INCLUDE__
#define __LGS_QUICK_SORT_H_INCLUDE__



typedef int (*lgs_qs_cmp) (void *e1, void *e2);


int lgs_quick_sort(void *base, int size, int offset, lgs_qs_cmp compare);


#endif

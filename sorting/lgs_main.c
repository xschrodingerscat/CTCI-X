
#include "lgs_common.h"
#include "lgs_quick_sort.h"



int compare(void *e1, void *e2);
void show(int array[], int n);

int 
main(int argc, char *argv[])
{
	int array[] = {2, 0, 4, 6, 7, 9, 8};

	int n = LGS_ARRAY_SIZE(array);
	lgs_qs_cmp cmp = compare;

	show(array, n);
	lgs_quick_sort(array, n, sizeof(array[0]), cmp);
	show(array, n);

	return 0;
}

int 
compare(void *e1, void *e2)
{
	int *a = (int *) e1;
	int *b = (int *) e2;

	if (*a > *b)
		return 1;
	else if (*a == *b)
		return 0;

	return -1;
}

void 
show(int *array, int n)
{
	int i;
	for (i = 0; i < n; ++ i) {
		printf("%d\n", array[i]);
	}
}

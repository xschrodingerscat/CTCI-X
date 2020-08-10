


#include "lgs_clock.h"


lgs_clock *
lgs_clock_create()
{
	lgs_clock *clk = lgs_malloc(sizeof(lgs_clock));
	clk->stop = clk->start = 0;
	return clk;
}

void 
lgs_clock_destroy(lgs_clock *clk)
{
	if (clk == NULL)
		return;

	lgs_free(clk);
	clk = NULL;
}

void 
lgs_clock_start(lgs_clock *clk)
{
	clk->start = clock();
}

void 
lgs_clock_stop(lgs_clock *clk)
{
	clk->stop = clock();
}

double 
lgs_clock_duration(lgs_clock *clk)
{
	if (clk->stop == 0)
		clk->stop = clock();

	return (double) (clk->stop - clk->start) / CLOCKS_PER_SEC;
}






#ifndef __LGS_CLOCK_H_INCLUDE__
#define __LGS_CLOCK_H_INCLUDE__

#include "../common/lgs_common.h"

typedef struct lgs_clock {
	clock_t start;
	clock_t stop;
} lgs_clock;

lgs_clock *lgs_clock_create();
void lgs_clock_destroy(lgs_clock *clk);

void lgs_clock_start(lgs_clock *clk);
void lgs_clock_stop(lgs_clock *clk);
double lgs_clock_duration(lgs_clock *clk);

#endif



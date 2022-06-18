#include <stdio.h>
#include "2.mod.h"

static int globalcnt;
int nbofcalls;

static void
count(void)
{
	globalcnt++;
}

void
func(void)
{
	nbofcalls++;
	count();
	printf("count is %d\n", globalcnt);
}

#include <stdio.h>
#include "19.hash.h"


int
main(int argc, char *argv[])
{
	Hash *h;
	int i, j;

stdout = stderr;

	h = mkhash(0);
	hashdump(h);

	for (i = 0; i < argc; i++) {
		printf("put #%d\n", i);
		hashput(h, argv[i]);
		for (j = 0; j < argc; j++) {
			printf("\thas #%d? %d\n", j, hashhas(h, argv[j]));
		}
	}
	hashdump(h);
	freehash(h);
	return 0;
}

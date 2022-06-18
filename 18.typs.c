#include <string.h>
#include <stdio.h>

typedef union RP RP;
union RP {
	char buf[4];
	int y;
	float f;
};

int
main(int argc, char *argv[])
{
	RP rp;

	rp.y = 666;

	printf("%s\n", rp.buf);	// very bad idea, for multiple reasons
	printf("%d\n", rp.y);
	printf("%g\n", rp.f);

	return 0;
}

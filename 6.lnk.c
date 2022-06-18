#include <stdio.h>

static void
func(void)
{
	static int initted;

	if (!initted) {
		initted++;
		printf("init...\n");
	}
	printf("whatever...\n");
}

int
main(int argc, char *argv[])
{
	func();
	func();
	return 0;
}

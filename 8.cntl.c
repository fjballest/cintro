#include <stdio.h>

enum {
	N = 10,
};

static void
loop1(void)
{
	int i;

	printf("%s\n", __func__);
	for (i = 0; i < N; i++) {
		printf("i %d\n", i);
	}
}

static void
loop2(void)
{
	int i;

	printf("%s\n", __func__);
	i = N;
	while (--i >= 0) {
		printf("i %d\n", i);
	}
}

static void
loop3(void)
{
	int i;

	printf("%s\n", __func__);
	i = 0;
	do {
		printf("i %d\n", i);
	} while (++i < N);
}

static void
sw(void)
{
	int i;

	printf("%s\n", __func__);
	i = 5;
	switch (i) {
	case 0:
		printf("0\n");
		break;
	case 1:
	case 2:
		printf("1 or 2\n");
		break;
	default:
		printf("other\n");
		break;
	}
}

int
main(int argc, char *argv[])
{
	loop1();
	loop2();
	loop3();
	sw();

	return 0;
}

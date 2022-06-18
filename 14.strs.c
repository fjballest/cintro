#include <string.h>
#include <stdio.h>

static char str[] = "hi there";

static void
pstr(char *str)
{
	int i;

	for (i = 0; str[i] != 0; i++) {
		printf("%c", str[i]);
	}
	printf("\n");
}

int
main(int argc, char *argv[])
{

	pstr(str);
	pstr("hello\tthere");
	return 0;
}

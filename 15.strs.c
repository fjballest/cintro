#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static int
mystrlen(char *s)
{
	int n;

	if (s == NULL) {	// not the std!
		return 0;
	}
	n = 0;
	while (*s++ != 0) {
		n++;
	}
	return n;
}

static void
mystrcpy(char *d, char *s)
{
	while ((*d++ = *s++) != 0) {
		;
	}
}


static char*
mystrdup(char *s)
{
	char *d;
	int n;

	if (s == NULL) {
		return NULL;
	}
	n = mystrlen(s);
	d = malloc(n+1);	// +1 for \0
	mystrcpy(d, s);
	return d;
}

int
main(int argc, char *argv[])
{
	char *s;

	s = mystrdup("one msg");
	printf("s: %s\n", s);
	printf("%ld chars + \\0\n", strlen(s));
	free(s);
	return 0;
}

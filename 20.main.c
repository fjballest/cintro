#include <stdio.h>
#include "20.names.h"

int
main(int argc, char *argv[])
{
	Str *s1, *s2;

	s1 = mkstr("one str");
	s2 = mkstr("another");

	printf("s1: %s\n", cstr(s1));
	printf("s2: %s\n", cstr(s2));
	putstr(&s2);
	s2 = dupstr(s1);
	printf("s1: %s\n", cstr(s1));
	printf("s2: %s\n", cstr(s2));
	s2 = setstr(s2, "changed");
	printf("s1: %s\n", cstr(s1));
	printf("s2: %s\n", cstr(s2));
	s2 = setstr(s2, "changed to a larger str");
	printf("s1: %s\n", cstr(s1));
	printf("s2: %s\n", cstr(s2));
	putstr(&s1);
	putstr(&s2);
	return 0;
}

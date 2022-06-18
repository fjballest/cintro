#include <stdio.h>
#include "5.mod.h"


int
main(int argc, char *argv[])
{
	func();
	func();
	printf("%d calls\n", nbofcalls);
	return 0;
}

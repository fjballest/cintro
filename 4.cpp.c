#include <stdio.h>

#define MSG "my msg"

#define MAX(a,b)	(((a)>(b)) ? (a) : (b))

int
main(int argc, char *argv[])
{
	printf("msg: %s\n", MSG);
	printf("max: %d\n", MAX(3, 5));

	// compiler concats strings
	printf("msg: " MSG "\n");
	return 0;
}

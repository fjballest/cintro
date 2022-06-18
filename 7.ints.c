#include <stdio.h>
#include <inttypes.h>

#ifdef NOTDEF
	const: say no
	unsigned int;
	short;
	uint8_t;
	long int;
	long long int;
#endif

// one of the good uses of CPP
#define X64	"%" PRIx64
#define D64	"%" PRId64
#define U64	"%" PRIu64
#define A64	"%014" PRIx64
#define X32	"%" PRIx32
#define D32	"%" PRId32
#define U32	"%" PRIu32

static void
func(void)
{
	int i;
	char c;
	uint32_t u;
	uint64_t ul;
	float f;
	double g;

	i = 3;
	c = 'x';

	printf("i %d %x\n", i, i);
	printf("c %d %x %c\n", c, c, c);

	c++;
	printf("c %d %x %c\n", c, c, c);
	u = c;
	printf("u %u\n", u);

	ul = u;		// bad idea in general, don't mix signs!
	printf("u %llu\n", ul);

	printf("u %"PRId64"\n", ul);
	printf("this is "D64" the same\n", ul);

	f = 3.14;
	g = 6.36;
	printf("%g and %g\n", f, g);
}

int
main(int argc, char *argv[])
{
	func();
	return 0;
}

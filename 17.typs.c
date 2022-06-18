#include <string.h>
#include <stdio.h>

typedef struct Pt Pt;
struct Pt {
	int x;
	int y;
};

static int
ptprintf(FILE *f, Pt *pt)
{
	if (pt == NULL) {
		return fprintf(f, "nullpt");
	}
	return fprintf(f, "[%d,%d]", pt->x, pt->y);
}

static int
snprintpt(char *buf, int nbuf, Pt *pt)
{
	if (pt == NULL) {
		return snprintf(buf, nbuf, "nullpt");
	}
	return snprintf(buf, nbuf, "[%d,%d]", pt->x, pt->y);
}

int
main(int argc, char *argv[])
{
	Pt pt, pt2;
	int tot;
	char buf[512];

	pt = (Pt){3, 4};

	printf("x = %d y = %d\n", pt.x, pt.y);
	pt2 = pt;
	printf("x = %d y = %d\n", pt2.x, pt2.y);

	ptprintf(stdout, &pt);
	printf("\n");

	tot = snprintpt(buf, sizeof buf, &pt);
	tot += snprintf(buf+tot, sizeof buf-tot, "\n");
	printf("%s", buf);
	return 0;
}

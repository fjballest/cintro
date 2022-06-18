#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int
main(int argc, char *argv[])
{
	char *s;
	int tot;
	char buf[8], bbuf[1024];

	s = strdup("one msg");
	printf("s: %s\n", s);
	free(s);
	strncpy(buf, "one big msg", sizeof buf);
	printf("%s\n", buf);

	tot = 0;
	tot += snprintf(bbuf+tot, sizeof bbuf-tot, "we add %d", 0);
	tot += snprintf(bbuf+tot, sizeof bbuf-tot, " and this too");
	printf("%s\n", bbuf);
	return 0;
}

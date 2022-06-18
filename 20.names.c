#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "20.names.h"


static void
fatal(char *msg)
{
	fprintf(stderr, "fatal: %s\n", msg);
	exit(1);
}

static void*
emalloc(int sz)
{
	void *p;

	p = malloc(sz);
	if (p == NULL) {
		fatal("no memory");
	}
	memset(p, 0, sz);	// safety first
	return p;
}

Str*
mkstr(char *s)
{
	Str *rs;
	int n;

	n = strlen(s);
	rs = emalloc(sizeof *rs + n + 1);
	memmove(rs->s, s, n);
	rs->ref.ref = 1;
	rs->len = n;
	rs->alen = n+1;
	return rs;
}

void
putstr(Str **rsp)
{
	Str *rs;

	rs = *rsp;
	if (rs != NULL) {
		*rsp = NULL;
		if (decref(&rs->ref) == 0) {
			free(rs);
		}
	}
}

Str*
dupstr(Str *rs)
{
	if (rs == NULL) {
		return NULL;
	}
	incref(&rs->ref);
	return rs;
}


Str*
setstr(Str *rs, char *sval)
{
	int n;

	n = strlen(sval);
	if (rs != NULL && (getref(&rs->ref) > 1 || rs->alen < n+1)) {
		// NB: we could use realloc(3) here, Incr bytes at a time.
		putstr(&rs);
		return mkstr(sval);
	}
	memmove(rs->s, sval, n);
	rs->s[n] = 0;
	rs->len = n;
	return rs;
}

int
cstrlen(Str *rs)
{
	if (rs == NULL) {
		return 0;
	}
	return rs->len;
}

char*
cstr(Str *rs)
{
	if (rs == NULL) {
		return "";
	}
	return rs->s;
}

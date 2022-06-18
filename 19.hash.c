#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "19.hash.h"

enum {TESTING = 1};

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

Hash*
mkhash(int sz)
{
	Hash *h;

	if (sz <= 0) {
		sz = 101;
	}
	h = emalloc(sizeof *h + sz * sizeof h->els[0]);
	h->nels = sz;
	return h;
}

static Helem*
mkent(char *s)
{
	Helem *he;
	int n;

	n = strlen(s);
	he = emalloc(sizeof *he + n + 1);
	memmove(he->s, s, n+1);
	return he;
}

void
freehash(Hash *h)
{
	Helem *he;

	if (h != NULL) {
		while (h->hs < h->he) {
			while ((he = h->els[h->hs]) != NULL) {
				h->els[h->hs] = he->next;
				memset(he, 7, sizeof *he);	// poison
				free(he);
			}
			h->hs++;
		}
	}
}

static uint32_t
strhash(char *s)
{
	uint32_t sh, c;

	sh = 5381;
	while ((c = *s++) != 0) {
		sh = ((sh << 5) + sh) + c;
	}
    return sh;
}

static Helem**
lookup(Hash *h, char *s)
{
	Helem **hep, *he;
	uint32_t hval;

	hval = strhash(s);
	hval %= h->nels;
	if (h->hs == h->he || h->hs > hval) {
		h->hs = hval;
	}
	if (h->he < hval+1) {
		h->he = hval+1;
	}
	for (hep = &h->els[hval]; (he = *hep) != NULL; hep = &he->next) {
		if (strcmp(he->s, s) == 0) {
			break;
		}
	}
	return hep;
}

void
hashput(Hash *h, char *s)
{
	Helem **hep;

	hep = lookup(h, s);
	if (*hep == NULL) {	// new entry
		*hep = mkent(s);
	}
}

int
hashhas(Hash *h, char *s)
{
	Helem **hep;

	hep = lookup(h, s);
	return *hep != NULL;
}

static void
helemok(Helem *he, int i, int nels)
{
	uint32_t hval;

	for (; he != NULL; he = he->next) {
		hval = strhash(he->s);
		if (hval%nels != i) {
			fatal("bad helem bucket");
		}
	}
}

void
hashok(Hash *h)
{
	int i;

	if (h == NULL || !TESTING) {
		return;
	}
	for (i = 0; i < h->nels; i++) {
		if (h->els[i] != NULL && (h->hs > i || h->he <= i)) {
			fatal("bad hash hs/he");
		}
		if (h->els[i] == NULL) {
			continue;
		}
		helemok(h->els[i], i, h->nels);
	}
}

void
hashdump(Hash *h)
{
	Helem *he;
	int i;

	printf("hash %p:\n", h);
	if (h == NULL) {
		return;
	}
	printf("\ths: %d\n", h->hs);
	printf("\the: %d\n", h->he);
	printf("\tnels: %d\n", h->nels);
	for (i = 0; i < h->nels; i++) {	// NB: debug, don't use hs/he
		for (he = h->els[i]; he != NULL; he = he->next) {
			printf("\t[%d] '%s'\n", i, he->s);
		}
	}
	hashok(h);
}

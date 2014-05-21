#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sdk.h"

int sdk_add(int a, int b)
{
	return a + b;
}

char *sdk_cat(const char *a, int i)
{
	char *str;

	/* Check string */
	if(a == NULL)
		return NULL;

	/* Cat string and integer */
	asprintf(&str, "%s %d", a, i);

	return str;
}

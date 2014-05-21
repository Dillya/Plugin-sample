#include "sdk.h"

char *module_func(char *a, int i)
{
	i = sdk_add(i, 12);
	return sdk_cat(a, i);
}

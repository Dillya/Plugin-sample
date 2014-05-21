#ifndef _SDK_H
#define _SDK_H

/* Function define for module */
typedef char *func(char *, int);

/* SDK functions in main binary */
int sdk_add(int a, int b);
char *sdk_cat(const char *a, int i);

#endif

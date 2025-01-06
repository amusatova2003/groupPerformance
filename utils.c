#ifndef UTILS_C
#define UTILS_C
#include <stdio.h>

void ClearBuffer()
{
    char c;
    while ((c=getchar()) != '\n' && c != EOF);
}
#endif
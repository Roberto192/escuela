#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <strings.h>

int print(int, ...);

int main(int argc, char const *argv[])
{    

    int num[argc-1];
    char *buff;

    for (int i = 1; i < argc; ++i)
    {
        num[i-1] = strtol(argv[i], &buff, 0);
    }

    print(argc-1,&num);

    return 0;
}

int print(int nArg, ...){
    
    int *num;

    va_list ap;

    va_start(ap, nArg);

    num = va_arg(ap, int (*));

    for (int i = 0; i < nArg; i++)
    {
        printf("%i._ %i\n",i,num[i]);
    }

    va_end(ap);

    return 0;
}
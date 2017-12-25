#include <stdio.h>
#include <stdlib.h>

int fib_r(int i)
{
    if (i==1) return 1;
    else if (i==0) return 0;
    else return fib_r(i-2)+fib_r(i-1);
}

int fib_i(int i)
{
    int k;
    int fp,fpp,f;
    f = fp = 1;
    fpp = 0;
    for(k=2;k<=i;++k)
    {
        f = fp+fpp;
        fpp = fp;
        fp = f;
    }
    return f;
}

int main()
{
    int i,sf;

    sf = scanf("%d",&i);

    printf ("iterativo:\n");
    printf("F%d = %d\n",i,fib_i(i));
    printf("recursiva:\n");
    printf("F%d = %d\n",i,fib_r(i));
}

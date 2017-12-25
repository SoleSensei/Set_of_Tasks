#include <stdio.h>

void f(double x)
{
    int sf;
    double k,res,der;
    sf = scanf("%lf",&k);
    if (sf!=EOF&&sf){
     res = k;
     der = 0;
     sf = scanf("%lf",&k);

     while (sf!=EOF&&sf)
     {
       der = der*x+res;
       res = x*res+k;
       sf = scanf("%lf",&k);
     }
     if(sf==EOF) sf=1; //Œ·ıÓ‰ if
     }

    if (sf!=EOF&&sf) {
            printf("\nf(x) = %.3lf",res);
            printf("\nf'(x) = %.3lf",der);
            }
    else    printf("\ninput error\n");
}

int main(void)
{

    double x;
    int sf;

    printf ("Gorner v1\n");
    sf = scanf("%lf",&x);

    if (sf!=EOF&&sf) f(x);
    else printf("\ninput error\n");


    return 0;
}


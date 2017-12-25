#include <stdio.h>

double abs(double x)
{
  return x>0 ? x : -x;
}

double sqrt(double xi,double x,double e)
{
   double nexti = 0.5*(xi+x/xi);
   return abs(nexti-xi)<e ? nexti : sqrt(nexti,x,e);
}

int main(void)
{
  double epsi,x;
  int sf;

  printf ("epsilon = ");
  sf = scanf("%lf",&epsi);
  printf ("x = ");

  while (sf!=EOF&&sf)
  {
      sf = scanf("%lf",&x);
      if (sf!=EOF&&sf){
       x = abs(x);
       x = sqrt(1,x,epsi);
       printf ("sqrt = %.10g\nx = ",x);
      }
      else printf ("\nend of file\n");
  }

  return 0;
}


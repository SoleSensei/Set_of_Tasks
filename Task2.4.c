#include <stdio.h>
#include <stdlib.h>

double str2double (char *s)
{
  if (*s){
   double int_ = (int)s[0]-'0'; //xxxx.0000
   double fr_ = 0.0;            //0000.xxxx
   double dec = 10;

   int i;
   for(i = 1; s[i] != '.' && s[i]; ++i) //integer part
       int_ = int_*10 + (int)s[i]-'0';

   if (!s[i]) return int_; // xxxx.\0 || xxxx\0

   for(i = i+1; s[i]; ++i){  //fraction part
       fr_= fr_ + ((int)s[i]-'0')/dec;
       dec = dec*10;
   }
   return int_+fr_;
  }
  else return -1;
}


int main()
{
    char s[100];
    double d[100];
    int i = 0;
    int sf;
    sf = scanf("%s",s);
    while (sf!=EOF){
           d[i] = str2double (s);
           sf = scanf("%s",s);
           ++i;
    }
    int k;
    for (k=0;k<i;++k)
         printf("double = %.10g\n",d[k]);

    return 0;
}

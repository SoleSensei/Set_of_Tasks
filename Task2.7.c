#include<stdio.h>
#include<setjmp.h>

jmp_buf begin; /* точка начала диалога с пользователем */
char curlex;	/* текущая лексема */

void getlex(void); /* выделяет из входного потока очередную лексему */

int expr(void); /* распознает выражение и вычисляет его значение */

int add(void); /* распознает слагаемое и вычисляет его значение */

int mult(void); /* распознает множитель и вычисляет его значение */

int upp(void);  /* возводит множитель в степень */

void error(); /* сообщает об ошибке в выражении и передает управление в начало функции main (точка begin) */

main()
{
    int result;
    setjmp(begin);
    printf("==>");
    getlex() ;
    result=expr();
    if (curlex != '\n') error();
    printf ("\n%d\n",result) ;

   return 0;
}

void getlex()
{
    while ( (curlex=getchar() ) == ' ');
}

void error(void)
{
    printf("\nERROR!\n");
    while(getchar()!='\n');
    longjmp(begin,1);
}

int expr ()
{
    int e = add();
    while (curlex == '+' || curlex == '-')
       { if (curlex == '+') {getlex (); e+=mult(); }
         else { getlex(); e-=mult(); }}
    return e;
}
int upp ()
{
    int u = mult();
    int s;
    int i;
    if (curlex == '^')
    {
        getlex();
        s = upp();
        int p = u;
        for (i = 2; i <= s; ++i)
            u=p*u;
    }
   return u;
}


int add ()
{
    int a = upp();
    while (curlex == '*' || curlex == '/')
    { if (curlex == '*') { getlex (); a*=upp(); }
        else { getlex(); a/=upp(); }}
   return a;
}

int mult()
{
    int m;
    switch(curlex){
    case '0': case '1': case '2': case '3': case '4': case '5':
    case '6': case '7': case '8': case '9': m=curlex-'0'; break;
    case '(': getlex(); m=expr();
       if (curlex == ')') break;
       /* иначе ошибка - нет закрывающей скобки */
    default : error();
}
    getlex() ;
   return m;
}

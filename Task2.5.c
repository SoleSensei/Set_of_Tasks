#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define N 1000

typedef struct Node *link;
typedef char* elemtype;

typedef struct Node {
        elemtype elem;
        link next;
}node;

typedef link list;

void exclude (list *ls)
{
    link q,p;
    q = *ls;
    while (q->next) q = q->next;          //q * to last;
    while ( !strcmp((*ls)->elem,q->elem))     //delete first elems
            if (*ls == q) break;
            else {p = *ls; *ls = (*ls)->next; free(p);}
    char* last; last = (char*) malloc (sizeof(*last)*N);   //last = last elem
    last = q->elem;
    q = *ls; // current
    p = *ls; // previous
    while (q->next)     // q != NULL, *ls <= * to last
    {
         q = q->next;
         if (q->next == NULL) break;    // q * to last
         if ( !strcmp(q->elem,last)){
             p->next = q->next;
             free(q);
             q = p;
         }

        p = q;
    }
}

list create (void)
{
    printf("List Creation: ");
    link lst,q;
    lst = q = NULL;
    int sf;
    char* el = NULL; el = (char*) malloc (sizeof(*el)*N);
    sf = scanf("%s",el);
    if (sf != EOF){
        lst = q = (link) malloc (sizeof(node));
        q -> elem = el;
        el = (char*) malloc (sizeof(*el)*N);
        sf = scanf("%s",el);
    }
    while (sf != EOF){
        q = q -> next = (link) malloc (sizeof(node));
        q -> elem = el;
        el = (char*) malloc (sizeof(*el)*N);
        sf = scanf("%s",el);
    } q -> next = NULL;

  return lst;
}

void out (list p)
{
  while (p){
    printf ("%s ",p->elem);
        p = p->next;
  }
 printf("\n");
}

int main(void)
{
    list head = NULL;
    head = create ();
    printf("List:   ");
    out (head);
    if (head != NULL)
    {
         printf("Exlist: ");
         exclude (&head);
         out (head);
    }
    else printf("Empty list");

}

#include <stdio.h>
#include <stdlib.h>

#define sch(elem) search_elem(head,elem) //! - head - type - tree -  main ()
#define rem(elem) remove_elem(&head,elem)
#define add(elem) add_elem(&head,elem)


typedef struct Node * link;
typedef int elemtype;

typedef struct Node {

    elemtype elem;
    link left;
    link right;
} node;

typedef link tree;

typedef int bool; //bool - true/false - 1/0

void connect (tree *from, tree *to, bool parent)
{
    if (parent)
         (*from)->left = *to;
    else (*from)->right = *to;
}

bool search_elem (tree tr, elemtype e)
{
    while (tr){
        if (e == tr->elem) return 1;
        else if (e > tr->elem) tr = tr -> right;
        else if (e < tr->elem) tr = tr -> left;
   }
  return 0;
}

void remove_elem (tree *tr, elemtype e)
{
    tree p,q;
    bool par = 0; //bool parent - left/right - 1/0
    p = q = *tr;
    while(q->elem!=e){
        if (e > q->elem)
                    { p = q; q = q -> right; par = 0; }
        if (e < q->elem)
                    { p = q; q = q -> left; par = 1; }
    }
    if (q->left == NULL){
        if (q == *tr) *tr=q->right; //if need to remove head item
        else connect(&p,&q->right,par);
    }else
    if (q->right == NULL){
        if (q == *tr) *tr=q->left;
        else connect(&p,&q->left,par);
    }else{
     tree leaf = q->right;
     tree pleaf = leaf; // previous to last leaf
     while (leaf->left){
            pleaf = leaf;
            leaf = leaf->left; // most left leaf in right subtree
     }
     pleaf->left = NULL;
     if (q == *tr) *tr = leaf;
     else connect(&p,&leaf,par);
     if (leaf != q->right) leaf->right = q->right; //if no left leaves in rigth subtree
     leaf->left = q->left;
   }
    free(q);
}

void add_elem (tree *tr, elemtype e)
{
    //printf("-K-");
    tree tmp,el;
    el = (tree) malloc (sizeof(node)); //node needed to add
    el->elem = e;
    el->left = el->right = NULL;
    tmp = *tr;
    if (tmp == NULL) *tr = el;
    else
    while (tmp != el){
        if (e > tmp->elem)
          if (tmp->right) tmp = tmp -> right;
          else tmp->right = el;
        else
          if (tmp->left) tmp = tmp -> left;
          else tmp->left = el;
   }
}

int main (void)
{
    tree head = NULL; //used in define

    int sf;
    elemtype a;
    char c;

    do {
        c = getchar();
        while (c == ' ' || c=='\t' || c=='\n') c = getchar();
            if (c != EOF)  sf = scanf("%d",&a);

        if (c == '?') if (sch(a)) printf("yes (%d)\n",a);  /* sch rem add - define */
                      else printf("no (%d)\n",a);
        if (c == '-') if (sch(a))  rem(a);
        if (c == '+') if (!sch(a)) add(a);

      } while (c != EOF);

  return 0;
}

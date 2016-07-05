#include<stdio.h> 
#include<stdlib.h> 
#include<assert.h> 
#include<string.h> 
#include<ctype.h> 
typedef struct node *link; 
struct node{int n; 
int team; 
link prev; 
link next; 
}; 
link NEW(int n,int team,link prev,link next) 
{link x = malloc(sizeof *x); 
x->n = n; 
x->team = team; 
x->prev = prev; 
x->next = next; 
return x; 
} 
typedef struct{ 
link head; 
link tail; 
}Queue; 
void init(Queue* Q) 
{ 
Q->head = malloc(sizeof *Q->head); 
Q->tail = malloc(sizeof *Q->tail); 
Q->head->next = Q->tail; 
Q->head->prev = Q->head; 
Q->tail->prev = Q->head; 
Q->tail->next = Q->tail; 
} 
link begin(Queue* Q) 
{return Q->head->next;} 
link end(Queue* Q) 
{return Q->tail;} 
void insert(Queue* Q,link t) 
{link x; 
x=Q->head; 
t->next = x->next; 
x->next->prev = t; 
x->next = t; 
t->prev = x; 
} 
link delete(Queue* Q,link t) 
{t->next->prev = t->prev; 
t->prev->next = t->next; 
return t; 
} 
int empty(Queue* Q) 
{return begin(Q)==end(Q);} 
void tqinsert(Queue* Q,link t) 
{link x; 
for(x=end(Q)->prev; x!=Q->head; x = x->prev) 
if(x->team == t->team)break; 
if(x==Q->head) 
x = end(Q)->prev; 
t->next = x->next; 
x->next->prev = t; 
x->next = t; 
t->prev = x; 
} 
main() 
{ 
Queue Q1,Q2; 
link x; 
int n,p,q,r; 
link t; 
char s[100]; 
int C; 
C=1; 
while(scanf("%d",&n)==1){ 
if(n==0)break; 
init(&Q1); 
init(&Q2); 
while(n--){ 
scanf("%d",&p); 
while(p--){ 
scanf("%d",&q); 
insert(&Q1,NEW(q,n,NULL,NULL)); 
} 
} 
printf("Scenario #%d\n",C); 
C++; 
scanf("\n"); 
while(scanf("%s",s)==1){ 
if(s[0]=='S')break; 
else if(s[0]=='E'){ 
scanf("%d",&r); 
for(t=begin(&Q1); t!=end(&Q1); t = t->next) 
if(t->n== r)break; 
tqinsert(&Q2,delete(&Q1,t)); 
}else{ 
if(!empty(&Q2)){ 
t = begin(&Q2); 
printf("%d\n",t->n); 
delete(&Q2,t); 
free(t); 
} 
} 
} 
printf("\n"); 
} 
}

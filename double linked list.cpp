# include <iostream>
using namespace std;
struct doublenode{
    int data;
     doublenode *next;
     doublenode *last;
};
typedef doublenode* linkedlist;
int size(linkedlist l)
{
  int cnt=0;
  while(l!=NULL)
  {
    cnt++;
    l=l->next;
}
return cnt;
}
linkedlist makenode(int x)
{
linkedlist tmp=new doublenode();
tmp->data=x;
tmp->next=NULL;
tmp->last=NULL;
return tmp;
}
void insertfirt(linkedlist &l,int x)
{
  linkedlist tmp=makenode(x); 
    tmp->next=l;
  if(l!=NULL)
     l->last=tmp;
}
void insertend(linkedlist &l,int x)
{
linkedlist tmp=makenode(x);
if(l==NULL)
{
l=tmp;
return;
}
linkedlist p=l;
while(p->next!=NULL)
  p=p->next;
p->next=tmp;
tmp->last=p;
}
void insertindex(linkedlist &l,int x,int pos)
{
int n=size(l);
if(pos<1 || pos>n+1)
 {
 cout<<"loi vi tri";
return;
}
if(pos==1)
 {
insertfirt(l,x);
return;
}
linkedlist p=l;
for(int i=0;i<=pos;i++)
  p=p->next;
linkedlist tmp=makenode(x);
tmp->next=p;
p->last->next=tmp;
tmp->last=p->last;
p->last=tmp;
}


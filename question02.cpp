#include<iostream>
using namespace std;
class node
{
    node *prev;
    int value;
    node *next;
    friend class DLL;
};
class DLL
{
node * head;
public:
DLL()
{
    head=NULL;
}
insert(int v)
{
    node *temp =new node;
    temp->prev=NULL;
    temp->value=v;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
    }
    else
    {
     node *t=head;
      while(t->next!=NULL)
      {
      t=t->next;
      }
      t->next=temp;
      temp->prev=t;
    }
}
void display()
{
    node* t=head;
    while(t!=NULL)
    {
        cout<<t->value<<" ";
        t=t->next;
    }
    cout<<endl;
}
findSum(int n)
{
    node*t=head;
    node*p=head;
    while(t!=NULL)
    {
        while(p!=NULL)
        {
        if(n==p->value+t->value && p!=t)
        {
         cout<<"("<<t->value<<","<<p->value<<")"<<endl;
        }
        p=p->next;
        }
        p=head;
        t=t->next;
    }
   
}
};
int main()
{
DLL s;
s.insert(1);
s.insert(2);
s.insert(3);
s.insert(4);
s.insert(5);
s.display();
s.findSum(6);
    return 0;
}
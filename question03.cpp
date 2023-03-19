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
void insertvalue(int n)
{
    node *temp=new node;
    temp->next=NULL;
    temp->prev=NULL;
    temp->value=n;
    node*t=head;
    if(n<t->value)
    {
    
      temp->next=head;
      head->prev=temp;
      head=temp;
    }
    else
    {
    while(t->next!=NULL)
    {
     t=t->next;
     if(n<t->value)
     break;
    }
    if(t->next==NULL && n>t->value)
    {
       
        temp->prev=t;
        t->next=temp;
    }
    else
    {
      t->prev->next=temp;
      temp->prev=t->prev;
      t->prev=temp;
      temp->next=t;
    }
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
};
int main()
{
DLL s;
s.insert(1);
s.insert(2);
s.insert(3);
s.insert(5);
s.insert(9);
s.display();
s.insertvalue(4);
s.display();
    return 0;
}
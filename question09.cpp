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
DigitSum()
{
    node *t=head;
    node *p;
    while(t!=NULL)
    {
        p=t;
     if(checkEven(t->value))
     {
       if(t==head)
       {
       head=t->next;
       t=head;
       delete p;
       }
       else if(t->next==NULL)
       {
          t->prev->next=NULL;
          delete p;
       }
       else
       {
        t->prev->next=t->next;
        t->next->prev=t->prev;
        t=t->prev;
        delete p;
       }
     }
     t=t->next;

    }
}
int checkEven(int n)
{
int a=0;

while(n!=0)
{
a=a+n%10;
n=n/10;
}
if(a%2==0)
return 1;
else
return 0;
}
void deleteL()
{
    node*t=head;
    while(t->next->next!=NULL)
    {
        t=t->next;
    }
    delete t->next;
    t->next=NULL;

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
s.insert(4);
s.insert(6);
s.display();
s.DigitSum();
s.display();
    return 0;
}
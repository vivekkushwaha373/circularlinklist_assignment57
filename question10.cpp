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
RemoveFib()
{
    node *t=head;
    node *p;
    while(t!=NULL)
    {
        p=t;
     if(checkFib(t->value))
     {
       if(t==head)
       {
       head=t->next;
       t=t->next;
       delete p;
       continue;
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
    //  if(t!=head)
     t=t->next;

    }
}
int checkFib(int n)
{
    // cout<<n<<" ";
    int a,b,c;
    a=b=1;
    if(n==1)
    return 1;
    while(1)
    {
      
      c=a+b;
      if(c==n)
      return 1;
      a=b;
      b=c;
      if(c>n)
      break;

    }
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
s.insert(5);
s.insert(6);
s.insert(7);
s.insert(8);
s.display();
s.RemoveFib();
s.display();
    return 0;
}
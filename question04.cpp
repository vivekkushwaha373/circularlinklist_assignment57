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
RemoveDuplicatenodes()
{
    node*t=head;
    while(t->next!=NULL)
    {
       
        if(t->value==t->next->value)
      { 
        deleteE(t); 
        }
        t=t->next;
    }
}
deleteE(node* s)
{
if(s==head)
{
//   head->next->prev=NULL;
  head=head->next;
  head->prev=NULL;
  delete s;
//   return head;
}
else
{
    node*t=head;
    while(t->next!=s)
    {
     t=t->next;
    }
    // node*x=t->next;
    t->next->next->prev=t;
    t->next=t->next->next;
    delete s;
    // return t;

}
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
};
int main()
{
DLL s;
s.insert(1);
s.insert(1);
s.insert(2);
s.insert(2);
s.insert(3);
s.insert(3);
s.insert(4);
s.insert(4);
s.insert(5);
s.insert(5);
s.display();
s.RemoveDuplicatenodes();
s.display();

    return 0;
}
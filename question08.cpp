#include<iostream>
using namespace std;
class DLL;
class node
{
node* prev;
int value;
node* next;
friend class DLL;
};
class DLL
{
int size=0;
node*head;
public:
DLL()
{
    head=NULL;
}
insert(int v)
{
node*temp=new node;
temp->prev=NULL;
temp->next=NULL;
temp->value=v;
if(head==NULL)
{
  head=temp;
  size++;
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
    size++;
}
}
Size()
{
    cout<<" Size = "<<size<<endl;
}
void display()
{

    node *t=head;
    while(t!=NULL)
    {
        cout<<t->value<<" ";
        t=t->next;
    }
    cout<<endl;
}
void reverse()
{
    node *t=head;
    node *t1=head;
    node *t2=head->next;
    // t1=t2=NULL;
    while(t!=NULL)
    {
    //  t1=t;
    //  t2=t->next;
    if(t2!=head->next)
    t2=t;
     if(t1==head)
     {
        t1->next=NULL;
        t1->prev=t2;
     }
    t=t2->next;
    t2->next=t1;
    t1->prev=t2;
    t1=t2;
    }
    t2->prev=NULL;
head=t2;
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
s.Size();
s.display();
s.reverse();
s.display();
// s.display();
}
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
void RemoveDuplicatenodes()
{
    node*t=NULL;
    node*x=head;
    while(x!=NULL)
    {
        t=x;
     while(t->next!=NULL)
      {
       if(x->value==t->next->value )
        {
        
        deleteE(t->next); 
    //   break;
        }
        t=t->next;
        if(t==NULL)
        break;
       }
    //    t=head;
     
     x=x->next;
   
        
    }
  
}


void deleteE(node* s)
{
    // cout<<"Delete is called"<<endl;
    node*t=head;
    if(s->next==NULL)
    {
        // node*t=head;
    while(t->next!=NULL)
    {
        t=t->next;
    }
    t->prev->next=NULL;
    delete s;
    
    }
    else
    {
    
    while(t->next!=s)
    {
     t=t->next;
    }
   
    t->next->next->prev=t;
    t->next=t->next->next;
    delete s;
    }
    
}
void insert(int v)
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
s.insert(7);
s.insert(4);
s.insert(5);
s.insert(8);
s.insert(8);
s.insert(3);
s.insert(4);
s.insert(4);
s.insert(1);
s.insert(2);
s.insert(5);
s.display();
s.RemoveDuplicatenodes();
s.display();

    return 0;
}
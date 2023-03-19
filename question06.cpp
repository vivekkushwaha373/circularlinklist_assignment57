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
int size=0;
node * head;
public:
DLL()
{
    head=NULL;
}
Size()
{
    cout<<size<<endl;;
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
// 1 3 4 8 5 2 0
void merge(node*p,node*q)
{


}
void sort()
{
    node*t=head;
    while(t->next->next!=NULL)
    {
      if(t->value>t->next->value)
      {
        
        break;
      }
      t=t->next;
    }
    
    reverse(t);
}
reverse(node *t)
{
   int arr[size];
   int i=0;
   node *s=t;
   node *m=t;
   while(t->next!=NULL)
   {
   
    t=t->next;

   }
   while(t!=s->prev)
   {
   
      arr[i]=t->value;
      t=t->prev;
      i++;
   }
     arr[i]=0;
   i=0;
   while(s!=NULL)
   {
    //  cout<<arr[i]<<" ";
     s->value=arr[i];
     s=s->next;
     i++;
   }
//    display();
m->prev->next=NULL;m->prev=NULL;
merge(head,m);


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
s.insert(3);
s.insert(4);
s.insert(8);
s.insert(5);
s.insert(2);
s.insert(0);
// s.display(2);
// s.deleteL(0);
s.display();
s.sort();
s.display();
s.Size();
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *next;
};
///Insert Function
Node *Insert(Node *head, int key)
{
    Node *NewNode, *temp;
    if(head==NULL)
    {
        head= new Node;
        head->key=key;
        head->next=NULL;
        return head;
    }
    else
    {
        NewNode =new Node;
        NewNode->key=key;
        NewNode->next=NULL;
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=NewNode;
    }
    return head;
}
///Insert at the Head
Node *InsertHead(Node *head, int key)
{
    Node *NewNode;
    NewNode= new Node;
    NewNode->key=key;
    NewNode->next=head;
    return NewNode;
}
///Insert After a Node
Node *InsertAfterANode(Node *head, int key, int data)
{
    Node *NewNode, *temp;
    NewNode=new Node;
    NewNode->key=key;
    temp=head;
    while(temp->key!=data)
    {
        temp=temp->next;
    }
    NewNode->next=temp->next;
    temp->next=NewNode;
    return head;
}
///Insert Before a Node
Node *InsertBeforeANode(Node *head, int key, int data)
{
    Node *NewNode, *temp, *BeforeTemp;
    NewNode=new Node;
    NewNode->key=key;
    temp=head;
    while(temp->key!=data)
    {
        BeforeTemp=temp;
        temp=temp->next;
    }
    NewNode->next=temp;
    BeforeTemp->next=NewNode;
    return head;
}
///Delete A node
Node *DeleteNode(Node *head, int key)
{
    Node *temp, *BeforeTemp;
    temp=head;
    while(temp->key!=key)
    {
        BeforeTemp=temp;
        temp=temp->next;
    }
    BeforeTemp->next=temp->next;
    delete temp;
    return head;

}
/// Search A Node
bool Search(Node *head, int data)
{
  Node *temp;
  temp=head;
  while(temp!=NULL)
  {
      if(temp->key==data)
      {
        return true;
      }
      else
      {
        temp=temp->next;

      }
  }
  return false;
}
///Display Link List
void Display(Node *head)
{
    if(head)
    {
        while(head!=NULL)
        {
            cout<<head<<" "<<head->key<<" "<<head->next<<endl;
            head=head->next;
        }
    }
}
int main()
{
    Node *head=NULL;
    int n,key;
    cout<<"Enter The Number of Element: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        head=Insert(head,key);
    }
    cout<<"\nDisplay Link List: "<<endl;
    Display(head);
    cout<<"\nInsert at The Head: "<<endl;
    head=InsertHead(head, 5);
    cout<<"\nDisplay Link List: "<<endl;
    Display(head);
    head= InsertAfterANode(head, 6, 3);
    cout<<"\nDisplay Link List: "<<endl;
    Display(head);
    head=InsertBeforeANode(head, 10, 3);
    cout<<"\nDisplay Link List: "<<endl;
    Display(head);
    cout<<"\nAfter Delete The Node: "<<endl;
    head=DeleteNode(head,3);
    Display(head);
    cout<<"\nSearch A Key: "<<endl;
    if(Search(head,5))
    {
        cout<<"Search Key is Find"<<endl;
    }
    else
    {
        cout<<"Search Key is Not Found"<<endl;
    }
    return 0;
}

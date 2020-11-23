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
Node *Reverse_Link_List(Node *head)
{
    Node *current,*previous_of_current_node,*next;
    previous_of_current_node=NULL;
    next=NULL;
    current=head;
    while(current!=NULL)
    {
      next=current->next;

      current->next=previous_of_current_node;

      previous_of_current_node=current;

      current=next;
    }
    head =previous_of_current_node;
    return head;
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
    cout<<"\nDisplay Link List Before Reverse: "<<endl;
    Display(head);

    cout<<"\nDisplay Link List After Reverse: "<<endl;
    head=Reverse_Link_List(head);
    Display(head);
    return 0;
}

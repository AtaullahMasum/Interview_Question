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
Node *NewNode(int key)
{
    Node *Newnode= new Node;
    Newnode->key=key;
    Newnode->next=NULL;
    return Newnode;
}
Node *Insert_Before_Head(Node *head, int key)
{
    Node *NewNode;
    NewNode = new Node;
    NewNode->key=key;
    NewNode->next=head;
    head=NewNode;
    return head;
}
Node *AddTwoList(Node *head1, Node *head2)
{
    Node *head=NULL,*newnode,*prevnode;///prevnode means last seen node
    int carry=0;
    while(head1 || head2)
    {
        int sum=0;
        if(head1)
        {
            sum += head1->key;
        }
        if(head2)
        {
            sum += head2->key;
        }
        sum += carry;

        carry = sum/10;
        sum = sum%10;
        newnode = NewNode(sum);
        if(head==NULL)
        {

            prevnode = newnode;
            head = prevnode;

        }
        else
        {
            prevnode->next= newnode;
            prevnode= newnode;
        }
        if(head1)
        {
            head1=head1->next;
        }
        if(head2)
        {
            head2=head2->next;
        }
    }
    if(carry!=0)
    {
        head=Insert_Before_Head(head, carry);
    }
    return head;
}
Node *Return_New_list(Node *head1, Node *head2)
{
    Node *head;
    head1=Reverse_Link_List(head1);
    head2=Reverse_Link_List(head2);
    head=AddTwoList(head1, head2);
    return head;
}
int main()
{
    Node *head1=NULL, *head2=NULL, *head;
    int n,key;
    cout<<"Enter The Number of Element: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        head1=Insert(head1,key);

    }
    cout<<"\nEnter The Number of Element: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        head2=Insert(head2,key);

    }
    cout<<"\nDisplay Link List1: "<<endl;
    Display(head1);
    cout<<"\nDisplay Link List2: "<<endl;
    Display(head2);
    head = Return_New_list(head1, head2);
    cout<<"\nDisplay New List : "<<endl;
    Display(head);
    return 0;

}

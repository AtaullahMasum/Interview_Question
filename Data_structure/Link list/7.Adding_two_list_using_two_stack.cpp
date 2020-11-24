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
Node *NewNode(int key)
{
    Node *newnode= new Node;
    newnode->key=key;
    newnode->next=NULL;
    return newnode;
}
Node *AddTwoList(Node *head1, Node *head2)
{
    stack<int> stack1, stack2;
    Node *result=NULL,*newnode;
    while(head1!=NULL)
    {
        stack1.push(head1->key);
        head1=head1->next;
    }
    while(head2!=NULL)
    {
        stack2.push(head2->key);
        head2=head2->next;
    }
    int carry=0;
    while(stack1.empty()==false || stack2.empty()==false)
    {
        int a=0, b=0;
        if(!stack1.empty())
        {
            a = stack1.top();
            stack1.pop();
        }
        if(!stack2.empty())
        {
            b= stack2.top();
            stack2.pop();
        }
        int total = a+b+carry;
        newnode= NewNode(total%10);
        carry = total/10;
        if(result==NULL)
        {
            result=newnode;
        }
        else
        {
            newnode->next=result;
            result=newnode;
        }

    }
    if(carry!=0)
    {
        newnode = NewNode(carry);
        newnode->next=result;
        result=newnode;
    }
    return result;
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
    head=AddTwoList(head1, head2);
    cout<<"\nDisplay Link list After Adding: "<<endl;
    Display(head);

}

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
///Using Slow and Fast Methods
void Middle_Element_Of_Link_List(Node *head)
{
    Node *slow,*fast;
    slow=head;
    fast=head;
    if(head!=NULL)
    {
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        cout<<"\nMiddle Element is :"<<slow->key<<endl;
    }

}
///using Move Middle for Only Odd Element
void Middle_Element_Of_Link_List_Odd_method(Node *head)
{
    Node *middle;
    int Count=0;
    middle=head;
    if(head)
    {
        while(head!=NULL)
        {
            if(Count & 1)
            {
                middle=middle->next;
            }
            Count++;
            head=head->next;
        }
        cout<<"\nMiddle Element is : "<<middle->key<<endl;
    }
    else
    {
        cout<<"List is Empty"<<endl;
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
    cout<<endl;
    Middle_Element_Of_Link_List(head);
    Middle_Element_Of_Link_List_Odd_method(head);
    return 0;
}

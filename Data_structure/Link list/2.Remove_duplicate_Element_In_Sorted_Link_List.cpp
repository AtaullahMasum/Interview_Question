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
Node *Delete_Duplicate(Node *head)
{
    Node *current,*next_next;
    current=head;
    if(current==NULL)
    {
        return head;
    }
    else
    {
        while(current->next!=NULL)
        {
            if(current->key==current->next->key)
            {
                next_next=current->next->next;
                delete current->next;
                current->next=next_next;
            }
            else
            {
                current=current->next;
            }
        }

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
    cout<<"\nDisplay Link List: "<<endl;
    head=Delete_Duplicate(head);
    Display(head);
    return 0;
}

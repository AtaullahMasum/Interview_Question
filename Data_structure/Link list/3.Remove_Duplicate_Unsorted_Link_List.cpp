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
///Using Double Loop
Node *Delete_Duplicate_Using_Double_Loop(Node *head)
{
    Node *temp1, *temp2,*duplicate_node;
    temp1=head;
    while(temp1!=NULL && temp1->next!=NULL)
    {
        temp2=temp1;
        while(temp2->next!=NULL)
        {
            if(temp1->key==temp2->next->key)
            {
                duplicate_node=temp2->next;
                temp2->next=temp2->next->next;
                delete duplicate_node;
            }
            else
            {
                temp2=temp2->next;
            }
        }
        temp1=temp1->next;
    }
    return head;
}
///Using Hashing
Node *Delete_Duplicate_Using_Hashing(Node *head)
{
    unordered_set<int> Set;
    Node *temp,*previouse_of_temp_node,*duplicate_node;
    temp=head;
    while(temp!=NULL)
    {
        if(Set.find(temp->key)==Set.end())
        {
            Set.insert(temp->key);
            previouse_of_temp_node=temp;
            temp=temp->next;
        }
        else
        {
            duplicate_node=temp;
            previouse_of_temp_node->next=temp->next;
            temp=temp->next;
            delete duplicate_node;

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
    head=Delete_Duplicate_Using_Double_Loop(head);
    Display(head);
    cout<<"\nDisplay Link List: "<<endl;
    head=Delete_Duplicate_Using_Hashing(head);
    Display(head);
    return 0;
}

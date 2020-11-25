#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left,*right;
};
Node *NewNode(int key)
{
    Node *newnode= new Node;
    newnode->key=key;
    newnode->left=nullptr;
    newnode->right=nullptr;
    return newnode;
}
Node *Insert_Recursively(Node *root, int key)
{
    if(root==nullptr)
    {
        return NewNode(key);
    }
    if(key > root->key)
    {
        root->right=Insert_Recursively(root->right, key);
    }
    else if( key < root->key)
    {
        root->left = Insert_Recursively(root->left, key);
    }
    return root;
}
void Iterative_Preorder(Node *root)
{
    if(root==nullptr)
    {
        return ;
    }
    stack<Node *> Stack;
    Stack.push(root);
    while(!Stack.empty())
    {
        Node *current= Stack.top();
        Stack.pop();
        cout<<current->key<<" ";
        if(current->right)
        {
            Stack.push(current->right);
        }
        if(current->left)
        {
            Stack.push(current->left);
        }
    }

}
void Iterative_Inorder(Node *root)
{
    stack<Node *> Stack;
    if(root==nullptr)
    {
        return ;
    }
    Node *current=root;
    while(!Stack.empty() || current)
    {
        while(current)
        {
            Stack.push(current);
            current=current->left;
        }
        current=Stack.top();
        cout<<current->key<<" ";
        Stack.pop();
        current=current->right;
    }
}
void Iterative_Postorder(Node *root)
{
   stack<Node *> Stack1, Stack2;
   Node *current=root;
   if(root==nullptr)
   {
       return ;
   }
   Stack1.push(current);
   while(!Stack1.empty())
   {
       current =Stack1.top();
       Stack1.pop();
       Stack2.push(current);
       if(current->left)
       {
           Stack1.push(current->left);
       }
       if(current->right)
       {
           Stack1.push(current->right);
       }
   }
   while(!Stack2.empty())
   {
       cout<<Stack2.top()->key<<" ";
       Stack2.pop();
   }
}
int main()
{
    Node *root=nullptr;
    int n, key;
    cout<<"Enter The Number Of Element: "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>key;
        root=Insert_Recursively(root,key);
    }
    cout<<"\nIterative Preorder: ";
    Iterative_Preorder(root);
    cout<<"\nIterative Inorder: ";
    Iterative_Inorder(root);
    cout<<"\nIterative Postorder: ";
    Iterative_Postorder(root);
    return 0;
}

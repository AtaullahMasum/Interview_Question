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
Node *Insert_Iterative_Way(Node *root, int key)
{
    Node *current;
    if(root==nullptr)
    {
        return NewNode(key);
    }
    current=root;
    while(true)
    {
        if(current->key > key)
        {
            if(current->left==nullptr)
            {
                current->left=NewNode(key);
                break;
            }
            else
            {
                current=current->left;
            }
        }
        else
        {
            if(current->right==nullptr)
            {
                current->right=NewNode(key);
                break;
            }
            else
            {
                current=current->right;
            }
        }
    }
    return root;
}

void Inorder_Traversal(Node *root)
{
    if(root)
    {
        Inorder_Traversal(root->left);
        cout<<root->key<<" ";
        Inorder_Traversal(root->right);
    }
}
void Preorder_Traversal(Node *root)
{
    if(root)
    {
        cout<<root->key<<" ";
        Preorder_Traversal(root->left);
        Preorder_Traversal(root->right);

    }
}
void Postorder_Traversal(Node *root)
{
    if(root)
    {
        Postorder_Traversal(root->left);
        Postorder_Traversal(root->right);
        cout<<root->key<<" ";
    }
}
Node *MinValue(Node *root)
{
    while(root && root->left)
    {
        root=root->left;
    }
    return root;
}
///Delete Operation
Node *Delete_Node(Node *root, int key)
{
    if(root==nullptr)
    {
        return root;
    }
    else if(key > root->key)
    {
        root->right = Delete_Node(root->right, key);
    }
    else if(key < root->key)
    {
        root->left = Delete_Node(root->left, key);
    }
    else
    {
        if(root->left==nullptr)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if(root->right==nullptr)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp = MinValue(root->right);
            root->key=temp->key;
            root->right=Delete_Node(root->right, temp->key);
        }
    }
    return root;
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
        root=Insert_Iterative_Way(root,key);
    }
    cout<<"\nPreOrder Traversal : ";
    Preorder_Traversal(root);
    cout<<"\nInorder Traversal : ";
    Inorder_Traversal(root);
    cout<<"\nPost Order Traversal: ";
    Postorder_Traversal(root);
    root = Delete_Node(root, 20);
    cout<<"\nInorder Traversal : ";
    Inorder_Traversal(root);

    return 0;
}

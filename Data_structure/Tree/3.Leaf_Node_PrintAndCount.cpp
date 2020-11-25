#include<bits/stdc++.h>
using namespace std;
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
void LeafNodePrintAndCount(Node *root, int &Count)
{
    if(root)
    {
        LeafNodePrintAndCount(root->left, Count);
        if(root->left==nullptr && root->right==nullptr)
        {
            Count++;
            cout<<root->key<<" ";
        }
        LeafNodePrintAndCount(root->right, Count);
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
    int Count=0;
    cout<<"\nLeaf Node of The Tree: ";
    LeafNodePrintAndCount(root, Count);
    cout<<"\nNumber Of Leaf Node: "<<Count<<endl;
    return 0;
}

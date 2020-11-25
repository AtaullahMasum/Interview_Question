#include<bits/stdc++.h>
using namespace std;
bool isRotate(string str1, string str2)
{
    if(str1.size()!=str2.size())
    {
        return false;
    }
    string temp = str1+str1;
    return (temp.find(str2) != string::npos);
}
int main()
{
    string str1, str2;
    cout<<"Enter The First String: "<<endl;
    cin>>str1;
    cout<<"\nEnter The Second String: "<<endl;
    cin>>str2;
    if(isRotate(str1,str2))
    {
        cout<<"Two String is Rotate"<<endl;
    }
    else
    {
        cout<<"Two String is not Rotate"<<endl;
    }
    return 0;
}

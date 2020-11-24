#include<bits/stdc++.h>
using namespace std;
void Reverse_String(string str)
{
    if(str.size()==0)
    {
        return ;
    }
    Reverse_String(str.substr(1));
    cout<<str[0];
}
int main()
{
    string str;
    cout<<"Enter The String: "<<endl;
    cin>>str;
    Reverse_String(str);
    return 0;
}

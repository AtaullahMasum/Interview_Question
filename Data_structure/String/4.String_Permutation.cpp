#include<bits/stdc++.h>
using namespace std;
void String_Permutation(string str)
{
    sort(str.begin(),str.end());
    do{
        cout<<str<<endl;
    }while(next_permutation(str.begin(),str.end()));
}
int main()
{
    string str;
    cout<<"Enter The String: ";
    cin>>str;
    cout<<"\nPermutation of String is : "<<endl;
    String_Permutation(str);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char Find_Duplicate_Character_In_A_String(string str)
{
    map<char, int> Map;
    for(int i=0;i<str.size();i++)
    {
        Map[str[i]]++;
    }
    for(auto it=Map.begin(); it!=Map.end();it++)
    {
        if(it->second==1)
        {
            return (it->first);
        }
    }
}
int main()
{
    string str;
    cout<<"Enter The String: ";
    cin>>str;
    cout<<"\nDisplay first Non Repeating Character in String: "<<endl;
    cout<<Find_Duplicate_Character_In_A_String(str);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
void Count_Word_In_String(string str)
{
    map<string, int> Map;
    stringstream sttr(str);
    string word;
    while(sttr>>word)
    {
        Map[word]++;
    }
    for(auto it=Map.begin();it!=Map.end();it++)
    {
        cout<<it->first <<" "<<it->second<<endl;
    }
}
int main()
{
    string str;
    cout<<"Enter The String : "<<endl;
    getline(cin, str);
    cout<<"\nDisplay Count Word"<<endl;
    Count_Word_In_String(str);
    return 0;
}

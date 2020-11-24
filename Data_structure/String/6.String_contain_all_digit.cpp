#include<bits/stdc++.h>
using namespace std;
const int MAX=10;

bool isDigit(char cha)
{
    if(cha>='0' && cha<='9')
    {
        return true;
    }
    return false;
}
bool Check_All_Digit(string str)
{
    bool isPresent[MAX]={false};
    for(int i=0;i<str.size();i++)
    {
        if(isDigit(str[i]))
        {
            isPresent[str[i]-'0']=true;
        }
    }
    for(int i=0;i<MAX;i++)
    {
        if(!isPresent[i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string str;
    cout<<"Enter The String : "<<endl;
    cin>>str;
    if(Check_All_Digit(str))
    {
        cout<<"All Digit contain"<<endl;
    }
    else
    {
        cout<<"All digit cann't contain"<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
void All_Pairs_Equal_To_A_Number(int arr[], int n, int num)
{
    unordered_set<int> Set(arr, arr+n);
    int Find_hash;
    for (int i=0;i<n;i++)
    {
        Find_hash=num-arr[i];
        if(Set.find(Find_hash)!=Set.end())
        {

            cout<<"("<<arr[i]<<" "<<Find_hash<<")";
            Set.erase(Set.find(arr[i]));

        }

    }
}
int main()
{
    int n;
    cout<<"Enter The Number Of Element: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    All_Pairs_Equal_To_A_Number(arr, n, 7);
    return 0;
}

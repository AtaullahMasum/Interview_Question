#include<bits/stdc++.h>
using namespace std;
void Remove_Duplicate_Value_In_Array(int arr[], int Size)
{
    unordered_set<int> Set;
    for(int i=0;i<Size;i++)
    {
        if(Set.find(arr[i])==Set.end())
        {
            Set.insert(arr[i]);
        }
        else
        {
            arr[i]=0;
        }
    }
    for (int i=0;i<Size;i++)
    {
        cout<<arr[i]<<" ";
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
    Remove_Duplicate_Value_In_Array(arr, n);
    return 0;
}

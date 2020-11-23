#include<bits/stdc++.h>
using namespace std;

void Multiple_Missing_Value_Duplicate_Array(int arr[], int Size)
{
    vector<int> Resister(Size,0);
    for(int i=0;i<Size;i++)
    {
        Resister[arr[i]]=1;
    }
    for(int i=1;i<=Size;i++)
    {
        if(Resister[i]==0)
        {
            cout<<i<<" ";
        }
    }
}
int main()
{
    int Size;
    cout<<"Enter The Total Size Of Array: ";
    cin>>Size;
    int arr[Size];
    for(int i=0;i<Size;i++)
    {
        cin>>arr[i];
    }
    Multiple_Missing_Value_Duplicate_Array(arr, Size);
    return 0;
}

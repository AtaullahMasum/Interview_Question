#include<bits/stdc++.h>
using namespace std;
int Second_Largest_Value_In_Array(int arr[], int Size)
{
    int Max= *max_element(arr, arr+Size);
    int Second_Max;
    Second_Max=arr[0];
    for(int i=0;i<Size;i++)
    {
        if(arr[i]>Second_Max && arr[i]!=Max)
        {
            Second_Max=arr[i];
        }
    }
    return Second_Max;
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
    cout<<"\nSecond Max is :  "<<Second_Largest_Value_In_Array(arr, n);
    return 0;
}

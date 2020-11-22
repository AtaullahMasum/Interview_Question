#include<bits/stdc++.h>
using namespace std;
//Solution 1:
int Missing_Value_Return(int arr[], int Size)
{
    int sum,i;
    //sum means total number of summation,i means iteration
    sum=(Size + 1)*(Size + 2)/2;
    for(i=0;i<Size;i++)
    {
        sum-=arr[i];
    }
    return sum;


}
//Solution 2:Using XOR
int Missing_Value_Return_Using_XOR(int arr[], int n)
{
    int First_Element_of_array=arr[0];
    int First_index_of_array = 1;
    for(int i=1;i<n;i++)
    {
        First_Element_of_array^=arr[i];
    }
    for(int i=2;i<=(n+1);i++)
    {
        First_index_of_array^=i;
    }
    return(First_Element_of_array^First_index_of_array);
}

//Solution 3:

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
    cout<<"\nMissing Value in the Array is :  "<<Missing_Value_Return(arr,n);
    cout<<"\nMissing Value Using XOR:  "<<Missing_Value_Return_Using_XOR(arr, n);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int Partition_Point_Return(int arr[], int low, int high);
void Quick_Sort(int arr[], int low, int high);


void Quick_Sort(int arr[], int low, int high)
{
    if(low<high)
    {
        int Partition_Point=Partition_Point_Return(arr, low, high);
        Quick_Sort(arr, low, Partition_Point-1);
        Quick_Sort(arr, Partition_Point+1, high);
    }
}
int Partition_Point_Return(int arr[], int low, int high)
{
    int pivot = arr[high];
    int index_lower_Point= (low-1);
    for(int j= low; j<=(high-1); j++)
    {
        if(arr[j] < pivot)
        {
            index_lower_Point++;
            swap(arr[index_lower_Point], arr[j]);
        }
    }
    swap(arr[index_lower_Point+1], arr[high]);
    return (index_lower_Point+1);
}
void Display(int arr[], int Size)
{
    for(int i=0;i<Size;i++)
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
    cout<<"Before Quick Sort: ";
    Display(arr, n);
    Quick_Sort(arr,0,n-1);
    cout<<"\nAfter Quick Sort: ";
    Display(arr, n);
    return 0;

}


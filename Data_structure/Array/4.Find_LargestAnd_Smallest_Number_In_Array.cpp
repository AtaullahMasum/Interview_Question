#include<bits/stdc++.h>
using namespace std;
pair<int, int> MinMax(int arr[], int Size)
{
    int Max= *max_element(arr, arr+Size);
    int Min = *min_element(arr, arr+Size);
    return make_pair(Max,Min);
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
    pair<int, int> Store_Min_Max=MinMax(arr, n);
    cout<<"\nMin is: "<<Store_Min_Max.first<<"\nMax is: "<<Store_Min_Max.second<<endl;
    return 0;
}

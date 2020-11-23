#include<bits/stdc++.h>
using namespace std;

void Find_Duplicate_Value(int arr[], int Size)
{
    unordered_map<int, int> Map;
    for(int i=0;i<Size;i++)
    {
        Map[arr[i]]++;
    }
    cout<<"Using Iterator: "<<endl;
    unordered_map<int, int>:: iterator it;
    for(it=Map.begin();it!=Map.end();it++)
    {
        if(it->second>1)
        {
            cout<< it->first<<" ";
        }
    }
    cout<<"\nUsing Auto: "<<endl;
    for(auto x: Map)
    {
        if(x.second>1)
        {
            cout<<x.first<<" ";
        }
    }
}
/*void printDuplicates(int arr[], int n)
{
    // unordered_map to store frequencies
    unordered_map<int, int> freq;
    for (int i=0; i<n; i++)
        freq[arr[i]]++;

    ///bool dup = false;
    unordered_map<int, int>:: iterator itr;
    for (itr=freq.begin(); itr!=freq.end(); itr++)
    {
        // if frequency is more than 1
        // print the element
        if (itr->second > 1)
        {
            cout << itr->first << " ";
            //dup = true;
        }
    }
}*/
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
    Find_Duplicate_Value(arr, n);
    return 0;
}

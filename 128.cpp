#include <bits/stdc++.h>
using namespace std;

bool isNear(vector<int>& arr,int x,int y,int n)
{
 if(arr[0]==x)
    {
        if(arr[1]==y) return true;
    }
    if(arr[n-1]==x)
    {
        if(arr[n-2]==y) return true;
    }

    for(int i = 1;i<n-1;i++)
    {
        if(arr[i]==x)
        {
            if(arr[i-1]==y||arr[i+1]==y) return true;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x,y;
    cin>>x>>y;
    if(isNear(arr,x,y,n))cout<<"Yes";
    else cout<<"No";
    return 0;
}
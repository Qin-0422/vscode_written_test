#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,x,y;
    cin>>n;
    vector<long long> arr(n,0);
    long long AllDistance = 0;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        AllDistance += arr[i];
    }
    cin>>x>>y;
    if(x>y) swap(x,y);
    long long PartDistance = 0;
    for(int i = x-1;i<y-1;i++)
    {
        PartDistance += arr[i];
    }
    PartDistance<AllDistance-PartDistance ? cout<<PartDistance : cout<<AllDistance-PartDistance;
    return 0;
}
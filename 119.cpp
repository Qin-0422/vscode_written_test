#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n ;
    cin>>n;
    vector<char> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }

    vector<pair<char,int>> mmap;

    int slowIndex = 0;
    int fastIndex = 1;
    for(;fastIndex<n;fastIndex++)
    {
        if(arr[fastIndex]==arr[slowIndex])
        {
            continue;
        }
        else
        {
            int len = fastIndex-slowIndex;
            if(len<3||(len%2==0&&len<6))
            {
                cout<<"-1"<<endl;
                return 0;
            }
            else if(len%2==1)
            {
                
                mmap.push_back({arr[slowIndex],len});
                slowIndex = fastIndex;
            }
            else 
            {
                mmap.push_back({arr[slowIndex],3});
                mmap.push_back({arr[slowIndex],len-3});
                slowIndex = fastIndex;
            }
        }
    }

    int len = fastIndex-slowIndex;
    if(len<3||(len%2==0&&len<6))
    {
        cout<<"-1"<<endl;
        return 0;
    }
    else if(len%2==1)
    {
        
        mmap.push_back({arr[slowIndex],len});
        slowIndex = fastIndex;
    }
    else 
    {
        mmap.push_back({arr[slowIndex],3});
        mmap.push_back({arr[slowIndex],len-3});
        slowIndex = fastIndex;
    }




    for(auto& pair : mmap)
    {
        for(auto j = 0;j<pair.second;j++)
        {
            cout<<pair.first;
        }
        cout<<" ";
    }
    return 0;
}
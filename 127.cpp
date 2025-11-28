#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,p1,p2,val;
    cin>>n>>m;

    vector<vector<int>> grid;
    for(int i = 0;i<m;i++)
    {
        cin>>p1>>p2>>val;
        grid.push_back({p1,p2,val});
    }

    vector<int> minDist(n+1,INT_MAX);
    minDist[1] = 0;

    for(int i = 1;i<n;i++)
    {
        for(vector<int>& side:grid)
        {
            int from = side[0];
            int to = side[1];
            int val = side[2];

            if(minDist[from]!=INT_MAX&&minDist[to]>minDist[from]+val)
            {
                minDist[to] = minDist[from]+val;
            }
        }
    }
    if(minDist[n]==INT_MAX)cout<<"unconnected";
    else cout<<minDist[n];
    return 0;
}
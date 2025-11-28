#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<ll> arr(100001);
vector<bool> red(100001,false);
vector<vector<int>> tree(100001);

bool isAiming(ll n)
{
    ll root = sqrt(n);
    if(root*root == n) return true;
    else return false;
}

int dfs(int u,int parent)
{
    int count = 0;
    for(int v:tree[u])
    {
        if(v==parent)continue;
        count += dfs(v,u);
        if(!red[u]&&!red[v]&&isAiming(arr[u]*arr[v]))
        {
            red[u] = true;
            red[v] = true;
            count += 2;
        }
    }
    return count;
}

int main()
{
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>arr[i];
    }

    int u,v;
    for(int i = 1;i<n;i++)
    {
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    int res = dfs(1,-1);
    cout<<res<<endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin>>t;
    int n;
    ll x;
    while (t--)
    {
        cin>>n>>x;
        vector<ll> nums(n);
        for(int i = 0;i<n;i++)
        {
            cin>>nums[i];
        }

        vector<vector<ll>> dp(n,vector<ll>(2,0));
        dp[0][0] = nums[0];
        dp[0][1] = x;

        ll result = max(dp[0][0],dp[0][1]);
        for(int i = 1;i<n;i++)
        {
            dp[i][0] = max(dp[i-1][0] + nums[i],nums[i]);
            ll used = max(dp[i-1][1]+nums[i],nums[i]);
            ll unused = max(dp[i-1][0]+x,x);
            dp[i][1] = max(used,unused);

            result = max(result,max(dp[i][0],dp[i][1]));
        }

        cout<<result<<endl;
    }
    
}
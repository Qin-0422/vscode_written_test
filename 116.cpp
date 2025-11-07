#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const int MAX_M = 3;

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> nums(n,vector<int>(2));
    for(int i = 0;i<n;i++)
    {
        cin>>nums[i][0]>>nums[i][1];
    }

    vector<vector<int>> dp(n+1,vector<int>(MAX_M,0));
    dp[0][0] = 1;

    for(int i = 1;i<=n;i++)
    {
        for(int j = 0;j<MAX_M;j++)
        {
            for(int k = 0;k<2;k++)
            {
                int sum = (j+nums[i-1][k])%MAX_M;
                dp[i][sum] = (dp[i][sum] + dp[i-1][j])%MOD;
            }
        }
    }
    cout<<dp[n][0];
    return 0;
}
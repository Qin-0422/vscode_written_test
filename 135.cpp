#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    //特判，终点即起点
    if(n==1 && m==1)
    {
        cout<<"0";
        return 0;
    }

    vector<string> pos(n);
    for(int i = 0;i<n;i++)
    {
        cin>>pos[i];
    }

    //特判，起点出现障碍物
    if(pos[0][0] == '*')
    {
        cout<<"-1";
        return 0;
    }

    vector<vector<int>> dp(n,vector<int>(m,INT_MAX - 1));
    //dir代表这个节点可以继续走的方向 按顺序分别是  下 右下 右
    vector<vector<string>> dir(n,vector<string>(m,"000"));
    dp[0][0] = 1;
    dir[0][0] = "111";

    //相当于初始化，把最上一行和最左列都处理了，因为后续动规需要用到 左 上 左上。
    for(int i = 1;i<n && pos[i][0]!='*';i++)
    {
        dp[i][0] = 1;
        dir[i][0] = "100";
    }
     for(int j=1;j<m && pos[0][j]!='*';j++){
        dp[0][j] = 1;
        dir[0][j] = "001";
    }
    for(int i=1,j=1;i<min(m,n)&&pos[i][j]!='*';i++,j++){
        dp[i][j] = 1;
        dir[i][j] = "010";
    }

    for(int i = 1;i<n;i++)
    {
        for(int j  =1;j<m;j++)
        {
            if(pos[i][j]=='*') continue;
            int dir1,dir2,dir3;
            //考虑当前格子的 左边 左上  上边 的格子
            //如果左边的格子 的方向 如果是右 则直接继承
            //不是右 则要在左边的格子的步数基础上+1得当前格子的步数
            //其余格子 规律相同
            if(dir[i][j-1][2]=='1') dir1 = dp[i][j-1];
            else dir1 = dp[i][j-1] + 1;
            if(dir[i-1][j-1][1]=='1') dir2 = dp[i-1][j-1];
            else dir2 = dp[i-1][j-1] + 1;
            if(dir[i-1][j][0]=='1') dir3 = dp[i-1][j];
            else dir3 = dp[i-1][j] + 1;

            dp[i][j] = min(dir1,min(dir2,dir3));
            if(dp[i][j]==dir1) dir[i][j][2] = '1';
            if(dp[i][j] == dir2) dir[i][j][1] = '1';
            if(dp[i][j] == dir3) dir[i][j][0] = '1';
            
        }
    }

    if(dp[n-1][m-1]==INT_MAX || dp[n-1][m-1]==INT_MAX-1) cout<<"-1";
    else cout<<dp[n-1][m-1];
    return 0;
}
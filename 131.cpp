#include <bits/stdc++.h>
using namespace std;
int dir[4][2] ={1,0,-1,0,0,1,0,-1};
void dfs(const vector<vector<char>>& words,vector<vector<bool>>& visited,int x,int y)
{
    if(visited[x][y])return;
    visited[x][y] = true;
    for(int i = 0;i<4;i++)
    {
        int cur_x = x + dir[i][0];
        int cur_y = y + dir[i][1];
        if(cur_x<0||cur_x>=words.size()||cur_y<0||cur_y>=words[0].size())continue;
        if(!visited[cur_x][cur_y]&&words[x][y]==words[cur_x][cur_y])
        dfs(words,visited,cur_x,cur_y);
    }
}
int main()
{
    int n;
    cin>>n;
    string word;
    for(int i = 0;i<n;i++)
    {
        char a;
        cin>>a;
        word += a;
    }
    int a = 1;
    int b = n;
    int result = n;
    while (a<=b)
    {
        if(n%a==0)
        {
            //这步很细节
            b = n/a;

            vector<vector<char>> words(a,vector<char>(b));
            int k = 0;
            for(int i = 0;i<a;i++)
            {
                for(int j = 0;j<b;j++)
                {
                    words[i][j] = word[k];
                    k++;
                }
            }

            int count = 0;
            vector<vector<bool>> visited(a,vector<bool>(b,false));
             for(int i = 0;i<a;i++)
            {
                for(int j = 0;j<b;j++)
                {
                   if(!visited[i][j])
                   {
                        count++;
                        dfs(words,visited,i,j);
                   }
                }
            }
            result = min(result,count);
        }
        a++;
    }
    cout<<result<<endl;
    return 0;
}
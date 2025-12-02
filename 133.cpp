#include <bits/stdc++.h>
using namespace std;

bool func1(vector<vector<char>>& chessBox,char target)
{
    if(chessBox[0][0]==target&&chessBox[2][2]==target) return true;
    if(chessBox[1][0]==target&&chessBox[1][2]==target) return true;
    if(chessBox[2][0]==target&&chessBox[0][2]==target) return true;
    if(chessBox[0][1]==target&&chessBox[2][1]==target) return true;
    return false;
}

bool func2(vector<vector<char>>& chessBox,char target,int x)
{
    if(chessBox[x][0]==target&&chessBox[x][2]==target) return true;
    return false;
}

bool func3(vector<vector<char>>& chessBox,char target,int y)
{
    if(chessBox[0][y]==target&&chessBox[2][y]==target) return true;
    return false;
}

int main()
{
    int t;
    cin>>t;
    vector<vector<char>> chessBox(3,vector<char>(3));
    while(t--)
    {
        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                cin >> chessBox[i][j];
         }
        }
        bool red = false;
        bool purple = false;
        if(chessBox[1][1]!='.')
        {
            if(chessBox[1][1]=='o')
            {
                if(func1(chessBox,'*')) red = true;
            }
            if(chessBox[1][1]=='*')
            {
                if(func1(chessBox,'o')) purple = true;
            }
        }

        if(chessBox[1][0]!='.')
        {
            if(chessBox[1][0]=='o')
            {
                if(func3(chessBox,'*',0)) red = true;
            }
            if(chessBox[1][0]=='*')
            {
                if(func3(chessBox,'o',0)) purple = true;
            }
        }
        if(chessBox[1][2]!='.')
        {
            if(chessBox[1][2]=='o')
            {
                if(func3(chessBox,'*',2)) red = true;
            }
            if(chessBox[1][2]=='*')
            {
                if(func3(chessBox,'o',2)) purple = true;
            }
        }

        if(chessBox[0][1]!='.')
        {
            if(chessBox[0][1]=='o')
            {
                if(func2(chessBox,'*',0)) red = true;
            }
            if(chessBox[0][1]=='*')
            {
                if(func2(chessBox,'o',0)) purple = true;
            }
        }
        if(chessBox[2][1]!='.')
        {
            if(chessBox[2][1]=='o')
            {
                if(func2(chessBox,'*',2)) red = true;
            }
            if(chessBox[2][1]=='*')
            {
                if(func2(chessBox,'o',2)) purple = true;
            }
        }
        if(red&&!purple) cout<<"kou"<<endl;
        else if(!red&&purple) cout<<"yukan"<<endl;
        else cout<<"draw"<<endl;
   
    }
    return 0;
}
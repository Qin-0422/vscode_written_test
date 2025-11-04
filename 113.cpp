#include <iostream>
#include <vector>
#include <climits>
using namespace std;



bool getPos(int x1,int y1,int x2,int y2)
{
    static const int kdx[8] = { 1, 2, -1, -2,  1,  2, -1, -2 };
    static const int kdy[8] = { 2, 1,  2,  1, -2, -1, -2, -1 };
    for(int i = 0;i<8;i++)
    {
        if(abs(x1+kdx[i]-x2)==abs(y1+kdy[i]-y2))return true;
        if(abs(kdx[i]+x2-x1)==abs(kdy[i]+y2-y1))return true;
    }
    return false;
}

bool isOneStep(int x1,int y1,int x2,int y2)
{
    if(abs(x2-x1)==abs(y2-y1))return true;
    if((abs(x2-x1)+abs(y2-y1))==3&&abs(x2-x1)!=3&&abs(y2-y1)!=3)return true; 
    return false;
}

bool isTwoStep(int x1,int y1,int x2,int y2)
{
    if((abs(x1+y1)%2)==(abs(x2+y2)%2))return true;
    if(getPos(x1,y1,x2,y2))return true; 
    return false;
}

int jump(int x1,int y1,int x2,int y2)
{
    if(x1==x2&&y1==y2) return 0;
    if(isOneStep(x1,y1,x2,y2))return 1;
    if(isTwoStep(x1,y1,x2,y2))return 2;
    return 3;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<jump(x1,y1,x2,y2)<<endl;
    }
    return 0;
}
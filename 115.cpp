#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int  n;
    cin>>n;
    vector<int> ai(n);
    vector<int> bi(n);
    for(int i = 0;i<n;i++)
    {
        cin>>ai[i];
    }
    for(int i = 0;i<n;i++)
    {
        cin>>bi[i];
    }
   

    const int VMAX = 1000;
    vector<int> cntA(VMAX+1,0),cntB(VMAX+1,0);
    for(int x:ai) cntA[x]++;
    for(int y:bi) cntB[y]++;

    int result = 0;
    for(int sum = 2;sum<=2*VMAX;sum++)
    {
        int pair = 0;
        for(int x = 1;x<min(sum,1001);x++)
        {
            int y = sum-x;
            if(y<1||y>VMAX)continue;
            pair += min(cntA[x],cntB[y]);
        }
        result = max(result,pair);
    }

    cout<<result<<endl;
    return 0;
}
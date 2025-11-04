#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    int hurt = 0;
    int continousNum = 0;
    vector<char> vec(n);
    for(int i = 0;i<n;i++)
    {
        cin>>vec[i];
    }
    for(int i = 0;i<n;i++)
    {
        hurt += (a + b*continousNum);
        if(vec[i]=='o')
        {
            continousNum++;
        }
        else if(vec[i]=='x') continousNum = 0;
    }
    cout<<hurt<<endl;
    return 0;
}
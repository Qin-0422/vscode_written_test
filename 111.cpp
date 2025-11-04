#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


vector<int> findDeterminant(int x)
{
    vector<int> result(4,0);
    unordered_map<int,pair<int,int>> map;
    for(int i = 1;i<=20;i++)
    {
        for(int j = 1;j<=20;j++)
        {
            int sum = i*j;
            if(map.count(sum-x))
            {
                result[0] = i;
                result[3] = j;
                result[1] = map[sum-x].first;
                result[2] = map[sum-x].second;
                return result;
            }
            if(map.count(sum+x))
            {
                result[1] = i;
                result[2] = j;
                result[0] = map[sum+x].first;
                result[3] = map[sum+x].second;
                return result;
            }

            if(!map.count(sum))
            {
                pair<int,int> my_pair(i,j);
                map[sum] = my_pair;
            }
        }
    }
    return {};
}

int main()
{
    int x;
    cin>>x;
    vector<int> res(4,0);
    res = findDeterminant(x);
    if(res.empty())
    {
        cout<<"-1";
        return 0;
    }
    cout<<res[0]<<" "<<res[1]<<endl;
    cout<<res[2]<<" "<<res[3];
    return 0;
}
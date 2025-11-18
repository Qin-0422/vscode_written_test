#include <bits/stdc++.h>
using namespace std;

void init(deque<int>& max,deque<int>& min, vector<int>& nums,int k)
{
    max.push_back (nums[0]);
    min.push_back(nums[0]);
    for(int i = 1;i<k;i++)
    {
        while(!max.empty()&&nums[i]>max.back())
        {
            max.pop_back();
        }
        max.push_back(nums[i]);

        while(!min.empty()&&nums[i]<min.back())
        {
            min.pop_back();
        }
        min.push_back(nums[i]);
    }
}

int main()
{
    //解决输入问题
    string s;
    getline(cin,s);
    int pos1,pos2;
    for(int i = 0;i<s.size();i++)
    {
        if(s[i]=='[') pos1 = i;
        else if(s[i]==']') pos2 = i;
    }
    int kpos = s.find('k')+4;
    int k = stoi(s.substr(kpos));
    string s1 = s.substr(pos1+1,pos2-pos1-1);
    int pos3 = -1;
    int pos4;
    vector<int> nums;
    for(int i = 0;i<s1.size();i++)
    {
        if(s1[i]==',')
        {
            pos4 = i;
            nums.push_back(stoi(s1.substr(pos3+1,pos4-pos3-1)));
            pos3 = pos4;
        }
    } 
    pos4 = s1.size();
    nums.push_back(stoi(s1.substr(pos3+1,pos4-pos3-1)));
    
    deque<int> mmax;
    deque<int> mmin;
    init(mmax,mmin,nums,k);
    int result = mmax.front()-mmin.front();
    
    int leftIndex = 0;
    int rightIndex = k;

    while(rightIndex<nums.size())
    {
        result = max(result,mmax.front()-mmin.front());

        if(nums[leftIndex]==mmax.front()) mmax.pop_front();
        if(nums[leftIndex]==mmin.front()) mmin.pop_front();

        while(!mmax.empty()&&nums[rightIndex]>mmax.back())
        {
            mmax.pop_back();
        }
        mmax.push_back(nums[rightIndex]);

        while(!mmin.empty()&&nums[rightIndex]<mmin.back())
        {
            mmin.pop_back();
        }
        mmin.push_back(nums[rightIndex]);


        leftIndex++;
        rightIndex++;
    }

    cout<<result<<endl;
    return 0;
}
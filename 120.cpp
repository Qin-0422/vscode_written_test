#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; //询问次数
    string s; //模式串
    string K; //这个后续 k值-1 后转化成string类型的存储
    vector<int> position;//记录‘？’的位置。
    int k;//第k小
    unsigned long  numofresult;//累计“总匹配个数”的乘积。遇到首位 ? 乘以 9 ，其他每个 ? 乘以 10 ，用来判断是否至少有 k 个匹配。也就是计算成不成立
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s.clear();
        position.clear();
        k=0;
        numofresult=1;
        cin>>s;
        cin>>k;
        if(s[0]=='0')
        {
            cout<<-1<<endl;
            continue;
        }

        //-------------这之前都很好理解，一些初始化 清空处理。

        //计算numofresult 将所有的'?'换成0或1 并存储'?'位置，判断是否输出-1。
        for(int j=0;j<s.size();j++)
        {
            if(s[j]=='?')
            {
                if(j==0)
                {
                    s[j]='1';
                    numofresult*=9;
                }
                else
                {
                    s[j]='0';
                    numofresult*=10;
                }
                position.push_back(j);
            }
        }
        if(k>numofresult)
        {
            cout<<-1<<endl;
            continue;
        }

        //好好想想 k-1是必要的。
        k--;
        //index记录每个‘？’在s中的索引位置
        int index = position.size()-1;
        K=to_string(k);
        for(int j=K.size()-1;j>=0;j--)
        {
            s[position[index]]+=(K[j]-'0');
            index--;
        }
        cout<<s<<endl;
    }
    return 0;
}
// 思路
// - 预处理：去除前导零；若两数相等直接返回 0
// - 比较大小：决定结果符号；若 a<b ，用 b-a 的绝对差并在前面加 -
// - 逐位相减：从低位到高位相减，必要时向高位借 1（即加 10 再减）
// - 去前导零：相减后去除前导零，若全为零，返回 0

#include <bits/stdc++.h>
using namespace std;

void preProcess(string& s)
{
    for(int i = 0;i<s.length();i++)
    {
        if(s[i]!='0')
        {
            s = s.substr(i,s.length()-i);
            break;
        }
    }
    if(s.length()==0) s ="0";
   
}
bool isEqual(string& s1,string& s2)
{
    if(s1.length()==s2.length())
    {
        for(int i = 0;i<s1.length();i++)
        {
            if(s1[i]!=s2[i])return false;
        }
        return true;
    }
    return false;
}

int compare(string& s1,string& s2)
{
    if(s1.length()>s2.length()) return 1;
    else if(s1.length()<s2.length()) return -1;
    else{
        for(int i = 0;i<s1.length();i++)
        {
            if(s1[i]>s2[i])return 1;
            else if(s1[i]<s2[i]) return -1;
            else continue;
        }
    }
    return 0;
}

void sub(string& s1,string& s2)
{
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for(int i = 0;i<s2.length();i++)
    {
        if(s1[i]>=s2[i]) s1[i] = s1[i] - (s2[i] - '0');
        else{
            for(int j = i+1;j<s1.length();j++)
            {
                if(s1[j]=='0') s1[j] = '9';
                else{
                    s1[j]--;
                    break;
                }
            }
            s1[i] -= (s2[i]-'0') - 10;
        }
    }
    reverse(s1.begin(), s1.end());
}

void my_swap(string& s1,string& s2)
{
    string temp = s1;
    s1 = s2;
    s2 = temp;
}

int main()
{
    //输入
    string s1;
    string s2;
    cin>>s1>>s2;

    //预处理
    preProcess(s1);
    preProcess(s2);
    if(isEqual(s1,s2))
    {
        cout<<"0";
        return 0;
    }

    //比较大小
    int com = compare(s1,s2);

    //错位相减
    if(com==-1)my_swap(s1,s2);
    sub(s1,s2);

    //去前导零
    preProcess(s1);

    //输出
    if(com==-1) cout<<"-";
    cout<<s1;
    return 0;
}
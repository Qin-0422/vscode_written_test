#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isOdd(int a)
{
    if(a%2==1)return true;
    return false;
}

//从小到大排序
void my_sort(int& x,int& y,int& z)
{
    if(y > z) swap(y,z);
    if(x > z) swap(x,y);
    if(y > z) swap(y,z);
}

int main()
{
    int x,y,z;
    cin>>x>>y>>z;

    my_sort(x,y,z);

    int result = 0;

    //记录初始三个数的奇偶情况
    int odd = 0;
    if(isOdd(x)) odd++;
    if(isOdd(y)) odd++;
    if(isOdd(z)) odd++;
    //第一种情况：三个数都是偶数
    if(odd==0)
    {
        result  = z-x;
    }
    //第二种：一奇俩偶
    else if(odd==1)
    {
       if(isOdd(y))
       {
            result = z-x+1;
       }
       else 
       {
            result  = z-x;
       }
    }
    //第三种：俩奇一偶
    else if(odd==2)
    {
       if(!isOdd(y))
       {
            result = z-x+1;
       }
       else 
       {
            result  = z-x;
       }
    }
    //最后一种：三奇
    else {
        result = z-x;
    }
    cout<<result;
    return 0;
}
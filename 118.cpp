#include <iostream>
#include <vector>

using namespace std;

int getNotZero(int num)
{
    int result = 0;
    while (num>0)
    {
        if(num%10!=0)result++;
        num/=10;
    }
    return result;
}

int main()
{
    int  n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int result = 0;
    for(int i = 0;i<n;i++)
    {
        result += getNotZero(arr[i]);
    }
    cout<<result<<endl;
    return 0;
}
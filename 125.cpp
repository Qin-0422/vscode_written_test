// #include <bits/stdc++.h>
// using namespace std;

// bool cmp(const vector<int>&a,const vector<int>&b)
// {
//     return a[0]<b[0];
// }

// int main()
// {
//     int n,m,k;
//     cin>>n>>m>>k;
    
//     vector<vector<int>> range(m,vector<int>(2,0));
//     for(int i = 0;i<m;i++)
//     {
//         cin>>range[i][0]>>range[i][1];
//     }

//     sort(range.begin(),range.end(),cmp);

//     int result = 0;
//     int sum = 0;
//     for(int i = 0;i<m;i++)
//     {
//         int j = i;
//         while(j<m&&range[j][0]-range[i][0]<=k)
//         {
//             if(range[j][1]-range[i][0]<=k) sum += range[j][1]-range[j][0];
//             else sum += k - (range[j][0]-range[i][0]);
//             j++;
//         }
//         result = max(result,sum);
//         sum = 0;
//     }

//     cout<<result<<endl;
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,k,m;
void solve()
{
   cin >> n >> m >> k;
   vector<int> arr(n+1,0);
   for(int i=0;i<m;++i)
   {
        int l,r;
        cin >> l >> r;
        arr[l]++,arr[r]--;
   }
   for(int i=1;i<n;++i) 
   arr[i] += arr[i-1];
   int left = 0,right = k-1;
   int cnt[2] = {0};
   for(int i=0;i<k;++i)
   {
     cnt[arr[i]]++; 
   }
   int ans = cnt[1];
   while(right<n-1){
        ++left,++right;
        cnt[arr[left-1]]--,cnt[arr[right]]++;
        ans = max(ans,cnt[1]);  
   }
   cout << ans <<endl;
}
int main()
{
    cin.tie(0)->sync_with_stdio(false);
    solve();
    return 0;
}
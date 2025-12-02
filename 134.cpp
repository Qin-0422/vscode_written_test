#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<char> curSymptom(n);
    for(int i = 0;i<n;i++)
    {
        cin>>curSymptom[i];
    }

    int m;
    cin>>m;
    vector<vector<char>> cure(m,vector<char>(n));
    vector<vector<char>> hurt(m,vector<char>(n));
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            cin>>cure[i][j];
        }
        for(int j = 0;j<n;j++)
        {
            cin>>hurt[i][j];
        }
    }
    int q;
    cin>>q;
    for(int i = 0;i<q;i++)
    {
        int target;
        cin>>target;
        int symptomNums = 0;
                  
        for(int j = 0;j<n;j++)
        {
            if(cure[target-1][j]=='1' && curSymptom[j]=='1')
            {
                curSymptom[j] = '0';
            }
            if(hurt[target-1][j]=='1'  && curSymptom[j]=='0')
            {
                curSymptom[j] = '1';
            }
            if(curSymptom[j]=='1') symptomNums++; 
        }               
        cout<<symptomNums<<endl;
    }
    return 0;
}
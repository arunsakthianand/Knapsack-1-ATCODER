#include <bits/stdc++.h>
using namespace std;
vector<long long int> dp;
vector<long long int> w,v;

void disp(vector<long long>v){
    cout<<"The array is: ";
    for(auto el:v) cout<<el<<" ";
    cout<<"\n";
}

long long int func(long long int WW,long long int NN)
{
    if (dp[NN-1] == -1)
    {
        if (NN == 0)
        {
            return 0;
        }
        else if (NN == 1)
        {
            if (WW<w[0])
            {
                dp[0] = 0;
            }
            else
            {
                dp[0] = v[0];
            }
            return dp[0];
        }
        else
        {
            if (WW-w[NN-1] > 0)
            {
                dp[NN-1] = max( func(WW-w[NN-1],NN-1) + v[NN-1] , func(WW,NN-1) );
            }
            else
            {
                dp[NN-1] = func(WW,NN-1);
            }
            return dp[NN-1];
        }
    }
    else
    {
        return dp[NN-1];
    }
    
}

int main()
{
    long long int N,W;

    cin>>N;
    cin>>W;
    for (int i = 0; i < N; i++)
    {
        long long int temp;
        cin>>temp;
        w.push_back(temp);
        cin>>temp;
        v.push_back(temp);
    }

    for (int i = 0; i < N; i++)
    {
        dp.push_back(-1);
    }
    
    cout<<func(W,N);
    return 0;
}
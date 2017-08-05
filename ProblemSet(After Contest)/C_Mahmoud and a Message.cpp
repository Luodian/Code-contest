//
//  main.cpp
//  debugger
//
//  Created by 李博 on 10/02/2017.
//  Copyright © 2017 李博. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
#include <numeric>
#include <set>
#include <list>
#include <map>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
#define lower_bound LB
#define upper_bound UB
#define mem(a,x) memset(a,x,sizeof(a))
#define IT iterator
#define test puts("OK")
#define lowbit(x) x & -x
#define PRQ priority_queue
#define PB push_back
#define gcd(a,b) _gcd(a,b)

const double PI = acos(-1.0);
const double eps = 1e-8;
const long long MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int maxn = 1005;

string seg;
int limit[30];
int f[maxn];
int MinimumSeg[maxn];
int MaxLen;

bool satisfy(int st,int ed)
{
    if (st == ed)
    {
        return 1;
    }
    else
    {
        for (int i = st; i <= ed; ++i)
        {
            if (limit[seg[i] - 'a' + 1] < (ed - st + 1))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    while(cin>>n)
    {
        seg.clear();
        mem(f,0);
        MaxLen = 0;
        MinimumSeg[0] = 1;
        cin>>seg;
        for (int i = 1; i <= 26; ++i)
        {
            cin>>limit[i];
        }
        f[0] = 1;
        if (seg.size() == 1)
        {
            MaxLen = 1;
        }
        else
        {
            for (int i = 1; i < seg.size(); ++i)
            {
                MinimumSeg[i] = INF;
                if (satisfy(0,i))
                {
                    f[i] ++;
                    MinimumSeg[i] = 1;
                    MaxLen = i + 1;
                }
                for (int j = 1; j <= i; ++j)
                {
                    if (satisfy(i-j+1,i))
                    {
                        f[i] = (f[i] + f[i-j]) % MOD;
                        MinimumSeg[i] = min(MinimumSeg[i-j] + 1,MinimumSeg[i]);
                        MaxLen = max(MaxLen,j);
                    }
                }
            }
        }
        cout<<f[n-1]<<"\n";
        cout<<MaxLen<<"\n";
        cout<<MinimumSeg[n-1]<<"\n";
    }
}

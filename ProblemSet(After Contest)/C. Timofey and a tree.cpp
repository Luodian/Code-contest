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
const int INF = 0x3f3f3f3f;
const int maxn = 100005;
vector<int> G[maxn];
int n;
int color[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n)
    {
        int Od[maxn];
        bool flag = 0;
        int cnt = 0;
        for (int i = 0 ; i < maxn; ++i)
        {
            G[i].clear();
        }
        mem(color,0);
        mem(Od,0);
        for (int i = 1; i <= n - 1; ++i)
        {
            int u,v;
            cin>>u>>v;
            G[u].PB(v);
            G[v].PB(u);
        }
        for (int i = 1; i <= n; ++i)
        {
            cin>>color[i];
            if (i != 1)
            {
                if (color[i] != color[i-1])
                {
                    flag = 1;
                }
            }
        }
        if (flag == 0)
        {
            cout<<"YES\n";
            cout<<"1\n";
        }
        else
        {
            for (int i = 1;i <= n; ++i)
            {
                for (int j = 0; j < G[i].size(); ++j)
                {
                    if (color[i] != color[G[i][j]])
                    {
                        Od[i] ++;
                        Od[G[i][j]] ++;
                        cnt ++;
                    }
                }
            }
            // for (int i = 1; i <= n; ++i)
            // {
            // 	cout<<Outdgree[i]<<" ";
            // }
            // cout<<cnt<<"\n";
            bool AnsExist = 0;
            for (int i = 1; i <= n; ++i)
            {
                if (Od[i] == cnt)
                {
                    cout<<"YES\n"<<i<<"\n";
                    AnsExist = 1;
                    break;
                }
            }
            if (AnsExist == 0)
            {
                cout<<"NO\n";
            }
        }
    }
    
}

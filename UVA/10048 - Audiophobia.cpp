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
#include <unordered_set>
#include <numeric>
#include <set>
#include <list>
#include <map>

using namespace std;
#define lower_bound LB
#define upper_bound UB
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define IT iterator
#define test puts("OK")
#define lowbit(x) x & -x
#define PRQ priority_queue
#define PB push_back
#define gcd(a,b) _gcd(a,b)


typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const LL mod=1000000007;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int g[maxn][maxn];
int C,S,Q;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int k = 1;
    while(cin>>C>>S>>Q && (C+S+Q))
    {
        for (int i = 0; i <= C; ++i)
        {
            for (int j = 0; j <= C; ++j)
            {
                g[i][j] = INF;
            }
        }
        
        vector<pair<int,int>> Queries;
        Queries.clear();

        for (int i = 0; i < S; ++i)
        {
            int u,v;
            int decibels;
            cin>>u>>v>>decibels;
            g[u][v] = g[v][u] = decibels;
        }
        
        for (int i = 0; i < Q; ++i)
        {
            pair<int,int> foo;
            int u,v;
            cin>>u>>v;
            foo = make_pair(u,v);
            Queries.PB(foo);
        }
        
        for (int k = 1; k <= C; ++k)
        {
            for (int i = 1;i <= C; ++i)
            {
                for (int j = 1; j <= C; ++j)
                {
                    if (max(g[i][k],g[k][j]) < g[i][j] && (g[i][k] != INF && g[k][j] != INF))
                    {
                        g[i][j] = max(g[i][k],g[k][j]);
                    }
                }
            }
        }

        if (k != 1)
        {
            cout<<'\n';
        }
        cout<<"Case #"<<k++<<endl;
        for (int i = 0; i < Q; ++i)
        {
            pair<int,int> foo = Queries[i];
            int u = foo.first;
            int v = foo.second;
            if (g[u][v] == INF)
            {
                cout<<"no path\n";
            }
            else
            {
                cout<<g[u][v]<<"\n";
            }
        }
    }

    return 0;
}
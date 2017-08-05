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
const int maxn = 10 + 5;

int n,T;
vector<int> tree[maxn];
vector<int> G[maxn];
bool vis[maxn];
int f[maxn][3];

//dfs将图转换成有根树
void dfs(int u)
{
    if (vis[u] == 1)
    {
        return;
    }
    else
    {
        vis[u] = 1;
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i];
            if (vis[v] == 0)
            {
                tree[u].PB(v);
                dfs(v);
            }
        }
    }
}



void init()
{
    mem(f,0);
    mem(vis,0);
    for (int i = 0 ; i < maxn; ++i)
    {
        tree[i].clear();
    }
    for (int i = 0; i < maxn; ++i)
    {
        G[i].clear();
    }
}

void dfs2(int u)
{
    f[u][0] = 1;
    f[u][1] = 0;
    f[u][2] = n;
    vis[u] = 1;
    for (int i = 0; i < tree[u].size(); ++i)
    {
        int v = tree[u][i];
        if (!vis[v])
        {
            dfs2(v);
            f[u][0] += min(f[v][1],f[v][0]);
            f[u][1] += f[v][2];
        }
    }
    for (int i = 0; i < tree[u].size(); ++i)
    {
        int v = tree[u][i];
        f[u][2] = min(f[u][2],f[u][1] - f[v][2] + f[v][0]);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(n != -1)
    {
        cin>>n;
        init();
        for (int i = 1; i <= n - 1; ++i)
        {
            int u,v;
            cin>>u>>v;
            G[u].PB(v);
            G[v].PB(u);
        }
        mem(vis,0);
        dfs(1);
        mem(vis,0);
        dfs2(1);
        int ans = min(f[1][0],f[1][2]);
        cout<<ans<<"\n";
        cin>>n;
    }
    
}

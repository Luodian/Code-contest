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
const int maxn = 150000 + 5;
int n,m;
vector<int> G[maxn];
bool vis[maxn];
bool circle;
int cnt;

void dfs(int cur,int fa,int start)
{
    if (vis[cur] == 1)
    {
        return;
    }
    vis[cur] = 1;
    for (int i = 0; i < G[cur].size(); ++i)
    {
        int next = G[cur][i];
        if (next != fa && next == start)
        {
            circle = 1;
            return;
        }
        else if (vis[next] == 0)
        {  
            cnt = cnt + 1;
            dfs(next,cur,start);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>n>>m)
    {
        for (int i = 0; i <= n; ++i)
        {
            G[i].clear();
        }
        for (int i = 0; i < m; ++i)
        {
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        circle = 0;
        bool flag = 1;
        for (int i = 1;i <= n; ++i)
        {
            mem(vis,0);
            circle = 0;
            cnt = 1;
            dfs(i,0,i);
            if (circle == 0 && cnt > 2)
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
    
}

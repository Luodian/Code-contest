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
const int maxn = 1050;
int n,m;
int graph[maxn][maxn];

bool vis[maxn];
int dist[maxn];

int djikstra()
{
    priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > Q;
    while(!Q.empty())
    {
        Q.pop();
    }
    for (int i = 2;i <= n; ++i)
    {
        dist[i] = INF;
    }
    dist[1] = 0;
    Q.push(make_pair(0,1));
    while(!Q.empty())
    {
        pair<int,int> bar = Q.top();
        Q.pop();
        int cur = bar.second;
        if (vis[cur] == 1)
        {
            continue;
        }
        vis[cur] = 1;
        int cur_dist = bar.first;
        for (int i = 1; i <= n; ++i)
        {
            if (graph[cur][i] != 0 && dist[i] > cur_dist + graph[cur][i])
            {
                dist[i] = cur_dist + graph[cur][i];
                Q.push(make_pair(dist[i],i));
            }
        }
    }
    return dist[n];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>m>>n)
    {
        mem(dist,0);
        mem(graph,INF);
        mem(vis,0);
        for (int i = 0; i < m; ++i)
        {
            int u,v,w;
            cin>>u>>v>>w;
            if (w < graph[u][v])
            {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }
        cout<<djikstra()<<endl;
    }
    return 0;
}
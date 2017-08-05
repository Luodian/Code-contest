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
const int maxn = 105;
string Info[maxn];
int n,m;
int st,ed;
struct edge
{
    int u,v,w;
    edge(int _u,int _v,int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<edge> G[maxn];
bool vis[maxn];
int dist[maxn];

void init()
{
    for (int i = 0; i < maxn; ++i)
    {
        G[i].clear();
        Info[i].clear();
    }
    mem(vis,0);
    mem(dist,INF);
}

int djikstra(int s)
{
    PRQ<pii,vector<pii>,greater<pii>> Q;
    dist[s] = 0;
    vis[s] = 1;
    Q.push(pii(dist[s],s));
    while(!Q.empty())
    {
        pii curType = Q.top();
        Q.pop();
        int curPos = curType.second;
        if (vis[curPos] == 1)
        {
            continue;
        }
        vis[curPos] = 1;
        for (int i = 0; i < G[curPos].size(); ++i)
        {
            edge nextEdge = G[curPos][i];
            if (dist[nextEdge.v] > dist[curPos] + nextEdge.w)
            {
                dist[nextEdge.v] = dist[curPos] + nextEdge.w;
                Q.push(pii(dist[nextEdge.v],nextEdge.v));
            }

        }
    }
    return dist[ed];
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
        init();
        for (int i = 1; i <= n; ++i)
        {
            cin>>Info[i];
            for (int j = 0; j < Info[i].size(); ++j)
            {
                if (Info[i][j] >= 'A' && Info[i][j] <= 'Z')
                {
                    Info[i][j] = Info[i][j] - 'A' + 'a';
                }
            }
        }
        for (int i = 0; i < m; ++i)
        {
            int u,v,w;
            cin>>u>>v;
            string uInfo = Info[u];
            string vInfo = Info[v];
            set<char> uSet,vSet;
            for (int j = 0; j < uInfo.size(); ++j)
            {
                uSet.insert(uInfo[j]);
            }
            for (int j = 0; j < vInfo.size(); ++j)
            {
                vSet.insert(vInfo[j]);
            }
            w = 0;
            for (auto uitr:uSet)
            {
                for (auto vitr:vSet)
                {
                    if (uitr == vitr)
                    {
                        w ++;
                    }
                }
            }
            G[u].push_back(edge(u,v,w));
            G[v].push_back(edge(v,u,w));
        }
        cin>>st>>ed;
        cout<<djikstra(st)<<"\n";
    }
    return 0;
}
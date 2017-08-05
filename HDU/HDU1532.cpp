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

const int maxn = 205;
int n,m,s,t;
int a[maxn];
int path[maxn];

struct edge
{
    int u;
    int v;
    int flow;
    int capacity;
    edge(int _u,int _v,int _flow,int _capacity)
    {
        u = _u;
        v = _v;
        flow = _flow;
        capacity = _capacity;
    }
};

vector<int> G[maxn];
vector<edge> Edge_set;

void init()
{
    for (int i = 0; i < maxn; ++i)
    {
        G[i].clear();
    }
    Edge_set.clear();
    mem(a,0);
    mem(path,0);
}

void add_edge(int u,int v,int capacity)
{
    Edge_set.push_back(edge(u,v,0,capacity));
    Edge_set.push_back(edge(v,u,0,0));
    int m = Edge_set.size();
    G[u].push_back(m - 2);
    G[v].push_back(m - 1);
}

int max_flow(int s,int t)
{
    queue<int> Q;
    int flow = 0;
    while(true)
    {
        mem(a,0);
        while(!Q.empty())
        {
            Q.pop();
        }
        Q.push(s);
        a[s] = INF;
        while (!Q.empty())
        {
            int cur = Q.front();
            Q.pop();
            for (int i = 0; i < G[cur].size(); ++i)
            {
                edge &e = Edge_set[G[cur][i]];
                int next_v = e.v;
                if (a[next_v] != 0 && e.capacity > e.flow)
                {
                    a[next_v] = min(a[cur], e.capacity - e.flow);
                    path[next_v] = G[cur][i];
                    Q.push(next_v);
                }
            }
            if (a[t])
            {
                break;
            }
        }
        if (!a[t])
        {
            break;
        }
        for (int u = t; u != s; u = Edge_set[path[u]].u)
        {
            Edge_set[path[u]].flow += a[t];
            Edge_set[(path[u] ^ 1)].flow -= a[t];
        }
        flow += a[t];
    }
    return flow;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    while(cin>>m>>n)
    {
        init();
        for (int i = 0; i < m; ++i)
        {
            int u,v,capacity;
            cin>>u>>v>>capacity;
            add_edge(u,v,capacity);
        }
        cout<<max_flow(1,n)<<endl;
    }
    return 0;
}
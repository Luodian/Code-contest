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
const int maxn = 1005;
int t;
int n,q;

struct coordinate
{
    int x,y;
    coordinate(int Input_x = 0,int Input_y = 0)
    {
        x = Input_x;
        y = Input_y;
    }
}nodes[maxn];

struct edge
{
    int u,v,w;
    edge(int &Input_u,int &Input_v,int &Input_w)
    {
        u = Input_u;
        v = Input_v;
        w = Input_w;
    }
    bool operator < (const edge &rhs) const
    {
        return w < rhs.w;
    }
};

int pre[maxn];
int cost[10];
vector<int> pack[10];
vector<edge> Edges;

void init()
{
    for (int i = 1; i < maxn; ++i)
    {
        pre[i] = i;
    }
    mem(cost,0);
    mem(nodes,0);
    for (int i = 0; i < 10; ++i)
    {
        pack[i].clear();
    }
    Edges.clear();
}

int find(const int &x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>t;
    while(t--)
    {
        init();
        cin>>n>>q;
        for (int i = 1; i <= q; ++i)
        {
            int temp;
            cin>>temp;
            cin>>cost[i];
            for (int j = 1; j <= temp; ++j)
            {
                int another_temp;
                cin>>another_temp;
                pack[i].PB(another_temp);
            }
        }
        for (int i = 1; i <= n; ++i)
        {
            int x,y;
            cin>>x>>y;
            coordinate a(x,y);
            nodes[i] = a;
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                int distance = pow(nodes[i].x - nodes[j].x,2) + pow(nodes[i].y - nodes[j].y,2);
                Edges.PB(edge(i,j,distance));
            }
        }
        sort(Edges.begin(),Edges.end());
        int ans = 0;
        int cnt = 0;
        vector<edge> need;
        for (int i = 0; i < Edges.size(); ++i)
        {
            int u = Edges[i].u;
            int v = Edges[i].v;
            int fu = find(u);
            int fv = find(v);
            if (fu != fv)
            {
                pre[fu] = fv;
                ans += Edges[i].w;
                need.PB(Edges[i]);
                cnt ++;
            }
            if (cnt == n - 1)
            {
                break;
            }
        }
        int Alter_Cost = 0;
        int Pack_Count = 0;
        for (int subset = 0; subset < (1 << q); subset ++)
        {
            for (int i = 1; i <= n; ++i)
            {
                pre[i] = i;
            }
            Alter_Cost = 0;
            Pack_Count = 0;
            for (int i = 0; i < q; ++i)
            {
                if (subset & (1 << i))
                {
                    Alter_Cost += cost[i+1];
                    for (int j = 1;  j < pack[i+1].size(); j ++)
                    {
                        int u = pack[i+1][j];
                        int v = pack[i+1][0];
                        int fu = find(u);
                        int fv = find(v);
                        if (fu != fv)
                        {
                            pre[fu] = fv;
                            Pack_Count ++;
                        }
                    }
                }
            }
            int Rest_Vertice = n - Pack_Count;
            int Rest_Count = 0;
            for (int i = 0; i < need.size(); ++i)
            {
                int u = need[i].u;
                int v = need[i].v;
                int fu = find(u);
                int fv = find(v);
                if (fu != fv)
                {
                    pre[fu] = fv;
                    Rest_Count ++;
                    Alter_Cost += need[i].w;
                }
                if (Rest_Count == Rest_Vertice)
                {
                    break;
                }
            }
            ans = min(ans,Alter_Cost);
        }
        cout<<ans<<"\n";
        if (t != 0)
        {
            cout<<"\n";
        }
    }
    return 0;
}

// q = 3
// {a,b,c}
// 
// 1 << 3 = 8
// subset:1,2,3,4,5,6,7
// j:0,1,2
// 1 << 0 = 1 : 001
// 1 << 1 = 2 : 010
// 1 << 2 = 4 : 100

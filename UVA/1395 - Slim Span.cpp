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
const int maxe = maxn * maxn / 2;
struct node
{
    int u,v,w;
}edges[maxe];
int pre[maxn];
int n,m;

int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

void init()
{
    for (int i = 1; i < maxn; ++i)
    {
        pre[i] = i;
    }
}

bool operator < (const node &x,const node &y)
{
    return x.w < y.w;
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m && n + m)
    {
        int u,v,w;
        init();
        for (int i = 1; i <= m; ++i)
        {
            cin>>u>>v>>w;
            edges[i].u = u;
            edges[i].v = v;
            edges[i].w = w;
        }
        if (m < (n - 1))
        {
            cout<<-1<<"\n";
            continue;
        }
        int ans = INF;
        int cnt = 0;
        sort(edges+1,edges+m+1);
        for (int L = 1; L + (n - 2) <= m; ++L)
        {
            cnt = 0;
            init();
            int R = L;
            for (int i = L; i <= m; ++i)
            {
                int x = edges[i].u;
                int y = edges[i].v;
                int fx = find(x);
                int fy = find(y);
                R++;
                if (fx != fy)
                {   
                    cnt++;
                    pre[fx] = fy;
                }
                if (cnt == n - 1)
                {
                    ans = min(ans,edges[R-1].w - edges[L].w);
                    break;
                }
            }
        }
        if (ans != INF)
        {
            cout<<ans<<"\n";
        }
        else
        {
            cout<<-1<<"\n";
        }
    }
    return 0;
}

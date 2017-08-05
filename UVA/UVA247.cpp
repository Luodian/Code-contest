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

const LL mod = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 30;
map<string,int> infoTable;
map<int,string> reverseTable;
int n,m;
int G[maxn][maxn];
vector<int> f[maxn];
int vis[maxn];
int ansCnt;
vector<int> ans[maxn];

void dfs(int u)
{
    if (!vis[u])
    {
        vis[u] = 1;
        ans[ansCnt].push_back(u);
        rep(i,0,f[u].size())
        {
            int v = f[u][i];
            dfs(v);
        }
    }
    
}

void init()
{
    infoTable.clear();
    reverseTable.clear();
    mem(G,0);
    mem(vis,0);
    ansCnt = 0;
    rep(i,0,maxn)
    {
        ans[i].clear();
        f[i].clear();
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
    int T = 0;
    while(cin>>n>>m &&  (n + m))
    {
        T ++;
        if (T != 1)
        {
            cout<<"\nCalling circles for data set "<<T<<":\n";
        }
        else
        {
            cout<<"Calling circles for data set "<<T<<":\n";
        }
        int du,dv;
        int curID = 0;
        init();
        string u,v;
        rep(i,0,m)
        {
            cin>>u>>v;
            if (infoTable.find(u) == infoTable.end())
            {
                infoTable[u] = curID ++;
                du = infoTable[u];
            }
            else
            {
                du = infoTable[u];
            }
            if (infoTable.find(v) == infoTable.end())
            {
                infoTable[v] = curID ++;
                dv = infoTable[v];
            }
            else
            {
                dv = infoTable[v];
            }
            G[du][dv] = 1;
            reverseTable[du] = u;
            reverseTable[dv] = v;
        }
        rep(k,0,n)
        {
            rep(i,0,n)
            {
                rep(j,0,n)
                {
                    if ((G[i][k] && G[k][j]) || (G[i][j] == 1))
                    {
                        G[i][j] = 1;
                    }
                }
            }
        }
        rep(i,0,n)
        {
            rep(j,i + 1,n)
            {
                if (G[i][j] && G[j][i])
                {
                    f[i].PB(j);
                }
            }
        }
        
        rep(i,0,n)
        {
            dfs(i);
            if (ans[i].size() != 0)
            {
                ansCnt ++;
            }
        }
        rep(i,0,ansCnt + 1)
        {
            rep(j,0,ans[i].size())
            {
                if (j != ans[i].size() - 1)
                {
                    cout<<reverseTable[ans[i][j]]<<", ";
                }
                else
                {
                    cout<<reverseTable[ans[i][j]]<<"\n";
                }
            }
        }
    }
    return 0;
}
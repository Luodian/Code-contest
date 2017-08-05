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
int color[maxn];
int vis[maxn];
set<int> color_count;
int n;
void dfs(int u,int side_color)
{
    if (vis[u] == 1)
    {
        return ;
    }
    else
    {
        vis[u] = 1;
        color_count.insert(color[u]);
        for (int i = 0; i < G[u].size(); ++i)
        {
            int v = G[u][i];
            if (!vis[v])
            {
                color_count.insert(color[v]);
                dfs(v,side_color);
            }
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
    while(cin>>n)
    {
        for (int i = 0; i < maxn; ++i)
        {
            G[i].clear();
        }
        mem(color,0);
        bool isSimple = 1;
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
                    isSimple = 0;
                }
            }
        }
        if (isSimple == 1)
        {
            cout<<"YES\n1\n";
        }
        else
        {
            bool find_root = 0;
            int root1,root2;
            for (int i = 1; i <= n; ++i)
            {
                for (int j = 0; j < G[i].size(); ++j)
                {
                    if (color[i] != color[G[i][j]])
                    {
                        root1 = i;
                        root2 = G[i][j];
                        find_root = 1;
                        break;
                    }
                }
                if (find_root == 1)
                {
                    break;
                }
            }
            int Current_Color;
            int ans_exist = 0;
            mem(vis,0);
            for (int i = 0; i < G[root1].size(); ++i)
            {
                int v = G[root1][i];
                Current_Color = color[v];
                vis[root1] = 1;
                color_count.clear();
                dfs(v,Current_Color);
                if (color_count.size() != 1)
                {
                    ans_exist = 0;
                    break;
                }
                ans_exist = 1;
            }
            if (ans_exist == 1)
            {
                cout<<"YES\n";
                cout<<root1<<"\n";
                continue;
            }
            mem(vis,0);
            for (int i = 0; i < G[root2].size(); ++i)
            {
                int v = G[root2][i];
                Current_Color = color[v];
                vis[root2] = 1;
                color_count.clear();
                dfs(v,Current_Color);
                if (color_count.size() != 1)
                {
                    ans_exist = 0;
                    break;
                }
                ans_exist = 2;
            }
            if (ans_exist == 2)
            {
                cout<<"YES\n";
                cout<<root2<<"\n";
                continue;
            }
            if (ans_exist == 0)
            {
                cout<<"NO\n";
            }
        }
    }
}


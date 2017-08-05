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
const int maxn = 10;
int n,m;
bool vis[maxn];
bool G[maxn][maxn];
int ans;

void dfs(int cur_row,int step)
{
    if (step == m)
    {
        ans ++;
        return;
    }
    for (int i = cur_row; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if(vis[j] == 0 && G[i][j] == 1)
            {
                vis[j] = 1;
                dfs(i + 1,step + 1);
                vis[j] = 0;
                //注意状态枚举的还原
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
    cout.tie(NULL);
    while(cin>>n>>m && n != -1 && m != -1)
    {
        ans = 0;
        mem(vis,0);
        mem(G,0);
        for (int i = 1;i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                char ch;
                cin>>ch;
                if (ch  == '#')
                {
                    G[i][j] = 1;
                }
                else
                {
                    G[i][j] = 0;
                }
            }
        }
        dfs(1,0);
        cout<<ans<<"\n";
    }
    return 0;
}
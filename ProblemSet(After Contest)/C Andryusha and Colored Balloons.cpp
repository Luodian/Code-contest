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
const int maxn = 2e5+5;
vector<int> Tree[maxn];

int n;
bool vised[maxn];
int colors[maxn];

int maxDegree;

void dfs(int x,int father)
{
    if (vised[x] == 1)
    {
        return;
    }
    vised[x] = 1;
    int j = 1;
    for (int i = 0; i < Tree[x].size(); ++i)
    {
        int y = Tree[x][i];
        if (vised[y] == 0)
        {
            while(j <= maxDegree+1 && (colors[x] == j || colors[father] == j))
            {
                j ++;
            }
            colors[y] = j++;
        }
    }
    
    for (int i = 0; i < Tree[x].size(); ++i)
    {
        int y = Tree[x][i];
        if (vised[y] == 0)
        {
            dfs(y,x);
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
    while(cin>>n)
    {
        mem(colors,0);
        mem(vised,0);
        for (int i = 0; i <= n; ++i)
        {
            Tree[i].clear();
        }
        for (int i = 0; i < n - 1; ++i)
        {
            int u,v;
            cin>>u>>v;
            Tree[u].push_back(v);
            Tree[v].push_back(u);
        }
        maxDegree = -INF;
        for (int i = 1; i <= n; ++i)
        {
            maxDegree = max(maxDegree,(int)Tree[i].size());
        }
        colors[1] = 1;
        dfs(1,0);
        cout<<maxDegree+1<<"\n";
        for (int i = 1;i <= n; ++i)
        {
            if (i != n)
            {
                cout<<colors[i]<<" ";
            }
            else
            {
                cout<<colors[i]<<"\n";
            }
        }

    }

}

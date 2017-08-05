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
const int maxn = 205;
int n,k;
map<string,int> SetId;
vector<int> tree[maxn];
int f[maxn][2];
bool uni[maxn][2];

void init()
{
    SetId.clear();
    for (int i = 0; i < maxn; ++i)
    {
        tree[i].clear();
    }
    mem(f,0);
    mem(uni,0);
}

void AddID(const string &info)
{
    if (SetId.find(info) == SetId.end())
    {
        SetId[info] = k++;
    }
}

int dp(int u,int choice)
{
    f[u][choice] = choice;
    uni[u][choice] = 1; //default it's unique;
    for (int i = 0; i < tree[u].size(); ++i)
    {
        int v = tree[u][i];
        if (choice == 1)
        {
            f[u][1] += dp(v,0);
            if (uni[v][0] == 0)
            {
                uni[u][1] = 0;
            }
        }
        else
        {
            f[u][0] += max(dp(v,0),dp(v,1));
            if (f[v][1] == f[v][0])
            {
                uni[u][0] = 0;
            }
            else if (f[v][1] > f[v][0] && uni[v][1] == 0)
            {
                uni[u][0] = 0;
            }
            else if (f[v][0] > f[v][1] && uni[v][0] == 0)
            {
                uni[u][0] = 0;
            }
        }
    }
    return f[u][choice];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n && n)
    {
        init();
        string info;
        cin>>info;
        SetId[info] = 0;
        k = 1;
        for (int i = 1; i <= n - 1; ++i)
        {
            cin>>info;
            AddID(info);
            int employee = SetId[info];
            cin>>info;
            AddID(info);
            int boss = SetId[info];
            tree[boss].PB(employee);
        }
        bool unique = 0;
        int ans = max(dp(0,0),dp(0,1));
        if(f[0][0] > f[0][1] && uni[0][0] == 1)
        {
            unique = 1;
        }
        else if (f[0][1] > f[0][0] && uni[0][1] == 1)
        {
            unique = 1;
        }
        if (unique == 1)
        {
            cout<<ans<<" Yes\n";
        }
        else
        {
            cout<<ans<<" No\n";
        }
        
    }
    
}

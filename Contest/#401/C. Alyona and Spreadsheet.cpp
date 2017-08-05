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
int row_min[maxn];
int ascend[maxn][2];
vector<int> matrix[maxn];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    while(cin>>n>>m)
    {
        mem(row_min,0);
        mem(ascend,0);
        for (int i = 0; i <= n; ++i)
        {
            matrix[i].clear();
        }
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                int u;
                cin>>u;
                matrix[i].PB(u);
            }
        }
        for (int i = 2; i <= n; ++i)
        {
           row_min[i] = INF;
           for (int j = 0; j < m; ++j)
           {
                if (matrix[i][j] >= matrix[i-1][j])
                {
                    ascend[j][1] = ascend[j][0];
                }
                else
                {
                    ascend[j][1] = i;
                }
                row_min[i] = min(row_min[i],ascend[j][1]);
                ascend[j][0] = ascend[j][1];
           }
        }
        int k;
        cin>>k;
        for (int i = 1; i <= k; ++i)
        {
            int l,r;
            cin>>l>>r;
            if (l == r)
            {
                puts("Yes");
            }
            else if (row_min[r] <= l)
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
    }
}

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
int graph[15][105];
int dp[15][105];
int Next[15][105]; // use Next matrix to represent the Next row after (i,j);
int n,m;


void init()
{
    mem(graph,0);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dp[i][j] = INF;
        }
    }
    mem(Next,0);
}

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m)
    {
        init();
        for (int i = 1;i <= n; ++i)
        {
            for (int j = 1;j <= m; ++j)
            {
                cin>>graph[i][j];
            }
        }
        int ans = INF;
        int first = 0;
        for (int j = m; j >= 1; --j)
        {
            for (int i = 1;i <= n; ++i)
            {
                if (j == m)
                {
                    dp[i][j] = graph[i][j];
                }
                else
                {
                    int rows[] = {0,i,i-1,i+1};
                    if (i == 1)
                    {
                        rows[2] = n;
                    }
                    if (i == n)
                    {
                        rows[3] = 1;
                    }
                    sort(rows+1,rows+4);
                    for (int k = 1; k <= 3; ++k)
                    {
                        int temp = dp[rows[k]][j+1] + graph[i][j];
                        if (temp < dp[i][j])
                        {
                            dp[i][j] = temp;
                            Next[i][j] = rows[k];
                        }
                    }
                }
                if (j == 1)
                {
                    if (dp[i][j] < ans)
                    {
                        ans = dp[i][j];
                        first = i;
                    }
                }
            }
        }
        cout<<first<<" ";
        int i,j;
        for (j = 1, i = Next[first][j]; j < m - 1; ++j, i = Next[i][j])
        {
            cout<<i<<" ";
        }
        cout<<Next[i][m-1]<<"\n";
        cout<<ans<<"\n";
    }
    
}

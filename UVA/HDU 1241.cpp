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
const int maxn = 105;
int direction[8][2] = {{1,1},{1,0},{0,1},{1,-1},{-1,1},{-1,-1},{0,-1},{-1,0}};
int n,m;
bool G[105][105];
struct node
{
    int x;
    int y;
    node(int xx = 0,int yy = 0)
    {
        x = xx;
        y = yy;
    }
};

void bfs(int x,int y)
{
    node cur(x,y);
    queue<node> Q;
    Q.push(cur);
    while(!Q.empty())
    {
        node now = Q.front();
        int now_x = now.x;
        int now_y = now.y;
        G[now_x][now_y] = 0;
        Q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int next_x = now_x + direction[i][0];
            int next_y = now_y + direction[i][1];
            if (next_x <= n && next_x >= 1 && next_y <=  m && next_y >= 1 && G[next_x][next_y] == 1)
            {
                G[next_x][next_y] = 0;
                node next(next_x,next_y);
                Q.push(next);
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
    while(cin>>n>>m && (m + n))
    {
        mem(G,0);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                char signal;
                cin>>signal;
                if( signal == '@')
                {
                    G[i][j] = 1;
                }
                else
                {
                    G[i][j] = 0;
                }
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                if(G[i][j] == 1)
                {
                    cnt ++;
                    bfs(i,j);
                }
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}

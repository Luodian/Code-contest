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
const int direction[8][2] = {{-1,-2},{-2,-1},{-2,1},{1,-2},{2,-1},{1,2},{2,1},{-1,2}};
bool vis[20][20];

struct node
{
    int x;
    int y;
    int step;
    node(int xx,int yy,int ss)
    {
        x = xx;
        y = yy;
        step = ss;
    }
};

int bfs(int st_x,int st_y,int ed_x,int ed_y)
{
    queue<node> Q;
    while(!Q.empty())
    {
        Q.pop();
    }
    
    Q.push(node(st_x,st_y,0));
    vis[st_x][st_y] = 1;
    while(!Q.empty())
    {
        node cur = Q.front();
        if (cur.x == ed_x && cur.y == ed_y)
        {
            return cur.step;
        }
        Q.pop();
        for (int i = 0; i < 8; ++i)
        {
            int next_x = cur.x + direction[i][0];
            int next_y = cur.y + direction[i][1];
            if (next_x <= 8 && next_x >= 1 && next_y <= 8 && next_y >= 1 && vis[next_x][next_y] == 0)
            {
                vis[next_x][next_y] = 1;
                Q.push(node(next_x,next_y,cur.step + 1));
            }
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string st,ed;
    while(cin>>st>>ed)
    {
        mem(vis,0);
        int st_x = st[0] - 'a' + 1;
        int st_y = st[1] - '0';
        
        int ed_x = ed[0] - 'a' + 1;
        int ed_y = ed[1] - '0';
        int ans = bfs(st_x,st_y,ed_x,ed_y);
        cout<<"To get from "<<st<<" to "<<ed<<" takes "<<ans<<" knight moves.\n";
    }
    return 0;
}
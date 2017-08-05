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
int A[2][25];
int B[2][25];
int r,c;

struct Edge
{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f)
    {
        from = u;
        to = v;
        cap = c;
        flow = f;
    }
};

struct EdmondsKarp
{
    int n,m;
    vector<Edge> edges;
    vector<int> G[50];
    int a[50];
    int p[50];
    
    int ans_matrix[50][50];
    
    void init ()
    {
        rep(i,0,50)
        {
            G[i].clear();
        }
        edges.clear();
        mem(p,0);
    }
    
    void addEdge(int from,int to,int cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0)); //网络流必须建立反向弧
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    
    int Maxflow(int s,int t)
    {
        int flow = 0;
        while(1)
        {
            mem(a,0);
            queue<int> Q;
            while(!Q.empty())
            {
                Q.pop();
            }
            Q.push(s);
            a[s] = INF;
            while(!Q.empty())
            {
                int x = Q.front();
                Q.pop();
                rep(i,0,G[x].size())
                {
                    Edge &e = edges[G[x][i]];
                    if (!a[e.to] && e.cap > e.flow)
                    {
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x],e.cap - e.flow); //求全局最小可改进量。
                        Q.push(e.to);
                    }
                }
                if (a[t])
                {
                    break;
                }
            }
            if (!a[t])
            {
                break;
            }
            for (int u = t; u != s; u = edges[p[u]].from)
            {
                edges[p[u]].flow += a[t];
            }
            flow += a[t];
        }
        return flow;
    }
    
    void output_ans()
    {
        mem(ans_matrix,0);
        
        rep(i, 1, r + 1)
        {
            rep(j,1,G[i].size())
            {
                int yi = edges[G[i][j]].to;
                int ans = edges[G[i][j]].flow;
                
                ans_matrix[i][yi-r] = ans + 1;
            }
        }
        
        rep(i,1,r + 1)
        {
            rep(j,1,c + 1)
            {
                if (j != c)
                {
                    cout<<ans_matrix[i][j]<<" ";
                }
                else
                {
                    cout<<ans_matrix[i][j]<<endl;
                }
            }
        }
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin>>T;
    int senerio = 0;
    while(T--)
    {
        mem(A,0);
        mem(B,0);
        cin>>r>>c;
        rep(i,0,r)
        {
            cin>>A[0][i];
        }
        
        A[1][0] = A[0][0];
        rep(i,1,r)
        {
            A[1][i] = A[0][i] - A[0][i-1];
        }
        
        rep(i,0,c)
        {
            cin>>B[0][i];
        }
        
        B[1][0] = B[0][0];
        rep(i,1,c)
        {
            B[1][i] = B[0][i] - B[0][i-1];
        }
        
        int super_s = 0;
        int super_t = 45;
        
        EdmondsKarp solver;
        solver.n = r + c + 2;
        solver.init();
        
        //对超级源点建图
        rep(i,0,r)
        {
            A[1][i] -= (c);
            int xi = i + 1;
            solver.addEdge(super_s,xi,A[1][i]);
        }
        
        //对超级汇点建图
        rep(i,0,c)
        {
            B[1][i] -= (r);
            int yi = i + 1 + r;
            solver.addEdge(yi,super_t,B[1][i]);
        }
        
        rep(i,0,r)
        {
            rep(j,r,r + c)
            {
                int xi = i + 1;
                int yi = j + 1;
                solver.addEdge(xi,yi,19);
            }
        }
        cout<<"Matrix "<<++senerio<<endl;
        solver.Maxflow(super_s,super_t);
        solver.output_ans();
        if (T)
        {
            cout<<endl;
        }
    }
    return 0;
}

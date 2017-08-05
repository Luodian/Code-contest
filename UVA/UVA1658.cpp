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

const LL mod=1000000007;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;
const int maxn = 1005<<1;

int n,m;
int a[maxn];
int path[maxn];
bool inq[maxn];


struct edge
{
	int u,v,cost,capacity;
	int flow;
	edge(int _u, int _v, int _cost, int _flow,int _capacity)
	{
		u = _u;
		v = _v;
		cost = _cost;
		capacity = _capacity;
		flow = _flow;
	}
};

vector<int> G[maxn];
vector<edge> Edge_set;

void init(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		G[i].clear();
	}
	Edge_set.clear();
	mem(a,0);
	mem(path,0);
}

void add_edge(int u,int v,int capacity,int cost)
{
	Edge_set.push_back(edge(u,v,cost,0,capacity));
	Edge_set.push_back(edge(v,u,-cost,0,0));
	m = Edge_set.size();
	G[u].push_back(m-2);
	G[v].push_back(m-1);
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<int()<<endl;
	return 0;
}
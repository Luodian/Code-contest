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
const int INF = 1000000000;
const int maxn = 20;
vector<string> before;
vector<string> after;
vector<int> cost;
int dist[(1<<maxn) + 5];
int vis[(1<<maxn) + 5];
int n,m;

struct node
{
	int bugs;
	int dist;
	bool operator < (const node &rhs) const
	{
		return dist < rhs.dist;
	}
};

int dijikstra()
{
	for (int i = 0; i < ((1 << maxn) + 5); ++i)
	{
		dist[i] = INF;
		vis[i] = 0;
	}
	PRQ<node> Q;
	while(!Q.empty())
	{
		Q.pop();	
	}
	node u;
	u.bugs = (1 << n) - 1;
	u.dist = 0;
	Q.push(u);
	dist[u.bugs] = 0;
	while(!Q.empty())
	{
		node cur = Q.top();
		Q.pop();
		if (cur.bugs == 0)
		{
			return cur.dist;
		}
		if (vis[cur.bugs] == 1)
		{
			continue;
		}
		vis[cur.bugs] = 1;
		for (int i = 0; i < m; ++i)
		{
			bool patchable = 1;
			for (int j = 0; j < n; ++j)
			{	
				if (before[i][j] == '+' && !(cur.bugs & (1 << j)))
				{
				    // 第j位必须不存在bug，但是u.bugs第j位存在bug。
					patchable = 0;
					break;
				}
				if (before[i][j] == '-' && (cur.bugs & (1 << j)))
				{
			        // 第j位必须有bug，但是u.bugs第j位不存在bug
					patchable = 0;
					break;
				}
			}
			if (!patchable)
			{
				continue;
			}

			node next;
			next.dist = cur.dist + cost[i];
			next.bugs = cur.bugs;
			for (int j = 0; j < n; ++j)
			{
				if (after[i][j] == '-')
				{
					next.bugs &= ~(1 << j);
				}
				if (after[i][j] == '+')
				{
					next.bugs |= (1 << j);
				}
			}
			int& D = dist[next.bugs];
			if (D < 0 || next.dist < D)
			{
				//未被访问或者是下一个点更接近
				D = next.dist;
				Q.push(next);
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
	int kase = 1;
	while(cin>>n>>m && (n + m) != 0)
	{
		cost.clear();
		before.clear();
		after.clear();
		cost.resize(m);
		before.resize(m);
		after.resize(m);
		for (int i = 0; i < m; ++i)
		{
			cin>>cost[i]>>before[i]>>after[i];
		}
		int ans = dijikstra();
		cout<<"Product "<<kase++<<endl;
		if (ans < 0) 
		{
			cout<<"Bugs cannot be fixed.\n";
		}
		else
		{
			cout<<"Fastest sequence takes "<<ans<<" seconds.\n";
		}
		cout<<"\n";
	}
	return 0;
}

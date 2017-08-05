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
const int maxn = 1005;
int graph[maxn][maxn];
int dp[maxn][maxn];

void show(const int &R)
{
	for (int i = 1; i <= R; ++i)
	{
		for (int j = 1; j <= R; ++j)
		{
			cout<<dp[i][j];
		}
		cout<<"\n";
	}
}

int solve(const int &R)
{
	mem(graph,0);
	mem(dp,0);
	for(int i = 1; i <= R; ++i)
	{
		for (int j = 1;j <= i; ++j)
		{
			cin>>graph[i][j];
		}
	}

	for(int j = 1; j <= R; ++j)
	{
		dp[R][j] = graph[R][j];
	}
	for(int i = R - 1; i >= 1; --i)
	{
		for (int j = 1; j <= i; ++j)
		{
			dp[i][j] = graph[i][j] + max(dp[i+1][j],dp[i+1][j+1]);
		}
	}
	return dp[1][1];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int R;
	while(cin>>R)
	{
		int ans = solve(R);
		cout<<ans<<"\n";
	}
}

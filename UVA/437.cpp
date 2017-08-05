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
#include <tuple>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef tuple<int,int,int> cube;
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
const int maxn = 35;
bool graph[maxn * 3][maxn * 3];
int dp[maxn * 3];
vector<tuple<int,int,int>> Blocks;
int n;
bool check(cube i,cube j)
{
	int a,b,c;
	int x,y,z;
	tie(a,b,c) = i;
	tie(x,y,z) = j;
	if ((a < x && b < y) || (a < y && b < x))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void show(bool **graph,int &n)
{	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0;j < n; ++j)
		{
			cout<<*((bool *)graph + n * i + j);
		}
		cout<<"\n";
	}
}

int dfs(int i)
{
	if (dp[i] != -1) return dp[i];
	int ans;
	tie(ignore,ignore,ans) = Blocks[i];
	dp[i] = ans;
	for (int j = 0; j < n * 3; ++j)
	{
		if (graph[i][j] == 1)
		{
			int temp;
			tie(ignore,ignore,temp) = Blocks[j];
			dp[i] = max(dp[i],dfs(j) + ans);
		}
	}
	return dp[i];
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int kase = 1;
	while(cin>>n && n)
	{
		Blocks.clear();
		for(int i = 1; i <= n; ++i)
		{
			int a,b,c;
			cin>>a>>b>>c;
			auto bar = make_tuple(a,b,c);
			auto foo = make_tuple(a,c,b);
			auto che = make_tuple(b,c,a);
			Blocks.push_back(bar);
			Blocks.push_back(foo);
			Blocks.push_back(che);
		}
		mem(graph,0);
		for (int i = 0; i < Blocks.size(); ++i)
		{
			for (int j = i + 1; j < Blocks.size(); ++j) 
			{
				graph[i][j] = check(Blocks[i],Blocks[j]);
				graph[j][i] = check(Blocks[j],Blocks[i]);
			}
		}
		fill(dp,dp+n*3,-1);
		int ans = 0;
		for (int i = 0; i < n * 3; ++i)
		{
			ans = max(ans,dfs(i));
		}
		printf("Case %d: maximum height = %d\n", kase++, ans);
	}
}

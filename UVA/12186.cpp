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
int n,T;
vector<int> tree[maxn];

int dp(int u)
{
	if (tree[u].size() == 0)
	{
		return 1;
	}
	vector<int> d;
	for (int i = 0; i < tree[u].size(); ++i)
	{
		d.PB(dp(tree[u][i]));
	}
	sort(d.begin(),d.end());
	int k = tree[u].size();
	int limit = (k * T - 1) / 100 + 1;
	int ans = 0;
	for (int i = 0; i < limit; ++i)
	{
		ans += d[i];
	}
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n>>T && (n + T))
	{
		for(int i = 0; i < maxn; ++i)
		{
			tree[i].clear();
		}
		for (int i = 1; i <= n; ++i)
		{
			int b;
			cin>>b;
			tree[b].PB(i);
		}
		cout<<dp(0)<<"\n";

	}
}

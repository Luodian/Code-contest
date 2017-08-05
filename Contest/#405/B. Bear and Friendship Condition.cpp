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
const int maxn = 150000 + 5;
int n,m;
vector<int> Tree[maxn];
long long vCount[maxn];
int pre[maxn];

void init(int n)
{
	mem(vCount,0);
	for (int i = 0; i < n; ++i)
	{
		Tree[i].clear();
	}
	for (int i = 1; i <= n; ++i)
	{
		pre[i] = i;
	}
}

int find(int x)
{
	if (pre[x] == x)
	{
		return x;
	}
	else
	{
		//x的父亲更改成它的祖先，降低树高度
		pre[x] = find(pre[x]);
		return pre[x];
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
	while(cin>>n>>m)
	{
		init(n);
		for (int i = 0; i < m; ++i)
		{
			int u,v;
			cin>>u>>v;
			int fu = find(u);
			int fv = find(v);
			if (fu != fv)
			{
				pre[fu] = fv;
			}
		}
		long long _sum = 0;
		for (int i = 1; i <= n ;++i)
		{
			int fi = find(i);
			vCount[fi] ++;
		}
		for (int i = 1;i <= n; ++i)
		{
			long long vertices = vCount[i];
			//如果int * int在这一步会爆掉，那么_sum + 的结果也会出现问题。
			if (vertices != 0)
			{
				_sum += ((vertices * (vertices - 1)) / 2);
			}
		}
		if (m >= _sum)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
	return 0;
}

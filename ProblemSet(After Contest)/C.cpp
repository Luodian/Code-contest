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



bool meet(int n,int iter)
{
	int ret = 0;
	while(iter)
	{
		ret += (iter) % 10;
		iter /= 10; 
	}
	if (ret == n)
	{
		return 1;
	}
	else
	{
		return 0;
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
	int n;
	while(cin>>n)
	{
		vector<int> ans;
		ans.clear();
		for (int i = 0; i <= 9; ++i)
		{
			for (int j = 0; j <= 9; ++j)
			{
				for (int k = 0; k <= 9; ++k)
				{
					int palin = 10000 * i + 1000 * j + 100 * k + 10 * j + i;
					if (meet(n,palin) == 1)
					{
						ans.push_back(palin);
					}
				}
			}
		}
		for (int i = 0; i <= 9; ++i)
		{
			for (int j = 0; j <= 9; ++j)
			{
				for (int k = 0; k <= 9; ++k)
				{
					int palin = 100000 * i + 10000 * j + 1000 * k + 100 * k + 10 * j + i;
					if (meet(n,palin) == 1)
					{
						ans.push_back(palin);
					}
				}
			}
		}
		for (int i = 0; i < ans.size(); ++i)
		{
			cout<<ans[i]<<endl;
		}
		if (ans.size() == 0)
		{
			cout<<-1<<endl;
		}
	}
	return 0;
}
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
const int maxn = 105;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	vector<int> ans;
	while(cin>>n)
	{
		ans.clear();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int u;
				cin>>u;
				if (i == j)
				{
					ans.push_back(sqrt(u));
				}
			}
		}
		for (int i = 0; i < ans.size(); ++i)
		{
			if (i != ans.size() - 1)
			{
				cout<<ans[i]<<" ";
			}
			else
			{
				cout<<ans[i]<<"\n";
			}
		}
	}
	return 0;
}
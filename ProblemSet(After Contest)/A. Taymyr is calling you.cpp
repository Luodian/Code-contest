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
const int maxn = 10005;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	bool nCount[maxn];
	bool mCount[maxn];
	int n,m,z;
	while(cin>>n>>m>>z)
	{
		mem(nCount,0);
		mem(mCount,0);
		for (int i = n; i <= z; i += n)
		{
			nCount[i] = 1;
		}
		for (int i = m; i <= z; i += m)
		{
			mCount[i] = 1;
		}
		int count = 0;
		for (int i = 1; i <= z; ++i)
		{
			if (mCount[i] && nCount[i])
			{
				count ++;
			}
		}
		cout<<count<<"\n";
	}

}

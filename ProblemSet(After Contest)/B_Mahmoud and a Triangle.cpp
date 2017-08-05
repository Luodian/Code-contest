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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	vector<int> Seg;
	while(cin>>n)
	{
		Seg.clear();
		for (int i = 1; i <= n; ++i)
		{
			int temp;
			cin>>temp;
			Seg.push_back(temp);
		}
		sort(Seg.begin(),Seg.begin() + n);
		int flag = -1;
		for (int i = 0; i < n - 2; ++i)
		{
			if (Seg[i] + Seg[i+1] > Seg[i+2])
			{
				flag = 1;
				break;
			}
			else
			{
				flag = 0;
			}
		}
		if (flag == 1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}

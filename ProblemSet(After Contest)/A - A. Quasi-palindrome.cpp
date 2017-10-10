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

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/A.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string a;
	while(cin>>a)
	{
		bool flag = 0;
		for (int i = 0;i < a.size() / 2; ++i)
		{
			if (a[i] != a[a.size() - i - 1])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			puts("YES");
		}
		else
		{
			int cnt = 0;
			string pre;
			pre.clear();
			for (int i = a.size() - 1; i >= 0; --i)
			{
				if (a[i] == '0')
				{
					pre += '0';
					cnt ++;
				}
				else
				{
					break;
				}
			}
			a = pre + a;
			bool flag = 0;
			for (int i = 0;i < a.size() / 2; ++i)
			{
				if (a[i] != a[a.size() - i - 1])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				puts("YES");
			}
			else
			{
				puts("NO");
			}
		}
	}
	return 0;
}
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
const int maxn = 100000 + 10;

int prime[maxn];
int n;

void sieve()
{
	for (int i = 0; i < maxn; ++i)
	{
		prime[i] = 1;
	}
	for (int i = 4; i < maxn; i += 2)
	{
		prime[i] = 2;
	}
	for (int i = 3; i < sqrt(maxn)+1; i += 2)
	{
		for (int j = i * i; j < maxn; j += (2 * i))
		{
			if (prime[j] == 2)
			{
				continue;
			}
			else
			{
				prime[j] = 2;
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin>>n)
	{
		sieve();
		if (n <= 2)
		{
			cout<<1<<"\n";
		}
		else
		{
			cout<<2<<"\n";
		}
		for (int i = 2; i <= n; ++i)
		{
			cout<<prime[i]<<" ";
		}
		cout<<prime[n+1]<<"\n";
	}
}

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
string A,B;
vector<int> sherlock,moriaty;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	while(cin>>n)
	{
		cin>>A>>B;
		for (int i = 0; i < n; ++i)
		{
			sherlock.PB(A[i] - '0');
			moriaty.PB(B[i] - '0');
		}
		int max1 = sherlock[0];
		int max2 = sherlock[0];
		int min1 = moriaty[0];
		int min2 = moriaty[0];
		for (int i = 1; i < n; ++i)
		{
			max1 = max(max1,sherlock[i]);
			max2 = max(max2,moriaty[i]);
			min1 = min(min1,sherlock[i]);
			min2 = min(min2,moriaty[i]);
		}
		if (max2 < min1)
		{
			cout<<n-1<<"\n";
			cout<<0<<"\n";
		}
		else if(min2 > max1)
		{
			cout<<0<<"\n";
			cout<<n-1<<"\n";
		}
	}
}

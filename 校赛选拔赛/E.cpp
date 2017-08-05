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
const uLL INF = 0x3f3f3f3f3f3f3f;

void scan_d(int &ret)
{
    char c;
    ret = 0;
    while((c=getchar())<'0' || c>'9');
    while(c>='0'&&c<='9') ret = ret*10 +(c-'0'),c=getchar();
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	int a,b;
	double ans;
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(5);
	scan_d(T);
	while(T--)
	{
		scan_d(a);
		scan_d(b);
		if (a == 0)
		{
			ans = 0;
			printf("%.5lf\n",ans);
		}
		else if (a == a + b)
		{
			ans = 1;
			printf("%.5lf\n",ans);
		}
		else
		{
			ans = a * 1.0 / (a + b);
			printf("%.5lf\n",ans);
		}
	}
	return 0;
}
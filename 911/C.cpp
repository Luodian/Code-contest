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
#define mem(a, x) memset(a,x,sizeof(a))
#define rep(i, a, n) for (int i=a;i<n;i++)
#define per(i, a, n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define IT iterator
#define test puts("OK")
#define lowbit(x) x & -x
#define PRQ priority_queue
#define PB push_back

typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int, int> pii;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;

const LL mod = 1000000007;
const double PI = acos (-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

uLL gcd (uLL a, uLL b)
{
	return b == 0 ? a : gcd (b, a % b);
}

int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("C.txt", "r", stdin);
#endif
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	map<int, int> m;
	int a, b, c;
	cin >> a >> b >> c;
	m[a]++;
	m[b]++;
	m[c]++;
	//if have 1s then we can gen any solutions
	if (m[1] >= 1)
	{
		cout << "YES\n";
		return 0;
	}
	// if have 2 of 2s , also
	if (m[2] >= 2)
	{
		cout << "YES\n";
		return 0;
	}
	//
	if (m[3] == 3)
	{
		cout << "YES\n";
		return 0;
	}
	if (m[2] == 1 && m[4] == 2)
	{
		cout << "YES\n";
		return 0;
	}
	cout << "NO\n";
	return 0;
}
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <sstream>
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
#define gcd(a, b) _gcd(a,b)

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

int main ()
{
#ifndef ONLINE_JUDGE
	freopen ("/Users/luodian/Desktop/a.txt", "r", stdin);
#endif
	ios::sync_with_stdio (false);
	cin.tie (nullptr);
	cout.tie (nullptr);
	int n;
	while (cin >> n)
	{
		vector<int> ans;
		ans.clear ();
		for (int i = 1; i <= min (100, n); ++i)
		{
			int part2 = n - i;
			string part2InStr;
			part2InStr.clear ();
			stringstream ss;
			ss.clear ();
			ss << part2;
			ss >> part2InStr;
			int res = 0;
			for (auto j = 0; j < part2InStr.size (); ++j)
			{
				res += part2InStr[j] - '0';
			}
			if (res == i)
			{
				ans.push_back (n - i);
			}
		}
		cout << ans.size () << endl;
		for (int i = static_cast<int>(ans.size () - 1); i >= 0; --i)
		{
			cout << ans[i] << endl;
		}
	}
	return 0;
}
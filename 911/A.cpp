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
	freopen ("/Users/luodian/Documents/Code contest/911/A.txt", "r", stdin);
#endif
	ios::sync_with_stdio (false);
	cin.tie (NULL);
	cout.tie (NULL);
	multimap<int,int> mp;
	int n;
	while(cin>>n)
	{
		mp.clear();
		for (int i = 0; i < n; ++i)
		{
			int a;
			cin>>a;
			mp.insert(pair<int,int>(a,i));
		}
		auto it = mp.begin();
		int minimum = it->first;
		vector<int> vec;
		vec.clear();
		for (auto item : mp)
		{
			if (item.first == minimum)
			{
				vec.push_back(item.second);
			}
		}
		sort(vec.begin(),vec.end());
		int temp_min = INF;
		for (int i = 0; i < vec.size() - 1; ++i)
		{
			temp_min = min(temp_min,vec[i+1] - vec[i]);
		}
		cout<<temp_min<<endl;
	}
	return 0;
}
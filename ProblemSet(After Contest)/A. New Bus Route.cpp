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
	cout.tie(NULL);
	vector<int> arr;
	int n;
	while(cin>>n)
	{
		arr.clear();
		arr.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		sort(arr.begin(),arr.begin() + n);
		vector<int> diff;
		for (int i = 1; i < arr.size(); ++i)
		{
			diff.push_back(arr[i] - arr[i-1]);
		}
		sort(diff.begin(),diff.begin() + diff.size());
		int ans = diff[0];
		int cnt = 0;
		for (int i = 1; i < diff.size() && diff[i] == ans; ++i)
		{
			cnt++;
		}
		cout<<ans<<" "<<cnt+1<<"\n";
	}
	return 0;
}
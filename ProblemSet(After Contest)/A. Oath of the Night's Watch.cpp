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
const int maxn = 100005;
vector<int> arr;

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
		for (int i = 0; i < n; ++i)
		{
			int u;
			cin>>u;
			arr.PB(u);
		}
		sort(arr.begin(),arr.end());
		int first = arr[0];
		int last  = arr[arr.size() - 1];
		int num = 0;
		for (int i = 1; i < arr.size() - 1; ++i)
		{
			if (arr[i] > first && arr[i] < last)
			{
				num ++;
			}
		}
		cout<<num<<"\n";
	}

}

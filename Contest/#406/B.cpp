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
 	set<int> st[10005];
 	int n,m;
 	while(cin>>n>>m)
 	{
 		for (int i = 0; i < m; ++i)
 		{
 			st[i].clear();
 			int k;
 			cin>>k;
 			for (int j = 0; j < k; ++j)
 			{
 				int getInt;
 				cin>>getInt;
 				st[i].insert(getInt);
 			}
 		}
 		bool flag = 0;
 		for (int i = 0; i < m; ++i)
 		{
 			for (auto itr : st[i])
 			{	
 				int getInt = -1 * itr;
 				if (st[i].find(getInt) != st[i].end())
 				{
 					flag = 1;
 					break;
 				}
 			}
 		}
 		if (flag == 0)
 		{
 			cout<<"YES\n";
 		}
 		else
 		{
 			cout<<"NO\n";
 		}
 	}
}

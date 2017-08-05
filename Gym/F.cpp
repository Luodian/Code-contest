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
// #define lower_bound LB
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
	int n;
	while(cin>>n)
	{
		int vis[4];
		string info;
		for (int i = 0; i < n; ++i)
		{
			mem(vis,0);
			cin>>info;
			for (int j = 0; j < info.size(); ++j)
			{
				if (isalpha(info[j]))
				{
					vis[0] ++;
				}
				else if (isdigit(info[j]))
				{
					vis[1] ++;
				}
				else if (info[j] == '@' || info[j] == '?' || info[j] == '!')
				{
					vis[2] ++;
				}
			}
			if (vis[0] < 4)
			{
				cout<<"The last character must be a letter.\n";
			}
			else if (vis[1] < 4)
			{
				cout<<"The last character must be a digit.\n";
			}
			else if (vis[2] < 2)
			{
				cout<<"The last character must be a symbol.\n";
			}
			else
			{
				cout<<"The last character can be any type.\n";
			}
		}
	}
	return 0;
}
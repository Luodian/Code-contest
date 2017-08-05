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
	string info;
	while(cin>>info)
	{
		int cnt = 0;
		bool flag = 0;
		bool vis[105];
		mem(vis,0);
		for (int i = 0; i < info.size(); ++i)
		{
			if (i != info.size() - 1 && info[i] == 'V' && info[i+1] == 'K' && vis[i] == 0 && vis[i+1] == 0)
			{	
				cnt ++;
				vis[i] = vis[i+1] = 1;
			}
		}
		for (int i = 0; i < info.size(); ++i)
		{
			if (i != info.size() - 1 && info[i] == 'V' && info[i+1] != 'K' && flag == 0 && vis[i] == 0 && vis[i+1] == 0)
			{
				cnt ++;
				vis[i] = vis[i+1] = 1;
				flag = 1;
			}
			else if (i != 0 && info[i] == 'K' && info[i - 1] != 'V' && flag == 0 && vis[i] == 0 && vis[i-1] == 0)
			{
				cnt ++;
				flag = 1;
				vis[i] = vis[i-1] = 1;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

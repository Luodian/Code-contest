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
	string info;
	bool occur[30];
	while(cin>>info)
	{
		bool is_ans = 1;
		for (int i = 0; i < info.size(); ++i)
		{
			mem(occur,0);
			for (int j = 0; j <= i; ++j)
			{
				occur[info[j] - 'a' + 1] = 1;
			}
			int alpha_index = info[i] - 'a' + 1;
			for (int j = alpha_index; j >= 1; --j)
			{
				if (occur[j] == 0)
				{
					is_ans = 0;
					break;
				} 
			}
			if (is_ans == 0)
			{
				break;
			}
		}
		if(is_ans == 1)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
	}
}

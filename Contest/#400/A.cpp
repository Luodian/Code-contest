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
const int maxn = 1005;

int n;
set<string> victims;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string info_a,info_b;
	cin>>info_a;
	victims.insert(info_a);
	cin>>info_b;
	victims.insert(info_b);
	cin>>n;
	cout<<info_a<<" "<<info_b<<"\n";
	for (int i = 1; i <= n; ++i)
	{
		cin>>info_a>>info_b;
		victims.erase(info_a);
		victims.insert(info_b);
		int k = 1;
		for (auto v : victims)
		{
			if (k == 1)
			{
				cout<<v<<" ";
				k++;
			}	
			else
			{
				cout<<v<<"\n";
			}
		}
	}
}

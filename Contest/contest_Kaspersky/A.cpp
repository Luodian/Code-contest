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
const int maxn = 105;
map<string,int> flight;
vector<int> G[maxn];
bool is_circle;

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
		string home;
		string info;
		int k = 1;
		for (int i = 0; i <= n ;++i)
		{
			G[i].clear();
		}
		flight.clear();
		cin>>home;
		flight[home] = k++;
		for(int i = 1; i <= n; ++i)
		{
			cin>>info;
			string A,B;
			for (int j = 0; j <= 2; ++j)
			{
				A.PB(info[j]);
			}
			for (int j = 5; j <= 7; ++j)
			{
				B.PB(info[j]);
			}
			// cout<<A<<" "<<B<<"\n";
			if(flight[A] == 0)
			{
				flight[A] = k++;
			}
			if (flight[B] == 0)
			{
				flight[B] = k++;
			}
			G[flight[A]].PB(flight[B]);
		}
		if (n % 2 == 1)
		{
			cout<<"contest\n";
			continue;
		}
		is_circle = 1;
		for (int i = 1; i < k; ++i)
		{
			if (i != 1 && G[i][0] != 1)
			{
				is_circle = 0;
				break;
			}
			if (G[i].size() == 0)
			{
				is_circle = 0;
				break;
			}
		}
		if (is_circle == 1)
		{
			cout<<"home\n";
		}
		else
		{
			cout<<"contest\n";
		}
	}
}

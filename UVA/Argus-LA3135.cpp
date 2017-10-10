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
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define IT iterator
#define test puts("OK")
#define lowbit(x) x & -x
#define PRQ priority_queue
#define PB push_back
#define gcd(a,b) _gcd(a,b)


typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const LL mod=1000000007;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

struct Item
{
	int id;
	int period;
	int Time;
	Item(int _id, int _period,int _Time)
	{
		id = _id;
		period = _period;
		Time = _Time;
	}
	bool operator < (const Item &rhs) const
	{
		if (Time == rhs.Time)
		{
			return id > rhs.id;
		}
		else
		{
			return Time > rhs.Time;
		}
	}
};

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string ret;
	int k;

	PRQ<Item> manager;

	while(cin>>ret && ret[0] != '#')
	{
		int Qid,period;
		cin>>Qid>>period;
		Item a(Qid,period,period);
		manager.push(a);
	}
	cin>>k;
	for (int i = 0; i < k; ++i)
	{
		Item out = manager.top();
		manager.pop();
		cout<<out.id<<endl;
		out.Time += out.period;
		manager.push(out);
	}
	return 0;
}
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
const int maxn = (50000+5) * 4;
int cnt,p;
int T;
bool IsDone[maxn];
string MainInfo;

struct Node
{	
	int hash;
	int left;
	int right;
	string head;
	bool operator < (const Node &rhs) const	
	{
		if (hash != rhs.hash)
		{
			return hash < rhs.hash;
		}
		else if (left != rhs.left)
		{
			return left < rhs.left;
		}
		else
		{
			return right < rhs.right;
		}
	}
}node[maxn];
map<Node,int> SetId;

int parse()
{
	int id = cnt ++;
	Node &u = node[id];
	u.hash = 0;
	u.left = u.right = -1;
	u.head = "";
	while(isalpha(MainInfo[p]))
	{
		u.hash = u.hash * 26 + MainInfo[p] - 'a' + 1;
		u.head.PB(MainInfo[p]);
		p ++;
	}
	if (MainInfo[p] == '(')
	{
		p ++;
		u.left = parse();
		p ++;
		u.right = parse();
		p ++;
	}
	if (SetId.count(u) != 0)
	{
		id --;
		cnt --;
		return SetId[u];
	}
	else
	{
		SetId[u] = id;
		return id;
	}
}

void solve(int v)
{
	if (IsDone[v] == 1)
	{	
		cout<<v;
	}	
	else
	{
		IsDone[v] = 1;
		cout<<node[v].head;
		if (node[v].left != -1)
		{
			cout<<"(";
			solve(node[v].left);
			cout<<",";
			solve(node[v].right);
			cout<<")";
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>T;
	while(T--)
	{
		cnt = 1;
		p = 0;
		MainInfo.clear();
		mem(IsDone,0);
		SetId.clear();
		cin>>MainInfo;
		int rootId = parse();
		solve(rootId);
		cout<<"\n";
	}
}
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
#include <bitset>

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
int n;
vector<int> FireTimes;
set<pair<int,int>> Filled;


struct node
{
	int Time;
	int X;
	int Y;
	bitset<8> Direc;
	node(int T,int _X,int _Y)
	{
		Time = T;
		X = _X;
		Y = _Y;
	}
};

long long bfs()
{
	long long ans = 0;
	queue<node> Q;
	while(!Q.empty())
	{
		Q.pop();
	}
	node head(1,0,0);
	bitset<8> bar(string("10000000"));
	head.Direc = bar;
	Q.push(head);
	int k = 0;
	while(!Q.empty())
	{
		node cur = Q.front();
		Q.pop();

		int time = cur.Time;
		for (int i = time; i <= FireTimes[k]; ++i)
		{
			ans ++;
		}
		pair<int,int> foo;
		foo = make_pair(cur.X,cur.Y);
		Filled.insert(foo);
		int next_x;
		int next_y;
		bitset<8> bar = cur.Direc;
		node next;
		//0代表上，1代表下，2代表左，3代表右，4代表左上，5代表右上，6代表左下，7代表右下。
		if (cur.Direc.test(0))
		{
			next_x = cur.X;
			next_y = cur.Y + FireTimes[k];
			Q.push(time+FireTimes[k],next_x,next_y);
			foo = make_pair(next_x,next_y);
		}
		if (cur.Direc.test(1))
		{
			next_x = cur.X;
			next_y = cur.Y - FireTimes[k];
			Q.push(time+FireTimes[k],next_x,next_y);
		}
		if (cur.Direc.test(2))
		{
			next_x = cur.X - FireTimes[k];
			next_y = cur.Y;
			Q.push(time+FireTimes[k],next_x,next_y);
		}
		if (cur.Direc.test(3))
		{
			next_x = cur.X + FireTimes[k];
			next_y = cur.Y;
			Q.push(time+FireTimes[k],next_x,next_y);
		}
		if (cur.Direc.test(4))
		{
			next_x = cur.X - FireTimes[k];
			next_y = cur.Y + FireTimes[k];
			Q.push(time+FireTimes[k],next_x,next_y);
		}
		if (cur.Direc.test(5))
		{
			next_x = cur.X + FireTimes[k];
			next_y = cur.Y + FireTimes[k];
			Q.push(time+FireTimes[k],next_x,next_y);
		}
		if (cur.Direc.test(6))
		{
			next_x = cur.X - FireTimes[k];
			next_y = cur.Y - FireTimes[k];
			Q.push(time+FireTimes[k],next_x,next_y);
		}
		if (cur.Direc.test(7))
		{
			next_x = cur.X + FireTimes[k];
			next_y = cur.Y - FireTimes[k];
			Q.push(time + FireTimes[k],next_x,next_y);
		}
		//直接考虑下一个爆炸结点的位置。
		ans += FireTimes[k];



	}

}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	while(cin>>n)
	{	
		FireTimes.clear();
		Filled.clear();
		FireTimes.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>FireTimes[i];
		}
	}
	return 0;
}
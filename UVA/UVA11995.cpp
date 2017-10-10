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

const LL mod = 1000000007;
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
	int op,item;
	stack<int> st;
	queue<int> que;
	PRQ<int> Prq;
	vector<int> ops;
	vector<int> elements;
	bool isSt,isQue,isPrq;
	bool isError = 0;
	while(cin>>n)
	{
		ops.clear();
		elements.clear();
		isSt = 1;
		isQue = 1;
		isPrq = 1;
		while(!st.empty())
		{
			st.pop();
		}
		while(!que.empty())
		{
			que.pop();
		}
		while(!Prq.empty())
		{
			Prq.pop();
		}
		rep(i,0,n)
		{
			cin>>op>>item;
			ops.PB(op);
			elements.PB(item);
		}

		// cout<<endl;
		// rep(i,0,SZ(ops))
		// {
		// 	cout<<ops[i]<<" "<<elements[i]<<endl;
		// }
		// judge if stack
		for (int i = 0; i < n; ++i)
		{
			op = ops[i];
			item = elements[i];
			if (op == 1)
			{
				st.push(item);
			}
			else
			{
				if (!st.empty())
				{
					int ans = st.top();
					st.pop();
					if (ans != item)
					{
						isSt = 0;
						break;
					}
				}
				else
				{
					isError = 1;
				}
			}
		}
		//judge if que
		for (int i = 0; i < n; ++i)
		{
			op = ops[i];
			item = elements[i];
			if (op == 1)
			{
				que.push(item);
			}
			else
			{
				if (!que.empty())
				{
					int ans = que.front();
					que.pop();
					if (ans != item)
					{
						isQue = 0;
						break;
					}
				}
				else
				{
					isError = 1;
				}
			}
		}
		for (int i = 0 ;i < n; ++i)
		{
			op = ops[i];
			item = elements[i];
			if (op == 1)
			{
				Prq.push(item);
			}
			else
			{
				if (!Prq.empty())
				{
					int ans = Prq.top();
					Prq.pop();
					if (ans != item)
					{
						isPrq= 0;
						break;
					}
				}
				else
				{
					isError = 1;
				}
			}
		}
		// cout<<(int(isPrq) + int(isSt) + int(isQue))<<endl;
		if (isError == 1)
		{
			cout<<"impossible"<<endl;
		}
		else if ((isPrq | isSt | isQue) == 0)
		{
			cout<<"impossible"<<endl;
		}
		else if (int(isPrq) + int(isSt) + int(isQue) >= 2)
		{
			cout<<"not sure"<<endl;
		}
		else if (isPrq)
		{
			cout<<"priority queue"<<endl;
		}
		else if (isQue)
		{
			cout<<"queue"<<endl;
		}
		else
		{
			cout<<"stack"<<endl;
		}
	}
	return 0;
}
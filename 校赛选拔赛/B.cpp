#include <iostream>
#include <fstream>
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
	ofstream file0;
	int ar[2005];
	int T;
	cin>>T;
	while(T--)
	{
		mem(ar,0);
		int r;
		cin>>r;
		if (r >= 1680)
		{
			cout<<1680<<" "<<10<<endl;
		}
		else if (r >= 840)
		{
			cout<<840<<" "<<8<<endl;
		}
		else if (r >= 720)
		{
			cout<<720<<" "<<6<<endl;
		}
		else
		{
			for (int i = 1; i <= r ; ++i)
			{
				for (int j = i; j <= r ; ++j)
				{
					for (int k = j; k <= r; ++k)
					{
						if (i + j + k > r)
						{
							break;
						}
						else if (pow(i,2) + pow(j,2) == pow(k,2))
						{
							ar[i+j+k]++;
						}
					}
				}
			}
			int maxid = 0;
			int maxium = -INF;
			for (int i = 0; i < 2005; ++i)
			{
				if (ar[i] > maxium)
				{
					maxid = i;
					maxium = ar[i];
				}
			}
			cout<<maxid<<" "<<maxium<<endl;
		}
		// int r;
		// cin>>r;
		// cout<<anstable[r - 10]<<" "<<idtable[r - 10]<<"\n";
	}
	return 0;
}
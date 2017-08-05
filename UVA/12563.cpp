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
const int maxn = 55;

int f_n[maxn][10000];
int f_t[maxn][10000];
int Songs[maxn];
int V,W,C,N;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin>>T;
	int kase = 1;
	while (T--)
	{
		mem(f_t,0);
		mem(f_n,0);
		mem(Songs,0);
		cin>>N>>C;
		for (int i = 1; i <= N; ++i)
		{
			cin>>Songs[i];
		}
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 0; j <= C; ++j)
			{
				f_n[i][j] = f_t[i-1][j];
				f_t[i][j] = f_n[i-1][j];
				if (j > Songs[i])
				{
					if (f_n[i][j] < f_n[i-1][j-Songs[i]] + 1)
					{
						f_n[i][j] = f_n[i-1][j-Songs[i]] + 1;
						f_t[i][j] = f_t[i-1][j-Songs[i]] + Songs[i];
					}
					else if (f_n[i][j] == f_n[i-1][j-Songs[i]] + 1)
					{
						f_t[i][j] = max(f_t[i-1][j],f_t[i-1][j-Songs[i]] + Songs[i]);
					}
				}
			}
		}
		// cout<<f_t[N][C]<<" "<<f_n[N][C]<<"\n";
		cout<<"Case "<<kase++<<": "<<f_n[N][C]+1<<" "<<f_t[N][C]+678<<"\n";
	}


}

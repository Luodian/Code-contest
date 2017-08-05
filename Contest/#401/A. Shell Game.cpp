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
int n;
int arr[3][10];
string info;

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	arr[0][1] = 1;
	arr[0][2] = 2;
	arr[0][3] = 2;
	arr[0][4] = 1;
	arr[0][5] = 0;
	arr[0][6] = 0;

	arr[1][1] = 0;
	arr[1][2] = 0;
	arr[1][3] = 1;
	arr[1][4] = 2;
	arr[1][5] = 2;
	arr[1][6] = 1;

	arr[2][1] = 2;
	arr[2][2] = 1;
	arr[2][3] = 0;
	arr[2][4] = 0;
	arr[2][5] = 1;
	arr[2][6] = 2;
	while(cin>>n)
	{
		int now;
		cin>>now;
		int accute_move = n % 6;
		if (accute_move == 0)
		{
			accute_move = 6;
		}
		for (int i = 0; i <= 2; ++i)
		{
			if (arr[i][accute_move] == now)
			{
				cout<<i<<"\n";
				break;
			}
		}
	}

}

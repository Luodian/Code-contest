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
vector<int> permu;
vector<int> linear_matrix;


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	string info;
	permu.resize(9);

	map<int,pair<int,int> > reverseMap;

	for (int i = 0; i < 9; ++i)
	{
		permu[i] = i + 1;
	}

	for (int i = 0; i < 3; ++i)
	{
		cin>>info;
		for (int i = 0; i < info.size(); ++i)
		{
			linear_matrix.push_back(info[i] - '0');
		}
		do
		{	
			bool suited = 1;
			for (int i = 0; i < 9; ++i)
			{
				if (linear_matrix[i] != 0 && linear_matrix[i] != permu[i])
				{
					suited = 0;
					break;
				}
			}
			if (suited == 0)
			{
				continue;
			}
			else
			{
				int cnt = 0;
				for (int i = 1; i <= 3; ++i)
				{
					for (int j = 1; j <= 3; ++j)
					{
						reverseMap[permu[cnt++]] = make_pair(i,j);
					}
				}

				for (int i = 1; i <= 8; ++i)
				{
					pair<int,int> foo = reverseMap[i];
					pair<int,int> bar = reverseMap[i+1];

					

				}

			}
		}while(next_permutation(permu.begin(),permu.begin() + 9))
	}
	return 0;
}
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


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	while (cin>>n)
	{
		int count = 0;
		int NonZeroIndex = 0;
		long long ArraySum = 0;
		int element;
		vector<int> array;
		array.clear();
		for (int i = 0; i < n; ++i)
		{
			cin>>element;
			ArraySum += element;
			if (element != 0)
			{
				count ++;
			}
			array.push_back(element);
		}
		if(count == 0)
		{
			cout<<"NO"<<"\n";
		}
		else
		{
			cout<<"YES"<<"\n";
			if (ArraySum != 0)
			{
				cout<<1<<"\n";
				cout<<1<<" "<<n<<"\n";
			}
			else
			{
				for (int i = 0; i < n; ++i)
				{
					if (array[i] != 0)
					{
						NonZeroIndex = i;
						break;
					}
				}
				cout<<2<<"\n";
				cout<<1<<" "<<NonZeroIndex+1<<"\n";
				cout<<NonZeroIndex + 2<<" "<<n<<"\n";
			}
		}
	}
}

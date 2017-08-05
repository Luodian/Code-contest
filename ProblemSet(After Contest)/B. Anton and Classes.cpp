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

struct node
{
	int l,r;
}section_n[200000+5],section_m[200000+5];

bool cmp1(const node &a,const node &b)
{
	return a.r < b.r;
}	

bool cmp2(const node &a,const node &b)
{
	return a.l > b.l;
}


int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
 	cout.tie(NULL);
 	int n,m;
 	cin>>n;
 	for (int i = 0; i < n; ++i)
 	{
 		cin>>section_n[i].l>>section_n[i].r;
 	}
 	cin>>m;
 	for (int i = 0; i < m; ++i)
 	{
 		cin>>section_m[i].l>>section_m[i].r;
 	}

 	int ans = 0;
 	bool found = 0;
 	sort(section_n,section_n + n,cmp1);
 	sort(section_m,section_m + m,cmp2);
 	int rest = section_m[0].l - section_n[0].r;
 	if (rest > 0)
 	{
 		ans = rest;
 		found = 1;
 	}
 	sort(section_m,section_m + m,cmp1);
 	sort(section_n,section_n + n,cmp2);
 	rest = section_n[0].l - section_m[0].r;
 	if (rest > 0)
 	{
 		ans = max(ans,rest);
 		found = 1;
 	}
 	if (found == 1)
 	{
 		cout<<ans<<endl;
 	}
 	else
 	{
 		cout<<0<<endl;
 	}

}


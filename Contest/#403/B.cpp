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
const int maxn = 60005;
struct node
{
    double x,v;
    bool operator < (const node &rhs) const
    {
        return x < rhs.x;
    }
}person[maxn];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin>>n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin>>person[i].x;
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>person[i].v;
        }
        sort(person,person+n);
        double ans = -INF;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                double temp  = (person[j].x - person[i].x) / (person[j].v + person[i].v);
                ans = max(ans,temp);
            }
        }
        printf("%.12lf\n",ans);
    }
}

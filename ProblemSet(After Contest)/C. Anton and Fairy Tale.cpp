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
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long n,m;
    while(cin>>n>>m)
    {
        if (n <= m)
        {
            cout<<n<<endl;
        }
        else
        {
            long long l = 0,r = 1e18;
            long long mid;
            long long final = n - m;
            while(l < r)
            {
                mid = (l + r) / 2;
                unsigned long long val = (mid * (mid + 1)) / 2;
                if (val >= final)
                {	
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            cout<<l + m<<endl;
        }
    }
}

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
const int maxn = 60000 + 5;
int n;
vector<double> cord;
vector<double> velocity;

bool ableMeet(double time)
{
    double left = cord[0] - time * velocity[0];
    double right = cord[0] + time * velocity[0];
    for (int i = 1; i < n; ++i)
    {
        double li = cord[i] - time * velocity[0];
        double re = cord[i] + time * velocity[0];
        if (li > right || re < left)
        {
            return 0;
        }
    }
    return 1;
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
        cord.clear();
        velocity.clear();
        cord.resize(n);
        velocity.resize(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>cord[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>velocity[i];
        }
        double l = 0;
        double r = 1e9;
        double mid;
        while(r - l > eps)
        {
            mid = (r + l) / 2;
            if (ableMeet(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        cout<<fixed<<setprecision(12);
        cout<<mid<<"\n";
    }
    
    
}

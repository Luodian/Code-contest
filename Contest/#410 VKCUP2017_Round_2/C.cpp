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
#define ull unsigned long long

const double PI = acos(-1.0);
const double eps = 1e-4;
const int INF = 0x3f3f3f3f;
double L,R;
long long n,p;
double arr[100005][2];

bool meet(double t)
{
    double res = 0;
    double used = 0;
    for (int i = 0; i < n; ++i)
    {
        used = (t * arr[i][0]);
        if (used - arr[i][1] > 0)
        {
            res += (used - arr[i][1]);
        }
    }
    if (res <= t * p)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(cin>>n>>p)
    {
        L = 0;
        R = 1e15;
        ull _sum = 0;
        mem(arr,0);
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i][0]>>arr[i][1];
            _sum += arr[i][0];
        }
        if (_sum <= p)
        {
            cout<<-1<<endl;
            continue;
        }
        double mid;
        while(R - L > eps)
        {
            mid = (L + R) / 2;
            if (meet(mid) == 1)
            {
                L = mid;
            }
            else
            {
                R = mid;
            }
        }
        if (abs(R - 1e15) < eps)
        {
            cout<<-1<<endl;
        }
        else
        {
            printf("%.9lf\n",R);
        }
    }
    return 0;
}

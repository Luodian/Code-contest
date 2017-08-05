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
map<long long,int> isZero;

void init(long long n)
{
    isZero.clear();
    long long level = log2(n);
    long long head = pow(2,level);
    while(head)
    {
        isZero[head] = n & 1;
        n >>= 1;
        head >>= 1;
    }
}

long long FindPos(long long index)
{
    if (index & 1)
    {
        return 1;
    }
    long long p = 2;
    while(index % p == 0)
    {
        if (index == p)
        {
            return index;
        }
        else
        {
            p <<= 1;
        }
    }
    return (p >> 1);
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long n,l,r;
    long long ans = 0;
    cin>>n>>l>>r;
    init(n);
    for (long long i = l; i <= r; ++i)
    {
        ans += isZero[FindPos(i)];
    }
    cout<<ans<<"\n";
    return 0;
}

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

long long mapTree(long long n,long long find)
{
    long long L = 1;
    long long R = n + 1;
    long long sequence = 1;
    while(L < R)
    {
        long long mid = (L + R) / 2;
        if (mid == find)
        {
            return sequence;
        }
        else if (mid > find)
        {
            R = mid - 1;
            sequence *= 2;
        }
        else if (mid < find)
        {
            L = mid;
            sequence = sequence * 2 + 1;
        }
    }
    return 0;
}

long long deduce(long long n,long long u)
{
    long long cnt = 0;
    stack<char> backward;
    while(u != 1)
    {
        if (u % 2 == 1)
        {
            backward.push('R');
        }
        else
        {
            backward.push('L');
        }
        u /= 2;
    }
    long long mid = (n + 1) / 2;
    while(mid != 1)
    {
        mid /= 2;
        cnt ++;
    }
    long long shift = pow(2,cnt-1);
    mid = (n + 1) / 2;
    while(!backward.empty())
    {
        char dir = backward.top();
        if (dir == 'L')
        {
            mid -= shift;
            shift /= 2;
        }
        else
        {
            mid += shift;
            shift /= 2;
        }
        backward.pop();
    }
    return mid;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,q;
    while(cin>>n>>q)
    {
        for (int i = 0; i < q; ++i)
        {
            long long u;
            string op;
            cin>>u>>op;
            long long st = mapTree(n,u);
            for (int j = 0; j < op.size(); ++j)
            {
                if (op[j] == 'U')
                {
                    if (st / 2 >= 1)
                    {
                        st /= 2;
                    }
                }
                else if (op[j] == 'L')
                {
                    if (st * 2 <= n)
                    {
                        st = st * 2;
                    }
                }
                else if (op[j] == 'R')
                {
                    if (st * 2 + 1 <= n)
                    {
                        st = st * 2 + 1;
                    }
                }
            }
            long long ed = deduce(n, st);
            cout<<ed<<endl;
        }
    }
    return 0;
}

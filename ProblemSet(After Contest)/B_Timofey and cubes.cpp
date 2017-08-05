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
const int maxn = 200005;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int array[maxn];
    while(cin>>n)
    {
        mem(array,0);
        for (int i = 1; i <= n; ++i)
        {
            cin>>array[i];
        }
        // int row;
        // if (n % 2 == 1)
        // {
        //     row = (n + 1) / 2 - 1;
        // }
        // else
        // {
        //     row = (n + 1) / 2;
        //     mid --;
        //     for (int i = 1; i <= row; ++i)
        //     {
        //         for (int j = 1; j <= i; ++j)
        //         {
        //             int first = mid - j + 1;
        //             int last = n - first + 1;
        //             swap(array[first],array[last]);
        //         }
        //     }
        // }
        for (int i = 1; i <= n / 2; ++i)
        {
            if ((i & 1) == 1)
            {
                swap(array[i],array[n + 1 - i]);
            }
        }
        for (int i = 1; i < n; ++i)
        {
            cout<<array[i]<<" ";
        }
        cout<<array[n]<<"\n";
    }
}
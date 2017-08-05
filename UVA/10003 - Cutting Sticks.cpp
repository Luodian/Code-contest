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
const int maxn = 55;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int seg[maxn];
    int f[maxn][maxn];
    int n,l;
    while(cin>>l && l != 0)
    {
        mem(f,0);
        mem(seg,0);
        cin>>n;
        for (int i = 1; i <= n; ++i)
        {
            cin>>seg[i];
        }
        seg[0] = 0;
        seg[n+1] = l;
        for (int seg_length = 1; seg_length <= n+1; seg_length ++) //枚举区间长度
        {
            for (int st = 0; st <= n; ++st)
            {
                int ed = st + seg_length;
                if (ed > n+1)
                {
                    break;
                }
                int ans = INF;
                int flag = 0;
                for (int k = st + 1; k < ed; ++k)
                {   
                    ans = min(ans,f[st][k]+f[k][ed]);
                    flag = 1;
                }
                if (flag == 1 && ans != INF)
                {
                    f[st][ed] = ans + (seg[ed] - seg[st]);
                }
            }
        }
        cout<<"The minimum cutting is ";
        cout<<f[0][n+1]<<".\n";
    }
}

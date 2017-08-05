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
#include <unordered_set>
#include <numeric>
#include <set>
#include <list>
#include <map>

using namespace std;
#define lower_bound LB
#define upper_bound UB
#define mem(a,x) memset(a,x,sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define IT iterator
#define test puts("OK")
#define lowbit(x) x & -x
#define PRQ priority_queue
#define PB push_back
#define gcd(a,b) _gcd(a,b)


typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const LL mod=1000000007;
const double PI = acos(-1.0);
const double eps = 1e-8;
const uLL INF = 0x3f3f3f3f3f3f3f;
PRQ<int,vector<int>,greater<int>> Q;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,n,k;
    cin>>t;
    int u;
    while(t--)
    {
        while(!Q.empty())
        {
            Q.pop();
        }
        cin>>n>>k;
        for (int i = 0; i < n; ++i)
        {
            cin>>u;
            Q.push(u);
        }
        for (int i = 0; (n - 1) % (k - 1) != 0 && i < (k - 1 - ( n - 1) % (k - 1)); ++i)
        {
            Q.push(0);
        }
        int ans = 0;
        while(Q.size() != 1)
        {
            int _sum = 0;
            for (int i = 0; i < k; ++i)
            {
                _sum += (Q.top());
                Q.pop();
            }
            Q.push(_sum);
            ans += _sum;
        }
        Q.pop();
        cout<<ans<<endl;
    }
    return 0;
}

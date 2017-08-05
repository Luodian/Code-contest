]#include <iostream>
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
const int INF = 0x3f3f3f3f;
const int maxn = 305;

int a[maxn];
int b[maxn];
int f[maxn][maxn];
int n;
int T;

int dfs(int l,int r)
{
    if (l > r)
    {
        return 0;
    }
    else if (l  == r)
    {
        return a[l] + b[l-1] + b[l+1];
    }
    else
    {
        int &ans = f[l][r];
        if (ans > 0)
        {
            return ans;
        }
        ans = INF;
        for (int k = l; k <= r; ++k)
        {
            ans = min(ans,dfs(l,k-1) + dfs(k + 1,r) + a[k]);
        }
        ans += (b[l-1] + b[r+1]);
        return ans;
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
    cin>>T;
    int kase = 1;
    while(T--)
    {
        cin>>n;
        mem(a,0);
        mem(b,0);
        mem(f,0);
        for (int i = 1; i <= n; ++i)
        {
            cin>>a[i];
        }
        for (int i = 1; i <= n; ++i)
        {
            cin>>b[i];
        }
        dfs(1,n);
        cout<<"Case #"<<kase++<<": ";
        cout<<f[1][n]<<endl;
    }
    return 0;
}

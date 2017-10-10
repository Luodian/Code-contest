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
const int INF = 0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/B.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    while(cin>>n)
    {
        vector<int> st;
        st.clear();
        int vis[105];
        mem(vis,0);
        for (int i = 0; i < 2 * n; ++i)
        {
            int temp;
            cin>>temp;
            st.push_back(temp);
        }
        long long finalAns = INF;
        vector<int> cur;
        for (int i = 0;i < st.size(); ++i)
        {
            for (int j = i + 1; j < st.size(); ++j)
            {
                cur.clear();
                cur = st;
                cur.erase(cur.begin() + j);
                cur.erase(cur.begin() + i);
                long long ans = 0;
                sort(cur.begin(),cur.end());
                for (int k = 0; k < cur.size(); k += 2)
                {
                    ans += (cur[k+1] - cur[k]);
                }
                finalAns = min(finalAns,ans);
            }
        }
        cout<<finalAns<<endl;
    }
    return 0;
}
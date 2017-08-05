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
const int maxn = 10005;
int n;
string info;
long long dp[maxn];
bool mostPre[15];

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
        cin>>info;
        mem(dp,0);
        dp[0] = 1;
        for (int i = 1; i < info.size(); ++i)
        {
            mem(mostPre,0);
            int index = -1;
            mostPre[info[i] - '0'] = 1;
            for (int j = i - 1; j >= 0; --j)
            {
                if (mostPre[info[j] - '0'] == 1)
                {
                    index = j;
                    break;
                }
                else
                {
                    mostPre[info[j] - '0'] = 1;
                }
            }
            if (index == -1)
            {
                dp[i] += 1;
            }
            else
            {
                dp[i] += dp[index];
            }
            for (int j = i - 1; j > index; --j)
            {
                dp[i] += dp[j];
            }
        }
        cout<<dp[info.size() - 1]<<endl;
    }
    return 0;
}
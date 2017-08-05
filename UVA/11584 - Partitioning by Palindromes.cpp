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
const int maxn = 1005;
bool isPalin[maxn][maxn];
int dp[maxn];
size_t len;
string sTr;

void makePalin()
{
    for (int i = 0; i < len; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            if (i == j)
            {
                isPalin[i][j] = 1;
            }
            else
            {
                if (i - j > 1)
                {
                    if (isPalin[j+1][i-1] && sTr[j] == sTr[i])
                    {
                        isPalin[j][i] = 1;
                    }
                    else
                    {
                        isPalin[j][i] = 0;
                    }
                }
                else
                {
                    if (sTr[i] == sTr[j])
                    {
                        isPalin[j][i] = 1;
                    }
                    else
                    {
                        isPalin[j][i] = 0;
                    }
                }
            }
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin>>T;
    while (T--)
    {
        mem(isPalin,0);
        cin>>sTr;
        len = sTr.size();
        makePalin();
        for (int i  = 0; i < len; ++i)
        {
            dp[i] = i + 1;
            if (isPalin[0][i])
            {
                dp[i] = 1;
            }
        }
        for (int i = 0; i < len; ++i)
        {
            for (int j = 0; j+1 <= i; ++j)
            {
                if (isPalin[j+1][i])
                {
                    dp[i] = min(dp[i],dp[j] + 1);
                }
            }
        }
        cout<<dp[len-1]<<"\n";
    }
    
}

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> arr;
    vector<int> circle;
    int n,k;
    while(cin>>n>>k)
    {
        arr.clear();
        arr.resize(k);
        circle.clear();
        circle.resize(n+1);
        for (int i = 1; i <= n; ++i)
        {
            circle[i] = i;
        }
        for (int i = 0; i < k; ++i)
        {
            cin>>arr[i];
        }
        int left = n;
        int cur = 1;
        vector<int> ans;
        ans.clear();
        for (int i = 0; i < arr.size(); ++i)
        {
            int step = arr[i];
            int shift = step % left;
            int cnt = 0;
            while(cnt != shift)
            {
                if (circle[cur] != 0)
                {
                    cnt++;
                }
                cur = (cur + 1) % n;
            }
            cur ++;
            left --;
        }
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i != ans.size() - 1)
            {
                cout<<ans[i]<<" ";
            }
            else
            {
                cout<<"\n";
            }
        }
    }
    return 0;
}
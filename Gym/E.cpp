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
    string info;
    vector<long long> repti;
    while(cin>>info)
    {
        repti.clear();
        repti.resize(26);
        for (int i = 0; i < info.size(); ++i)
        {
            repti[info[i] - 'a'] ++;
        }
        int min_ans = 100005;
        long long min_cost = INF;
        // for (int i = 0; i < 26; ++i)
        // {
        // 	cout<<repti[i]<<" ";
        // }
        // cout<<"\n";
        for (int i = 100000; i >= 2; --i)
        {
            long long cur_cost = 0;
            for (int j = 0; j < 26; ++j)
            {
                if (repti[j] != 0)
                {
                    cur_cost += (repti[j] % (long long)i) * (repti[j]);
                }
            }
            if (cur_cost <= min_cost)
            {
                min_cost = cur_cost;
                min_ans = i;
            }
        }
        cout<<min_ans<<"\n";
    }
    
    return 0;
}
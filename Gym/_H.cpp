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
    int n;
    vector<int> arr;
    vector<int> ans;
    map<int,int> book;
    while(cin>>n)
    {
        arr.clear();
        arr.resize(n);
        book.clear();
        ans.clear();
        ans.resize(n);
        for (int i = 0; i < n;++i)
        {
            cin>>arr[i];
        }
        for (int i = arr.size() - 1; i >= 0; --i)
        {
            int cur = arr[i];
            int suitedIndex = n;
            bool found = 0;
            for (int j = cur + 1; j <= 50; ++j)
            {
                if (book.find(j) != book.end() && book[j] < suitedIndex)
                {
                    suitedIndex = book[j];
                    found = 1;
                }
            }
            if (found == 1)
            {
                ans[i] = arr[suitedIndex];
            }
            else
            {
                ans[i] = -1;
            }
            book[cur] = i;
        }
        for (int i = 0; i < ans.size(); ++i)
        {
            if (i == n - 1)
            {
                cout<<ans[i]<<endl;
            }
            else
            {
                cout<<ans[i]<<" ";
            }
        }
    }
    return 0;
}

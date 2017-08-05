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
const int maxn = 150;
int T;
int f[maxn][maxn];
string info;

bool match(char a,char b)
{
    string combine;
    combine.PB(a);
    combine.PB(b);
    if (combine == "()" || combine == "[]")
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void print(int i,int j)
{
    if (i > j)
    {
        return;
    }
    if (i == j)
    {
        if(info[i] == '(' || info[i] == ')')
        {
            cout<<"()";
        }
        else
        {
            cout<<"[]";
        }
        return;
    }
    int ans = f[i][j];
    if (match(info[i],info[j]) == 1 && ans == f[i+1][j-1])
    {
        cout<<info[i];
        print(i+1,j-1);
        cout<<info[j];
        return;
    }
    for (int k = i; k < j; ++k)
    {
        if (ans == f[i][k] + f[k+1][j])
        {
            print(i,k);
            print(k+1,j);
            return;
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("/Users/luodian/Desktop/in.txt","r",stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    getchar();
    while(T--)
    {
        getline(cin,info);
        getline(cin,info);
        mem(f,0);
        int n = (int)info.size() - 1;
        for(int i = 0; i <= n; ++i)
        {
            f[i][i] = 1;
        }
        for (int k = 1; k <= n; ++k) //枚举区间长度
        {
            for (int i = 0; i <= n - 1; ++i)
            {
                for(int j = i + k; j <= n; ++j)
                {
                    f[i][j] = k + 1;
                }
            }
        }
        for (int k = 1; k <= n; ++k)
        {
            for (int i = 0; i <= n - 1; ++i)
            {
                int j = i + k;
                if (j > n)
                {
                    continue;
                }
                if (match(info[i],info[j]) == 1)
                {
                    f[i][j] = min(f[i][j],f[i+1][j-1]);
                }
                for (int c = i; c < j; ++c)
                {
                    f[i][j] = min(f[i][j],f[i][c]+f[c+1][j]);
                }
            }
        }
        print(0,n);
        if (T) 
        {
            cout<<"\n\n";
        }
        else
        {
            cout<<"\n";
        }
        // cout<<f[0][n]<<"\n";
    }
    
}

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
    // #ifndef ONLINE_JUDGE   
    //     freopen("in.txt","r",stdin);
    // #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    char graph[10][10];
    mem(graph,0);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            cin>>graph[i][j];
        }
    }
    bool isFlag = false;
    int countX = 0;
    int countDot = 0;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            if ((j + 2 < 4))
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i][j+direct] == 'x')
                    {
                        countX ++;
                    }
                    else if (graph[i][j+direct] == '.')
                    {
                        countDot ++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                    break;
                }
            }
            if ((j + 2 < 4) && (i + 2) < 4)
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i+direct][j+direct] == 'x')
                    {
                        countX++;
                    }
                    else if (graph[i+direct][j+direct] == '.')
                    {
                        countDot++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                }
            }
            if ((i + 2 < 4))
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i+direct][j] == 'x')
                    {
                        countX++;
                    }
                    else if (graph[i+direct][j] == '.')
                    {
                        countDot++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                }
            }
            if ((j - 2 > 0))
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i][j-direct] == 'x')
                    {
                        countX++;
                    }
                    else if (graph[i][j-direct] == '.')
                    {
                        countDot++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                }
            }
            if ((i - 2) > 0)
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i-direct][j] == 'x')
                    {
                        countX++;
                    }
                    else if (graph[i-direct][j] == '.')
                    {
                        countDot++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                }
            }
            if ((i + 2 < 4) && (j - 2) > 0)
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i+direct][j-direct] == 'x')
                    {
                        countX++;
                    }
                    else if (graph[i+direct][j-direct] == '.')
                    {
                        countDot++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                }
            }
            if ((j+2) < 4 && (i-2 > 0))
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i-direct][j+direct] == 'x')
                    {
                        countX++;
                    }
                    else if (graph[i-direct][j+direct] == '.')
                    {
                        countDot++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                }
            }
            if ((j - 2) > 0 && (i - 2) > 0)
            {
                countX = 0;
                countDot = 0;
                for (int direct = 0; direct <= 2; ++direct)
                {
                    if (graph[i-direct][j-direct] == 'x')
                    {
                        countX++;
                    }
                    else if (graph[i-direct][j-direct] == '.')
                    {
                        countDot++;
                    }
                }
                if (countX == 2 && countDot == 1)
                {
                    isFlag = 1;
                }
            }
        }
    }
    if(isFlag)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
    }
    
}

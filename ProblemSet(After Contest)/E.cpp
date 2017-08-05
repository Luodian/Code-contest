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
const int maxn = 5;

int dist[maxn];
bool vis[maxn];
int w[maxn][maxn];
int n,m;



int dijkstra()
{
    //初始化v[0]到v[i]的距离
    for(int i = 1;i <= n;i++)
        dist[i] = w[0][i];                                       
    vis[1]=1;//标记v[0]点
    for(int i = 1; i <= n; i++)
    {
        //查找最近点
        int min = INF,k = 0;
        for(int j = 1; j <= n; j++)
            if(!vis[j] && dist[j] < min)
                min = dist[j],k = j;
        vis[k] = 1;//标记查找到的最近点
        //判断是直接v[0]连接v[j]短，还是经过v[k]连接v[j]更短
        for(int j = 1; j <= n; j++)
            if(!vis[j] && min+w[k][j] < dist[j])
                dist[j] = min+w[k][j];
    }
    return dist[n];
}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("/Users/luodian/Desktop/in.txt","r",stdin);
	#endif
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mem(vis,0);
	mem(w,INF);
	mem(dist,0);
	n = 3;
	m = 3;
	w[1][3] = 2;
	w[1][2] = 3;
	w[2][3] = -2;
	cout<<dijkstra()<<endl;
	return 0;
}
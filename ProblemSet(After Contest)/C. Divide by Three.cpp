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
#define ln "\n"


typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

const LL mod = 1000000007;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int INF = 0x3f3f3f3f;

int sumUp(const string &a)
{
	int ret = 0;
	for (int i = 0;i < a.size(); ++i)
	{
		ret += (a[i] - '0');
		ret %= 3;
	}
	return ret;
}

void erase_leading_zero(string &a)
{
	int k  = 0;
	if (a.size() == 1)
	{
		return;
	}
	while(a[k] == '0')
	{
		k ++;
	}	
	a = a.substr(k,a.size());
	if (a.size() == 0)
	{
		a = '0';
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
	string b;
	string ans;
	while(cin>>b)
	{
		ans.clear();
		int sum_all = sumUp(b);
		if (sum_all % 3 == 0)
		{
			cout<<b<<"\n";
		}
		else if (b.size() == 1)
		{
			if (sum_all == 1 || sum_all == 2) 
			{
				cout<<-1<<ln;
			}
			else
			{
				cout<<b<<ln;
			}
		}
		else if (b.size() == 2)
		{
			if (sum_all == 1)
			{
				if ((b[0] - '0') % 3 == 1)
				{
					if ((b[1] - '0') % 3 == 1)
					{
						cout<<-1<<ln;
					}
					else if ((b[1] - '0') % 3 == 0)
					{
						cout<<b[1]<<ln;
					}
				}
				else if ((b[0] - '0') % 3 == 2)
				{
					if ((b[1] - '0') % 3 == 0)
					{
						cout<<b[1]<<ln;
					}
					else if ((b[1] - '0') % 3 == 2)
					{
						cout<<-1<<ln;
					}
				}
				else if ((b[0] - '0') % 3 == 0)
				{
					cout<<b[0]<<ln;
				}
			}
			else if (sum_all == 2)
			{
				if ((b[0] - '0') % 3 == 1)
				{
					cout<<-1<<ln;
				}
				else
				{
					for (int i = 0; i < b.size(); ++i)
					{
						if ((b[i] - '0') % 3 != 2)
						{
							cout<<b[i];
						}
					}
					cout<<ln;
				}
			}
		}
		else
		{
			// cout<<"sum : "<<sum_all<<ln;
			if (sum_all == 1)
			{
				string c = b;
				string ans_c;
				ans_c.clear();

				for (int i = b.size() - 1;i >= 0; --i)
				{
					if ((b[i] - '0') % 3 == 1)
					{
						b[i] = '#';
						break;
					}
				}
				int cnt_mask = 0;
				for (int i = 0; i < b.size(); ++i)
				{
					if (b[i] != '#')
					{
						ans.push_back(b[i]);
					}
					else
					{
						cnt_mask ++;
					}
				}
				int cnt_two = 0;
				for (int i = c.size() - 1;i >= 0 && cnt_two != 2; --i)
				{
					if ((c[i] - '0') % 3 == 2)
					{
						c[i] = '#';
						cnt_two ++;
					}
				}
				int c_cnt_mask = 0;
				for (int i = 0; i < c.size(); ++i)
				{
					if (c[i] != '#')
					{
						ans_c.push_back(c[i]);
					}
					else
					{
						c_cnt_mask ++;
					}
				}
				erase_leading_zero(ans);
				erase_leading_zero(ans_c);
				// cout<<ans<<" "<<ans_c<<ln;
				if (cnt_mask != 0 && cnt_two != 0)
				{
					if (ans.size() < ans_c.size() && cnt_two == 2)
					{
						cout<<ans_c<<ln;
					}
					else
					{
						cout<<ans<<ln;
					}
				}
				else if (cnt_mask != 0)
				{
					cout<<ans<<ln;
				}
				else if (cnt_two != 0)
				{
					cout<<ans_c<<ln;
				}
				else
				{
					cout<<-1<<ln;
				}
			}
			else if (sum_all == 2)
			{
				int cnt_one = 0;
				string c = b;
				string ans_c;
				ans_c.clear();
				for (int i = b.size() - 1; i >= 0 && cnt_one != 2; --i)
				{
					if ((b[i] - '0') % 3 == 1)
					{
						cnt_one ++;
						b[i] = '#';
					}
				}
				for (int i = c.size() - 1; i >= 0; --i)
				{
					if ((c[i] - '0') % 3 == 2)
					{
						c[i] = '#';
						break;
					}
				}
				int cnt_mask = 0;
				for (int i = 0; i < b.size(); ++i)
				{
					if (b[i] != '#')
					{
						ans.push_back(b[i]);
					}
					else
					{
						cnt_mask ++;
					}
				}
				int c_cnt_mask = 0;
				for (int i = 0; i < c.size(); ++i)
				{
					if (c[i] != '#')
					{
						ans_c.push_back(c[i]);
					}
					else
					{
						c_cnt_mask ++;
					}
				}
				erase_leading_zero(ans);
				erase_leading_zero(ans_c);
				// cout<<ans<<" "<<ans_c<<ln;
				if (cnt_mask != 0 && c_cnt_mask != 0)
				{
					if (ans.size() > ans_c.size() && cnt_one == 2)
					{
						cout<<ans<<ln;
					}
					else
					{
						cout<<ans_c<<ln;
					}
				}
				else if (cnt_mask != 0)
				{
					cout<<ans<<ln;
				}
				else if (c_cnt_mask != 0)
				{
					cout<<ans_c<<ln;
				}
				else
				{
					cout<<-1<<ln;
				}
			}
		}
	}
	return 0;
}
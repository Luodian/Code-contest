#include <iostream>

using namespace std;

int main()
{
	int a,b,k;
	while(cin>>k>>a>>b)
	{
		if ((max(a,b) < k) || (a > k && b < k && a % k != 0) || (b > k && a < k && b % k != 0))
		{
			cout<<-1<<"\n";
		}
		else
		{
			cout<< a / k + b / k <<"\n";
		}
	}
}

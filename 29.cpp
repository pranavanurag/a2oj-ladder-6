#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;


	if (k < (n/2) || (n == 1 && k != 0))
		cout<<-1<<endl;
	else if (k == (n/2))
	{
		int x = (int)1e8;
		for (int i = 1; i <= n; i++)
			cout<<(x++)<<" ";
		cout<<endl;
	}
	else
	{
		int a = (k - (n/2) + 1);
		cout<<a<<" "<<2*a<<" ";
		int x = (int)1e9 - (int)1e5;
		for (int i = 3; i <= n; i++)
			cout<<(x++)<<" ";
		cout<<endl;
	}
	return 0;
}
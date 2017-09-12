#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin>>n>>k;
	if ((n*(n - 1))/2 <= k)
		cout<<"no solution"<<endl;
	else
	{
		for (int i = 0; i < n; i++)
			cout<<0<<" "<<i<<endl;
	}
	return 0;
}
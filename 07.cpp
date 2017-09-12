#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	int x[101], y[101];
	int p = min(n, m);
	cout<<p + 1<<"\n";
	for (int i = 0; i <= p; i++)
		x[i] = i, y[i] = i + 1;
	if (n < m)
	{
		for (int i = 0; i <= p; i++)
			cout<<x[i]<<" "<<y[i]<<"\n";
	}
	else if (n > m)
	{
		for (int i = 0; i <= p; i++)
			cout<<y[i]<<" "<<x[i]<<"\n";
	}
	else
	{
		for (int i = 0; i <= p; i++)
			cout<<p - i<<" "<<i<<endl;
	}
	return 0;
}
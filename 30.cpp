#include <bits/stdc++.h>

using namespace std;

int n, m, a[100001], l[100001], r[100001];

void pre()
{
	for (int i = 1; i <= n; i++)
	{
		int j = i;
		while (a[j + 1] >= a[j] && j < n)
			j++;

		for (int k = i; k <= j; k++)
			r[k] = j;
		i = j;
	}

	for (int i = n; i >= 1; i--)
	{
		int j = i;
		while (a[j - 1] >= a[j] && j > 1)
			j--;

		for (int k = i; k >= j; k--)
			l[k] = j;
		i = j;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	pre();

	while (m--)
	{
		int x, y;
		cin>>x>>y;
		if (r[x] >= l[y])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
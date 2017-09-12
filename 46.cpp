#include <bits/stdc++.h>

using namespace std;

vector <int> a;
int n;

bool all_ones()
{
	for (auto x: a)
		if (x != 1)
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int temp;
	for (int i = 1; i <= n && cin>>temp; i++)
		a.push_back(temp);

	if (all_ones())
	{
		for (int i = 1; i < n; i++)
			cout<<1<<" ";
		cout<<2<<endl;
	}
	else
	{
		sort(a.begin(), a.end());
		a[n - 1] = 1;
		sort(a.begin(), a.end());
		for (auto x: a)
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;
}
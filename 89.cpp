#include <bits/stdc++.h>

using namespace std;

int n, a[100001];
int h[200001];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	for (int i = 1; i <= (n + 1)/2; i++)
	{
		h[(int)1e5 + a[i] - i]++;
		if (i != n - i + 1)
			h[(int)1e5 + a[n - i + 1] - i]++;
	}

	int best = 0;
	for (int i = 1e5; i <= 2e5; i++)
		best = max(h[i], best);

	cout<<n - best<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define N (int)(1e5)
#define ll long long

ll n, dp[N + 1], occ[N + 1], a[N + 1];

int main()
{
	ios::sync_with_stdio(false);
	memset(occ, 0, sizeof(occ));

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		occ[a[i]]++;
	}

	dp[1] = occ[1];
	dp[2] = max(dp[1], 2*occ[2]);
	for (int i = 3; i <= N; i++)
		dp[i] = max(dp[i - 1], dp[i - 2] + i*occ[i]);

	cout<<dp[N]<<endl;
	return 0;
}
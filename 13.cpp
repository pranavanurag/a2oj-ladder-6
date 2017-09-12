#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll board[2001][2001], n;
ll profit[2001][2001], major_diag_sum[4001], minor_diag_sum[4001];

void precompute()
{
	memset(major_diag_sum, 0, sizeof(major_diag_sum));
	memset(minor_diag_sum, 0, sizeof(minor_diag_sum));

	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			major_diag_sum[i - j + n] += board[i][j],
			minor_diag_sum[i + j] += board[i][j];	

	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			profit[i][j] = major_diag_sum[i - j + n] + minor_diag_sum[i + j] - board[i][j];
}

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			cin>>board[i][j];

	precompute();

	ll best1 = -1, besti1, bestj1;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			if ((i + j)%2 == 0)
				if (best1 < profit[i][j])
					best1 = profit[i][j], besti1 = i, bestj1 = j;


	ll best2 = -1, besti2, bestj2;
	for (ll i = 1; i <= n; i++)
		for (ll j = 1; j <= n; j++)
			if ((i + j)%2 == 1)
				if (best2 < profit[i][j])
					best2 = profit[i][j], besti2 = i, bestj2 = j;

	cout<<best1 + best2<<endl;
	cout<<besti1<<" "<<bestj1<<" "<<besti2<<" "<<bestj2<<endl;

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll a[301][301], n, m, k;
vector <pair <ll, ll> > ans[(ll)(1e6)];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;

	ll covered = 0;

	for (ll i = 1; i <= n; i++)
		if (i%2)
		{
			for (ll j = 1; j <= m; j++)
			{
				a[i][j] = (covered*k)/(n*m) + 1;
				covered++;
			}
		}
		else
		{
			for (ll j = m; j >= 1; j--)
			{
				a[i][j] = (covered*k)/(n*m) + 1;
				covered++;
			}
		}

	for (ll i = 1; i <= n; i++)
		if (i%2)
		{
			for (ll j = 1; j <= m; j++)
				ans[a[i][j]].push_back(make_pair(i, j));
		}
		else
		{
			for (ll j = m; j >= 1; j--)
				ans[a[i][j]].push_back(make_pair(i, j));
		}

	for (ll x = 1; x <= k; x++)
	{
		cout<<ans[x].size()<<" ";
		for (auto p: ans[x])
			cout<<p.first<<" "<<p.second<<" ";
		cout<<endl;
	}

	return 0;
}
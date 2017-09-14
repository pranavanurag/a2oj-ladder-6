#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define sq(x) ((x)*(x))

ll solve(ll i, ll n)
{
	ll minxs = sq(n) - sq(i + 1);
	ll minx = sqrt(minxs) + 1;

	ll maxxs = sq(n) - sq(i);
	ll maxx = sqrt(maxxs);

	if (maxx >= minx)
		return 2*(maxx - minx) + 1;
	else
		return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;

	if (n == 0)
	{
		cout<<1<<endl;
		return 0;
	}

	ll ans = 4;
	for (int i = 1; i <= n - 1; i++)
		ans += 4*solve(i, n);
	cout<<ans<<endl;

	return 0;
}
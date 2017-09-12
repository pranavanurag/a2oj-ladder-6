#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX

ll n, l, r, ql, qr, w[100001], sum_pre[100001];

void pre()
{
	sum_pre[0] = 0;
	for (ll i = 1; i <= n; i++)
		sum_pre[i] = sum_pre[i - 1] + w[i];
}

ll sum_q(ll x, ll y)
{
	if (x > y)
		return 0;
	return sum_pre[y] - sum_pre[x - 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>l>>r>>ql>>qr;
	for (ll i = 1; i <= n; i++)
		cin>>w[i];

	pre();

	ll ans = INF;
	for (ll i = 0; i <= n/2; i++)
	{
		ll current = l*sum_q(1, i) + r*sum_q(n - i + 1, n);
		ll x = i + 1,  y = n - i;
		if (x <= y)
			current += min(l*sum_q(x, y) + (y - x)*ql, r*sum_q(x, y) + (y - x)*qr);
		ans = min(ans, current);
	}

	cout<<ans<<endl;
	return 0;
}
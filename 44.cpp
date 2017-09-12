#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod ((ll)(1e9) + 7)

ll ncrmod[1000001];

ll fast_exp_mod(ll x, ll a)
{
	ll ans = 1, current = x;
	while (a)
	{
		if (a%2 == 1)
			ans = (ans*current)%mod;
		a /= 2;
		current = (current*current)%mod;
	}
	return ans;
}

void pre_compute(ll n)
{
	ncrmod[0] = 1;
	for (ll i = 1; i <= n; i++)
		ncrmod[i] = (((ncrmod[i - 1]*(n - i + 1))%mod)*fast_exp_mod(i, mod - 2))%mod;
}

bool is_good(ll x, ll a, ll b)
{
	while (x > 0)
	{
		if (x%10 != a && x%10 != b)
			return 0;
		x /= 10;
	}
	return 1;
}

ll a, b, n;

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>a>>b>>n;

	pre_compute(n);
	ll ans = 0;

	for (ll x = 0; x <= n; x++)
	{
		ll sod = x*a + (n - x)*b;
		if (is_good(sod, a, b))
			ans = (ans + ncrmod[x])%mod;
	}

	cout<<ans<<endl;

	return 0;
}
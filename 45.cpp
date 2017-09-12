#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod ((ll)(1e9) + 9)

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

ll n, m, k;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;

	ll singles = min(m, (n - m)*(k - 1));
	ll cont = m - singles;
	ll ans = (((fast_exp_mod(2, (cont/k) + 1) + mod - 2)%mod)*k)%mod;

	ans = (ans + cont%k)%mod;
	ans = (ans + singles)%mod;

	cout<<ans<<endl;

	return 0;
}
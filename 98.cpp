#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod ((ll)1e9 + 7)

ll n;
map <ll, ll> cnt;
vector <ll> fac_mod;

void pre_calc()
{
	fac_mod.push_back(1);
	for (ll i = 1; i <= (ll)1e5; i++)
		fac_mod.push_back((i*fac_mod[i - 1])%mod);
}

ll fast_exp_mod(ll x, ll a)
{
	ll current = x, ans = 1;
	while (a > 0)
	{
		if (a%2 == 1)
			ans = (ans*current)%mod;

		current = (current*current)%mod;
		a /= 2;
	}
	return ans;
}

void prime_factorize(ll x)
{
	for (ll i = 2; i*i <= x; i++)
		while (x%i == 0)
		{
			cnt[i]++;
			x /= i;
		}

	if (x != 1)
		cnt[x]++;
}

ll ncr_mod(ll n, ll r)
{
	ll num = fac_mod[n];
	ll denom = (fac_mod[n - r]*fac_mod[r])%mod;
	return (num*fast_exp_mod(denom, mod - 2))%mod;
}

int main()
{
	ios::sync_with_stdio(false);
	pre_calc();

	cin>>n;
	for (ll i = 0; i < n; i++)
	{
		ll temp; cin>>temp;
		prime_factorize(temp);
	}

	ll ans = 1;
	for (auto it = cnt.begin(); it != cnt.end(); it++)
	{
		ll a = (*it).second;
		ans = (ans*ncr_mod(a + n - 1, n - 1))%mod;
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod ((ll)(1e9) + 7)

ll n, m;
vector <ll> a, lens, fac_mod;

ll fast_exp_mod(ll x, ll a)
{
	ll ans = 1, curr = x;
	while (a > 0)
	{
		if (a%2 == 1)
			ans = (ans*curr)%mod;
		a /= 2;
		curr = (curr*curr)%mod;
	}
	return ans;
}

void pre()
{
	fac_mod.push_back(1);
	for (ll i = 1; i <= 1000; i++)
		fac_mod.push_back((fac_mod[i - 1]*i)%mod);
}

ll sum_vec(vector <ll> &x)
{
	ll ans = 0;
	for (auto q: x)
		ans += q;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	pre();

	cin>>n>>m;
	for (int i = 0, temp; i < m && cin>>temp; i++)
		a.push_back(temp);

	sort(a.begin(), a.end());

	bool left_end = (a[0] == 1), right_end = (a[m - 1] == n);


	if (!left_end)
		lens.push_back(a[0] - 1);

	for (int i = 0; i < a.size() - 1; i++)
		if (a[i + 1] > a[i] + 1)
			lens.push_back(a[i + 1] - a[i] - 1);

	if (!right_end)
		lens.push_back(n - a[m - 1]);

	ll ans = fac_mod[sum_vec(lens)];
	for (auto len: lens)
		ans = (ans*fast_exp_mod(fac_mod[len], mod - 2))%mod;

	for (int i = 0; i < lens.size(); i++)
	{
		if (i == 0 && !left_end)
			continue;
		if (i == lens.size() - 1 && !right_end)
			continue;
		ans = (ans*fast_exp_mod(2, lens[i] - 1))%mod;
	}

	cout<<ans<<endl;
	return 0;
}
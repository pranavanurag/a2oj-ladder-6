/*input
5 2
0 0 1 1 1
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod ((ll)(1e9 + 7))

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

vector <ll> a;
set <ll> values;
map <ll, ll> my_hash;
ll sum = 0, n, x;

ll prime_power(ll q)
{
	ll ans = 0;
	while (q%x == 0)
		ans++, q /= x;
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>x;

	ll temp;
	for (ll i = 1; i <= n && cin>>temp; i++)
		a.push_back(temp), sum += temp;

	for (auto ax: a)
	{
		my_hash[sum - ax]++;
		values.insert(sum - ax);
	}

	ll ans = LONG_LONG_MAX;
	for (auto v: values)
		ans = min(ans, v + prime_power(my_hash[v]));

	ans = min(ans, sum);
	cout<<fast_exp_mod(x, ans)<<endl;
	return 0;
}
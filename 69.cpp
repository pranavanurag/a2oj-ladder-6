#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod ((ll)(1e9) + 7)

ll num(string s)
{
	ll ans = 0;
	for (int i = 0; i < s.size(); i++)
		ans = ((2*ans)%mod + (int)(s[i] - '0'))%mod;
	return ans;
}

ll fast_exp_mod(ll x, ll a)
{
	ll ans = 1, current = x;
	while (a > 0)
	{
		if (a%2 == 1)
			ans = (ans*current)%mod;
		a /= 2;
		current = (current*current)%mod;
	}
	return ans;
}

string x;

int main()
{
	ios::sync_with_stdio(false);
	cin>>x;
	cout<<(num(x)*fast_exp_mod(2, x.size() - 1))%mod<<endl;
	return 0;
}
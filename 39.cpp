/*input
1
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll a, ll b)
{
	ll y = min(a, b);
	ll x = max(a, b);

	if (y == 0)
		return x;
	else if (x%y == 0)
		return y;
	else
		return gcd(y, x%y);
}

ll lcm(ll x, ll y)
{
	return (x*y)/gcd(x, y);
}

ll lcm(ll x, ll y, ll z)
{
	return lcm(lcm(x, y), z);
}

int main()
{
	ios::sync_with_stdio(false);
	ll n;
	cin>>n;
	if (n == 1)
		cout<<1<<endl;
	else if (n == 2)
		cout<<2<<endl;
	else if (n == 3)
		cout<<6<<endl;
	else if (n%2 == 1)
		cout<<n*(n - 1)*(n - 2)<<endl;
	else if (n%2 == 0)
	{
		ll ans = (n - 1)*(n - 2)*(n - 3);
		for (int i = max((ll)1, n - 50); i <= n; i++)
			for (int j = max((ll)1, n - 50); j <= n; j++)
				for (int k = max((ll)1, n - 50); k <= n; k++)
					ans = max(ans, lcm(i, j, k));

		cout<<ans<<endl;
	}
	return 0;
}
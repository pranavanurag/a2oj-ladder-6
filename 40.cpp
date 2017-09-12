#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios::sync_with_stdio(false);
	ll a, b, ans = 0;
	cin>>a>>b;

	if (a < b)
		swap(a, b);
	while (a%b != 0)
	{
		ll x = max(a, b);
		ll y = min(a, b);

		ans += (x/y);
		a = y;
		b = x%y;
	}
	cout<<ans + (a/b)<<endl;
	return 0;
}
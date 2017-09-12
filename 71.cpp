#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll gcd(ll x, ll y)
{
	if (y == 0)
		return x;
	return gcd(y, x%y);
}
int main()
{
	ios::sync_with_stdio(false);
	ll a, b;
	cin>>a>>b;

	ll g = gcd(a, b);
	a = a/g;
	b = b/g;
	ll lcm = (a*b)/gcd(a, b);
	if (a < b)
	{
		if (lcm < a*(a + 1))
			cout<<"Masha"<<endl;
		else if (lcm > a*(a + 1))
			cout<<"Dasha"<<endl;
		else
			cout<<"Equal"<<endl;
	}
	else
	{
		if (lcm < b*(b + 1))
			cout<<"Dasha"<<endl;
		else if (lcm > b*(b + 1))
			cout<<"Masha"<<endl;
		else
			cout<<"Equal"<<endl;
	}
	return 0;
}
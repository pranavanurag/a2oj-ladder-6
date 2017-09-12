#include <bits/stdc++.h>

using namespace std;

#define ll long long

vector <ll> lucky_numbers;

ll my_stoi(string x)
{
	ll ans = 0;
	for (ll i = 0; i < x.length(); i++)
		ans = ans*10 + (ll)(x[i] - '0');
	return ans;
}

void gen_permutations(string current, ll i, ll n)
{
	lucky_numbers.push_back(my_stoi(current));
	if (i == n + 1)
		return;
	else
	{
		current = current + '4';
		gen_permutations(current, i + 1, n);
		current.pop_back();

		current = current + '7';
		gen_permutations(current, i + 1, n);
		current.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	gen_permutations("", 1, 11);
	sort(lucky_numbers.begin(), lucky_numbers.end());

	ll l, r;
	cin>>l>>r;

	ll ans = 0;
	for (ll i = 1; i < lucky_numbers.size() - 1; i++)
	{
		ll current = lucky_numbers[i],
			prev = lucky_numbers[i - 1],
			next = lucky_numbers[i + 1];

		ll x, y;

		if (current < l || prev >= r)
			continue;
	
		x = max(prev, l), y = min(current, r);

		// cout<<"current = "<<current<<", next = "<<next<<", prev = "<<prev<<", x = "<<x<<", y = "<<y<<endl;

		if (x == l && x != prev)
			ans += (y - x + 1)*current;
		else if (prev < r)
			ans += (y - x)*current;
	}
	
	cout<<ans<<endl;
	return 0;
}
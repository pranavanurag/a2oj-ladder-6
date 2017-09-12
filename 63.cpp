#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll number_of_digits(ll x) {
	ll ans = 0;
	while (x > 0)
		x /= 10, ans++;
	return ans;
}

ll first_digit(ll x){
	ll ans = x%10;
	while (x > 0)
		ans = x%10, x /= 10;
	return ans;
}

ll last_digit(ll x) {
	return x%10;
}

ll extract(ll x) {
	if (x < 100)
		return -1;
	x /= 10;
	return x%(ll)(pow(10, number_of_digits(x) - 1));
}

ll f(ll x) {
	if (x < 10)
		return x;

	ll ans = extract(x) + 1, middle = extract(x);
	if (last_digit(x) < first_digit(x))
		ans--;
	if (middle < 0)
		ans++;

	if (number_of_digits(x) >= 2)
		ans += (first_digit(x) - 1)*(ll)pow(10, number_of_digits(x) - 2);

	for (ll i = 0; i < number_of_digits(x) - 2; i++)
		ans += 9*(ll)(pow(10, i));
	
	ans += 9;
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	ll x, y;
	cin>>x>>y;
	cout<<f(y) - f(x - 1)<<endl;
	return 0;
}
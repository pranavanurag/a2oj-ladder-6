#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll n, d, ans = 0;
vector <ll> a;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>d;
	while (n--)
	{
		ll temp;
		cin>>temp;
		a.push_back(temp);
	}

	for (ll i = 0; i < a.size(); i++)
	{
		ll idx = upper_bound(a.begin(), a.end(), a[i] + d) - a.begin();
		idx--;
		if (idx > i + 1)
			ans += ((idx - i)*(idx - i - 1))/2;
	}

	cout<<ans<<endl;
	return 0;
}
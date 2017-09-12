#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod (ll)(1e9 + 7)

string s[101];
ll n, len;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>len;
	for (ll i = 1; i <= n; i++)
		cin>>s[i];


	ll ans = 1;
	for (ll j = 0; j < len; j++)
	{
		set <char> distinct_chars;
		for (ll i = 1; i <= n; i++)
			distinct_chars.insert(s[i][j]);
		ans = (ans*distinct_chars.size())%(mod);
	}

	cout<<ans<<endl;
	return 0;
}
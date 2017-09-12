#include <bits/stdc++.h>

using namespace std;

#define ll long long

int main()
{
	ios::sync_with_stdio(false);
	ll n, m, s;
	cin>>n>>m>>s;
	ll x = (n + s - 1)/s, y = (m + s - 1)/s;

	ll left1 = n - s*x + s,
		left2 = m - s*y + s;

	cout<<left1*left2*x*y<<endl;
	return 0;
}
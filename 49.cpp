#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N (ll)1e7

bool is_prime[N + 1];
vector <ll> pf;

void seive()
{
	for (ll i = 2; i <= N; i++)
		is_prime[i] = 1;
	for (ll i = 2; i*i <= N; i++)
		if (is_prime[i])
			for (ll j = i*i; j <= N; j += i)
				is_prime[j] = 0;
}

void prime_factorize(ll x)
{
	for (ll i = 2; i*i <= x; i++)
		if (is_prime[i] && x%i == 0)
		{
			ll y = x, j = i;
			while (y > 0 && y%j == 0)
				pf.push_back(i), j *= i;
		}
	sort(pf.begin(), pf.end());
}

bool check_prime(ll x)
{
	if (x <= N)
		return is_prime[x];
	for (ll i = 2; i*i <= x; i++)
		if (x%i == 0)
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	
	seive();

	ll q;
	cin>>q;

	if (check_prime(q) || q == 1)
		cout<<1<<endl<<0<<endl;
	else
	{
		prime_factorize(q);
		if (pf.size() == 1 || (pf.size() == 2 && pf[0]*pf[1] == q))
			cout<<2<<endl;
		else
			cout<<1<<endl<<pf[0]*pf[1]<<endl;		
	}
	return 0;
}
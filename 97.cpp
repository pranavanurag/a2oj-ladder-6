#include <bits/stdc++.h>

using namespace std;

#define ll long long

void add_to(multiset <ll>& k_set, multiset <ll>& other_set, ll x, ll k, ll &sum_set)
{
	if (k_set.size() < k)
		k_set.insert(x), sum_set += x;
	else if (k != 0 && x > *k_set.begin())
	{
		ll first = *k_set.begin();
		sum_set -= first;
		k_set.erase(k_set.begin());
		other_set.insert(first);
		k_set.insert(x);
		sum_set += x;
	}
	else
		other_set.insert(x);
}

void remove_from(multiset <ll>& k_set, multiset <ll>& other_set, ll x, ll k, ll &sum_set)
{
	if (other_set.find(x) != other_set.end())
		other_set.erase(other_set.find(x));
	else
	{
		k_set.erase(k_set.find(x));
		sum_set -= x;

		if (!other_set.empty())
		{
			ll last = *prev(other_set.end());
			k_set.insert(last);
			sum_set += last;
			other_set.erase(prev(other_set.end()));
		}
	}
}

ll n, len, k, a[100001];
multiset <ll> k_pos, k_neg, other_pos, other_neg;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>len;
	for (ll i = 1; i <= n; i++)
		cin>>a[i];
	cin>>k;

	ll sum_pos = 0, sum_neg = 0, total = 0;
	for (ll i = 1; i <= len; i++)
	{
		total += a[i];
		if (a[i] > 0)
			add_to(k_pos, other_pos, a[i], k, sum_pos);
		else if (a[i] < 0)
			add_to(k_neg, other_neg, -a[i], k, sum_neg);
	}

	ll ans = max(abs(total - 2*sum_pos), abs(total + 2*sum_neg));

	for (ll i = 2; i <= n - len + 1; i++)
	{
		ll going = a[i - 1], coming = a[i + len - 1];
		total = total - going + coming;
		if (coming > 0)
			add_to(k_pos, other_pos, coming, k, sum_pos);
		else if (coming < 0)
			add_to(k_neg, other_neg, -coming, k, sum_neg);

		if (going > 0)
			remove_from(k_pos, other_pos, going, k, sum_pos);
		else if (going < 0)
			remove_from(k_neg, other_neg, -going, k, sum_neg);

		ans = max(ans, max(abs(total - 2*sum_pos), abs(total + 2*sum_neg)));
	}

	cout<<ans<<endl;
	return 0;
}
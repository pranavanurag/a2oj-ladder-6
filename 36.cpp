#include <bits/stdc++.h>

using namespace std;

#define N 300000
#define ll long long

ll tree[4*N + 5], lazy[4*N + 5];

void propogate_lazy(ll i, ll tx1, ll tx2)
{
	tree[i] += (tx2 - tx1 + 1)*lazy[i];
	if (tx1 != tx2)
	{
		lazy[2*i] += lazy[i];
		lazy[2*i + 1] += lazy[i];
	}
	lazy[i] = 0;
}

void update_range(ll i, ll tx1, ll tx2, ll x1, ll x2, ll p)
{
	propogate_lazy(i, tx1, tx2);

	if (tx1 > tx2 || x1 > x2 || tx1 > x2 || tx2 < x1)
		return;1

	if (tx1 >= x1 && tx2 <= x2)
	{
		tree[i] += (tx2 - tx1 + 1)*p;
		if (tx1 != tx2)
			lazy[2*i] += p, lazy[2*i + 1] += p;
		return;
	}

	ll txm = (tx1 + tx2)/2;
	update_range(2*i, tx1, txm, x1, x2, p);
	update_range(2*i + 1, txm + 1, tx2, x1, x2, p);
	tree[i] = tree[2*i] + tree[2*i + 1];
}

void remove_el(ll i, ll tx1, ll tx2, ll x)
{
	propogate_lazy(i, tx1, tx2);

	if (tx1 > tx2 || tx1 > x || tx2 < x)
		return;

	if (tx1 == x && tx2 == x)
	{
		tree[i] = 0;
		return;
	}

	ll txm = (tx1 + tx2)/2;
	remove_el(2*i, tx1, txm, x);
	remove_el(2*i + 1, txm + 1, tx2, x);
	tree[i] = tree[2*i] + tree[2*i + 1];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cout<<fixed;

	memset(tree, 0, sizeof(tree));
	memset(lazy, 0, sizeof(lazy));

	ll t, n = 1;
	cin>>t;
	while (t--)
	{
		ll type;
		cin>>type;
		if (type == 1)
		{
			ll a, x;
			cin>>a>>x;
			update_range(1, 1, N, 1, a, x);
		}
		else if (type == 2)
		{
			ll k;
			cin>>k;
			n++;
			update_range(1, 1, N, n, n, k);
		}
		else
		{
			remove_el(1, 1, N, n);
			n--;
		}
		cout<<((long double)tree[1])/((long double)(n))<<endl;
	}
	return 0;
}
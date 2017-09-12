#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX

ll n, k, a[100001], sum_pre[100001];

void pre()
{
	sum_pre[0] = 0;
	for (ll i = 1; i <= n; i++)
		sum_pre[i] = sum_pre[i - 1] + a[i];
}

ll sum_q(ll l, ll r)
{
	return sum_pre[r] - sum_pre[l - 1];
}

ll can(ll len)
{
	for (ll i = len; i <= n; i++)
		if (len*a[i] - sum_q(i - len + 1, i) <= k)
			return a[i];
	return -INF;	
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for (ll i = 1; i <= n; i++)
		cin>>a[i];

	sort(a + 1, a + n + 1);
	pre();

	ll low = 1, high = n, mid = low + (high - low + 1)/2;
	while (low < high)
	{
		if (can(mid) != -INF)
			low = mid;
		else
			high = mid - 1;
		mid = low + (high - low + 1)/2;
	}

	cout<<mid<<" "<<can(mid)<<endl;
	return 0;
}
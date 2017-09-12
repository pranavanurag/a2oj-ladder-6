#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll pre[(int)(1e6)], suf[(int)(1e6)];
int n, a[(int)(1e6)];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	pre[0] = 0;
	for (int i = 1; i <= n; i++)
		pre[i] = pre[i - 1] + a[i];
	suf[n + 1] = 0;
	for (int i = n; i >= 1; i--)
		suf[i] = suf[i + 1] + a[i];

	ll sum = pre[n];
	if (sum%3)
		cout<<"0\n";
	else
	{
		ll ans = 0;
		vector <int> hashpre, hashsuf;
		for (int i = 1; i <= n; i++)
		{
			if (pre[i] == sum/3)
				hashpre.push_back(i);
			if (suf[i] == sum/3)
				hashsuf.push_back(i);
		}

		for (auto p: hashpre)
			ans += hashsuf.size() - (upper_bound(hashsuf.begin(), hashsuf.end(), p + 1) - hashsuf.begin());
		cout<<ans<<endl;
	}
	return 0;
}
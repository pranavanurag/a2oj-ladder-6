#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll sum_pre[100001];
int n;

ll sum_q(int l, int r)
{
	return sum_pre[r] - sum_pre[l - 1];
}

int main()
{
	sum_pre[0] = 0;
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		int temp;
		cin>>temp;
		sum_pre[i] = sum_pre[i - 1] + temp;
	}

	int ans = 0;
	for (int i = 1; i <= n - 1; i++)
		if (sum_q(1, i) == sum_q(i + 1, n))
			ans++;

	cout<<ans<<endl;
	return 0;
}
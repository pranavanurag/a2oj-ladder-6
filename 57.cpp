#include <bits/stdc++.h>

using namespace std;

int n, a[100001];

int sum(int skip, int start)
{
	int ans = 0;
	for (int i = start; i <= n; i += skip)
		ans += a[i];
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1; i <= n; i++)
		cin>>a[i];

	bool ans = 0;
	for (int i = 1; i*i <= n; i++)
	{
		if (n%i == 0)
		{
			if (i >= 3)
			{
				for (int start = 1; start <= n/i; start++)
					if (sum(n/i, start) == i)
						ans = 1;
			}
			if (n/i >= 3)
			{
				for (int start = 1; start <= i; start++)
					if (sum(i, start) == n/i)
						ans = 1;
			}
		}
	}

	if (ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
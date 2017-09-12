#include <bits/stdc++.h>

using namespace std;

long long a[4001], target, n, pre_sum[4001];

void pre()
{
	pre_sum[0] = 0;
	for (long long i = 1; i <= n; i++)
		pre_sum[i] = pre_sum[i - 1] + a[i];
}

long long sum_q(long long x1, long long x2)
{
	return pre_sum[x2] - pre_sum[x1 - 1];
}

map <long long, long long> sum_hash;

void hash_it()
{
	for (long long x1 = 1; x1 <= n; x1++)
		for (long long x2 = x1; x2 <= n; x2++)
			sum_hash[sum_q(x1, x2)]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>target>>s;
	n = s.size();
	for (long long i = 0; i < n; i++)
		a[i + 1] = (long long)(s[i] - '0');

	pre();
	hash_it();

	long long ans = 0;
	if (target != 0)
	{	
		for (long long x1 = 1; x1 <= n; x1++)
				for (long long x2 = x1; x2 <= n; x2++)
					if (sum_q(x1, x2) != 0)
						if (target%sum_q(x1, x2) == 0)
							ans += sum_hash[target/sum_q(x1, x2)];
	}
	else
		ans = sum_hash[0]*n*(n + 1) - pow(sum_hash[0], 2);

	cout<<ans<<endl;
	return 0;
}
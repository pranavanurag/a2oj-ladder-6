#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define N (ll)1e7

int spf[N + 1], count_num[N + 1], count_den[N + 1];
int n, m;
int a[(int)1e5 + 1], b[(int)1e5 + 1];
int ans_num[(int)1e5 + 1], ans_den[(int)1e5 + 1];

void pre_calc()
{
	for (ll i = 2; i <= N; i++)
		spf[i] = -1;
	for (ll i = 2; i <= N; i++)
		if (spf[i] == -1)
		{
			spf[i] = i;
			for (ll j = i*i; j <= N; j += i)
				spf[j] = i;
		}
}

vector <int> prime_factorize(int x)
{
	vector <int> ans;
	while (x > 1)
	{
		ans.push_back(spf[x]);
		x /= spf[x];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	pre_calc();

	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		for (auto factor: prime_factorize(a[i]))
			count_num[factor]++;
	}
	for (int i = 1; i <= m; i++)
	{
		cin>>b[i];
		for (auto factor: prime_factorize(b[i]))
			count_den[factor]++;
	}
	
	for (int i = 1; i <= n; i++)
	{
		int ans = 1;
		while (a[i] > 1)
		{
			int f = spf[a[i]];
			if (count_den[f])
				count_den[f]--;
			else
				ans *= f;

			a[i] /= f;
		}
		ans_num[i] = ans;
	}

	for (int i = 1; i <= m; i++)
	{
		int ans = 1;
		while (b[i] > 1)
		{
			int f = spf[b[i]];
			if (count_num[f])
				count_num[f]--;
			else
				ans *= f;

			b[i] /= f;
		}
		ans_den[i] = ans;
	}

	cout<<n<<" "<<m<<endl;
	for (int i = 1; i <= n; i++)
		cout<<ans_num[i]<<" ";
	cout<<endl;
	for (int i = 1; i <= m; i++)
		cout<<ans_den[i]<<" ";
	cout<<endl;
	return 0;
}
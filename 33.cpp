#include <bits/stdc++.h>

using namespace std;

#define INF (int)1e9

int n, m, x, y, a[1001], memo[1001][2];
int sum_pre[1001];

void init()
{
	memset(a, 0, sizeof(a));
	for (int i = 0; i <= 1000; i++)
		for (int j = 0; j <= 1; j++)
			memo[i][j] = -1;
}

void pre_calc()
{
	sum_pre[0] = 0;
	for (int i = 1; i <= m; i++)
		sum_pre[i] = sum_pre[i - 1] + a[i];
}

int dp(int i, int c)
{
	if (i == m + 1)
		return 0;		
	else if (memo[i][c] > -1)
		return memo[i][c];
	else
	{
		memo[i][c] = INF;
		if (c == 0)
			for (int j = i + x - 1; j <= i + y - 1 && j <= m; j++)
				memo[i][c] = min(memo[i][c], dp(j + 1, 1) + sum_pre[j] - sum_pre[i - 1]);
		else
			for (int j = i + x - 1; j <= i + y - 1 && j <= m; j++)
				memo[i][c] = min(memo[i][c], dp(j + 1, 0) + n*(j - i + 1) - (sum_pre[j] - sum_pre[i - 1]));
		return memo[i][c];
	}
}

int main()
{
	ios::sync_with_stdio(false);

	init();

	cin>>n>>m>>x>>y;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin>>s;
		for (int i = 0; i < m; i++)
			if (s[i] == '#')
				a[i + 1]++;
	}

	pre_calc();

	cout<<min(dp(1, 0), dp(1, 1))<<endl;

	return 0;
}
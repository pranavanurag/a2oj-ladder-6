#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[51][51];
bool vis[51][51];

void dfs(int i, int j)
{
	if (i < n && a[i + 1][j])
	{
		if (!vis[i + 1][j])
			vis[i + 1][j] = 1, dfs(i + 1, j);
	}
	if (i > 1 && a[i - 1][j])
	{
		if (!vis[i - 1][j])
			vis[i - 1][j] = 1, dfs(i - 1, j);
	}
	if (j < m && a[i][j + 1])
	{
		if (!vis[i][j + 1])
			vis[i][j + 1] = 1, dfs(i, j + 1);
	}
	if (j > 1 && a[i][j - 1])
	{
		if (!vis[i][j - 1])
			vis[i][j - 1] = 1, dfs(i, j - 1);
	}
}

bool is_connected()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			vis[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] && !vis[i][j])
			{
				vis[i][j] = 1;
				dfs(i, j);
				
				for (int i = 1; i <= n; i++)
					for (int j= 1; j <= m; j++)
						if (a[i][j] && !vis[i][j])
							return 0;
				return 1;
			}
}

int colored()
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans += a[i][j];
	return ans;
}

void display()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i = 1; i <= n; i++)
	{
		string temp;
		cin>>temp;
		for (int j = 0; j < m; j++)
			a[i][j + 1] = (temp[j] == '#');
	}

	if (colored() < 2)
	{
		cout<<-1<<endl;
		return 0;
	}
	else if (!is_connected())
	{
		cout<<0<<endl;
		return 0;
	}
	else
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (a[i][j])
				{
					a[i][j] = 0;
					if (!is_connected())
					{
						cout<<1<<endl;
						return 0;
					}
					a[i][j] = 1;
				}		
	}
	if (colored() > 2)
		cout<<2<<endl;
	else
		cout<<-1<<endl;
	return 0;
}
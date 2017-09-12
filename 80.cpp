#include <bits/stdc++.h>

using namespace std;

int a[1001][1001];
vector <int> ans;

void swap_row(int r1, int r2, int n)
{
	vector <int> row1, row2;
	for (int j = 1; j <= n; j++)
		row1.push_back(a[r1][j]), row2.push_back(a[r2][j]);
	for (int j = 1; j <= n; j++)
		a[r1][j] = row2[j - 1], a[r2][j] = row1[j - 1];
}

void swap_column(int c1, int c2, int n)
{
	vector <int> column1, column2;
	for (int i = 1; i <= n; i++)
		column1.push_back(a[i][c1]), column2.push_back(a[i][c2]);
	for (int i = 1; i <= n; i++)
		a[i][c1] = column2[i - 1], a[i][c2] = column1[i - 1];
}

bool has_one(int r, int n)
{
	for (int j = 1; j <= n; j++)
		if (a[r][j] == 1)
			return 1;
	return 0;
}

bool has_no_one(int c, int n)
{
	for (int i = 1; i <= n; i++)
		if (a[i][c] == 1)
			return 0;
	return 1;
}

void do_it(int n)
{
	if (n == 1)
		return;

	for (int c = 1; c < n; c++)
		if (has_no_one(c, n))
		{
			ans.push_back(2), ans.push_back(c), ans.push_back(n);
			swap_column(c, n, n);
			break;
		}

	for (int r = 1; r < n; r++)
		if (has_one(r, n))
		{
			ans.push_back(1), ans.push_back(r), ans.push_back(n);
			swap_row(r, n, n);
			break;
		}

	do_it(n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i = 1; i <= n - 1; i++)
	{
		int x, y;
		cin>>x>>y;
		a[x][y] = 1;
	}
	do_it(n);
	cout<<ans.size()/3<<endl;
	for (int i = 0; i < ans.size(); i += 3)
		cout<<ans[i]<<" "<<ans[i + 1]<<" "<<ans[i + 2]<<endl;
	return 0;
}
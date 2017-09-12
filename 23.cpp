#include <bits/stdc++.h>

using namespace std;

string temp[501];
int grid[501][501];
int n, m, k, counter = 0, cells = 0;
bool visited[501][501];

bool can_recurse(int i, int j)
{
	if (i > n || j > m || i < 1 || j < 1)
		return 0;
	else
		return (grid[i][j] == 1 && !visited[i][j]);
}

void wall_everything_else()
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (grid[i][j] == 1 && !visited[i][j])
				grid[i][j] = -1;
}

void dfs(int i, int j)
{
	counter++;

	if (counter == cells - k)
		wall_everything_else();

	if (can_recurse(i + 1, j))
		visited[i + 1][j] = 1, dfs(i + 1, j);
	if (can_recurse(i, j + 1))
		visited[i][j + 1] = 1, dfs(i, j + 1);
	if (can_recurse(i - 1, j))
		visited[i - 1][j] = 1, dfs(i - 1, j);
	if (can_recurse(i, j - 1))
		visited[i][j - 1] = 1, dfs(i, j - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	for (int i = 0; i < n; i++)
		cin>>temp[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (temp[i][j] == '.')
			{
				grid[i + 1][j + 1] = 1;
				cells++;
			}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (grid[i][j] && !visited[i][j])
				visited[i][j] = 1, dfs(i, j);

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			if (grid[i][j] == 1)
				cout<<".";
			else if (grid[i][j] == 0)
				cout<<"#";
			else
				cout<<"X";
		cout<<endl;
	}
	return 0;
}
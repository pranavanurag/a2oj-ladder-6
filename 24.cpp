#include <bits/stdc++.h>

using namespace std;

int n;
bool visited[1001][1001], ispt[1001][1001];
vector <int> adj_x[1001], adj_y[1001];

void dfs(int x, int y)
{
	for (auto vy: adj_y[x])
		if (!visited[x][vy])
			visited[x][vy] = 1, dfs(x, vy);

	for (auto vx: adj_x[y])
		if (!visited[vx][y])
			visited[vx][y] = 1, dfs(vx, y);
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int tx, ty;
		cin>>tx>>ty;
		ispt[tx][ty] = 1;
		adj_x[ty].push_back(tx);
		adj_y[tx].push_back(ty);
	}

	int ans = 0;
	for (int i = 1; i <= 1000; i++)
		for (int j = 1; j <= 1000; j++)
			if (ispt[i][j] && !visited[i][j])
				ans++, visited[i][j] = 1, dfs(i, j);

	cout<<ans - 1<<endl;
	return 0;
}
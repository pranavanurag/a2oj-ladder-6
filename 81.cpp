#include <bits/stdc++.h>

using namespace std;

map <int, vector <int> > adj;
set <int> cities;
map <int, bool> visited;

void dfs(int u)
{
	cout<<u<<" ";
	for (auto v: adj[u])
		if (!visited[v])
			visited[v] = 1, dfs(v);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		cities.insert(x);
		cities.insert(y);
	}

	int start;
	for (auto c: cities)
		if (adj[c].size() == 1)
			start = c;

	visited[start] = 1;
	dfs(start);
	return 0;
}
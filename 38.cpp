#include <bits/stdc++.h>

using namespace std;

int n;
vector <int> adj[100001];
bool visited[100001], flip[100001], init[100001], goal[100001];

void dfs(int u)
{
	flip[u] = goal[u]^init[u];
	for (auto v: adj[u])
		if (!visited[v])
		{
			visited[v] = 1, dfs(v);
			for (auto gv: adj[v])
				if (flip[gv] && flip[u] && u != gv)
					flip[gv] = 0;
				else if (!flip[gv] && flip[u] && u != gv)
					flip[gv] = 1;
		}
}

int main()
{
	ios::sync_with_stdio(false);

	memset(visited, 0, sizeof(visited));

	cin>>n;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		cin>>init[i];
	for (int i = 1; i <= n; i++)
		cin>>goal[i];

	visited[1] = 1;
	dfs(1);
	
	vector <int> ans;
	for (int i = 1; i <= n; i++)
		if (flip[i])
			ans.push_back(i);

	cout<<ans.size()<<endl;
	for (auto u: ans)
		cout<<u<<endl;
	return 0;
}
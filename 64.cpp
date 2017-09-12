#include <bits/stdc++.h>

using namespace std;

int child[1001], parent[1001], val[1001][1001];
int n, m;
vector <int> ans_v;

int main()
{
	ios::sync_with_stdio(false);

	memset(parent, -1, sizeof parent);
	memset(child, -1, sizeof child);

	cin>>n>>m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, x;
		cin>>u>>v>>x;
		child[u] = v, parent[v] = u, val[u][v] = x;
	}

	for (int i = 1; i <= n; i++)
	{
		if (parent[i] == -1 && child[i] != -1)
		{
			int u = i, ans = INT_MAX;
			while (child[u] != -1)
			{
				ans = min(ans, val[u][child[u]]);
				u = child[u];
			}
			ans_v.push_back(i), ans_v.push_back(u), ans_v.push_back(ans);
		}
	}

	cout<<ans_v.size()/3<<endl;
	for (int i = 0; i < ans_v.size(); i += 3)
		cout<<ans_v[i]<<" "<<ans_v[i + 1]<<" "<<ans_v[i + 2]<<endl;
	return 0;
}
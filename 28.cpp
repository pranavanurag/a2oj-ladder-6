#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mod (ll)(1e9 + 7)

vector <ll> adj[100001], adj_t[100001];
ll n, costs[100001], m, fintime[100001];
ll t = 0;
bool visited[100001];
map <ll, ll> fintimevsnode;
vector <ll> comp;

ll ans1 = 0, ans2 = 1;

void dfs1(ll u)
{
	t++;
	
	for (auto v: adj[u])
		if (!visited[v])
			visited[v] = 1, dfs1(v);

	fintime[u] = ++t;
	fintimevsnode[t] = u;
}

void dfs2(ll u)
{
	comp.push_back(u);
	for (auto v: adj_t[u])
		if (!visited[v])
			visited[v] = 1, dfs2(v);
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (ll i = 1; i <= n; i++)
		cin>>costs[i];

	cin>>m;
	while (m--)
	{
		ll u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj_t[v].push_back(u);
	}

	for (ll u = 1; u <= n; u++)
		if (!visited[u])
			visited[u] = 1, dfs1(u);

	sort(fintime + 1, fintime + n + 1);

	memset(visited, 0, sizeof(visited));
	for (ll i = n; i >= 1; i--)
	{
		ll u = fintimevsnode[fintime[i]];
		if (!visited[u])
		{
			comp.clear(), visited[u] = 1, dfs2(u);

			ll local_min = (ll)1e9, local_number_of_mins = 0;
			for (auto u: comp)
				local_min = min(local_min, costs[u]);

			for (auto u: comp)
			{
				if (costs[u] == local_min)
					local_number_of_mins++;
			}

			ans1 += local_min;
			ans2 = (ans2%mod*local_number_of_mins%mod)%mod;
			
		}
	}

	cout<<ans1<<" "<<ans2<<endl;
	return 0;
}
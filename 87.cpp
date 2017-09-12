#include <bits/stdc++.h>

using namespace std;

#define N 200

vector <int> adj[N + 1];
int comp[N + 1], n, indegree[N + 1], indegree1[N + 1];
queue <int> qs[4];

int process_queue(queue <int> &q)
{
	int ans = 0;
	while (!q.empty())
		{
			int u = q.front();
			q.pop();
			ans++;

			for (int v: adj[u])
				if (--indegree[v] == 0)
					qs[comp[v]].push(v);
		}
	return ans;
}

bool all_empty()
{
	return (qs[0].empty() && qs[1].empty() && qs[2].empty());
}

int get_ans(int start)
{
	int ans = 0;

	for (int i = 1; i <= n; i++)
		if (indegree[i] == 0)
			qs[comp[i]].push(i);

	while (!all_empty())
	{
		ans += process_queue(qs[start]);
		if (all_empty())
			return ans;

		ans++;
		ans += process_queue(qs[(start + 1)%3]);
		if (all_empty())
			return ans;

		ans++;
		ans += process_queue(qs[(start + 2)%3]);
		if (all_empty())
			return ans;

		ans++;
	}


	return ans;
}

void reset()
{
	for (int i = 1; i <= n; i++)
		indegree[i] = indegree1[i];
}

int main()
{
	ios::sync_with_stdio(false);
	memset(indegree, 0, sizeof indegree);

	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>comp[i];
		comp[i]--;
	}
	for (int i = 1, k; i <= n && cin>>k; i++)
		for (int j = 0, v; j < k && cin>>v; j++)
			adj[v].push_back(i), indegree[i]++, indegree1[i]++;

	int ans0 = get_ans(0);
	reset();
	int ans1 = get_ans(1);
	reset();
	int ans2 = get_ans(2);

	cout<<min(ans0, min(ans1, ans2))<<endl;
	return 0;
}
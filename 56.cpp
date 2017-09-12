#include <bits/stdc++.h>

using namespace std;

#define pii pair <int, int> 

pii source, target;
map <pii, bool> visited;
map <pii, int> level;
vector <pii> seg;

bool allowed(pii u)
{
	return binary_search(seg.begin(), seg.end(), u);
}

vector <pii> neighbours(pii u)
{
	int x = u.first, y = u.second;
	vector <pii> ans;
	ans.push_back(make_pair(x + 1, y - 1));
	ans.push_back(make_pair(x + 1, y));
	ans.push_back(make_pair(x + 1, y + 1));
	ans.push_back(make_pair(x, y + 1));
	ans.push_back(make_pair(x - 1, y + 1));
	ans.push_back(make_pair(x - 1, y));
	ans.push_back(make_pair(x - 1, y - 1));
	ans.push_back(make_pair(x, y - 1));
	return ans;
}

queue <pii> q;
void bfs()
{
	visited[source] = 1;
	level[source] = 0;
	q.push(source);

	while (!q.empty())
	{
		pii u = q.front();
		q.pop();
		for (auto v: neighbours(u))
			if (allowed(v) && !visited[v])
				visited[v] = 1, level[v] = level[u] + 1, q.push(v);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>source.first>>source.second>>target.first>>target.second;
	int t;
	cin>>t;
	while (t--)
	{
		int x, y1, y2;
		cin>>x>>y1>>y2;
		for (int i = y1; i <= y2; i++)
			seg.push_back(make_pair(x, i));
	}

	sort(seg.begin(), seg.end());

	bfs();
	if (!visited[target])
		cout<<"-1"<<endl;
	else
		cout<<level[target]<<endl;
	return 0;
}
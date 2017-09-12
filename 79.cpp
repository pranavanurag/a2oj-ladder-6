#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > src;
int dist[2001][2001], n, m;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	ios::sync_with_stdio(false);
	fin>>n>>m;
	int k;
	fin>>k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		fin>>x>>y;
		src.push_back(make_pair(x, y));
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j] = INT_MAX;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (auto pt: src)
				dist[i][j] = min(dist[i][j], abs(pt.first - i) + abs(pt.second - j));

	int ansi = -1, ansj = -1, max_dist = -1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (max_dist < dist[i][j])
				ansi = i, ansj = j, max_dist = dist[i][j];

	fout<<ansi<<" "<<ansj<<endl;
	return 0;
}
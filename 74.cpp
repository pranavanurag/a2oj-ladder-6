#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000][1000];
bool visited[1000][1000];
int state[1000][1000], seq_length[1000][1000] = {{0}};
bool active[1000][1000];
map <char, int> lookup;
bool loop = 0;

vector <pair <int, int> > neighbours(int i, int j)
{
	vector <pair <int, int> > ans;
	int next = (a[i][j] + 1)%4;
	if (i < n - 1 && a[i + 1][j] == next)
		ans.push_back(make_pair(i + 1, j));
	if (j < m - 1 && a[i][j + 1] == next)
		ans.push_back(make_pair(i, j + 1));
	if (i > 0 && a[i - 1][j] == next)
		ans.push_back(make_pair(i - 1, j));
	if (j > 0 && a[i][j - 1] == next)
		ans.push_back(make_pair(i, j - 1));
	return ans;
}

void dfs_loop_check(int i, int j, int current_state)
{
	active[i][j] = 1;
	for (auto v: neighbours(i, j))
	{
		int vi = v.first, vj = v.second;
		if (state[vi][vj] == state[i][j] && active[vi][vj])
		{
			loop = 1;
			return;
		}
		else if (state[vi][vj] == -1)
		{
			state[vi][vj] = state[i][j];
			dfs_loop_check(vi, vj, current_state);
		}
	}
	active[i][j] = 0;
}

void loop_check()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			state[i][j] = -1;

	int s = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (state[i][j] == -1)
			{
				state[i][j] = s;
				dfs_loop_check(i, j, s);
				s++;
			}
}

void dfs(int ui, int uj)
{
	active[ui][uj] = 1;
	seq_length[ui][uj] = 1;
	for (auto v: neighbours(ui, uj))
	{
		int vi = v.first, vj = v.second;
		if (!visited[vi][vj])
			visited[vi][vj] = 1, dfs(vi, vj);
		if (!active[vi][vj])
			seq_length[ui][uj] = max(seq_length[ui][uj], seq_length[vi][vj] + 1);
	}
	active[ui][uj] = 0;
}

int find_ans()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			seq_length[i][j] = INT_MIN, visited[i][j] = 0, active[i][j] = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!visited[i][j] && a[i][j] == 0)
			{
				visited[i][j] = 1;
				dfs(i, j);
			}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			ans = max(ans, seq_length[i][j]);
	return ans/4;
}

int main()
{
	ios::sync_with_stdio(false);

	lookup['D'] = 0;
	lookup['I'] = 1;
	lookup['M'] = 2;
	lookup['A'] = 3;

	cin>>n>>m;
	for (int i = 0; i < n; i++)
	{
		string temp;
		cin>>temp;
		for (int j = 0; j < m; j++)
			a[i][j] = lookup[temp[j]];
	}

	loop_check();

	if (loop)
		cout<<"Poor Inna!"<<endl;
	else
	{
		int ans = find_ans();
		if (ans == 0)
			cout<<"Poor Dima!"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
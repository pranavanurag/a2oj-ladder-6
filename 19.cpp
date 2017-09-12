#include <bits/stdc++.h>

using namespace std;

#define noderef(balance, prev_weight, level) graph[balance + 10][prev_weight][level]

vector <int> weights;
int m;
vector <int> ans;

struct node
{
	int parent_balance, parent_prev_weight, parent_level;
	bool visited;

	node()
	{
		parent_balance = -1;
		parent_prev_weight = -1;
		parent_level = -1;
		visited = 0;
	}
} graph[21][11][1001];

void backtrack(int balance, int prev_weight, int level)
{
	while (level > 0)
	{
		ans.push_back(prev_weight);
		node u = noderef(balance, prev_weight, level);
		balance = u.parent_balance;
		prev_weight = u.parent_prev_weight;
		level--;
	}
}

void dfs(int balance, int prev_weight, int level)
{
	if (level > m)
		return;

	if (level == m)
	{
		backtrack(balance, prev_weight, level);
		return;
	}

	for (auto w: weights)
	{
		int new_balance = balance + pow(-1, level)*w;
		if (!noderef(new_balance, w, level + 1).visited && w != prev_weight && balance*new_balance < 0)
		{
			//set parent pointer for backtracking
			noderef(new_balance, w, level + 1).parent_balance = balance;
			noderef(new_balance, w, level + 1).parent_prev_weight = prev_weight;
			noderef(new_balance, w, level + 1).parent_level = level;

			noderef(new_balance, w, level + 1).visited = 1;
			
			dfs(new_balance, w, level + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	string temp;
	cin>>temp>>m;
	for (int i = 0; i < 10; i++)
		if (temp[i] == '1')
			weights.push_back(i + 1);

	for (auto w: weights)
	{
		noderef(w, w, 1).visited = 1;
		dfs(w, w, 1);
	}

	if (ans.size())
	{
		cout<<"YES"<<endl;
		for (int i = m - 1; i >= 0; i--)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	else
		cout<<"NO"<<endl;

	return 0;
}
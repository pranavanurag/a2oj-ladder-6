#include <bits/stdc++.h>

using namespace std;

int ans = 0;
string s, name[1001];
vector <string> x;
vector <int> adj[1001];
map <string, int> csc;

bool is_punctuation(string x)
{
	return (x == ":" || x == "." || x == ",");
}

void dfs(int u)
{
	ans += csc[name[u]];
	csc[name[u]]++;
	for (auto v: adj[u])
		dfs(v);
	csc[name[u]]--;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>s;

	string curr = "";
	for (int i = 0; i < s.size(); i++)
		if (!is_punctuation(string(1, s[i])))
			curr += s[i];
		else if (curr.size())
		{
			x.push_back(curr);
			x.push_back(string(1, s[i]));
			curr = "";
		}
		else
			x.push_back(string(1, s[i]));

	for (int i = 0; i < x.size(); i++)
		if (!is_punctuation(x[i]))
			name[i] = x[i];

	stack <int> current;
	current.push(0);
	for (int i = 1; i < x.size(); i++)
	{
		if (x[i] == ":" || x[i] == ",")
			continue;
		else if (x[i] == ".")
			current.pop();
		else
		{
			int u = current.top();
			adj[u].push_back(i);
			current.push(i);
		}
	}

	dfs(0);
	cout<<ans<<endl;
	return 0;
}
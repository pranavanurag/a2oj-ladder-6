#include <bits/stdc++.h>

using namespace std;

string s;
stack <pair <char, int> > st;
vector <pair <int, int> > ans;
int closing_idx[100000];

int find_ans(int l, int r)
{
	int local_ans = 0;
	for (int i = l; i <= r; i++)
		if (s[i] == '[')
			local_ans++;
	return local_ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>s;

	memset(closing_idx, -1, sizeof closing_idx);

	for (int i = 0; i < s.size(); i++)
	{
		if (st.empty() && (s[i] == ']' || s[i] == ')'))
			continue;
		else if (s[i] == '(' || s[i] == '[')
			st.push(make_pair(s[i], i));
		else if (s[i] == ')' && st.top().first == '(')
		{
			auto x = st.top();
			closing_idx[x.second] = i;
			st.pop();
		}
		else if (s[i] == ']' && st.top().first == '[')
		{
			auto x = st.top();
			closing_idx[x.second] = i;
			st.pop();
		}
		else
		{
			while (!st.empty())
				st.pop();
		}
	}

	int ansl = -1, ansr = -1, best = 0;
	for (int i = 0; i < s.size(); i++)
		if (closing_idx[i] != -1)
		{
			int l = i, r = closing_idx[i], current = 0;
			while (r + 1 < s.size() && closing_idx[r + 1] != -1)
				r = closing_idx[r + 1];
			if (find_ans(l, r) > best)
			{
				best = find_ans(l, r);
				ansl = l, ansr = r;
			}
			i = r;
		}

	if (ansl == -1 || ansr == -1)
		cout<<0<<endl<<endl;
	else
	{
		cout<<best<<endl;
		for (int i = ansl; i <= ansr; i++)
			cout<<s[i];
		cout<<endl;
	}
	return 0;
}
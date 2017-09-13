#include <bits/stdc++.h>

using namespace std;

set <string> perms;

string make_string(string x, int i, int j, int k, int l, int m, int n)
{
	return string(1, x[i - 1]) + string(1, x[j - 1]) + string(1, x[k - 1]) + string(1, x[l - 1]) + string(1, x[m - 1]) + string(1, x[n - 1]);
}

set <string> make_rotations(string x)
{
	set <string> ans;
	ans.insert(make_string(x, 1, 2, 3, 4, 5, 6));
	ans.insert(make_string(x, 6, 2, 5, 4, 1, 3));
	ans.insert(make_string(x, 3, 2, 1, 4, 6, 5));
	ans.insert(make_string(x, 5, 2, 6, 4, 3, 1));
	ans.insert(make_string(x, 1, 4, 3, 2, 5, 6));
	ans.insert(make_string(x, 6, 4, 5, 2, 1, 3));
	ans.insert(make_string(x, 3, 4, 1, 2, 6, 5));
	ans.insert(make_string(x, 5, 4, 6, 2, 3, 1));

	ans.insert(make_string(x, 4, 3, 2, 1, 5, 6));
	ans.insert(make_string(x, 6, 3, 5, 1, 4, 2));
	ans.insert(make_string(x, 2, 3, 4, 1, 6, 5));
	ans.insert(make_string(x, 5, 3, 6, 1, 2, 4));
	ans.insert(make_string(x, 4, 1, 2, 3, 5, 6));
	ans.insert(make_string(x, 6, 1, 5, 3, 4, 2));
	ans.insert(make_string(x, 2, 1, 4, 3, 6, 5));
	ans.insert(make_string(x, 5, 1, 6, 3, 2, 4));

	ans.insert(make_string(x, 1, 6, 3, 5, 2, 4));
	ans.insert(make_string(x, 4, 6, 2, 5, 1, 3));
	ans.insert(make_string(x, 3, 6, 1, 5, 4, 2));
	ans.insert(make_string(x, 2, 6, 4, 5, 3, 1));
	ans.insert(make_string(x, 1, 5, 3, 6, 2, 4));
	ans.insert(make_string(x, 4, 5, 2, 6, 1, 3));
	ans.insert(make_string(x, 3, 5, 1, 6, 4, 2));
	ans.insert(make_string(x, 2, 5, 4, 6, 3, 1));

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);

	string x;
	cin>>x;

	int cnt[26] = {0};
	for (auto c: x)
		cnt[c - 'A']++;
	vector <int> cnts;
	for (int i = 0; i < 26; i++)
		if (cnt[i])
			cnts.push_back(cnt[i]);
	sort(cnts.begin(), cnts.end());
	reverse(cnts.begin(), cnts.end());
	char curr = 'A';
	string mys = "";
	for (int c: cnts)
	{
		while (c--)
			mys += curr;
		curr++;
	}
	x = mys;

	do
	{
		perms.insert(x);
	} while (next_permutation(x.begin(), x.end()));

	for (auto p: perms)
	{
		for (auto rot: make_rotations(p))
			if (p != rot && perms.find(rot) != perms.end())
				perms.erase(rot);
	}
	cout<<perms.size()<<endl;
	return 0;
}
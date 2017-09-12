#include <bits/stdc++.h>

using namespace std;

vector <vector <int> > schemes;
string current[4];

bool is_vowel(char x)
{
	return (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u');
}

int find_idx(string &x, int k)
{
	for (int i = x.size() - 1; i >= 0; i--)
	{
		if (is_vowel(x[i]))
			k--;
		if (!k)
			return i;
	}
	return -1;
}

bool check_suffix(string &x, string &y, int k)
{
	int i = find_idx(x, k), j = find_idx(y, k);

	if (i == -1 || j == -1)
		return 0;

	if (x.size() - i != y.size() - j)
		return 0;

	while (i < x.size() && j < y.size())
		if (x[i++] != y[j++])
			return 0;
	return 1;
}

vector <int> get_scheme(int k)
{
	vector <int> ans;
	if (check_suffix(current[0], current[1], k) && check_suffix(current[2], current[3], k))
		ans.push_back(1);
	if (check_suffix(current[0], current[2], k) && check_suffix(current[1], current[3], k))
		ans.push_back(2);
	if (check_suffix(current[0], current[3], k) && check_suffix(current[1], current[2], k))
		ans.push_back(3);
	return ans;
}

bool check_all()
{
	for (auto scheme: schemes)
		if (scheme.size() != 3)
			return 0;
	return 1;
}

bool check_for(int cand)
{
	for (auto scheme: schemes)
		if (find(scheme.begin(), scheme.end(), cand) == scheme.end())
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);

	int n, k;
	cin>>n>>k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
			cin>>current[j];
		schemes.push_back(get_scheme(k));
	}

	if (check_all())
		cout<<"aaaa"<<endl;
	else if (check_for(1))
		cout<<"aabb"<<endl;
	else if (check_for(2))
		cout<<"abab"<<endl;
	else if (check_for(3))
		cout<<"abba"<<endl;
	else
		cout<<"NO"<<endl;
	
	return 0;
}
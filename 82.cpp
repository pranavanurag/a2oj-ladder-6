#include <bits/stdc++.h>

using namespace std;

pair <int, int> get_type(string x)
{
	int n = x.length();

	if (n > 3 && x.substr(n - 4, 4) == "lios")
		return make_pair(1, -1);
	else if (n > 2 && x.substr(n - 3, 3) == "etr")
		return make_pair(2, -1);
	else if (n > 5 && x.substr(n - 6, 6) == "initis")
		return make_pair(3, -1);
	else if (n > 4 && x.substr(n - 5, 5) == "liala")
		return make_pair(1, 1);
	else if (n > 3 && x.substr(n - 4, 4) == "etra")
		return make_pair(2, 1);
	else if (n > 5 && x.substr(n - 6, 6) == "inites")
		return make_pair(3, 1);

	return make_pair(0, 0);
}

vector <string> words;
vector <pair <int, int> > sent;

bool gender_check()
{
	int gen = sent[0].second;
	for (auto p: sent)
		if (p.second != gen)
			return 0;
	return 1;
}

int find_idx()
{
	for (int i = 0; i < sent.size(); i++)
		if (sent[i].first == 2)
			return i;

	return 0;
}

bool structure_check()
{
	if (sent.size() == 1)
		return (sent[0].first != 0);

	int i = find_idx() - 1;
	if (sent[i + 1].first != 2)
		return 0;

	while (i >= 0)
		if (sent[i--].first != 1)
			return 0;

	i = find_idx() + 1;
	while (i < sent.size())
		if (sent[i++].first != 3)
			return 0;

	return 1;
}

int main()
{
	ios::sync_with_stdio(false);

	string temp;
	while (cin>>temp)
		words.push_back(temp);

	for (auto word: words)
		sent.push_back(get_type(word));

	if (gender_check() && structure_check())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
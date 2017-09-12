#include <bits/stdc++.h>

using namespace std;

int exp_total[4];
bool like[8][8];
vector <pair <int, int> > ans;
vector <int> curr_group[4];

int id(string s)
{
	if(s == "Anka")
		return 1;
	if(s == "Chapay")
		return 2;
	if (s == "Cleo")
		return 3;
	if(s == "Troll")
		return 4;
	if(s == "Dracul")
		return 5;
	if(s == "Snowy")
		return 6;
	if(s == "Hexadecimal")
		return 7;
}

bool is_valid()
{
	for (int i = 1; i <= 3; i++)
		if (!curr_group[i].size())
			return 0;
	return 1;
}

pair <int, int> find_curr_ans()
{
	int total_likeness = 0;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = 0; j < curr_group[i].size(); j++)
			for (int k = 0; k < curr_group[i].size(); k++)
				total_likeness += (like[curr_group[i][j]][curr_group[i][k]]);
	}

	vector <int> exp_gain;
	exp_gain.resize(7);
	for (int i = 1; i <= 3; i++)
		for (auto hero: curr_group[i])
			exp_gain[hero - 1] = exp_total[i]/curr_group[i].size();


	sort(exp_gain.begin(), exp_gain.end());
	return make_pair(exp_gain[6] - exp_gain[0], -total_likeness);
}

void find_all(int i = 1)
{
	if (i == 8)
	{
		if (is_valid())
			ans.push_back(find_curr_ans());
	}
	else
		for (int x = 1; x <= 3; x++)
		{
			curr_group[x].push_back(i);
			find_all(i + 1);
			curr_group[x].pop_back();
		}
}

int main()
{
	ios::sync_with_stdio(false);
	
	int n;
	cin>>n;
	while (n--)
	{
		string x, y, z;
		cin>>x>>y>>z;
		like[id(x)][id(z)] = 1;	
	}

	for (int i = 1; i <= 3; i++)
		cin>>exp_total[i];

	find_all();

	sort(ans.begin(), ans.end());
	cout<<ans[0].first<<" "<<-ans[0].second<<endl;
	return 0;
}
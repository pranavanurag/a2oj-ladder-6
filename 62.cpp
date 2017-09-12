#include <bits/stdc++.h>

using namespace std;

#define pcc pair <char, char> 

vector <pcc> forb;

bool is_forb(pcc a)
{
	for (auto y: forb)
		if (y == a)
			return 1;
	return 0;
}

string s;
vector <char> x;
vector <int> count_x;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin>>s>>n;
	while (n--)
	{
		string temp;
		cin>>temp;
		forb.push_back(make_pair(temp[0], temp[1]));
		forb.push_back(make_pair(temp[1], temp[0]));
	}

	for (int i = 0; i < s.size(); i++)
	{
		x.push_back(s[i]);
		int j = i + 1, this_count_x = 1;
		while (s[j] == s[i])
			j++, this_count_x++;
		count_x.push_back(this_count_x);

		i = j - 1;
	}

	int ans = 0;
	for (int i = 0; i < x.size() - 1; i++)
	{
		int sum[2] = {0, 0};
		sum[i%2] += count_x[i];
		while (is_forb(make_pair(x[i], x[i + 1])) && i < x.size())
			sum[(i + 1)%2] += count_x[i + 1], i++;
		ans += min(sum[0], sum[1]);
	}

	cout<<ans<<endl;
	return 0;
}
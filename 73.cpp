#include <bits/stdc++.h>

using namespace std;

string s1, s2;
vector <int> shash[26];

int main()
{
	ios::sync_with_stdio(false);
	cin>>s1>>s2;

	for (int i = 0; i < s1.size(); i++)
		shash[s1[i] - 'a'].push_back(i);

	for (int i = 0; i < s2.size(); i++)
		if (shash[s2[i] - 'a'].size() == 0)
		{
			cout<<-1<<endl;
			return 0;
		}

	int ans = 1, ptr = shash[s2[0] - 'a'][0];
	for (int i = 1; i < s2.size(); i++)
	{
		auto up_it = upper_bound(shash[s2[i] - 'a'].begin(), shash[s2[i] - 'a'].end(), ptr);
		if (up_it == shash[s2[i] - 'a'].end())
			ans++, ptr = shash[s2[i] - 'a'][0];
		else
			ptr = *up_it;
	}

	cout<<ans<<endl;
	return 0;
}
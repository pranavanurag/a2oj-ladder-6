#include <bits/stdc++.h>

using namespace std;

string s, ans;
bool can[2000001];

bool is_cons_double(int i)
{
	return (ans[i] == ans[i + 1] && ans[i + 2] == ans[i + 3]);
}

int main()
{
	ios::sync_with_stdio(false);

	for (int i = 0; i < 2000000; i++)
		can[i] = 1;

	cin>>s;

	char prev_char = s[0];
	ans += s[0];
	int cont = 1;
	
	for (int i = 1; i < s.length(); i++)
	{
		cont = (s[i] == prev_char)?cont + 1: 1;

		if (cont < 3)
			ans += s[i];

		prev_char = s[i];
	}

	if (ans.length() >= 4)
		for (int i = 0; i < ans.length() - 3;)
			if (is_cons_double(i))
			{
				can[i + 2] = 0;
				i = i + 4;
			}
			else
				i++;

	for (int i = 0; i < ans.length(); i++)
		if (can[i])
			cout<<ans[i];
	cout<<endl;
	return 0;
}
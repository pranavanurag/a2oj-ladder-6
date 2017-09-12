#include <bits/stdc++.h>

using namespace std;

bool prep[1001];
string s;
int cnt[26];

int main()
{
	ios::sync_with_stdio(false);
	cin>>s;
	memset(prep, 1, sizeof prep);
	int n = s.length();
	for (auto c: s)
		cnt[c - 'a']++;

	for (int i = 2; i <= n/2; i++)
	{
		if (prep[i])
		{
			for (int j = i*i; j <= n; j += i)
				prep[j] = 0;
			prep[i] = 0;
		}
	}

	vector <int> idx, idx2;
	for (int i = 1; i <= n; i++)
		if (!prep[i])
			idx.push_back(i);
		else
			idx2.push_back(i);

	int ch = -1;
	for (int i = 0; i < 26; i++)
		if (cnt[i] >= idx.size())
			ch = i;

	if (ch < 0)
		cout<<"NO"<<endl;
	else
	{
		string ans = s;
		for (auto i: idx)
			ans[i - 1] = 'a' + ch;
		cnt[ch] -= idx.size();

		ch = 0;
		for (auto i: idx2)
		{
			while (cnt[ch] == 0 && ch < 26)
				ch++;
			ans[i - 1] = 'a' + ch;
			cnt[ch]--;
		}
		cout<<"YES"<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
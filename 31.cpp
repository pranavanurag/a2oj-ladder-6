#include <bits/stdc++.h>

using namespace std;

int pos[1000001], sop[1000001];
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin>>s;

	int n = s.length();
	int l = n, r = 1;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'l')
			pos[i] = l--;
		else
			pos[i] = r++;

		sop[pos[i]] = i + 1;
	}
	sort(pos, pos + n);

	for (int i = 0; i < n; i++)
		cout<<sop[pos[i]]<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

int ans_max[1001], ans_min[1001], m, s;

int main()
{
	ios::sync_with_stdio(false);
	cin>>m>>s;
	if (s > 9*m || s < 0 || (s == 0 && m > 1))
		cout<<"-1 -1"<<endl;
	else
	{
		int rem = s, i;

		for (i = m; i >= 1 && rem > 9; i--)
			ans_max[i] = 9, rem -= 9;
		ans_max[i] = rem;
		for (int j = i - 1; j >= 1; j--)
			ans_max[j] = 0;

		rem = s;
		for (i = 1; i <= m && rem >= 10; i++)
			ans_min[i] = 9, rem -= 9;
		if (i == m)
			ans_min[i] = rem;
		else
		{
			ans_min[i] = --rem;
			rem = 1;
			for (int j = i + 1; j < m; j++)
				ans_min[j] = 0;
			ans_min[m] = rem;
		}

		for (int x = m; x >= 1; x--)
			cout<<ans_min[x];
		cout<<" ";
		for (int x = m; x >= 1; x--)
			cout<<ans_max[x];
		cout<<endl;
	}
	return 0;
}
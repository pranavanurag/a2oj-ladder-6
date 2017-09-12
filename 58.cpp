#include <bits/stdc++.h>

using namespace std;

int a[101][101], n;

bool row_has_one(int i)
{
	for (int x = 1; x <= n; x++)
		if (a[i][x])
			return 1;
	return 0;
}

bool column_has_one(int i)
{
	for (int j = 1; j <= n; j++)
		if (a[j][i])
			return 1;
	return 0;
}

bool ans_exists_1()
{
	for (int i = 1; i <= n; i++)
		if (!row_has_one(i))
			return 0;
	return 1;
}

bool ans_exists_2()
{
	for (int i = 1; i <= n; i++)
		if (!column_has_one(i))
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin>>s;
		for (int j = 0; j < n; j++)
			a[i + 1][j + 1] = (s[j] == '.');
	}

	if (!ans_exists_1() && !ans_exists_2())
		cout<<-1<<endl;
	else if (ans_exists_1())
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (a[i][j])
				{
					cout<<i<<" "<<j<<endl;
					break;
				}
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
				if (a[j][i])
				{
					cout<<j<<" "<<i<<endl;
					break;
				}
		}
	}
	return 0;
}
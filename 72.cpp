#include <bits/stdc++.h>

using namespace std;

int a[4000], n, curr_count[1000001], another[1000001];
set <int> dist_nums, curr;

int next_occ(int x, int i)
{
	for (int j = i + 1; j < n; j++)
		if (a[j] == x)
			return j;
	return -1;
}

void clear_curr()
{
	for (auto x: dist_nums)
	{
		curr_count[x] = 0;
		another[x] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		cin>>a[i];
		dist_nums.insert(a[i]);
	}

	int ans = 0;
	for (auto x: dist_nums)
	{
		int start = next_occ(x, -1);
		int end = next_occ(x, start);

		while (end != -1)
		{
			for (int i = start + 1; i <= end - 1; i++)
				curr.insert(a[i]);

			for (auto c: curr)
				curr_count[c]++;
			curr.clear();

			start = end;
			end = next_occ(x, end);
		}

		for (int i = start + 1; i < n; i++)
			another[a[i]] = 1;

		for (auto x: dist_nums)
			if (another[x])
				ans = max(ans, 2*curr_count[x] + 2);
			else
				ans = max(ans, 2*curr_count[x] + 1);

		clear_curr();
	}

	for (int i = 0; i < n; i++)
		curr_count[a[i]]++;
	for (auto x: dist_nums)
		ans = max(curr_count[x], ans);

	cout<<ans<<endl;
	return 0;
}
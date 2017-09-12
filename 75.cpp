#include <bits/stdc++.h>

using namespace std;

vector <int> solve(int n, int m, int k)
{
	vector <int> ans;
	for (int i = 0; i < k; i++)
		ans.push_back(1);
	int last_join_date = 1;
	while (last_join_date + n <= n + m + 1)
	{
		ans.push_back(last_join_date + n - 1);
		if (last_join_date <= m)
			for (int i = 0; i < k - 1; i++)
				ans.push_back(last_join_date + n);
		last_join_date = ans[ans.size() - 1];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int n, m, k;
	cin>>n>>m>>k;
	auto ans = solve(n, m, k);
	cout<<ans.size()<<endl;
	for (auto el: ans)
		cout<<el<<" ";
	cout<<endl;
	return 0;
}
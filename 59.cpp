#include <bits/stdc++.h>

using namespace std;

int m, n, min_disc = INT_MAX, ans = 0;
vector <int> prices;

int main()
{
	ios::sync_with_stdio(false);

	cin>>m;
	int tmp;
	while (m-- && cin>>tmp)
		min_disc = min(min_disc, tmp);

	cin>>n;
	int temp;
	while (n-- && cin>>temp)
		prices.push_back(temp);

	sort(prices.begin(), prices.end());
	reverse(prices.begin(), prices.end());

	int bought = 0;
	for (int i = 0; i < prices.size(); i++)
	{
		if (bought%min_disc == 0 && bought != 0)
			i += 2;
		if (i < prices.size())
			ans += prices[i];
		bought++;
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define pii pair <int, int> 

vector <pair <pii, int> > time_stamps;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		pii temp;
		cin>>temp.first>>temp.second;

		pair <pii, int> temp2;
		temp2.first.first = temp.first, temp2.first.second = 1, temp2.second = i;
		time_stamps.push_back(temp2);

		temp2.first.first = temp.second, temp2.first.second = -1, temp2.second = i;
		time_stamps.push_back(temp2);
	}

	sort(time_stamps.begin(), time_stamps.end());

	vector <int> ans;
	for (int i = 0; i < n; i++)
	{
		int count = 0, max_count = 0;
		for (auto x: time_stamps)
			if (x.second != i)
			{
				count += x.first.second;
				max_count = max(max_count, count);
			}
		if (max_count < 2)
			ans.push_back(i + 1);
	}

	cout<<ans.size()<<endl;
	for (auto x: ans)
		cout<<x<<" ";
	cout<<endl;
	return 0;
}
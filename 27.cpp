#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > points;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		pair <int, int> temp;
		cin>>temp.first>>temp.second;
		points.push_back(temp);
	}

	sort(points.begin(), points.end());

	int max_close_coordinate = -1, ans = 0;
	for (auto pt: points)
	{
		max_close_coordinate = max(max_close_coordinate, pt.second);
		if (max_close_coordinate > pt.second)
			ans++;
	}

	cout<<ans<<endl;
	return 0;
}
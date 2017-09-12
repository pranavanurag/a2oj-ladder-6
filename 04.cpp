#include <bits/stdc++.h>

using namespace std;

#define pii pair <int, int>

vector <pii > ex;
int n;

struct compare
{
	bool operator()(const pii &left, const pii &right)
	{
		if (left.first < right.first)
			return 1;
		else if (left.first > right.first)
			return 0;
		else
			return left.second < right.second;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	pair <int, int> tmp;
	for (int i = 0; i < n && cin>>tmp.first>>tmp.second; i++)
		ex.push_back(tmp);

	sort(ex.begin(), ex.end(), compare());

	int prev = min(ex[0].first, ex[0].second);
	for (auto e: ex)
	{
		int current;
		if (e.second < e.first && e.second >= prev)
			current = e.second;
		else
			current = e.first;

		prev = current;
	}
	cout<<prev<<endl;
	return 0;
}
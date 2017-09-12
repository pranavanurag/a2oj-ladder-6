#include <bits/stdc++.h>

using namespace std;

set <int> vals;
int n;
vector <int> a;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0, temp; i < n && cin>>temp; i++)
		a.push_back(temp);

	set <int> prev, current;
	for (auto x: a)
	{
		for (auto p: prev)
			current.insert(p|x);
		current.insert(x);

		for (auto v: current)
			vals.insert(v);

		prev = current;
		current.clear();
	}

	cout<<vals.size()<<endl;
	return 0;
}
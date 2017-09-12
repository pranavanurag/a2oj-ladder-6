#include <bits/stdc++.h>

using namespace std;

set <pair <int, int> > pts;
map <pair <int, int>, int> cnt;

int main()
{
	ios::sync_with_stdio(false);
	bool ans = 1;
	int a = -1, b = -1, x_eq = 0, y_eq = 0;
	for (int i = 0; i < 4; i++)
	{
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;

		pair <int, int> p1 = make_pair(x1, y1);
		pair <int, int> p2 = make_pair(x2, y2);

		pts.insert(p1);
		pts.insert(p2);
		cnt[p1]++;
		cnt[p2]++;

		if (x1 == x2)
		{
			if (a < 0)
				a = abs(y1 - y2);
			else if (a != abs(y1 - y2))
				ans = 0;

			x_eq++;
		}
		else if (y1 == y2)
		{
			if (b < 0)
				b = abs(x1 - x2);
			else if (b != abs(x1 - x2))
				ans = 0;

			y_eq++;
		}
		else
			ans = 0;
	}

	ans &= (pts.size() == 4);
	ans &= (a > 0);
	ans &= (b > 0);
	ans &= (x_eq == 2);
	ans &= (y_eq == 2);

	for (auto p: pts)
		if (cnt[p] != 2)
			ans = 0;

	if (ans)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
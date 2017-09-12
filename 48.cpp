#include <bits/stdc++.h>

using namespace std;

#define pii pair <int, int>

vector <pii > gen_rotations(int x, int y, int cx, int cy)
{
	vector <pii > ans;

	ans.push_back(make_pair(x, y));
	ans.push_back(make_pair(-(y - cy) + cx, (x - cx) + cy));
	ans.push_back(make_pair(-(x - cx) + cx, -(y - cy) + cy));
	ans.push_back(make_pair((y - cy) + cx, -(x - cx) + cy));
	
	return ans;
}

double dist(pii p1, pii p2)
{
	double x1 = p1.first, y1 = p1.second;
	double x2 = p2.first, y2 = p2.second;
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}

bool is_valid_square(pii p1, pii p2, pii p3, pii p4)
{
	set <double> lens;
	lens.insert(dist(p1, p2));
	lens.insert(dist(p1, p3));
	lens.insert(dist(p1, p4));
	lens.insert(dist(p2, p3));
	lens.insert(dist(p2, p4));
	lens.insert(dist(p3, p4));

	if (lens.size() != 2)
		return 0;

	double d1 = 0, d2;
	for (auto d: lens)
		if (d == 0)
			return 0;
		else if (!d1)
			d1 = d;
		else
			d2 = d;

	return (2*d1 - d2 < 1e6);
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while (n--)
	{
		int x[5], y[5], cx[5], cy[5];
		vector <pii > rot[5];

		for (int i = 1; i <= 4; i++)
		{
			cin>>x[i]>>y[i]>>cx[i]>>cy[i];
			rot[i] = gen_rotations(x[i], y[i], cx[i], cy[i]);
		}

		int ans = 1000;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				for (int k = 0; k < 4; k++)
					for (int l = 0; l < 4; l++)
						if (is_valid_square(rot[1][i], rot[2][j], rot[3][k], rot[4][l]))
							ans = min(ans, i + j + k + l);

		if (ans == 1000)
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}	
	return 0;
}
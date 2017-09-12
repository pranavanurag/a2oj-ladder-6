#include <bits/stdc++.h>

using namespace std;

vector <double> angles;

double rad2deg(double x)
{
	return (180*x)/3.14159265359;
}

double slope_angle(double x, double y)
{
	if (x == 0)
	{
		if (y > 0)
			return 90;
		else
			return 270;
	}
	if (y == 0)
	{
		if (x > 0)
			return 0;
		else
			return 180;
	}

	double og = rad2deg(atan(abs(y/x)));

	if (x > 0 && y > 0)
		return og;
	else if (x < 0 && y > 0)
		return 180 - og;
	else if (x < 0 && y < 0)
		return 180 + og;
	else
		return 360 - og;
}

int main()
{
	ios::sync_with_stdio(false);
	cout<<setprecision(12)<<fixed;
	int n;
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		double x, y;
		cin>>x>>y;
		if (x != 0 || y != 0)
			angles.push_back(slope_angle(x, y));
	}
	sort(angles.begin(), angles.end());
	double ans = angles[n - 1] - angles[0];
	for (int i = 0; i < n - 1; i++)
		ans = min(ans, 360 - angles[i + 1] + angles[i]);
	cout<<ans<<endl;
	return 0;
}
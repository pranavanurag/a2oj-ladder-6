#include <bits/stdc++.h>

using namespace std;

#define ll long long

bool is_perfect_square(ll x)
{
	ll root = sqrt(x);
	return root*root == x;
}

vector <pair <int, int> > pts;
vector <pair <int, int> > ans;

int main()
{
	ios::sync_with_stdio(false);
	ll a, b;
	cin>>a>>b;
	for (ll i = 1; i <= a - 1; i++)
		if (is_perfect_square(a*a - i*i))
			pts.push_back(make_pair(i, sqrt(a*a - i*i)));


	for (auto pt: pts)
	{
		int x1 = pt.first, y1 = pt.second, x2 = 0, y2 = 0;

		if (x1 == 0 || y1 == 0)
			continue;
		else
		{
			if ((b*y1)%a == 0)
			{
				x2 = -(b*y1)/a;

				if ((x1*x2)%y1 == 0)
					y2 = -(x1*x2)/y1;
			}

			if (x1 == x2 || y1 == y2)
				x2 = -x2, y2 = -y2;


			if (x2 == 0 || y2 == 0)
				continue;
			else
			{
				ans.push_back(make_pair(x1, y1));
				ans.push_back(make_pair(x2, y2));
			}
		}
	}

	if (ans.size() == 0)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		cout<<0<<" "<<0<<endl;
		cout<<ans[0].first<<" "<<ans[0].second<<endl;
		cout<<ans[1].first<<" "<<ans[1].second<<endl;
	}
	return 0;
}
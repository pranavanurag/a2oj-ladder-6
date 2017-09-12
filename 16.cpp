#include <bits/stdc++.h>

using namespace std;

vector <int> v;
int n;

bool is_ap(vector <int> a)
{
	for (int i = 0; i < a.size() - 2; i++)
		if (a[i + 1] - a[i] != a[i + 2] - a[i + 1])
			return 0;
	return 1;
}

bool constant_vector(vector <int> a)
{
	for (int i = 1; i < a.size(); i++)
		if (a[i] != a[i - 1])
			return 0;
	return 1;
}

int fix_vector(vector <int>& a, int d)
{
	int ans = -1;
	for (int i = 0; i < a.size() - 1; i++)
		if (a[i + 1] - a[i] != d)
		{
			ans = a[i] + d;
			a.push_back(a[i] + d);
			break;
		}
	sort(a.begin(), a.end());
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	if (n == 1)
		cout<<"-1"<<endl;
	else if (constant_vector(v))
		cout<<1<<endl<<v[0]<<endl;
	else if (is_ap(v))
	{
		int d = v[1] - v[0];
		if (n == 2 && (v[1] + v[0])%2 == 0)
			cout<<3<<endl<<v[0] - d<<" "<<(v[0] + v[1])/2<<" "<<v[1] + d<<endl;
		else
			cout<<2<<endl<<v[0] - d<<" "<<v[n - 1] + d<<endl;
	}
	else
	{
		int d = (int)1e9;
		for (int i = 0; i < n - 1; i++)
			d = min(d, v[i + 1] - v[i]);
		int ans = fix_vector(v, d);
		if (is_ap(v))
			cout<<1<<endl<<ans<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}
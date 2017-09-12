#include <bits/stdc++.h>

using namespace std;

string s;
int n, p, a[(int)(1e5) + 1];

int distance(char x, char y)
{
	int t1 = x - 'a', t2 = y - 'a';
	int n1 = max(t1, t2), n2 = min(t1, t2);
	return min((26 + n2 - n1), n1 - n2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>p>>s;

	int ans = 0;

	for (int i = 0; i < (n + 1)/2; i++)
	{
		a[i] = distance(s[i], s[n - i - 1]);
		ans += a[i];
	}

	p = min(p, n - p + 1);
	p--;

	int right_most = p, left_most = p;
	for (int i = 0; i < (n + 1)/2; i++)
		if (a[i])
			right_most = i;
	for (int i = (n + 1)/2 - 1; i >= 0; i--)
		if (a[i])
			left_most = i;

	if (right_most >= p && left_most >= p)
		ans += (right_most - p);
	else if (right_most <= p && left_most <= p)
		ans += (p - left_most);
	else
	{
		int left_first = 2*(abs(p - left_most)) + (right_most - p);
		int right_first = 2*(abs(right_most - p)) + (p - left_most);
		ans += min(left_first, right_first);
	}

	cout<<ans<<endl;
	return 0;
}
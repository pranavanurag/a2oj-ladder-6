/*input
28 6 3
*/
#include <bits/stdc++.h>

using namespace std;

#define ll long long
int d;
map <pair <int, int>, int> imap;

ll f(int n, int k, int p)
{
	if (n < 0)
		return 0;
	if (n == 0 && p == 0)
		return 1;
	if (imap[make_pair(n, p)])
		return imap[make_pair(n, p)];
	ll ans = 0;
	for(int i=1;i<=k; i++)
	{
		if(i>=d)
			ans += f(n - i, k, 0);
		else
			ans += f(n - i, k, p);
	}
	imap[make_pair(n, p)] = ans; 
	return ans;
}

int main()
{
	int n,k;
	cin>>n>>k>>d;
	cout<<f(n, k, 1)<<"\n";
}
#include <bits/stdc++.h>

using namespace std;

long double k, n, b, t;

int main()
{
	ios::sync_with_stdio(false);
	cin>>k>>b>>n>>t;

	long double x = ((k - 1)*t + b)/(k - 1 + b);

	if (x != 1)
		cout<<max(0, (int)ceil(n - (log10(x)/log10(k))))<<endl;
	else
		cout<<max(0, (int)ceil((n*b + 1 - t)/b))<<endl;
	return 0;
}
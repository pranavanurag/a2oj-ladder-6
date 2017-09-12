#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	for (int i = 1; i <= n; i++)
		if (i%2 == 1)
			cout<<(i + 1)/2<<" ";
		else
			cout<<n - i/2 + 1<<" ";
	cout<<endl;
	return 0;
}
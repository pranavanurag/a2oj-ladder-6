#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	long long a[3];
	cin>>a[0]>>a[1]>>a[2];
	sort(a, a + 3);
	if (a[2] >= 2*(a[0] + a[1]))
		cout<<a[0] + a[1]<<endl;
	else
		cout<<(a[0] + a[1] + a[2])/3<<endl;
	return 0;
}
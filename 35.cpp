#include <bits/stdc++.h>

using namespace std;

double best = 0, sum = 0, n;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		double temp;
		cin>>temp;
		sum += temp;
		best = max(temp, best);
	}
	cout<<(int)max(best, ceil(sum/(n - 1)))<<endl;
	return 0;
}
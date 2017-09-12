/*input
25 3 3
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int n, k, d;
	cin>>n>>k>>d;
	if (pow(double(k), double(d)) < double(n))
		cout<<"-1"<<endl;
	else
	{
		for (int i = 1; i <= d; i++)
		{
			int x = 1;
			int change_after = pow(k, d - i);
			for (int j = 1; j <= n; j++)
			{
				cout<<x<<" ";
				if (j%change_after == 0)
					x++;
				if (x > k)
					x = 1;
			}
			cout<<endl;
		}
	}
	return 0;
}
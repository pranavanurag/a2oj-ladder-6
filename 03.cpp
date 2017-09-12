#include <bits/stdc++.h>

using namespace std;

int z, o;
string ans;

int main()
{
	ios::sync_with_stdio(false);
	cin>>z>>o;
	if (z > o + 1 || o > 2*z + 2)
		cout<<"-1\n";
	else
	{
		while (z > 0 && o > 0)
		{
			if (z > o && z > 1 && o > 0)
				ans += "010", z -= 2, o -= 1;
			else if (z == o && z > 0 && o > 0)
				ans += "10", z -= 1, o -= 1;
			else if (o > z && o > 1 && z > 0)
				ans += "110", z -= 1, o -= 2;
		}
		while (o > 0)
			ans += "1", o -= 1;
		while (z > 0)
			ans += "0", z -= 1;
		cout<<ans<<endl;
	}
	return 0;
}
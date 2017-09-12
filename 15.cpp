#include <bits/stdc++.h>

using namespace std;

int req_sum;

int main()
{
	ios::sync_with_stdio(false);
	cin>>req_sum;

	int ans = -1;
	for (int y = 0; 7*y <= req_sum; y++)
	{
		if ((req_sum - 7*y)%4 == 0)
			ans = y;
	}


	if (ans < 0)
		cout<<-1;
	else
	{
		for (int i = 1; i <= (req_sum - 7*ans)/4; i++)
			cout<<4;
		for (int i = 1; i <= ans; i++)
			cout<<7;
		cout<<endl;
	}

	return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll req_bread = 0, req_sausage = 0, req_cheese = 0;
ll total_monies;
ll n_bread, n_sausage, n_cheese;
ll price_bread, price_sausage, price_cheese;

bool can_make(ll x)
{
	ll mbn = max((ll)0, req_bread*x - n_bread);
	ll msn = max((ll)0, req_sausage*x - n_sausage);
	ll mcn = max((ll)0, req_cheese*x - n_cheese);

	return mbn*price_bread + msn*price_sausage + mcn*price_cheese <= total_monies;
}

int main()
{
	ios::sync_with_stdio(false);

	string temp;
	cin>>temp;
	for (auto c: temp)
		if (c == 'B')
			req_bread++;
		else if (c == 'S')
			req_sausage++;
		else
			req_cheese++;
	
	cin>>n_bread>>n_sausage>>n_cheese;
	cin>>price_bread>>price_sausage>>price_cheese;
	cin>>total_monies;

	ll low = 0, high = (ll)(1e14);
	ll mid = low + (high - low + 1)/2;
	while (low < high)
	{
		if (can_make(mid))
			low = mid;
		else
			high = mid - 1;
		mid = low + (high - low + 1)/2;
	}

	cout<<mid<<endl;
	return 0;
}
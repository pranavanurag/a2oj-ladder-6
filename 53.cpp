#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define INF INT_MAX

ll required_hp(ll atky, ll defy, ll atkm, ll defm, ll hpm)
{
	ll dec_y = max((ll)0, atkm - defy);
	ll dec_m = max((ll)0, atky - defm);

	if (dec_y == 0 && dec_m > 0)
		return 0;
	else if (dec_m == 0 && dec_y >= 0)
		return INF;
	else
	{
		ll last_m = (hpm + dec_m - 1)/dec_m;
		return last_m*dec_y + 1;
	}
}

ll hpy, atky, defy, hpm, atkm, defm, h, a, d;

int main()
{
	ios::sync_with_stdio(false);
	cin>>hpy>>atky>>defy;
	cin>>hpm>>atkm>>defm;
	cin>>h>>a>>d;

	ll ans = INF;
	for (ll atk_buy = 0; atk_buy <= 200; atk_buy++)
		for (ll def_buy = 0; def_buy <= 200; def_buy++)
		{
			ll hp_buy = required_hp(atk_buy + atky, def_buy + defy, atkm, defm, hpm) - hpy;
			if (hp_buy < 0)
				hp_buy = 0;
			ll req_monies = h*hp_buy + a*atk_buy + d*def_buy;

			ans = min(req_monies, ans);
		}

	cout<<ans<<endl;
	return 0;
}
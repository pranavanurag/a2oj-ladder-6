#include <bits/stdc++.h>

using namespace std;

#define ll long long

int a[1000005], n;
int left_num, right_num;
int left_rems[1000005], right_rems[1000005];

ll mod_exp(int base, int exp, int num)
{
	ll ans = 1, current = base;

	while (exp)
	{
		if (exp%2 == 1)
			ans = (ans*current)%num;
		exp /= 2;
		current = (current*current)%num;
	}

	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	
	string temp;
	cin>>temp>>left_num>>right_num;

	n = temp.size();
	for (int i = 0; i < n; i++)
		a[i + 1] = (int)(temp[i] - '0');

	left_rems[0] = 0;
	for (int i = 1; i <= n; i++)
		left_rems[i] = ((left_rems[i - 1]*10)%left_num + a[i]%left_num)%left_num;

	right_rems[n + 1] = 0;
	for (int i = n; i >= 1; i--)
		right_rems[i] = ((a[i]%right_num*mod_exp(10, n - i, right_num))%right_num + right_rems[i + 1])%right_num;

	int ans = -1;
	for (int i = 1; i < n; i++)
		if (left_rems[i] == 0 && right_rems[i + 1] == 0 && a[i + 1] != 0)
			ans = i;

	if (ans < 0)
		cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		for (int i = 1; i <= ans; i++)
			cout<<a[i];
		cout<<endl;
		for (int i = ans + 1; i <= n; i++)
			cout<<a[i];
		cout<<endl;
	}
	return 0;
}
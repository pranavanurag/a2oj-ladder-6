#include <bits/stdc++.h>

using namespace std;

int pre_xor[1000001], n, ans = 0, a[1000001];

void pre_compute() {
	pre_xor[0] = 0;
	for (int i = 1; i <= 1000000; i++)
		pre_xor[i] = pre_xor[i - 1]^i;

}

int main() {
	ios::sync_with_stdio(false);
	pre_compute();
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		ans ^= a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		ans ^= pre_xor[n%i];
		if ((n/i)%2 == 1)
			ans ^= pre_xor[i - 1];
	}
	cout<<ans<<endl;
	return 0;
}
#include <iostream>
#include <cstring>

using namespace std;

#define N (int)1e7

int freq[N + 1], n, ans[N + 1];
bool is_prime[N + 1];
int presum[N + 1];

void seive()
{
	for (int i = 2; i <= N; i++)
		is_prime[i] = 1;

	for (int i = 2; i*i <= N; i++)
		if (is_prime[i])
			for (int j = i*i; j <= N; j += i)
				is_prime[j] = 0;
}

int main()
{
	ios::sync_with_stdio(false);

	seive();

	memset(freq, 0, sizeof(freq));

	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		freq[temp]++;
	}

	for (int p = 2; p <= N; p++)
		if (is_prime[p])
		{
			for (int i = p; i <= N; i += p)
				ans[p] += freq[i];
		}

	presum[0] = 0;
	for (int i = 1; i <= N; i++)
		presum[i] = presum[i - 1] + ans[i];

	int q;
	cin>>q;
	while (q--)
	{
		int l, r;
		cin>>l>>r;
		r = min((int)1e7, r);
		l = min((int)1e7, l);
		cout<<presum[r] - presum[l - 1]<<endl;
	}
	return 0;
}
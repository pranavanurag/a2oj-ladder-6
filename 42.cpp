#include <bits/stdc++.h>

using namespace std;

int a[1001], n, base, ans[1001];

void show(int x[], int len) {
	for (int i = 1; i <= len; i++)
		cout<<(char)(x[i] + (int)'a' - 1);
	cout<<endl;
}

int main() {
	ios::sync_with_stdio(false);
	string temp;
	cin>>n>>base>>temp;

	for (int i = 0; i < n; i++)
		a[i + 1] = (int)(temp[i] - 'a') + 1;


	bool flag = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j < i; j++)
			ans[j] = a[j];

		ans[i] = a[i] + 1;
		while (i > 1 && ans[i] == ans[i - 1] || (i > 2 && ans[i] == ans[i - 2]))
			ans[i]++;
		if (ans[i] > base)
			continue;

		for (int j = i + 1; j <= n; j++) {
			ans[j] = 1;
			while (j > 1 && ans[j] == ans[j - 1] || (j > 2 && ans[j] == ans[j - 2]))
				ans[j]++;
			if (ans[j] > base) {
				break;
			}
		}

		flag = 1;
		show(ans, n);
		break;
	}

	if (!flag)
		cout<<"NO"<<endl;
	return 0;
}
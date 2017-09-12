#include <bits/stdc++.h>

using namespace std;

int n, a[101];
bool visited[101];

bool all_visited()
{
	for (int i = 1; i <= n; i++)
		if (!visited[i])
			return 0;
	return 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		cin>>a[i];
		visited[i] = 0;
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	while (!all_visited())
	{
		ans++;
		int current_stack_size = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] >= current_stack_size && !visited[i])
				current_stack_size++, visited[i] = 1;
	}
	cout<<ans<<endl;
	return 0;
}
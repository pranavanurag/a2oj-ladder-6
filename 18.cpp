#include <bits/stdc++.h>

using namespace std;

vector <string> x;
vector <int> a;

void gen_permutations(string current, int i, int n)
{
	if (i == n + 1)
		x.push_back(current);
	else
	{
		for (int j = 0; j < 2; j++)
		{
			current = current + (char)(j + '0');
			gen_permutations(current, i + 1, n);
			current.pop_back();
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	gen_permutations("", 1, 10);
	sort(x.begin(), x.end());
	for (auto s: x)
		a.push_back(stoi(s));
	
	int p;
	cin>>p;
	cout<<upper_bound(a.begin(), a.end(), p) - a.begin() - 1<<endl;

	return 0;
}
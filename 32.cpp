#include <bits/stdc++.h>

using namespace std;

vector <pair <int, int> > boys;
int n;

int main()
{
	cin>>n;
	for (int i = 1; i <= n; i++)
	{
		pair <int, int> temp;
		cin>>temp.first;
		temp.second = i;
		boys.push_back(temp);
	}

	sort(boys.begin(), boys.end());
	reverse(boys.begin(), boys.end());

	cout<<(n + 1)/2<<endl;	
	for (int i = 0; i < n; i += 2)
		cout<<boys[i].second<<" ";
	cout<<endl;

	cout<<n/2<<endl;
	for (int i = 1; i < n; i += 2)
		cout<<boys[i].second<<" ";
	cout<<endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;
vector <int> b;
int n;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin>>temp;
		a.push_back(temp);
		b.push_back(temp);
	}

	sort(a.begin(), a.end());

	int dist = 0;
	for (int i = 0; i < n; i++)
		if (a[i] != b[i])
			dist++;

	if (dist < 3)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}
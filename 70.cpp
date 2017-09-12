#include <bits/stdc++.h>

using namespace std;

vector <int> a;
vector <pair <int, int> > b;

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while (t--)
	{
		int q;
		cin>>q;
		if (q)
			a.push_back(q);
		else
		{
			int n = a.size();
			if (n == 0)
				cout<<"0"<<endl;
			else if (n == 1)
			{
				cout<<"pushStack"<<endl;
				cout<<"1 popStack"<<endl;
			}
			else if (n == 2)
			{
				cout<<"pushStack"<<endl;
				cout<<"pushQueue"<<endl;
				cout<<"2 popStack popQueue"<<endl;
			}
			else
			{
				for (int i = 0; i < n; i++)
					b.push_back(make_pair(a[i], i));
				sort(b.begin(), b.end());
				reverse(b.begin(), b.end());

				int idx1 = b[0].second, idx2 = b[1].second, idx3 = b[2].second;
				for (int i = 0; i < n; i++)
				{
					if (i == idx1)
						cout<<"pushStack"<<endl;
					else if (i == idx2)
						cout<<"pushQueue"<<endl;
					else if (i == idx3)
						cout<<"pushFront"<<endl;
					else
						cout<<"pushBack"<<endl;
				}
				cout<<"3 popStack popQueue popFront"<<endl;

			}
			a.clear(), b.clear();
		}
	}

	for (int i = 0; i < a.size(); i++)
		cout<<"pushStack"<<endl;

	return 0;
}
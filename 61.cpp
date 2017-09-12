#include <bits/stdc++.h>

using namespace std;

string s;
int x[10];

int main()
{
	ios::sync_with_stdio(false);

	memset(x, 0, sizeof x);
	cin>>s;
	for (auto c: s)
		x[(int)(c - '0')]++;
	x[1]--, x[6]--, x[8]--, x[9]--;

	int rem = 0;
	for (int i = 1; i <= 9; i++)
		while (x[i]--)
		{
			cout<<i;
			rem = ((rem*3)%7 + i%7)%7;
		}

	string p = "1689";
	int req_mod = (7 - (rem*10000)%7)%7;
	while (stoi(p)%7 != req_mod)
		random_shuffle(p.begin(), p.end());
	cout<<p;

	while (x[0]--)
		cout<<0;
	cout<<endl;
	return 0;
}
#include <bits/stdc++.h>

using namespace std;

vector <string> s;
char let;
int n;
bool change[1000000], lower_case[1000000];
string w;

void find_occ(string w, string x)
{
	int pos = -1;
	while (w.find(x, pos + 1) != string::npos)
	{
		pos = w.find(x, pos + 1);
		// cout<<"x = "<<x<<", w = "<<w<<", pos = "<<pos<<endl;
		for (int i = pos; i < pos + x.size(); i++)
			change[i] = 1;
	}
}

string to_upper(string x)
{
	string ans = "";
	for (auto c: x)
		ans += toupper(c);
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	string temp;
	for (int i = 0; i < n && cin>>temp; i++)
		s.push_back(temp);
	cin>>w>>let;

	string w_upper = to_upper(w);
	let = toupper(let);

	for (int i = 0; i < w.size(); i++)
		lower_case[i] = !(w[i] == w_upper[i]);

	for (auto si: s)
		find_occ(w_upper, to_upper(si));

	for (int i = 0; i < w_upper.size(); i++)
		if (change[i])
		{
			if (w_upper[i] != let)
				w_upper[i] = let;
			else if (w_upper[i] == 'A')
				w_upper[i] = 'B';
			else
				w_upper[i] = 'A';
		}

	for (int i = 0; i < w.size(); i++)
		if (lower_case[i])
			w[i] = tolower(w_upper[i]);
		else
			w[i] = w_upper[i];

	cout<<w<<endl;
	return 0;
}
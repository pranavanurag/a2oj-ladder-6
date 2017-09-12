#include <bits/stdc++.h>

using namespace std;

vector <string> words, ans;

int rec(int i)
{
	if (i < 0 || i >= words.size())
		return -1;

	if (words[i] == "int")
	{
		ans.push_back("int");
		return i + 1;
	}
	if (words[i] == "pair")
	{
		ans.push_back("pair");
		ans.push_back("<");
		int j = rec(i + 1);
		ans.push_back(",");
		int k = rec(j);
		ans.push_back(">");
		return k;
	}
}

bool check()
{
	int x = 0;
	for (auto el: ans)
		if (el == "pair" || el == "int")
			x++;
	return x == words.size();
}

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	string temp;
	while (cin>>temp)
		words.push_back(temp);

	int x = rec(0);
	if (x < 0 || !check())
		cout<<"Error occurred"<<endl;
	else
	{
		for (auto el: ans)
			cout<<el;
		cout<<endl;
	}
	return 0;
}
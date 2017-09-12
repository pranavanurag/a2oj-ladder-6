#include <bits/stdc++.h>

using namespace std;

#define ll long long

struct pt
{
	ll x, y;
};

struct less_than_key
{
	inline bool operator() (const pt& a, const pt& b)
	{
		return (a.x*a.x + a.y*a.y < b.x*b.x + b.y*b.y);
	}
};

vector <pt> bombs;

void go_to_point(ll a, ll b)	//(0, 0) -> (a, b)
{
	if (a < 0)
		printf("1 %lld L\n", -a);
	else if (a > 0)
		printf("1 %lld R\n", a);

	if (b < 0)
		printf("1 %lld D\n",-b);
	else if (b > 0)
		printf("1 %lld U\n", b);
}

void go_to_origin(ll a, ll b)	//(a, b) -> (0, 0)
{
	if (a < 0)
		printf("1 %lld R\n", -a);
	else if (a > 0)
		printf("1 %lld L\n", a);

	if (b < 0)
		printf("1 %lld U\n", -b);
	else if (b > 0)
		printf("1 %lld D\n", b);
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		pt temp;
		scanf("%lld %lld", &temp.x, &temp.y);
		bombs.push_back(temp);
	}

	sort(bombs.begin(), bombs.end(), less_than_key());

	int ans = 0;
	for (auto point: bombs)
	{
		ans += 2;
		if (abs(point.x) > 0)
			ans += 2;
		if (abs(point.y) > 0)
			ans += 2;
	}


	printf("%d\n", ans);
	for (auto point: bombs)
	{
		go_to_point(point.x, point.y);
		printf("2\n");
		go_to_origin(point.x, point.y);
		printf("3\n");
	}
	return 0;
}
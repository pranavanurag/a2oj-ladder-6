#include <bits/stdc++.h>

using namespace std;

#define ld long double
#define pi ((ld)3.14159265359)

ld d2r(ld x)
{
	return (pi*x)/180;
}

ld r2d(ld x)
{
	return (180*x)/pi;
}

int main()
{
	ios::sync_with_stdio(false);
	cout<<setprecision(12)<<fixed;

	ld w, h, alpha;
	cin>>w>>h>>alpha;

	alpha = min(alpha, 180 - alpha);
	if (h > w)
		swap(h, w);
	ld tan_alpha = tan(d2r(alpha));


	if (alpha == 0)
		cout<<h*w<<endl;
	else if (alpha == 90)
		cout<<h*h<<endl;
	else if (tan(d2r(alpha/2)) >= h/w)
		cout<<h*h/sin(d2r(alpha))<<endl;
	else
	{
		ld theta = r2d(atan(h/w));
		ld r = sqrt(w*w + h*h)/2;
		ld x0 = r*cos(d2r(theta + alpha));
		ld y0 = r*sin(d2r(theta + alpha));

		ld c1 = y0 - tan_alpha*x0;
		ld c2 = y0 + x0/tan_alpha;

		ld x1 = (h/2 - c1)/tan_alpha;
		ld len1 = x1 + w/2;

		ld x2 = (c2 - h/2)*tan_alpha;
		ld len2 = x2 - x1;

		ld len3 = w - len1 - len2;
		// cout<<"("<<h/2<<" - "<<c1<<")/"<<tan_alpha<<endl;
		// cout<<"x1 = "<<x1<<", x2 = "<<x2<<endl;
		// cout<<len1<<", "<<len2<<", "<<len3<<endl;

		ld area1 = 0.5*len1*len1*tan_alpha, area3 = 0.5*len3*len3/tan_alpha;

		ld ans = h*w - 2*(area1 + area3);
		cout<<ans<<endl;
	}
	return 0;
}
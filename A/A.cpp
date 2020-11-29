#define LL long long
#define pq priority_queue
#define ULL unsigned long long
#define pb push_back
#define mem(a, x) memset(a, x, sizeof a)
#define pii pair<int, int>
#define fir(i, a, b) for (int i = a; i <= (int)b; ++i)
#define afir(i, a, b) for (int i = (int)a; i >= b; --i)
#define ft first
#define vi vector<int>
#define sd second
#define ALL(a) a.begin(), a.end()
#define bug puts("-------")
#define mpr(a, b) make_pair(a, b)
#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 10;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch <= '9' && ch >= '0')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main()
{
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if (a > b)
	{
		if (2 * x < y)
			y = 2 * x;
		cout << (a - b - 1) * y + x;
	}
	else
	{
		if (2 * x < y)
			y = 2 * x;
		cout << (b - a) * y + x;
	}

	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a, b, x, y;
	cin >> a >> b >> x >> y;
	if (a < b)
		cout << min(x * abs(b - a) * 2 + x, y * abs(b - a) + x);
	else if (a > b)
		cout << min(x * (a - b) * 2 - x, y * (a - b - ((!a - b) & 1)) + x);
	else
		cout << x << '\n';
}
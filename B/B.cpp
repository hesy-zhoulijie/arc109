#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	ll n;
	cin >> n;
	ll l = 0, r = 2e9;
	while (r - l > 1)
	{
		ll m = (l + r) / 2;
		(m * (m + 1) / 2 <= n + 1 ? l : r) = m;
	}
	cout << n - l + 1 << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f;
const double pi = 3.1415926535897932384626;
inline ll read()
{
	ll x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
ll n, i;
int main()
{
	n = read();
	for (i = 1;; i++)
	{
		if ((i + 1) * i / 2 <= n + 1 && (i + 2) * (i + 1) / 2 > n + 1)
			break;
	}
	printf("%lld\n", n - i + 1);
	return 0;
}
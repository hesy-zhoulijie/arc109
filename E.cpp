#include "atcoder/all"
#include "bits/stdc++.h"
using namespace std;
using namespace atcoder;
using mint = modint998244353;
#define endl "\n"
int main()
{
	int N;
	cin >> N;
	mint half = (mint)N / 2;
	mint anssub = 1; //1/2^n
	for (int i = 0; i < N; ++i)
	{
		anssub /= 2;
	}
	vector<mint> memo(N, 0); //Σ2 ^ (2 * j - 1)*(2 * j + 1)
	mint twop = 1;
	twop /= 2;
	for (int i = 1; i < N; ++i)
	{
		twop *= 2;
		twop *= 2;
		memo[i] = memo[i - 1] + twop * (2 * i + 1);
	}
	for (int i = 0; i < N; ++i)
	{
		if ((0 == i) || ((N - 1) == i))
		{
			cout << half.val() << endl;
			continue;
		}
		mint ans = memo[min(i - 1, N - 2 - i)];
		ans *= anssub;
		ans += half;
		cout << ans.val() << endl;
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
static const ll mod = 998244353;
ll modpow(ll a, ll n)
{
	ll res = 1;
	while (0 < n)
	{
		if (n % 2 == 1)
			res = (res * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return res;
}
ll N;
ll sum[200005];
int main()
{
	cin >> N;
	ll a = 2;
	for (ll i = 1; i < 200005; i++)
	{
		sum[i] = ((2 * i + 1) * a + sum[i - 1]) % mod;
		a = (a * 4) % mod;
	}
	ll x = (N * modpow(2, mod - 2)) % mod;
	ll y = modpow(2, N);
	y = modpow(y, mod - 2);
	for (ll i = 1; i <= N; i++)
	{
		ll Min = min(i - 2, N - 1 - i);
		if (Min <= 0)
			Min = 0;
		cout << (x + sum[Min] * y) % mod << endl;
	}

	return 0;
}
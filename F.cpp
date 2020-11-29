#include <bits/stdc++.h>
#define For(i, a, b) for (int i = (a); i <= (b); i++)
using namespace std;
void ckmin(int &a, int b)
{
	a = min(a, b);
}
const int N = 100015;
int n;
char s[N], t[N];
int aa[N], bb[N];
int dp[N][2][2][2][3][4];
int jd[3] = {3, 3, 1};
int nd[3][3] = {{0, 1, 0}, {0, 0, 0}, {1}};
int solve()
{
	memset(dp, 63, sizeof dp);
	dp[0][0][0][0][0][0] = 0;
	int ans = 1e9;
	For(i, 1, n) For(a, 0, 1) For(b, 0, 1) For(c, 0, 1) For(d, 0, 2) For(e, 0, 3)
	{
		int v = dp[i - 1][a][b][c][d][e];
		if (v > 1e6)
			continue;
		if (!c)
		{
			if (bb[i - 1])
				continue;
			if (!bb[i])
				ckmin(dp[i][a][b][0][0][0], v);
			if (aa[i - 1] == 0)
			{
				ckmin(dp[i][a][b][1][0][1 + aa[i]], v - i);
				if (!a)
					ckmin(dp[i][1][b][1][1][1 + 1], v - i);
			}
			else
			{
				ckmin(dp[i][a][b][1][0][!aa[i]], v - i);
				if (!a)
					ckmin(dp[i][1][b][1][1][!aa[i]], v - i);
			}
			if (!b)
				ckmin(dp[i][a][1][1][2][aa[i]], v - i);
		}
		else
		{
			ckmin(dp[i][a][b][c][d][e == jd[d] ? e : e + (aa[i] == nd[d][e] || (d == 1 && e == 1))], v);
			if (!bb[i] && (e >= jd[d] || (d != 2 && e == jd[d] - 1 && aa[i] == nd[d][e])))
				ckmin(dp[i][a][b][0][0][0], v + i);
		}
	}
	For(a, 0, 1) For(b, 0, 1) For(d, 0, 2) For(e, 0, 3)
		ckmin(ans, dp[n][a][b][0][d][e]);
	return ans;
}
int main()
{
	cin >> n;
	scanf("%s%s", s + 1, t + 1);
	For(i, 1, n)
		aa[i + 2] = s[i] == 'w' ? 0 : 1;
	aa[n + 3] = aa[n + 4] = aa[n + 5] = 1;
	For(i, 1, n)
		bb[i + 2] = t[i] == 'o';
	n += 4;
	int ans = solve();
	For(i, 0, n + 1)
		aa[i] ^= 1;
	ckmin(ans, solve());
	cout << ans << endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	string _s, _t;
	cin >> n >> _s >> _t;
	int ans = n;
	const int M = int(1e9);

	auto chk = [&](int &a, int b) {
		a = min(a, b);
	};
	for (int z = 0; z < 2; z++)
	{
		string s = "wwww" + _s + "bbbb";
		string t = "____" + _t + "____";
		vector<vector<int>> best(4, vector<int>(9, M));
		best[0][8] = 0;
		for (int i = 1; i + 1 < (int)s.size(); i++)
		{
			for (int seen = 0; seen < 4; seen++)
			{
				chk(best[seen][8], best[seen][7]);
				if (seen & 1)
					chk(best[seen][8], best[seen ^ 1][1]);
				if (seen & 2)
					chk(best[seen][8], best[seen ^ 2][3]);
			}
			for (int seen = 0; seen < 4; seen++)
			{
				chk(best[seen][0], best[seen][8]);
				chk(best[seen][2], best[seen][8]);
				chk(best[seen][4], best[seen][8]);
			}
			for (int seen = 0; seen < 4; seen++)
			{
				if (t[i] == 'o')
					best[seen][8] = M;
				for (int r = 0; r < 8; r++)
				{
					best[seen][r] += 1;
				}
			}
			for (int seen = 0; seen < 4; seen++)
			{
				if (s[i] == 'b')
				{
					chk(best[seen][1], best[seen][0]);
				}
				if (s[i - 1] == 'w' && s[i + 1] == 'w')
				{
					chk(best[seen][3], best[seen][2]);
				}
				if (s[i - 1] == 'w')
				{
					chk(best[seen][5], best[seen][4]);
				}
				if (s[i] == 'b')
				{
					chk(best[seen][6], best[seen][5]);
				}
				if (s[i + 1] == 'w')
				{
					chk(best[seen][7], best[seen][6]);
				}
			}
		}
		for (int seen = 0; seen < 4; seen++)
		{
			ans = min(ans, best[seen][8]);
		}
		for (char &c : _s)
			c = c ^ 'w' ^ 'b';
		reverse(_s.begin(), _s.end());
		reverse(_t.begin(), _t.end());
	}
	cout << ans << '\n';
}
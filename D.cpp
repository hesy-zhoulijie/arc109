#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    long long cx = 0, cy = 0;
    for (int i = 0; i < 3; ++i) {
      int x, y;
      cin >> x >> y;
      cx += x, cy += y;
    }

    cx -= cx / 3 + (cx > 0);
    cy -= cy / 3 + (cy > 0);

    if (cx == cy && cx != 0 && cx != 1) {
      cout << abs(cx) + 1 << "\n";
    } else {
      cout << max(abs(cx), abs(cy)) << "\n";
    }
  }
}

#include <iostream>

long long solve (long long x, long long y) {
	x -= x / 3 + (x > 0);
	y -= y / 3 + (y > 0);
	if (x == 0 and y == 0) return 0;
	if (x == 1 and y == 1) return 1;
	return std::max(std::abs(x), std::abs(y)) + (x == y);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int TestCase;
	std::cin >> TestCase;
	while (TestCase--) {
		long long a, b, c, d, e, f;
		std::cin >> a >> b >> c >> d >> e >> f;
		std::cout << solve(a + c + e, b + d + f) << '\n';
	}
	return 0;
}
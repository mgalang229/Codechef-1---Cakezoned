#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long even = 0;
	long long odd = 0;
	// precompute the values in the odd and even positions
	for (int i = 0; i < n; i++) {
		int h;
		cin >> h;
		if ((i + 1) % 2 == 0) {
			even += h;
		} else {
			odd += h;
		}
	}
	int q;
	cin >> q;
	// get the queries
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			// in type 1, get the input of 'l', 'r', 'x'
			long long l, r, x;
			cin >> l >> r >> x;
			if (l % 2 == 0 && r % 2 == 0) {
				// if 'l' and 'r' have the same parity (even), then there 
				// would be an odd number of elements covering the range (inclusive)
				// in this case, the even-positioned numbers would populate the odd occurrences 
				// (that's why there is a plus one in the calculation of 'even')
				even += ((1 + (r - l) / 2) * x);
				// while, the odd-positioned numbers would populate the even occurrences
				odd += (((r - l) / 2) * x);
			} else if (l % 2 == 1 && r % 2 == 1) {
				// if 'l' and 'r' have the same parity (odd), then there
				// would be an odd number of elements covering the range (inclusive)
				// in this case, the odd-positioned numbers would populate the odd occurrences
				// (that's why there is a plus one in the calculation of 'odd')
				odd += ((1 + (r - l) / 2) * x);
				// while, the even-positioned numbers would populate the even occurrences
				even += (((r - l) / 2) * x);
			} else {
				// in the final case, 'l' and 'r' have different parity (i.e., 'l' is even and 'r' is odd)
				// more importantly, the number of elements covering this range would be even
				// therefore, the odd and even occurrences are also even
				even += (((r - l + 1) / 2) * x);
				odd += (((r - l + 1) / 2) * x);
			}
		} else if (type == 2) {
			// in type 2, print the total sum of odd-positioned elements
			cout << odd << '\n';
		} else {
			// in type 3, print the total sum of even-positioned elements
			cout << even << '\n';
		}
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int helper(int l, int r, char c) {
  if (l == r) {
    return s[l] != c;
  }
  int ans1 = 0, ans2 = 0;
  int mid = (l + r) >> 1;
  for (int i = l; i <= mid; i++) {
    if (s[i] != c) {
      ans1++;
    }
  }
  for (int i = mid + 1; i <= r; i++) {
    if (s[i] != c) {
      ans2++;
    }
  }
  ans1 += helper(mid + 1, r, c + 1);
  ans2 += helper(l, mid, c + 1);
  return min(ans1, ans2);
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> s;
    cout /*<< "ans:" */ << helper(0, n - 1, 'a') << endl;
  }
  return 0;
}
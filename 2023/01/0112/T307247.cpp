#include <bits/stdc++.h>
using namespace std;
int cnt1 = 0, cnt2 = 0;
int main() {
  int n;
  cin >> n;
  vector<vector<int> > a(n);
  set<int> s;
  map<int, int> m;
  for (auto &i : a) {
    int k;
    cin >> k;
    i.resize(k);
    for (auto &j : i) {
      cin >> j;
      s.emplace(j);
    }
  }
  for (auto &i : s) {
    m[i] = ++cnt1;
  }
  for (auto &i : a) {
    for (auto &j : i) {
      j = m[j];
    }
  }
  for (auto &i : a) {
    for (int j = 1; j < i.size(); j++) {
      if (i[j] - i[j - 1] > 1 || i[j] - i[j - 1] < 0) {
        cnt2++;
      }
    }
  }
  cout << cnt2 << ' ' << cnt2 + n - 1 << endl;
  return 0;
}
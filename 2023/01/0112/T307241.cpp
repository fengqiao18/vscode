#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
char s[200005], t[200005];
int cnt1 = 0, cnt2 = 0;
vector<int> pos;
vector<bool> p;
inline void count(int n) {
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1') {
      cnt1++;
    }
    if (t[i] == '1') {
      cnt2++;
    }
  }
  return;
}
int main() {
  int n;
  cin >> n >> (s + 1) >> (t + 1);
  p.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] != t[i]) {
      pos.push_back(i);
    }
  }
  if (pos.size() & 1) {
    cout << -1;
    return 0;
  }
  count(n);
  if (cnt1 == cnt2) {
    for (int i = 1; i <= n; i++) {
      cout << 0;
    }
  } else if (cnt1 > cnt2) {
    for (int i = 1; i <= n; i++) {
      p[i] = 0;
    }
    int dif = cnt1 - cnt2;
    int len = pos.size() - 1;
    for (int i = len; ~i; --i) {
      if (dif == 0) {
        break;
      }
      if (s[pos[i]] == '1' && t[pos[i]] == '0') {
        p[pos[i]] = 1, dif -= 2;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << p[i];
    }
  } else {
    for (int i = 1; i <= n; i++) {
      p[i] = 0;
    }
    int dif = cnt2 - cnt1;
    int len = pos.size() - 1;
    for (int i = len; ~i; --i) {
      if (dif == 0) {
        break;
      }
      if (t[pos[i]] == '1' && s[pos[i]] == '0') {
        p[pos[i]] = 1, dif -= 2;
      }
    }
    for (int i = 1; i <= n; i++) {
      cout << p[i];
    }
  }
  return 0;
}
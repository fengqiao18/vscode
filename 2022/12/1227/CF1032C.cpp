#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], ans[N];
bool f[N][6];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= 5; i++) {
    f[1][i] = 1;
  }
  for (int i = 2; i <= n; i++) {
    if (a[i - 1] < a[i]) {
      for (int j = 1; j <= 5; j++) {
        if (f[i - 1][j]) {
          for (int k = j + 1; k <= 5; k++) {
            f[i][k] = 1;
          }
          break;
        }
      }
    } else if (a[i - 1] > a[i]) {
      for (int j = 5; j; j--) {
        if (f[i - 1][j]) {
          for (int k = j - 1; k; k--) {
            f[i][k] = 1;
          }
          break;
        }
      }
    } else {
      for (int j = 1; j <= 5; j++) {
        for (int k = 1; f[i - 1][j] && k <= 5; k++) {
          f[i][k] |= j != k;
        }
      }
    }
  }
  for (int i = 5; i; i--) {
    if (f[n][i]) {
      ans[n] = i;
      break;
    }
  }
  if (!ans[n]) {
    cout << -1;
    return 0;
  }
  for (int i = n - 1; i; i--) {
    if (a[i] < a[i + 1]) {
      for (int j = ans[i + 1] - 1; j; j--) {
        if (f[i][j]) {
          ans[i] = j;
          break;
        }
      }
    } else if (a[i] > a[i + 1]) {
      for (int j = ans[i + 1] + 1; j <= 5; j++){
        if (f[i][j]) {
          ans[i] = j;
          break;
        }
      }
    } else {
      for (int j = 1; j <= 5; j++)
        if (f[i][j] && j != ans[i + 1]) {
          ans[i] = j;
          break;
        }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] <<" ";
  }
  return 0;
}
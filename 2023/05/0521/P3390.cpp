#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 105;
const int mod = 1e9 + 7;
int n;
struct matrix {
  int a[N][N];
  matrix() {
    memset(a, 0, sizeof(a));
  }
  void build() {
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++) {
      a[i][i] = 1;
    }
  }
  friend matrix operator*(const matrix A, const matrix B) {
    matrix C;
    for (int k = 1; k <= n; k++) {
      for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
          C.a[i][j] = (C.a[i][j] + A.a[i][k] * B.a[k][j] % mod) % mod;
        }
      }
    }
    return C;
  }
};
matrix a;
void init() {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a.a[i][j];
    }
  }
}
matrix fpow(matrix a, int k) {
  matrix ans;
  ans.build();
  do {
    if (k % 2 == 1) {
      ans = ans * a;
    }
    a = a * a;
    k >>= 1;
  } while (k);
  return ans;
}
signed main() {
  int k;
  cin >> n >> k;
  init();
  matrix ans = fpow(a, k);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << ans.a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
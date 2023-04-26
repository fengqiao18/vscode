#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const double EPS = 1e-6;
double a[N], mini[N], grade[N];
double maxi, sum;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  mini[n] = a[n];
  for (int i = n - 1; i >= 1; i--) {
    mini[i] = min(a[i], mini[i + 1]);
  }
  for (int i = 1; i <= n - 2; ++i) {
    sum -= a[i];
    grade[i] = (sum - mini[i + 1]) / (n - i - 1);
    maxi = max(grade[i], maxi);
  }
  for (int i = 1; i <= n - 2; ++i) {
    if (maxi - grade[i] < EPS && maxi - grade[i] > -EPS) {
      cout << i << endl;
    }
  }
  return 0;
}

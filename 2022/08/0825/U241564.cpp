#include<bits/stdc++.h>
using namespace std;
const int N = 11;
struct E {   
  bool b[N][N];  
  int t, xl, xr, yl, yr; 
} e[N];
int c[N][N], n, k, i1, i2; 
bool P(int o, int x, int y) {  
  for (int i = e[o].xl; i <= e[o].xr; i++) {
    for (int j = e[o].yl; j <= e[o].yr; j++) {                 
      if ((c[i + x][j + y] += e[o].b[i][j]) > e[0].b[i + x][j + y]) {  
        return 0;
      }
    }
  }
  return 1;
}
void helper() {  
  for (i1 = 1; i1 <= k; i1++) {
    for (i2 = i1 + 1; i2 <= k; i2++) {  
      if (e[i1].t + e[i2].t == e[0].t) {  
        for (int x1 = 1 - e[i1].xl; x1 <= n - e[i1].xr; x1++) {
          for (int y1 = 1 - e[i1].yl; y1 <= n - e[i1].yr; y1++) {  
            for (int x2 = 1 - e[i2].xl; x2 <= n - e[i2].xr; x2++) {
              for (int y2 = 1 - e[i2].yl; y2 <= n - e[i2].yr; y2++) {  
                fill(c[0], c[n + 1], 0);                              
                if (P(i1, x1, y1) && P(i2, x2, y2)) {                 
                  return;
                }
              }
            }
          }
        }
      }
    }
  }
}
int main() {
  cin >> n >> k;
  for (int i = 0; i <= k; i++) {
    e[i].xl = e[i].yl = n + 1;
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        char ch;
        cin >> ch;
        if (ch == '#') {
          e[i].t += e[i].b[x][y] = 1; 
          e[i].xl = min(e[i].xl, x), e[i].xr = max(e[i].xr, x);
          e[i].yl = min(e[i].yl, y), e[i].yr = max(e[i].yr, y);
        }
      }
    }
  }
  helper();
  cout << i1 << " " << i2;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int size[130];
int dfs(string q, string z) {
  if (q.size() == 0) {
    return 0;
  }
  if (q.size() == 1) {
    return size[q[0]] = 1;
  }
  int pos = z.find(q[0]);
  int tmp1 = dfs(q.substr(1, pos), z.substr(0, pos));
  int tmp2 = dfs(q.substr(pos + 1), z.substr(pos + 1));
  return size[q[0]] = tmp1 + tmp2;
}
int main() {
  string q, z;
  cin >> q >> z;
  int tmp = dfs(q, z);
  for (int i = 0; i < q.size(); i++) {
    for (int j = 1; j <= size[q[i]]; j++) {
      cout << q[i];
    }
    cout << endl;
  }
  return 0;
}
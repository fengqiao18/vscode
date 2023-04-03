#include <bits/stdc++.h>
using namespace std;
bool vis[26];
vector<int> G[26];
int ideg[26], odeg[26];
void dfs(int cur) {
  vis[cur] = 1;
  for (int i = 0; i < G[cur].size(); i++) {
    int tmp = G[cur][i];
    if (!vis[tmp]) {
      dfs(tmp);
    }
  }
  return;
}
bool f() {
  int cnt1 = 0, cnt2 = 0;
  for (int i = 0; i < 26; i++) {
    if (ideg[i] || odeg[i]) {
      dfs(i);
      break;
    }
  }
  for (int i = 0; i < 26; i++) {
    if ((ideg[i] || odeg[i]) && !vis[i]) {
      return 0;
    }
  }
  for (int i = 0; i < 26; i++) {
    if (abs(ideg[i] - odeg[i]) > 1) {
      return 0;
    }
    else if (!(ideg[i] ^ (odeg[i] + 1))) {
      cnt1++;
      if (!(cnt1 ^ 2)) {
        return 0;
      }
    }
    else if (!(ideg[i] ^ (odeg[i] - 1))) {
      cnt2++;
      if (!(cnt2 ^ 2)) {
        return 0;
      }
    } else {
			continue;
		}
  }
  return 1;
}
bool helper() {
  memset(ideg, 0, sizeof(ideg));
  memset(odeg, 0, sizeof(odeg));
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < 26; i++) {
    G[i].clear();
  }
  int m;
	cin>>m;
  while(m--) {
    string s;
    cin >> s;
    int x = s[0] - 'a', y = s[s.size() - 1] - 'a';
    G[x].push_back(y), G[y].push_back(x);
    ideg[y]++, odeg[x]++;
  }
	return f();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    cout << (helper() ? "Ordering is possible." : "The door cannot be opened.") << endl;
  }
  return 0;
}
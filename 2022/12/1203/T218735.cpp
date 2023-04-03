#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
struct node {
  int prev, next;
  char c;
};
node a[N];
int tot, n;
int fd(int x) {
  int i = 0;
  if (x <= 11) {
    for (; x; i = a[i].next, x--) {
    }
  } else {
    for (x = tot - x + 1; x; i = a[i].prev, x--) {
    }
  }
  return i;
}
void insert(int x) {
  int i = fd(x);
  a[n].prev = i, a[n].next = a[i].next;
  a[a[i].next].prev = n, a[i].next = n;
  tot++;
  return;
}
void del(int x) {
  int i = fd(x);
  a[a[i].prev].next = a[i].next;
  a[a[i].next].prev = a[i].prev;
  tot--;
}
int main() {
  ios ::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int q;
  cin >> q;
  while (q--) {
    char o;
    int x;
    cin >> o >> x;
    if (o == 'I') {
      cin >> a[++n].c;
      insert(x);
    } else {
      del(x);
    }
  }
  for (int i = a[0].next; i; i = a[i].next) {
    cout << a[i].c;
  }
  return 0;
}
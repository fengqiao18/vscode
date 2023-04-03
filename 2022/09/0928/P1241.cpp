#include <bits/stdc++.h>
using namespace std;
int top, w[110];
string a;
char s[110], c[110];
int main() {
  cin >> a;
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == '(' || a[i] == '[') {
      s[++top] = a[i];
      w[top] = i;
      if (a[i] == '(')
        c[i] = ')';
      else
        c[i] = ']';
    }
    if (a[i] == ')') {
      if (top && s[top] == '(') {
        c[w[top]] = ' ';
        top--;
      } else
        c[i] = '(';
    }
    if (a[i] == ']') {
      if (top && s[top] == '[') {
        c[w[top]] = ' ';
        top--;
      } else
        c[i] = '[';
    }
  }
  for (int i = 0; i < a.size(); i++) {
    if (c[i] == '(' || c[i] == '[')
      cout << c[i] << a[i];
    else if (c[i] == ')' || c[i] == ']')
      cout << a[i] << c[i];
    else
      cout << a[i];
  }
  return 0;
}
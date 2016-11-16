#include<bits/stdc++.h>      //Includes all header files
using namespace std;

int mini(int n_2, int n_5, int n_6) {
  return min(min(n_2, n_5), min(n_5, n_6));
}

long long int answer (int n_2, int n_3, int n_5, int n_6) {
  long long int ans = 0;
  ans += 256*mini(n_2, n_5, n_6);
  n_2 -= mini(n_2, n_5, n_6);
  ans += 32*min(n_2, n_3);
  return ans;
}

int main () {
  int n_2, n_3, n_5, n_6;
  cin >> n_2 >> n_3 >> n_5 >> n_6;
  cout << answer(n_2, n_3, n_5, n_6);
  return 0;
}

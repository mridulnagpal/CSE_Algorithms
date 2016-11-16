#include<bits/stdc++.h>  //Includes all header files
using namespace std;

int winner(string str, int length) {
  int count = 0;
  for (int i = 0; i < length; i++) {
    if(str[i] == 'A')
      count++;
      else
       count--;
  }
  return count;
}

int main () {
  string str;
  int length;
  cin >> length >> str;
  if (winner(str, length) > 0)
    cout << "Anton\n";
  else if (winner(str, length) < 0)
    cout << "Danik\n";
  else
    cout << "Friendship\n";
  return 0;
}

#include <iostream>
#include <string>
using namespace std;

bool isCircular(string s, string t) {
  return (s.length() == t.length() && (s + s).find(t) != string::npos);
}

int main() {
  cout << isCircular("waterbottle", "erbottlewat") << endl;
}
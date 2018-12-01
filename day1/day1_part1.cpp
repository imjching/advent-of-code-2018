#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define trav(a, v) for (auto &a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int current = 0;
    string line;
    while (getline(cin, line)) {
      if (line[0] == '-') {
        current -= stoi(line.substr(1));
      } else {
        current += stoi(line.substr(1));
      }
    }
    cout << current << endl;

    return 0;
}

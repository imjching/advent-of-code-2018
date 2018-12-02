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

    vector<string> lines;
    string line;
    while (getline(cin, line)) {
      lines.emplace_back(line);
    }

    // Inefficient Algorithm
    for (int i = 0; i < lines.size(); ++i) {
      for (int j = i + 1; j < lines.size(); ++j) {
        if (lines[i].length() != lines[j].length()) {
          continue;
        }

        int diff = 0, last_index = -1;
        for (int z = 0; lines[i][z]; ++z) {
          if (lines[i][z] != lines[j][z]) {
            ++diff;
            last_index = z;
          }
        }

        if (diff == 1) {
          cout << (lines[i].substr(0, last_index) + lines[i].substr(last_index + 1)) << endl;
        }
      }
    }

    return 0;
}

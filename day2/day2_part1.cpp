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

    int twice, thrice;
    twice = thrice = 0;
    string line;
    while (getline(cin, line)) {
      int freq[26] = {0};
      rep(i, 0, sz(line)) {
        ++freq[line[i] - 'a'];
      }
      bool o, t;
      o = t = false;
      rep(i, 0, 26) {
        if (!o && freq[i] == 2) {
          ++twice;
          o = true;
        }
        if (!t && freq[i] == 3) {
          ++thrice;
          t = true;
        }
      }
    }

    cout << (twice * thrice) << endl;

    return 0;
}

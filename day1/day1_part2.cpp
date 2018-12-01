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

    vector<string> input;
    string line;
    while (getline(cin, line)) {
      input.emplace_back(line);
    }

    unordered_set<int> freqs;
    int current = 0;
    while (true) {
      trav(it, input) {
        if (freqs.count(current) > 0) {
          goto end;
        }
        freqs.insert(current);
        if (it[0] == '-') {
          current -= stoi(it.substr(1));
        } else {
          current += stoi(it.substr(1));
        }
      }
    }
end:
    cout << current << endl;

    return 0;
}

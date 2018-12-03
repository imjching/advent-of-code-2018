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

  vector<vi> grid;
  grid.resize(3000);
  trav(a, grid) {
    // a.resize(3000);
    a.assign(3000, 0);
  }

  string line;
  while (getline(cin, line)) {
    // cout << line << endl;
    auto align = line.find('@');
    auto align2 = line.find(':');

    string offset = line.substr(align + 2, align2);
    string size = line.substr(align2 + 2);

    auto a = offset.find(',');
    int left = stoi(offset.substr(0, a));
    int top = stoi(offset.substr(a + 1));

    auto b = size.find('x');
    int width = stoi(size.substr(0, b));
    int height = stoi(size.substr(b + 1));

    for (int j = 0; j < height; ++j) {
      for (int i = 0; i < width; ++i) {
        ++grid[j + top][i + left];
      }
    }
    // cout << left << " " << top << " " << width << " " << height << endl;
  }

  int count = 0;
  trav(a, grid) {
    trav(b, a) {
      if (b >= 2) {
        ++count;
      }
    }
  }

  cout << count << endl;

  return 0;
}

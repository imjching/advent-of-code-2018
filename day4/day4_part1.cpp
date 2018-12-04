#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < int(b); ++i)
#define trav(a, v) for (auto &a : v)
#define all(x) x.begin(), x.end()
#define sz(x) (int) (x).size()
#define INF 1000000000

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct entry {
  int year, month, day, hour, minute, action;
};

bool operator<(const entry &e1, const entry &e2) {
  return tie(e1.year, e1.month, e1.day, e1.hour, e1.minute) <
         tie(e2.year, e2.month, e2.day, e2.hour, e2.minute);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  vector<entry> input;
  string line;
  while (getline(cin, line)) {
    string date = line.substr(1, 10);
    string time = line.substr(12, 5);
    string message = line.substr(19);

    int action = 0; // -2 = wakes up, -1 = falls asleep, id = guard ID
    if (message.find("wakes") != string::npos) {
      action = -2;
    } else if (message.find("falls") != string::npos) {
      action = -1;
    } else {
      auto space = line.substr(6).find(' ');
      action = stoi(message.substr(6).substr(1, space));
    }

    input.push_back({
      stoi(date.substr(0, 4)),
      stoi(date.substr(5, 2)),
      stoi(date.substr(8, 2)),
      stoi(time.substr(0, 2)),
      stoi(time.substr(3, 2)),
      action
    });
  }

  sort(input.begin(), input.end());

  unordered_map<int, array<int, 60>> schedule;
  unordered_map<int, int> sleep_sum;

  int prev_id = -1, sleep_start = -1;
  trav(a, input) {
    if (a.action >= 0) {
      schedule[prev_id]; // init map
      prev_id = a.action;
    } else if (a.action == -1) { // falls asleep
      sleep_start = a.minute;
    } else {
      rep(i, sleep_start, a.minute) {
        schedule[prev_id][i] += 1;
      }
      sleep_sum[prev_id] += (a.minute - sleep_start);
    }
  }

  // Find guard that sleeps the most
  int sleep_count = -INF, guard = INF;
  trav(s, sleep_sum) {
    if (s.second > sleep_count) {
      sleep_count = s.second;
      guard = s.first;
    }
  }

  // Find minute that has the most overlaps
  int day_count = -INF, minute_id = -INF;
  rep(i, 0, 60) {
    if (schedule[guard][i] > day_count) {
      day_count = schedule[guard][i];
      minute_id = i;
    }
  }

  cout << "Guard " << guard << " spent the most minutes asleep during minute " << minute_id << "." << endl;

  return 0;
}

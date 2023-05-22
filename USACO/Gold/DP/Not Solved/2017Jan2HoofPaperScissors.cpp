#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define endl "\n"
#define int int64_t
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FOR0(i, a) FOR(i, 0, a)
#define FOR1(i, a) for (int i = (1); i <= (a); ++i)
#define TRAV(a, x) for (auto &a : x)

using pii = pair<int, int>;
using vi = vector<int>;

int addone(int a, int b) {
  if (a == 0 && b == 1) {
    return 1;
  }
  if (a == 1 && b == 2) {
    return 1;
  }
  if (a == 2 && b == 0) {
    return 1;
  }
  return 0;
}

int dp[100][100000 + 5][3];
void fileIO(string filename) {
  freopen((filename + ".in").c_str(), "r", stdin);
  freopen((filename + ".out").c_str(), "w", stdout);
}

int32_t main() {
  fileIO("hps");
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  int in[N + 1];
  FOR1(i, N) {
    char a;
    cin >> a;
    if (a == 'P') {
      in[i] = 0;
    } else if (a == 'H') {
      in[i] = 1;
    } else {
      in[i] = 2;
    }
  }

  dp[0][0][0] = 0;
  dp[0][0][1] = 0;
  dp[0][0][2] = 0;
  int ans = 0;
  FOR1(i, N) {
    FOR1(j, (K + 1)) {
      int add = addone(0, in[i]);
      dp[j][i][0] = max(dp[j][i - 1][0] + add, max(dp[j - 1][i - 1][2] + add,
                                                   dp[j - 1][i - 1][1] + add));

      add = addone(1, in[i]);
      dp[j][i][1] = max(dp[j][i - 1][1] + add, max(dp[j - 1][i - 1][2] + add,
                                                   dp[j - 1][i - 1][0] + add));

      add = addone(2, in[i]);
      dp[j][i][2] = max(dp[j][i - 1][2] + add, max(dp[j - 1][i - 1][0] + add,
                                                   dp[j - 1][i - 1][1] + add));
      if (i == N) {
        ans = max(ans, max(dp[j][N][0], max(dp[j][N][1], dp[j][N][2])));
      }
    }
  }
  cout << ans << endl;
  ;

  return 0;
}

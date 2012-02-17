#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
const double EPS = 1e-10;
const double PI  = acos(-1.0);
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define check(x) cerr << #x << " = "; REP(q,(x).size()) cerr << (x)[q] << " "; cerr << endl;

template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& stream, const std::pair<T1, T2>& data) {
  return stream << "(" << data.first << "," << data.second << ")";
}

static const LL MOD = 1000000007;

int main() {
  int n, m, k;
  cin >> n >> m >> k;

  LL answer = 1;
  if (k > n ||k == 1) {
    REP(i, n) {
      answer *= m;
      answer %= MOD;
    }
  } else if (k == n) {
    REP(i, (n+1)/2) {
      answer *= m;
      answer %= MOD;
    }
  } else {
    if (k % 2 == 0) {
      answer = m;
    } else {
      answer = m * m;
    }
  }
  cout << answer << endl;
}

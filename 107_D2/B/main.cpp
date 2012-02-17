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

bool isIdentical(int digits[]) {
  REP(i, 6) {
    if (digits[i] != digits[0]) return false; 
  }
  return true;
}

bool isDecreasing(int digits[]) {
  int last = digits[0];
  for (int i = 1; i < 6; i++) {
    if (digits[i] >= last) return false;
    last = digits[i];
  }
  return true;
}

void printNames(vector<string>& names) {
  REP(i, names.size()) {
    if (i != names.size()-1) cout << names[i] << ", ";
    else cout << names[i] << "." << endl;
  }
}

int main() {
  int N; cin >> N;
  vector<string> names[3];
  vector<int> maxNums(3, 0);
  REP(i, N) {
    int numbers;
    string name;
    cin >> numbers >> name;
    vector<int> counts(3, 0);
    REP(j, numbers) {
      string phone; cin >> phone;
      int digits[6];
      REP(k, 6) digits[k] = phone[k/2*3 + k%2] - '0';
      if (isIdentical(digits)) {
        counts[0]++;
      } else if (isDecreasing(digits)) { 
        counts[1]++;
      } else {
        counts[2]++;
      }
    }

    REP(k, 3) {
      if (counts[k] == maxNums[k]) {
        names[k].push_back(name);
      } else if (counts[k] > maxNums[k]) {
        names[k].clear();
        names[k].push_back(name);
        maxNums[k] = counts[k];
      }
    }
  }

  cout << "If you want to call a taxi, you should call: ";
  printNames(names[0]);
  cout << "If you want to order a pizza, you should call: ";
  printNames(names[1]);
  cout << "If you want to go to a cafe with a wonderful girl, you should call: ";
  printNames(names[2]);
}


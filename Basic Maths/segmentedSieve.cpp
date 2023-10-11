#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<bool> Sieve(int n) {
  vector<bool> sieve(n + 1, true);

  sieve[0] = sieve[1] = false;
  for (int i = 2; i < sqrt(n); i++) {
    if (sieve[i]) {
      int j = i * i;
      while (j < n) {
        sieve[j] = false;
        j += i;
      }
    }
  }
  return sieve;
}

vector<bool> segmentedSieve(int L, int R) {
  vector<bool> primes = Sieve(sqrt(R));
  vector<int> basePrimes;

  for (int i = 0; i < primes.size(); i++) {
    if (primes[i]) {
      basePrimes.push_back(i);
    }
  }

  vector<bool> segSieve(R - L + 1, true);
  if (L == 0 || L == 1) {
    segSieve[L] = false;
  }
  for (auto prime : basePrimes) {
    int fm = (L / prime) * prime; // first divide hone wala number with prime in that range
    fm = fm < L ? fm + prime : fm; // if fm chota hh L se toh usme ith prime add krdo
    int j = max(fm, prime * prime);
    while (j <= R) {
      segSieve[j - L] = false;
      j += prime;
    }
  }
  return segSieve;
}

int main() {
  // vector<bool> sieve = Sieve(25);
  // for (int i = 0; i < 25; i++) {
  //   if (sieve[i]) {
  //     cout << i << " ";
  //   }
  // }
  int L = 110;
  int R = 130;
  vector<bool> segSieve = segmentedSieve(L, R);
  for (int i = 0; i < segSieve.size(); i++) {
    if (segSieve[i]) {
      cout << L + i << " ";
    }
  }
  cout<<endl;
  return 0;
}

// time complexity: O(nloglogn)
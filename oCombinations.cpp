#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000003;  
const int MAX = 1000000;
long long fact[MAX + 5];
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % MOD;  
        base = (base * base) % MOD;
        exp >>= 1; 
    }
    return res;
}

// Modular Inverse
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// Precompute factorials
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= MAX; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
}

void solve(int caseNum) {
    int n, k;
    cin >> n >> k;

    if (k > n) {
        cout << "Case " << caseNum << ": 0\n"; 
        return;
    }
    if (k == 0 || k == n) {
        cout << "Case " << caseNum << ": 1\n";
        return;
    }

    long long num = fact[n];
    long long den = (fact[k] * fact[n - k]) % MOD;
    long long ans = (num * modInverse(den)) % MOD;

    cout << "Case " << caseNum << ": " << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        solve(i);
    }

    return 0;
}
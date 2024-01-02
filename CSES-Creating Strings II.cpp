#include <bits/stdc++.h>
using namespace std;
#define trav(a, x) for(auto& a : x)
#define vi vector<int> 
typedef long long ll;

const int mod = 1e9 + 7, MOD = 998244353;

const int MAXN = 1e6;

long long fac[MAXN + 1], inv[MAXN + 1];
		
/** Computes x^y modulo p in O(log p) time. */
long long exp(long long x, long long y, long long p) {
	long long res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
}

/** Precomputes all modular inverse factorials from 0 to MAXN in O(n log p) time */
void inverses(long long p) {
	inv[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		inv[i] = exp(fac[i], p - 2, p);
	}
}
		
/** Computes nCr mod p */
long long choose(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}

int main()
{	
    
    factorial(mod);
    inverses(mod);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> count(26, 0);
    for(int i = 0; i < n; ++i) {
        
        int p = s[i] - 'a';
        count[p]++;
    } 
    ll res = 1;
    res *= fac[n];
    res = (res+mod)%mod;
    for(int i = 0; i < 26; ++i) {
        if(count[i] != 0) {
            res *= inv[count[i]];
            res = (res+mod)%mod;
        }
    }
    cout << res << "\n";
    return 0;
}




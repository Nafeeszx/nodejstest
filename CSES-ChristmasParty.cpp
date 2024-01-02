#include <bits/stdc++.h>
using namespace std;
#define trav(a, x) for(auto& a : x)
#define vi vector<int> 
typedef long long ll;

const int mod = 1e9 + 7, MOD = 998244353;

const int MAXN = 1e6;

long long fac[MAXN + 1], inv[MAXN + 1];
		
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

void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		fac[i] = fac[i - 1] * i % p;
	}
}

void inverses(long long p) {
	inv[0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		inv[i] = exp(fac[i], p - 2, p);
	}
}
		
int main()
{	
    
    factorial(mod);
    inverses(mod);
    int n;
    cin >> n;
    ll res = 0;
    for(int i = 0; i <= n; ++i) {
        if(i % 2 == 0) {
            res += inv[i];
            res = (res+mod)%mod;
        } else {
            res -= inv[i];
            res = (res+mod)%mod;
        }
    }
    res *= fac[n];
    res = (res+mod) % mod;
    cout << res;
    return 0;
}




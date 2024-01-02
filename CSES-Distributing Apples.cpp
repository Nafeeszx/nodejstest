#include <bits/stdc++.h>
using namespace std;
#define trav(a, x) for(auto& a : x)
#define vi vector<int> 
typedef long long ll;

const int mod = 1e9 + 7, MOD = 998244353;

const int MAXN = 2e6;

long long fac[MAXN + 1];
		
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

int main()
{	
    
    factorial(mod);
    int n, m;
    cin >> n >> m;
    ll res = fac[n+m-1];
    if(m == 0 || n-1 == 0) res = 1;
    else {
    res *= exp(fac[m], mod-2, mod);
    res = (res+mod)%mod;
    res *= exp(fac[n-1], mod-2, mod);
    res = (res+mod)%mod;
    }
    cout << res;
    return 0;
}




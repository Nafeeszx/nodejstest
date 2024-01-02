#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define trav(a, x) for(auto& a : x)
#define FOR(i, a, b) for (int i=(a); i<=(signed)(b); i++)
#define ROF(i, a, b) for (int i=(a); i>=(signed)(b); i--)
#define F0R(i, a) for (int i=0; i<(signed)(a); i++)
#define vi vector<int>
#define vvl vector<vector<ll>>
#define all(v) (v).begin(), (v).end()
typedef long long ll;

void setIO(string name = "") { 
    ios_base::sync_with_stdio(0); cin.tie(0);
    if(name.size()){
        freopen((name+".in").c_str(), "r", stdin);
        freopen((name+".out").c_str(), "w", stdout);
    }
}

const int N = 1e6;
const ll mod = 1e9 + 7, MOD = 998244353;

ll binpowmod(ll a, ll b, ll c) {
    ll k = 1;
    do {
        if(b % 2 == 1) {
            k *= a;
            k %= c;
        }
        a = a*a;
        a %= c;
        b /= 2;
    } while(b > 0);
    return k;
}

int main() 
{	
    setIO("help");
    
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    F0R(i, n) cin >> v[i].first >> v[i].second;
    sort(all(v));
    int left = 0;
    set<int> s;
    vector<ll> dp(n, 0);
    dp[0] = 1;
    s.insert(v[0].second);
    FOR(i, 1, n-1) {
        while(s.size() > 0 && *s.begin() < v[i].first) {
            s.erase(s.begin());
            left++;
        }
        s.insert(v[i].second);
        dp[i] = 2*dp[i-1] + binpowmod(2, left, mod);
        dp[i] %= mod;
    }
    cout << dp[n-1] << "\n";
    return 0;
}   
